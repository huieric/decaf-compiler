/* File: ast_stmt.cc
 * -----------------
 * Implementation of statement node classes.
 */
#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "ast_expr.h"
#include "errors.h"

int Scope::AddDecl(Decl* d) {
    Decl* lookup = table->Lookup(d->GetName());

    if (lookup != NULL) {
        ReportError::DeclConflict(d, lookup);
        return 1;
    }
    table->Enter(d->GetName(), d);
    return 0;
}

Scope* Program::gScope = new Scope();

Program::Program(List<Decl*> *d) {
    Assert(d != NULL);
    (decls=d)->SetParentAll(this);
}

void Program::Check() {
    /* pp3: here is where the semantic analyzer is kicked off.
     *      The general idea is perform a tree traversal of the
     *      entire program, examining all constructs for compliance
     *      with the semantic rules.  Each node can have its own way of
     *      checking itself, which makes for a great use of inheritance
     *      and polymorphism in the node classes.
     */
    BuildScope();

    for(int i = 0; i < decls->NumElements(); i++)
        decls->Nth(i)->Check();
}

void Program::BuildScope() {
    for(int i = 0; i < decls->NumElements(); i++) 
        gScope->AddDecl(decls->Nth(i));
    for(int i = 0; i < decls->NumElements(); i++)
        decls->Nth(i)->BuildScope(gScope);
}

void Stmt::BuildScope(Scope* p) {
    scope->SetParent(p);
}

StmtBlock::StmtBlock(List<VarDecl*> *d, List<Stmt*> *s) {
    Assert(d != NULL && s != NULL);
    (decls=d)->SetParentAll(this);
    (stmts=s)->SetParentAll(this);
}

void StmtBlock::BuildScope(Scope* p) {
    scope->SetParent(p);

    for(int i = 0; i < decls->NumElements(); i++)
        scope->AddDecl(decls->Nth(i));

    for(int i = 0; i < decls->NumElements(); i++)
        decls->Nth(i)->BuildScope(scope);
    for(int i = 0; i < stmts->NumElements(); i++)
        stmts->Nth(i)->BuildScope(scope);
}

void StmtBlock::Check() {
    for(int i = 0; i < decls->NumElements(); i++)
        decls->Nth(i)->Check();
    for(int i = 0; i < stmts->NumElements(); i++)
        stmts->Nth(i)->Check();
}

ConditionalStmt::ConditionalStmt(Expr *t, Stmt *b) { 
    Assert(t != NULL && b != NULL);
    (test=t)->SetParent(this); 
    (body=b)->SetParent(this);
}

void ConditionalStmt::BuildScope(Scope* p) {
    scope->SetParent(p);

    test->BuildScope(scope);
    body->BuildScope(scope);
}

void ConditionalStmt::Check() {
    if(!test->GetType()->IsEquivalentTo(Type::boolType)) {
        ReportError::TestNotBoolean(test);
        return;
    }
    test->Check();
    body->Check();    
}

void LoopStmt::BuildScope(Scope* p) {
    scope->SetParent(p);
    scope->SetLoopStmt(this);

    test->BuildScope(scope);
    body->BuildScope(scope);
}

ForStmt::ForStmt(Expr *i, Expr *t, Expr *s, Stmt *b): LoopStmt(t, b) { 
    Assert(i != NULL && t != NULL && s != NULL && b != NULL);
    (init=i)->SetParent(this);
    (step=s)->SetParent(this);
}

IfStmt::IfStmt(Expr *t, Stmt *tb, Stmt *eb): ConditionalStmt(t, tb) { 
    Assert(t != NULL && tb != NULL); // else can be NULL
    elseBody = eb;
    if (elseBody) elseBody->SetParent(this);
}

void IfStmt::BuildScope(Scope* p) {
    scope->SetParent(p);

    test->BuildScope(scope);
    body->BuildScope(scope);
    if(elseBody) elseBody->BuildScope(scope);
}

