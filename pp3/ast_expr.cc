/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */

#include <string.h>
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"

ClassDecl* Expr::GetClassDecl(Scope* s) {
    ClassDecl* c;
    while(s != NULL) {
        if((c = s->GetClassDecl()) != NULL)
            return c;
        s = s->GetParent();
    }
    return NULL;
}

Decl* Expr::GetFieldDecl(Identifier* id, Type* b) {
    NamedType* t = dynamic_cast<NamedType*>(b);
    while(t != NULL) {
        Decl* d = Program::gScope->table->Lookup(t->GetName());       
        ClassDecl* c = dynamic_cast<ClassDecl*>(d);
        InterfaceDecl* i = dynamic_cast<InterfaceDecl*>(d);
        if(c != NULL) {
            Decl* lookup = c->GetScope()->table->Lookup(id->GetName());
            if(lookup != NULL)
                return lookup;
            t = c->GetExtends();
        }
        else if(i != NULL) {
            Decl* lookup = i->GetScope()->table->Lookup(id->GetName());
            if(lookup != NULL)
                return lookup;
            t = NULL;
        }
        else 
            t = NULL;        
    }
    return GetFieldDecl(id, scope);
}

Decl* Expr::GetFieldDecl(Identifier* id, Scope* s) {
    while(s != NULL) {
        Decl* lookup = s->table->Lookup(id->GetName());
        if(lookup != NULL)
            return lookup;
        s = s->GetParent();
    }
    return NULL;
}

IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}

DoubleConstant::DoubleConstant(yyltype loc, double val) : Expr(loc) {
    value = val;
}

BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}

StringConstant::StringConstant(yyltype loc, const char *val) : Expr(loc) {
    Assert(val != NULL);
    value = strdup(val);
}

Operator::Operator(yyltype loc, const char *tok) : Node(loc) {
    Assert(tok != NULL);
    strncpy(tokenString, tok, sizeof(tokenString));
}

CompoundExpr::CompoundExpr(Expr *l, Operator *o, Expr *r) 
  : Expr(Join(l->GetLocation(), r->GetLocation())) {
    Assert(l != NULL && o != NULL && r != NULL);
    (op=o)->SetParent(this);
    (left=l)->SetParent(this); 
    (right=r)->SetParent(this);
}

CompoundExpr::CompoundExpr(Operator *o, Expr *r) 
  : Expr(Join(o->GetLocation(), r->GetLocation())) {
    Assert(o != NULL && r != NULL);
    left = NULL; 
    (op=o)->SetParent(this);
    (right=r)->SetParent(this);
}
   
CompoundExpr::CompoundExpr(Expr *l, Operator *o) 
  : Expr(Join(l->GetLocation(), o->GetLocation())) {
    Assert(l != NULL && o != NULL);
    (op=o)->SetParent(this);
    (left=l)->SetParent(this); 
    right = NULL;
}

void CompoundExpr::BuildScope(Scope* p) {
    scope->SetParent(p);

    if(left) left->BuildScope(scope);
    if(right) right->BuildScope(scope);
}

Type* CompoundExpr::GetType() {
    if(left)
        return left->GetType();
    else 
        return right->GetType();
}

void CompoundExpr::Check() {
    if(left) 
        left->Check();
    else 
        right->Check();
}

Type* ArithmeticExpr::GetType() {
    if(left && right) {
        Type* ltype = left->GetType();
        Type* rtype = right->GetType();
        if(ltype->IsEquivalentTo(Type::intType) &&
        rtype->IsEquivalentTo(Type::intType))
            return ltype;
        if(ltype->IsEquivalentTo(Type::doubleType) &&
        rtype->IsEquivalentTo(Type::doubleType))
            return ltype;
        return Type::errorType;
    }
    Type* utype = left ? left->GetType() : right->GetType();
    if(utype->IsEquivalentTo(Type::intType) ||
    utype->IsEquivalentTo(Type::doubleType))
        return utype;
    return Type::errorType;
}

