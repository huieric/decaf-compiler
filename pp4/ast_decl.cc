/* File: ast_decl.cc
 * -----------------
 * Implementation of Decl node classes.
 */
#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"
        
         
Decl::Decl(Identifier *n) : Node(*n->GetLocation()), scope(new Scope) {
    Assert(n != NULL);
    (id=n)->SetParent(this); 
}

void Decl::BuildScope(Scope* p) {
    scope->SetParent(p);
}

VarDecl::VarDecl(Identifier *n, Type *t) : Decl(n) {
    Assert(n != NULL && t != NULL);
    (type=t)->SetParent(this);
}

void VarDecl::Check() {
    CheckType();    
}

void VarDecl::CheckType() {
    if(type->IsPrimitive())
        return;
    Scope* s = scope;
    while(s != NULL) {
        Decl* d = s->table->Lookup(type->GetName());
        if(d != NULL) {
            if(dynamic_cast<ClassDecl*>(d)==NULL && 
            dynamic_cast<InterfaceDecl*>(d)==NULL) {
                type->ReportNotDeclaredIdentifier(LookingForType);
                // type = Type::errorType; // for error recovery
            }
            return;
        }
        s = s->GetParent();
    }
    type->ReportNotDeclaredIdentifier(LookingForType);
    // type = Type::errorType; // for error recovery
}

bool VarDecl::IsEquivalentTo(Decl* other) {
    VarDecl* varDecl = dynamic_cast<VarDecl*>(other);
    if(varDecl == NULL)
        return false;
    return type->IsEquivalentTo(varDecl->GetType());
}

ClassDecl::ClassDecl(Identifier *n, NamedType *ex, List<NamedType*> *imp, List<Decl*> *m) : Decl(n) {
    // extends can be NULL, impl & mem may be empty lists but cannot be NULL
    Assert(n != NULL && imp != NULL && m != NULL);     
    extends = ex;
    if (extends) extends->SetParent(this);
    (implements=imp)->SetParentAll(this);
    (members=m)->SetParentAll(this);
}

void ClassDecl::BuildScope(Scope* p) {
    scope->SetParent(p);
    scope->SetClassDecl(this);

    for(int i = 0; i < members->NumElements(); i++)
        scope->AddDecl(members->Nth(i));
    for(int i = 0; i < members->NumElements(); i++)
        members->Nth(i)->BuildScope(scope);    
}

void ClassDecl::Check() {
    for(int i = 0; i < members->NumElements(); i++)
        members->Nth(i)->Check();
    
    if(extends) CheckExtends();
    CheckImplements();

    for(int i = 0; i < implements->NumElements(); i++)
        CheckImplementedMembers(implements->Nth(i));
    if(extends) CheckExtendedMembers(extends);

    for(int i = 0; i < implements->NumElements(); i++)
        CheckImplementedInterfaces(implements->Nth(i));
}

void ClassDecl::CheckExtends() {
    Decl* d = scope->GetParent()->table->Lookup(extends->GetName());
    if(dynamic_cast<ClassDecl*>(d) == NULL)
        extends->ReportNotDeclaredIdentifier(LookingForClass);
}

void ClassDecl::CheckImplements() {
    for(int i = 0; i < implements->NumElements(); i++) {
        Decl* d = scope->GetParent()->table->Lookup(implements->Nth(i)->GetName());
        if(dynamic_cast<InterfaceDecl*>(d) == NULL)
            implements->Nth(i)->ReportNotDeclaredIdentifier(LookingForInterface);
    }
}

void ClassDecl::CheckExtendedMembers(NamedType* ex) {
    if(ex == NULL) return;
    Decl* d = scope->GetParent()->table->Lookup(ex->GetName());
    ClassDecl* extDecl = dynamic_cast<ClassDecl*>(d);
    if(extDecl == NULL)
        return;
    CheckExtendedMembers(extDecl->GetExtends());
    CheckAgainstScope(extDecl->GetScope());
}

void ClassDecl::CheckImplementedMembers(NamedType* im) {
    Decl* d = scope->GetParent()->table->Lookup(im->GetName());
    InterfaceDecl* intDecl = dynamic_cast<InterfaceDecl*>(d);
    if(intDecl == NULL) return; // error to report
    CheckAgainstScope(intDecl->GetScope());
}

void ClassDecl::CheckImplementedInterfaces(NamedType* im) {
    Decl* d = scope->GetParent()->table->Lookup(im->GetName());
    InterfaceDecl* intDecl = dynamic_cast<InterfaceDecl*>(d);
    if(intDecl == NULL) return; // error to report
    List<Decl*> *members = intDecl->GetMembers();
    for(int i = 0; i < members->NumElements(); i++) {
        Decl* proDecl = members->Nth(i);
        ClassDecl* classDecl = this;
        Decl* lookup;
        while(classDecl != NULL) {
            lookup = classDecl->GetScope()->table->Lookup(proDecl->GetName());        
            if(lookup != NULL) break;
            if(classDecl->GetExtends() == NULL)
                classDecl = NULL;
            else {
                NamedType* extType = classDecl->GetExtends();
                Decl* d = Program::gScope->table->Lookup(extType->GetName());
                classDecl = dynamic_cast<ClassDecl*>(d);
            }            
        }
        if(lookup == NULL) {
            ReportError::InterfaceNotImplemented(this, im);
            return;
        }
    }
}

void ClassDecl::CheckAgainstScope(Scope* s) {
    Iterator<Decl*> iter = scope->table->GetIterator();
    Decl* d;
    while((d=iter.GetNextValue())!=NULL) {
        Assert(dynamic_cast<VarDecl*>(d) != NULL ||
        dynamic_cast<FnDecl*>(d) != NULL);
        Decl* lookup = s->table->Lookup(d->GetName());
        if(lookup != NULL) {
            if(dynamic_cast<VarDecl*>(lookup) != NULL)
                ReportError::DeclConflict(d, lookup);                
            if(dynamic_cast<FnDecl*>(lookup) != NULL &&
            !d->IsEquivalentTo(lookup))
                ReportError::OverrideMismatch(d);
        }       
    }
}

InterfaceDecl::InterfaceDecl(Identifier *n, List<Decl*> *m) : Decl(n) {
    Assert(n != NULL && m != NULL);
    (members=m)->SetParentAll(this);
}

void InterfaceDecl::BuildScope(Scope* p) {
    scope->SetParent(p);

    for(int i = 0; i < members->NumElements(); i++)
        scope->AddDecl(members->Nth(i));
    for(int i = 0; i < members->NumElements(); i++)
        members->Nth(i)->BuildScope(scope);
}

void InterfaceDecl::Check() {
    for(int i = 0; i < members->NumElements(); i++) 
        members->Nth(i)->Check();    
}

FnDecl::FnDecl(Identifier *n, Type *r, List<VarDecl*> *d) : Decl(n) {
    Assert(n != NULL && r!= NULL && d != NULL);
    (returnType=r)->SetParent(this);
    (formals=d)->SetParentAll(this);
    body = NULL;
}

void FnDecl::SetFunctionBody(Stmt *b) { 
    (body=b)->SetParent(this);
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

void FnDecl::Check() {
    for(int i = 0; i < formals->NumElements(); i++) 
        formals->Nth(i)->Check();
    if(body)
        body->Check();
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
