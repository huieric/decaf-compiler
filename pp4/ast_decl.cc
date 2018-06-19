/* File: ast_decl.cc
 * -----------------
 * Implementation of Decl node classes.
 */
#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"
        
void Decl::BuildScope(Scope* p) {
    scope->SetParent(p);
}

void ClassDecl::BuildScope(Scope* p) {
    scope->SetParent(p);
    scope->SetClassDecl(this);

    for(int i = 0; i < members->NumElements(); i++)
        scope->AddDecl(members->Nth(i));
    for(int i = 0; i < members->NumElements(); i++)
        members->Nth(i)->BuildScope(scope);    
}

void InterfaceDecl::BuildScope(Scope* p) {
    scope->SetParent(p);

    for(int i = 0; i < members->NumElements(); i++)
        scope->AddDecl(members->Nth(i));
    for(int i = 0; i < members->NumElements(); i++)
        members->Nth(i)->BuildScope(scope);
}

void FnDecl::BuildScope(Scope* p) {
    scope->SetParent(p);
    scope->SetFnDecl(this);

    for(int i = 0; i < formals->NumElements(); i++)
        scope->AddDecl(formals->Nth(i));
    for(int i = 0; i < formals->NumElements(); i++)        
        formals->Nth(i)->BuildScope(scope);
    if(body) body->BuildScope(scope);
}

Decl::Decl(Identifier *n) : Node(*n->GetLocation()), scope(new Scope) {
    Assert(n != NULL);
    (id=n)->SetParent(this); 
}

VarDecl::VarDecl(Identifier *n, Type *t) : Decl(n) {
    Assert(n != NULL && t != NULL);
    (type=t)->SetParent(this);
}
  
Location* VarDecl::Emit(CodeGenerator* cg) {
    return NULL;
}

ClassDecl::ClassDecl(Identifier *n, NamedType *ex, List<NamedType*> *imp, List<Decl*> *m) : Decl(n) {
    // extends can be NULL, impl & mem may be empty lists but cannot be NULL
    Assert(n != NULL && imp != NULL && m != NULL);     
    extends = ex;
    if (extends) extends->SetParent(this);
    (implements=imp)->SetParentAll(this);
    (members=m)->SetParentAll(this);
}

Location* ClassDecl::Emit(CodeGenerator* cg) {
    for(int i = 0, n = members->NumElements(); i < n; i++)
        members->Nth(i)->Emit(cg);
    return NULL;
}

InterfaceDecl::InterfaceDecl(Identifier *n, List<Decl*> *m) : Decl(n) {
    Assert(n != NULL && m != NULL);
    (members=m)->SetParentAll(this);
}

Location* InterfaceDecl::Emit(CodeGenerator* cg) {
    for(int i = 0, n = members->NumElements(); i < n; i++)
        members->Nth(i)->Emit(cg);
    return NULL;
}

FnDecl::FnDecl(Identifier *n, Type *r, List<VarDecl*> *d) : Decl(n) {
    Assert(n != NULL && r!= NULL && d != NULL);
    (returnType=r)->SetParent(this);
    (formals=d)->SetParentAll(this);
    body = NULL;
    label = new std::string(n->GetName());
    if(*label != "main")
        label->insert(0, "__");
    localOffset = CodeGenerator::OffsetToFirstLocal;
}

void FnDecl::SetFunctionBody(Stmt *b) { 
    (body=b)->SetParent(this);
}

const char* FnDecl::GetLabel() {
    return label->c_str();
}

Location* FnDecl::Emit(CodeGenerator* cg) {
    int offset = CodeGenerator::OffsetToFirstParam;    
    for(int i = 0, n = formals->NumElements(); i < n; i++) {
        VarDecl* v = formals->Nth(n-i-1);
        Location* l = new Location(fpRelative, offset, v->GetName());
        v->SetMemLoc(l);
        offset += v->GetMemBytes();
    }
    if(body) {
        cg->resetLocalOffset();
        cg->GenLabel(GetLabel());
        cg->GenBeginFunc()->SetFrameSize(body->GetMemBytes());
        body->Emit(cg);
        cg->GenEndFunc();
    }
    return NULL;
}

bool VarDecl::IsEquivalentTo(Decl* other) {
    VarDecl* varDecl = dynamic_cast<VarDecl*>(other);
    if(varDecl == NULL)
        return false;
    return type->IsEquivalentTo(varDecl->GetType());
}

bool FnDecl::IsEquivalentTo(Decl* other) {
    FnDecl* fnDecl = dynamic_cast<FnDecl*>(other);    
    if(fnDecl == NULL)
        return false;
    if(!returnType->IsEquivalentTo(fnDecl->GetReturnType()))
        return false;
    if(formals->NumElements() != fnDecl->GetFormals()->NumElements())
        return false;
    for(int i = 0; i < formals->NumElements(); i++) 
        if(!formals->Nth(i)->IsEquivalentTo(fnDecl->GetFormals()->Nth(i)))
            return false;

    return true;
}

int VarDecl::GetMemBytes() {
    return CodeGenerator::VarSize;
}

int ClassDecl::GetMemBytes() {
    return 0; // TODO
}