void ArithmeticExpr::Check() {
    if(left) 
        left->Check();
    if(right) 
        right->Check();
    
    if(left && right) {        
        Type* ltype = left->GetType();
        Type* rtype = right->GetType();
        if(ltype->IsEquivalentTo(Type::intType) &&
        rtype->IsEquivalentTo(Type::intType))
            return;
        if(ltype->IsEquivalentTo(Type::doubleType) &&
        rtype->IsEquivalentTo(Type::doubleType))
            return;
        ReportError::IncompatibleOperands(op, ltype, rtype);
        return;
    }
    Type* utype = left ? left->GetType() : right->GetType();
    if(utype->IsEquivalentTo(Type::intType) ||
    utype->IsEquivalentTo(Type::doubleType))
        return;
    ReportError::IncompatibleOperand(op, utype);
}

Type* RelationalExpr::GetType() {
    Type* ltype = left->GetType();
    Type* rtype = right->GetType();
    if(ltype->IsEquivalentTo(Type::intType) &&
        rtype->IsEquivalentTo(Type::intType))
        return Type::boolType;
    if(ltype->IsEquivalentTo(Type::doubleType) &&
        rtype->IsEquivalentTo(Type::doubleType))
        return Type::boolType;
    return Type::errorType;
}

void RelationalExpr::Check() {
    left->Check();
    right->Check();

    Type* ltype = left->GetType();
    Type* rtype = right->GetType();
    if(ltype->IsEquivalentTo(Type::intType) &&
        rtype->IsEquivalentTo(Type::intType))
        return;
    if(ltype->IsEquivalentTo(Type::doubleType) &&
        rtype->IsEquivalentTo(Type::doubleType))
        return;
    ReportError::IncompatibleOperands(op, ltype, rtype);
}

Type* EqualityExpr::GetType() {
    Type* ltype = left->GetType();
    Type* rtype = right->GetType();
    if(ltype->IsEquivalentTo(rtype) ||
    rtype->IsEquivalentTo(ltype))
        return Type::boolType;
    return Type::errorType;
}

void EqualityExpr::Check() {
    left->Check();
    right->Check();

    Type* ltype = left->GetType();
    Type* rtype = right->GetType();
    if(!(ltype->IsEquivalentTo(rtype) ||
    rtype->IsEquivalentTo(ltype)))
        ReportError::IncompatibleOperands(op, ltype, rtype);
    if(ltype->IsEquivalentTo(Type::voidType) ||
    rtype->IsEquivalentTo(Type::voidType))
        ReportError::IncompatibleOperands(op, ltype, rtype);
}

Type* LogicalExpr::GetType() {
    Type* rtype = right->GetType();
    if(left == NULL) {
        if(rtype->IsEquivalentTo(Type::boolType))
            return Type::boolType;
        return Type::errorType;
    }
    Type* ltype = left->GetType();
    if(ltype->IsEquivalentTo(Type::boolType) &&
    rtype->IsEquivalentTo(Type::boolType))
        return Type::boolType;
    return Type::errorType;
}

void LogicalExpr::Check() {
    if(left) left->Check();
    right->Check();

    Type* rtype = right->GetType();
    if(left == NULL) {
        if(rtype->IsEquivalentTo(Type::boolType))
            return;
        ReportError::IncompatibleOperand(op, rtype);
        return;
    }
    Type* ltype = left->GetType();
    if(ltype->IsEquivalentTo(Type::boolType) &&
    rtype->IsEquivalentTo(Type::boolType))
        return;
    ReportError::IncompatibleOperands(op, ltype, rtype);
}

Type* AssignExpr::GetType() {
    Type* ltype = left->GetType();
    Type* rtype = right->GetType();
    if(ltype->IsEquivalentTo(rtype))
        return ltype;
    return Type::errorType;
}

void AssignExpr::Check() {
    left->Check();
    right->Check();

    Type* ltype = left->GetType();
    Type* rtype = right->GetType();
    if(rtype->IsEquivalentTo(ltype))
        return;
    ReportError::IncompatibleOperands(op, ltype, rtype);
}

Type* This::GetType() {
    ClassDecl* classDecl = GetClassDecl(scope);
    if(classDecl != NULL)
        return classDecl->GetType();
    return Type::errorType;
}

