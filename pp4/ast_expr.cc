/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */

#include <string.h>
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "codegen.h"

void CompoundExpr::BuildScope(Scope* p) {
    scope->SetParent(p);

    if(left) left->BuildScope(scope);
    if(right) right->BuildScope(scope);
}

void ArrayAccess::BuildScope(Scope* p) {
    scope->SetParent(p);

    base->BuildScope(scope);
    subscript->BuildScope(scope);
}

void FieldAccess::BuildScope(Scope* p) {
    scope->SetParent(p);
    if(base)
        base->BuildScope(scope);
}

void Call::BuildScope(Scope* p) {
    scope->SetParent(p);
    if(base) base->BuildScope(scope);
    for(int i = 0; i < actuals->NumElements(); i++)
        actuals->Nth(i)->BuildScope(scope);
}

void NewArrayExpr::BuildScope(Scope* p) {
    scope->SetParent(p);
    size->BuildScope(scope);
}

IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}

Location* IntConstant::Emit(CodeGenerator* cg) {
    return cg->GenLoadConstant(value);
}

DoubleConstant::DoubleConstant(yyltype loc, double val) : Expr(loc) {
    value = val;
}

Location* DoubleConstant::Emit(CodeGenerator* cg) {
    Assert(0);
    return NULL;
}

BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}

Location* BoolConstant::Emit(CodeGenerator* cg) {
    return cg->GenLoadConstant(value ? 1 : 0);
}

StringConstant::StringConstant(yyltype loc, const char *val) : Expr(loc) {
    Assert(val != NULL);
    value = strdup(val);
}

Location* StringConstant::Emit(CodeGenerator* cg) {
    return cg->GenLoadConstant(value);
}

Location* NullConstant::Emit(CodeGenerator* cg) {
    return cg->GenLoadConstant(0);
}

Operator::Operator(yyltype loc, const char *tok) : Node(loc) {
    Assert(tok != NULL);
    strncpy(tokenString, tok, sizeof(tokenString));
}