void IfStmt::Check() {
    test->Check();
    body->Check();
    if(elseBody) elseBody->Check();
    
    if(!test->GetType()->IsEquivalentTo(Type::boolType)) {
        ReportError::TestNotBoolean(test);
        return;
    }    
}

void BreakStmt::Check() {
    Scope* s = scope;
    while(s != NULL) {
        if(s->GetLoopStmt() != NULL)
            return;
        s = s->GetParent();
    }
    ReportError::BreakOutsideLoop(this);
}

ReturnStmt::ReturnStmt(yyltype loc, Expr *e) : Stmt(loc) { 
    Assert(e != NULL);
    (expr=e)->SetParent(this);
}

void ReturnStmt::BuildScope(Scope* p) {
    scope->SetParent(p);

    expr->BuildScope(scope);    
}

void ReturnStmt::Check() {
    expr->Check();

    Scope* s = scope;
    while(s != NULL) {
        FnDecl* f;
        if((f=s->GetFnDecl()) != NULL) {
            Type* given = expr->GetType();
            Type* expected = f->GetReturnType();
            if(given->IsEquivalentTo(expected))
                return;
            ReportError::ReturnMismatch(this, given, expected);
        }            
        s = s->GetParent();
    }
    // ReportError::Formatted(location, "return outside function");
}

PrintStmt::PrintStmt(List<Expr*> *a) {    
    Assert(a != NULL);
    (args=a)->SetParentAll(this);
}

void PrintStmt::BuildScope(Scope* p) {
    scope->SetParent(p);

    for(int i = 0; i < args->NumElements(); i++)
        args->Nth(i)->BuildScope(scope);
}

void PrintStmt::Check() {
    for(int i = 0; i < args->NumElements(); i++)
        args->Nth(i)->Check();

    for(int i = 0; i < args->NumElements(); i++) {
        Expr* a = args->Nth(i);
        if(!a->GetType()->IsEquivalentTo(Type::stringType) &&
        !a->GetType()->IsEquivalentTo(Type::intType) &&
        !a->GetType()->IsEquivalentTo(Type::boolType))
            ReportError::PrintArgMismatch(a, i+1, a->GetType());        
    }
}

SwitchLabel::SwitchLabel(IntConstant *l, List<Stmt*> *s) {
    Assert(l != NULL && s != NULL);
    (label=l)->SetParent(this);
    (stmts=s)->SetParentAll(this);
}

SwitchLabel::SwitchLabel(List<Stmt*> *s) {
    Assert(s != NULL);
    label = NULL;
    (stmts=s)->SetParentAll(this);
}

void SwitchLabel::BuildScope(Scope* p) {
    scope->SetParent(p);

    if(label) label->BuildScope(scope);
    if(stmts) {
        for(int i = 0; i < stmts->NumElements(); i++)
            stmts->Nth(i)->BuildScope(scope);    
    }
}

void SwitchLabel::Check() {
    if(label) label->Check();
    if(stmts) {
        for(int i = 0; i < stmts->NumElements(); i++)
            stmts->Nth(i)->Check();
    }
}

SwitchStmt::SwitchStmt(Expr *n, List<CaseStmt*> *cases, DefaultStmt *def) {
    Assert(n != NULL && cases != NULL && cases->NumElements() != 0);
    (num=n)->SetParent(this);
    (caseStmts=cases)->SetParentAll(this);
    defaultStmt = def;
    if(def) def->SetParent(this);
}

void SwitchStmt::BuildScope(Scope* p) {
    scope->SetParent(p);

    num->BuildScope(scope);
    for(int i = 0; i < caseStmts->NumElements(); i++)
        caseStmts->Nth(i)->BuildScope(scope);
    if(defaultStmt) defaultStmt->BuildScope(scope);
}

void SwitchStmt::Check() {
    num->Check();
    for(int i = 0; i < caseStmts->NumElements(); i++)
        caseStmts->Nth(i)->Check();
    if(defaultStmt)
        defaultStmt->Check();
}