void This::Check() {
    ClassDecl* classDecl = GetClassDecl(scope);
    if(classDecl != NULL)
        return;
    ReportError::ThisOutsideClassScope(this);
}

ArrayAccess::ArrayAccess(yyltype loc, Expr *b, Expr *s) : LValue(loc) {
    (base=b)->SetParent(this); 
    (subscript=s)->SetParent(this);
}

void ArrayAccess::BuildScope(Scope* p) {
    scope->SetParent(p);

    base->BuildScope(scope);
    subscript->BuildScope(scope);
}

Type* ArrayAccess::GetType() {
    ArrayType* t = dynamic_cast<ArrayType*>(base->GetType());    
    if(t != NULL)
        return t->GetElemType();
    return Type::errorType;
}

void ArrayAccess::Check() {
    base->Check();
    subscript->Check();

    ArrayType* t = dynamic_cast<ArrayType*>(base->GetType());    
    Type* stype = subscript->GetType();
    if(t == NULL)
        ReportError::BracketsOnNonArray(base);
    if(!stype->IsEquivalentTo(Type::intType))
        ReportError::SubscriptNotInteger(subscript);
}

FieldAccess::FieldAccess(Expr *b, Identifier *f) 
  : LValue(b? Join(b->GetLocation(), f->GetLocation()) : *f->GetLocation()) {
    Assert(f != NULL); // b can be be NULL (just means no explicit base)
    base = b; 
    if (base) base->SetParent(this); 
    (field=f)->SetParent(this);
}

void FieldAccess::BuildScope(Scope* p) {
    scope->SetParent(p);
    if(base)
        base->BuildScope(scope);
}

Type* FieldAccess::GetType() {
    Decl* d;
    ClassDecl* c = GetClassDecl(scope);
    Type* t;
    if(base == NULL) {
        if(c == NULL) {
            d = GetFieldDecl(field, scope);
        }
        else {
            t = c->GetType();
            d = GetFieldDecl(field, t);
        }
    }
    else {
        t = base->GetType();
        d = GetFieldDecl(field, t);
    }
    if(d == NULL || dynamic_cast<VarDecl*>(d) == NULL)
        return Type::errorType;
    return dynamic_cast<VarDecl*>(d)->GetType();
}

void FieldAccess::Check() {
    if(base) base->Check();

    Decl* d;
    ClassDecl* c = GetClassDecl(scope);
    Type* t;
    if(base == NULL) {
        if(c == NULL) {
            if((d = GetFieldDecl(field, scope)) == NULL) {
                ReportError::IdentifierNotDeclared(field, LookingForVariable);
                return;                
            }  
        }
        else {
            t = c->GetType();
            if((d = GetFieldDecl(field, t)) == NULL) {
                ReportError::FieldNotFoundInBase(field, t);
                return;
            }
        }
    }
    else {
        t = base->GetType();
        if((d = GetFieldDecl(field, t)) == NULL) {
            ReportError::FieldNotFoundInBase(field, t);
            return;
        }
        else if(c == NULL) {
            ReportError::InaccessibleField(field, t);
            return;
        }
    }
    if(dynamic_cast<VarDecl*>(d) == NULL)
        ReportError::IdentifierNotDeclared(field, LookingForVariable);
}