Location* Operator::Emit(CodeGenerator* cg) {
    return NULL;
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
   
Location* CompoundExpr::Emit(CodeGenerator* cg) {
    op->Emit(cg);
    if(left)
        left->Emit(cg);
    if(right)
        right->Emit(cg);
    return NULL;
}  

Location* ArithmeticExpr::Emit(CodeGenerator* cg) {
    op->Emit(cg);
    if(left)
        left->Emit(cg);
    if(right)
        right->Emit(cg);
    return NULL;
}

Location* RelationalExpr::Emit(CodeGenerator* cg) {
    op->Emit(cg);
    if(left)
        left->Emit(cg);
    if(right)
        right->Emit(cg);
    return NULL;
}

Location* EqualityExpr::Emit(CodeGenerator* cg) {
    op->Emit(cg);
    if(left)
        left->Emit(cg);
    if(right)
        right->Emit(cg);
    return NULL;
}

Location* LogicalExpr::Emit(CodeGenerator* cg) {
    op->Emit(cg);
    if(left)
        left->Emit(cg);
    if(right)
        right->Emit(cg);
    return NULL;
}

Location* AssignExpr::Emit(CodeGenerator* cg) {
    op->Emit(cg);
    if(left)
        left->Emit(cg);
    if(right)
        right->Emit(cg);
    return NULL;
}

Location* LValue::Emit(CodeGenerator* cg) {
    return NULL;
}

Location* This::Emit(CodeGenerator* cg) {
    return NULL;
}

ArrayAccess::ArrayAccess(yyltype loc, Expr *b, Expr *s) : LValue(loc) {
    Assert(base!=NULL && subscript!=NULL);
    (base=b)->SetParent(this); 
    (subscript=s)->SetParent(this);
}

Location* ArrayAccess::Emit(CodeGenerator* cg) {
    base->Emit(cg);
    subscript->Emit(cg);
    return NULL;
}

FieldAccess::FieldAccess(Expr *b, Identifier *f) 
  : LValue(b? Join(b->GetLocation(), f->GetLocation()) : *f->GetLocation()) {
    Assert(f != NULL); // b can be be NULL (just means no explicit base)
    base = b; 
    if (base) base->SetParent(this); 
    (field=f)->SetParent(this);
}

Location* FieldAccess::Emit(CodeGenerator* cg) {
    if(base)
        base->Emit(cg);
    // field->Emit();
    return NULL;
}

Call::Call(yyltype loc, Expr *b, Identifier *f, List<Expr*> *a) : Expr(loc)  {
    Assert(f != NULL && a != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
    (actuals=a)->SetParentAll(this);
}
 
Location* Call::Emit(CodeGenerator* cg) {
    if(base)
        base->Emit(cg);
    // field->Emit();
    for(int i = 0, n = actuals->NumElements(); i < n; i++)
        actuals->Nth(i)->Emit(cg);    
    return NULL;
}

NewExpr::NewExpr(yyltype loc, NamedType *c) : Expr(loc) { 
  Assert(c != NULL);
  (cType=c)->SetParent(this);
}

Location* NewExpr::Emit(CodeGenerator* cg) {
    // cType->Emit();
    return NULL;
}

NewArrayExpr::NewArrayExpr(yyltype loc, Expr *sz, Type *et) : Expr(loc) {
    Assert(sz != NULL && et != NULL);
    (size=sz)->SetParent(this); 
    (elemType=et)->SetParent(this);
}

Location* NewArrayExpr::Emit(CodeGenerator* cg) {
    size->Emit(cg);
    // elemType->Emit();
    return NULL;
}

CompoundExpr::CompoundExpr(Expr *l, Operator *o) 
  : Expr(Join(l->GetLocation(), o->GetLocation())) {
    Assert(l != NULL && o != NULL);
    (op=o)->SetParent(this);
    (left=l)->SetParent(this); 
    right = NULL;
}
       
Location* ReadIntegerExpr::Emit(CodeGenerator* cg) {
    return cg->GenBuiltInCall(ReadInteger);
}

Location* ReadLineExpr::Emit(CodeGenerator* cg) {
    return cg->GenBuiltInCall(ReadLine);
}

Location* PostfixExpr::Emit(CodeGenerator* cg) {
    return NULL;    
}

Type* CompoundExpr::GetType() {
    if(left)
        return left->GetType();
    else 
        return right->GetType();
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

Type* EqualityExpr::GetType() {
    Type* ltype = left->GetType();
    Type* rtype = right->GetType();
    if(ltype->IsEquivalentTo(rtype) ||
    rtype->IsEquivalentTo(ltype))
        return Type::boolType;
    return Type::errorType;
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

Type* AssignExpr::GetType() {
    Type* ltype = left->GetType();
    Type* rtype = right->GetType();
    if(ltype->IsEquivalentTo(rtype))
        return ltype;
    return Type::errorType;
}

Type* This::GetType() {
    ClassDecl* classDecl = GetClassDecl(scope);
    if(classDecl != NULL)
        return classDecl->GetType();
    return Type::errorType;
}

Type* ArrayAccess::GetType() {
    ArrayType* t = dynamic_cast<ArrayType*>(base->GetType());    
    if(t != NULL)
        return t->GetElemType();
    return Type::errorType;
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

Type* NewExpr::GetType() {
    Decl* d = Program::gScope->table->Lookup(cType->GetName());
    ClassDecl* c = dynamic_cast<ClassDecl*>(d);
    if(c == NULL)
        return Type::errorType;
    return c->GetType();
}

Type* NewArrayExpr::GetType() {
    return new ArrayType(elemType);
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

int ArithmeticExpr::GetMemBytes() {
    return 0;
}

int RelationalExpr::GetMemBytes() {
    return 0;
}

int EqualityExpr::GetMemBytes() {
    return 0;
}

int LogicalExpr::GetMemBytes() {
    return 0;
}

int AssignExpr::GetMemBytes() {
    return 0;
}

int This::GetMemBytes() {
    return 0;
}

int ArrayAccess::GetMemBytes() {
    return 0;    
}

int FieldAccess::GetMemBytes() {
    return 0;
}

int Call::GetMemBytes() {
    return 0;
}

int NewExpr::GetMemBytes() {
    return 0;
}

int NewArrayExpr::GetMemBytes() {
    return 0;
}

int ReadIntegerExpr::GetMemBytes() {
    return 0;
}

int ReadLineExpr::GetMemBytes() {
    return 0;
}

int PostfixExpr::GetMemBytes() {
    return 0;
}
