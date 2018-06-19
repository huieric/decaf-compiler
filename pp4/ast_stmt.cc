/* File: ast_stmt.cc
 * -----------------
 * Implementation of statement node classes.
 */
#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "ast_expr.h"
#include "errors.h"
#include "hashtable.h"
#include "codegen.h"

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

void Program::BuildScope() {
    for(int i = 0; i < decls->NumElements(); i++) 
        gScope->AddDecl(decls->Nth(i));
    for(int i = 0; i < decls->NumElements(); i++)
        decls->Nth(i)->BuildScope(gScope);
}

void Stmt::BuildScope(Scope* p) {
    scope->SetParent(p);
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

void ConditionalStmt::BuildScope(Scope* p) {
    scope->SetParent(p);

    test->BuildScope(scope);
    body->BuildScope(scope);
}

void LoopStmt::BuildScope(Scope* p) {
    scope->SetParent(p);
    scope->SetLoopStmt(this);

    test->BuildScope(scope);
    body->BuildScope(scope);
}

void ForStmt::BuildScope(Scope* p) {
    scope->SetParent(p);
    scope->SetLoopStmt(this);

    init->BuildScope(scope);
    test->BuildScope(scope);
    step->BuildScope(scope);
    body->BuildScope(scope);
}

void IfStmt::BuildScope(Scope* p) {
    scope->SetParent(p);

    test->BuildScope(scope);
    body->BuildScope(scope);
    if(elseBody) elseBody->BuildScope(scope);
}

void ReturnStmt::BuildScope(Scope* p) {
    scope->SetParent(p);
    if(expr)
        expr->BuildScope(scope);
}

void PrintStmt::BuildScope(Scope* p) {
    scope->SetParent(p);

    for(int i = 0; i < args->NumElements(); i++)
        args->Nth(i)->BuildScope(scope);
}

void SwitchLabel::BuildScope(Scope* p) {
    scope->SetParent(p);

    if(label) label->BuildScope(scope);
    if(stmts) {
        for(int i = 0; i < stmts->NumElements(); i++)
            stmts->Nth(i)->BuildScope(scope);    
    }
}

void SwitchStmt::BuildScope(Scope* p) {
    scope->SetParent(p);

    num->BuildScope(scope);
    for(int i = 0; i < caseStmts->NumElements(); i++)
        caseStmts->Nth(i)->BuildScope(scope);
    if(defaultStmt) defaultStmt->BuildScope(scope);
}

Program::Program(List<Decl*> *d) : codeGenerator(new CodeGenerator) {
    Assert(d != NULL);
    (decls=d)->SetParentAll(this);
}

void Program::Check() {
    /* You can use your pp3 semantic analysis or leave it out if
     * you want to avoid the clutter.  We won't test pp4 against 
     * semantically-invalid programs.
     */
    BuildScope();
}

void Program::Emit() {
    /* pp4: here is where the code generation is kicked off.
     *      The general idea is perform a tree traversal of the
     *      entire program, generating instructions as you go.
     *      Each node can have its own way of translating itself,
     *      which makes for a great use of inheritance and
     *      polymorphism in the node classes.
     */
    int offset = CodeGenerator::OffsetToFirstGlobal;
    for(int i = 0, n = decls->NumElements(); i < n; i++) {
        VarDecl* v = dynamic_cast<VarDecl*>(decls->Nth(i));
        if(v != NULL) {
            Location* l = new Location(gpRelative, offset, v->GetName());
            v->SetMemLoc(l);
            offset += v->GetMemBytes();
        }
    }
    for(int i = 0, n = decls->NumElements(); i < n; i++) 
        decls->Nth(i)->Emit(codeGenerator);
    codeGenerator->DoFinalCodeGen();
}

StmtBlock::StmtBlock(List<VarDecl*> *d, List<Stmt*> *s) {
    Assert(d != NULL && s != NULL);
    (decls=d)->SetParentAll(this);
    (stmts=s)->SetParentAll(this);
}

Location* StmtBlock::Emit(CodeGenerator* cg) {    
    for(int i = 0, n = decls->NumElements(); i < n; i++) {
        VarDecl* v = dynamic_cast<VarDecl*>(decls->Nth(i));
        if(v != NULL) {
            Location* l = cg->GenLocalVar(v->GetName(), v->GetMemBytes());
            // Location* l = new Location(fpRelative, offset, v->GetName());
            v->SetMemLoc(l);
        }
    }
    for(int i = 0, n = stmts->NumElements(); i < n; i++)
        stmts->Nth(i)->Emit(cg);
    return NULL;
}

ConditionalStmt::ConditionalStmt(Expr *t, Stmt *b) { 
    Assert(t != NULL && b != NULL);
    (test=t)->SetParent(this); 
    (body=b)->SetParent(this);
}

Location* ConditionalStmt::Emit(CodeGenerator* cg) {
    test->Emit(cg);
    body->Emit(cg);
    return NULL;
}

Location* LoopStmt::Emit(CodeGenerator* cg) {
    return NULL;
}

ForStmt::ForStmt(Expr *i, Expr *t, Expr *s, Stmt *b): LoopStmt(t, b) { 
    Assert(i != NULL && t != NULL && s != NULL && b != NULL);
    (init=i)->SetParent(this);
    (step=s)->SetParent(this);
}

Location* ForStmt::Emit(CodeGenerator* cg) {
    const char* loop = cg->NewLabel();
    const char* done = cg->NewLabel();
    SetBreak(done);
    init->Emit(cg);
    cg->GenLabel(loop);
    cg->GenIfZ(test->Emit(cg), done);
    body->Emit(cg);
    step->Emit(cg);
    cg->GenGoto(loop);
    cg->GenLabel(done);    
    return NULL;
}

Location* WhileStmt::Emit(CodeGenerator* cg) {
    const char* loop = cg->NewLabel();
    const char* done = cg->NewLabel();
    SetBreak(done);
    cg->GenLabel(loop);
    cg->GenIfZ(test->Emit(cg), done);
    body->Emit(cg);
    cg->GenGoto(loop);
    cg->GenLabel(done); 
    return NULL;
}

IfStmt::IfStmt(Expr *t, Stmt *tb, Stmt *eb): ConditionalStmt(t, tb) { 
    Assert(t != NULL && tb != NULL); // else can be NULL
    elseBody = eb;
    if (elseBody) elseBody->SetParent(this);
}

Location* IfStmt::Emit(CodeGenerator* cg) {
    if(elseBody)
        EmitElse(cg);
    else
        EmitNoElse(cg);
    return NULL;
}

Location* IfStmt::EmitNoElse(CodeGenerator* cg) {
    const char* not_do = cg->NewLabel();
    cg->GenIfZ(test->Emit(cg), not_do);
    body->Emit(cg);
    cg->GenLabel(not_do);
    return NULL;
}

Location* IfStmt::EmitElse(CodeGenerator* cg) {
    const char* then_label = cg->NewLabel();
    const char* else_label = cg->NewLabel();
    cg->GenIfZ(test->Emit(cg), else_label);
    body->Emit(cg);
    cg->GenGoto(then_label);
    cg->GenLabel(else_label);
    elseBody->Emit(cg);
    cg->GenLabel(then_label);
    return NULL;
}

Location* BreakStmt::Emit(CodeGenerator* cg) {
    Scope* s = scope;
    LoopStmt* l = NULL;
    while(s != NULL) {
        if((l=s->GetLoopStmt()) != NULL) 
            break;
        s = s->GetParent();
    }
    Assert(l != NULL);
    cg->GenGoto(l->GetBreak());
    return NULL;
}

ReturnStmt::ReturnStmt(yyltype loc, Expr *e) : Stmt(loc) { 
    Assert(e != NULL);
    (expr=e)->SetParent(this);
}

Location* ReturnStmt::Emit(CodeGenerator* cg) {
    if(expr)
        cg->GenReturn(expr->Emit(cg));
    else
        cg->GenReturn();
    return NULL;      
}

PrintStmt::PrintStmt(List<Expr*> *a) {    
    Assert(a != NULL);
    (args=a)->SetParentAll(this);
}

Location* PrintStmt::Emit(CodeGenerator* cg) {
    for(int i = 0, n = args->NumElements(); i < n; i++) {
        Expr* e = args->Nth(i);
        BuiltIn b = e->GetType()->GetPrint();
        Location* t = e->Emit(cg);
        Assert(b != NumBuiltIns);
        cg->GenBuiltInCall(b, t);
    }
    return NULL;
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

SwitchStmt::SwitchStmt(Expr *n, List<CaseStmt*> *cases, DefaultStmt *def) {
    Assert(n != NULL && cases != NULL && cases->NumElements() != 0);
    (num=n)->SetParent(this);
    (caseStmts=cases)->SetParentAll(this);
    defaultStmt = def;
    if(def) def->SetParent(this);
}

Location* SwitchLabel::Emit(CodeGenerator* cg) {
    if(label)
        label->Emit(cg);
    if(stmts) {
        for(int i = 0, n = stmts->NumElements(); i < n; i++)
            stmts->Nth(i)->Emit(cg);
    }
    return NULL;
}

Location* CaseStmt::Emit(CodeGenerator* cg) {
    return NULL;
}

Location* DefaultStmt::Emit(CodeGenerator* cg) {
    return NULL;
}

Location* SwitchStmt::Emit(CodeGenerator* cg) {
    num->Emit(cg);
    for(int i = 0, n = caseStmts->NumElements(); i < n; i++)
        caseStmts->Nth(i)->Emit(cg);
    if(defaultStmt)
        defaultStmt->Emit(cg);
    return NULL;
}

int StmtBlock::GetMemBytes() {
    int memBytes = 0;
    for(int i = 0, n = decls->NumElements(); i < n; i++)
        memBytes += decls->Nth(i)->GetMemBytes();
    for(int i = 0, n = stmts->NumElements(); i < n; i++)
        memBytes += stmts->Nth(i)->GetMemBytes();
    return memBytes;
}

int ForStmt::GetMemBytes() {
    return init->GetMemBytes() + test->GetMemBytes() + step->GetMemBytes() + body->GetMemBytes();
}

int WhileStmt::GetMemBytes() {
    return test->GetMemBytes() + body->GetMemBytes();
}

int IfStmt::GetMemBytes() {
    if(elseBody)
        return test->GetMemBytes() + body->GetMemBytes() + elseBody->GetMemBytes();
    else
        return test->GetMemBytes() + body->GetMemBytes();
}

int ReturnStmt::GetMemBytes() {
    if(expr)
        return expr->GetMemBytes();
    else
        return 0;
}

int PrintStmt::GetMemBytes() {
    int memBytes = 0;
    for(int i = 0, n = args->NumElements(); i < n; i++)
        memBytes += args->Nth(i)->GetMemBytes();
    return memBytes;
}

int CaseStmt::GetMemBytes() {
    return 0;
}

int DefaultStmt::GetMemBytes() {
    return 0;
}

int SwitchStmt::GetMemBytes() {
    return 0;
}