Call::Call(yyltype loc, Expr *b, Identifier *f, List<Expr*> *a) : Expr(loc)  {
    Assert(f != NULL && a != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
    (actuals=a)->SetParentAll(this);
}
 
void Call::BuildScope(Scope* p) {
    scope->SetParent(p);
    if(base) base->BuildScope(scope);
    for(int i = 0; i < actuals->NumElements(); i++)
        actuals->Nth(i)->BuildScope(scope);
}

Type* Call::GetType() {
    Decl* d;
    ClassDecl* c = GetClassDecl(scope);
    Type* t;
    if(base == NULL) {
        if(c == NULL) {
            d = GetFieldDecl(field, scope);
        }
        else {
            t = c->GetType();
            d = GetFieldDecl(field, t);
        }
    }
    else {
        t = base->GetType();
        d = GetFieldDecl(field, t);
        if(d==NULL && dynamic_cast<ArrayType*>(t)!=NULL && 
        strcmp(field->GetName(), "length")==0)
            return Type::intType;
    }
    if(d == NULL || dynamic_cast<FnDecl*>(d) == NULL)
        return Type::errorType;
    return dynamic_cast<FnDecl*>(d)->GetReturnType();
}

void Call::Check() {
    if(base) base->Check();
    for(int i = 0; i < actuals->NumElements(); i++)
        actuals->Nth(i)->Check();
    
    Decl* d;
    ClassDecl* c = GetClassDecl(scope);
    Type* t;
    if(base == NULL) {
        if(c == NULL) {
            if((d = GetFieldDecl(field, scope)) == NULL) {
                ReportError::IdentifierNotDeclared(field, LookingForFunction);
                return;
            }  
        }
        else {
            t = c->GetType();
            if((d = GetFieldDecl(field, t)) == NULL) {
                ReportError::IdentifierNotDeclared(field, LookingForFunction);
                return;
            }
        }
    }
    else {
        t = base->GetType();
        if((d = GetFieldDecl(field, t)) == NULL) {
            if((dynamic_cast<ArrayType*>(t)!=NULL &&
                strcmp(field->GetName(), "length")==0)) {
                return;
            }
            NamedType* nType = dynamic_cast<NamedType*>(t);
            if(nType) {
                Decl* lookup = Program::gScope->table->Lookup(nType->GetName());
                if(lookup == NULL) return;
            }        
            ReportError::FieldNotFoundInBase(field, t);
            return;
        }
    }
    FnDecl* f = dynamic_cast<FnDecl*>(d);
    if(f == NULL) {
        return;
    }
    CheckActuals(f);
}

void Call::CheckActuals(FnDecl* f) {
    List<VarDecl*> *formals = f->GetFormals();
    int numExpected = formals->NumElements();
    int numGiven = actuals->NumElements();
    if(numGiven != numExpected) {
        ReportError::NumArgsMismatch(field, numExpected, numGiven);
        return;
    }
    for(int i = 0; i < numExpected; i++) {
        Type* given = actuals->Nth(i)->GetType();
        Type* expected = formals->Nth(i)->GetType();
        if(!given->IsEquivalentTo(expected))
            ReportError::ArgMismatch(actuals->Nth(i), i+1, given, expected);        
    }
}

NewExpr::NewExpr(yyltype loc, NamedType *c) : Expr(loc) { 
  Assert(c != NULL);
  (cType=c)->SetParent(this);
}

Type* NewExpr::GetType() {
    Decl* d = Program::gScope->table->Lookup(cType->GetName());
    ClassDecl* c = dynamic_cast<ClassDecl*>(d);
    if(c == NULL)
        return Type::errorType;
    return c->GetType();
}

void NewExpr::Check() {    
    Decl* d = Program::gScope->table->Lookup(cType->GetName());
    ClassDecl* c = dynamic_cast<ClassDecl*>(d);
    if(c == NULL)
        cType->ReportNotDeclaredIdentifier(LookingForClass);
}

NewArrayExpr::NewArrayExpr(yyltype loc, Expr *sz, Type *et) : Expr(loc) {
    Assert(sz != NULL && et != NULL);
    (size=sz)->SetParent(this); 
    (elemType=et)->SetParent(this);
}

void NewArrayExpr::BuildScope(Scope* p) {
    scope->SetParent(p);
    size->BuildScope(scope);
}

Type* NewArrayExpr::GetType() {
    return new ArrayType(elemType);
}

void NewArrayExpr::Check() {
    size->Check();

    if(!size->GetType()->IsEquivalentTo(Type::intType))
        ReportError::NewArraySizeNotInteger(size);
    if(elemType->IsPrimitive() && !elemType->IsEquivalentTo(Type::voidType))
        return;
    Decl* d = Program::gScope->table->Lookup(elemType->GetName());
    if(dynamic_cast<ClassDecl*>(d)==NULL)
        elemType->ReportNotDeclaredIdentifier(LookingForType);
}

Type* ReadIntegerExpr::GetType() {
    return Type::intType;
}

Type* ReadLineExpr::GetType() {
    return Type::stringType;
}

Type* PostfixExpr::GetType() {
    return Type::intType;
}
