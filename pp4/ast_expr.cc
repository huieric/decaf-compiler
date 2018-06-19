/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */

#include <string.h>
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "codegen.h"
#include "errors.h"

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
    if(left) 
        return EmitBinary(cg, left, right);
    else 
        return EmitUnary(cg, right);
}

Location* ArithmeticExpr::EmitBinary(CodeGenerator* cg, Expr* left, Expr* right) {
    Location* lhs = left->Emit(cg);
    Location* rhs = right->Emit(cg);
    return cg->GenBinaryOp(op->GetName(), lhs, rhs);
}

Location* ArithmeticExpr::EmitUnary(CodeGenerator* cg, Expr* right) {
    Location* zero = cg->GenLoadConstant(0);
    Location* rhs = right->Emit(cg);
    return cg->GenBinaryOp(op->GetName(), zero, rhs);
}

Location* RelationalExpr::Emit(CodeGenerator* cg) {
    const char* op_tok = op->GetName();
    if(strcmp(op_tok, "<")==0)
        return EmitLess(cg, left, right);
    else if(strcmp(op_tok, "<=")==0) 
        return EmitLessEqual(cg, left, right);
    else if(strcmp(op_tok, ">")==0) 
        return EmitLess(cg, right, left);
    else if(strcmp(op_tok, ">=")==0) 
        return EmitLessEqual(cg, right, left);
    else 
        Assert(0);
    return NULL;
}

Location* RelationalExpr::EmitLess(CodeGenerator* cg, Expr* left, Expr* right) {
    Location* lhs = left->Emit(cg);
    Location* rhs = right->Emit(cg);
    return cg->GenBinaryOp("<", lhs, rhs);
}

Location* RelationalExpr::EmitLessEqual(CodeGenerator* cg, Expr* left, Expr* right) {
    Location* lhs = left->Emit(cg);
    Location* rhs = right->Emit(cg);
    Location* less = cg->GenBinaryOp("<", lhs, rhs);
    Location* equal = cg->GenBinaryOp("==", lhs, rhs);
    return cg->GenBinaryOp("||", less, equal);
}

Location* EqualityExpr::Emit(CodeGenerator* cg) {
    const char* op_tok = op->GetName();
    if(strcmp(op_tok, "==")==0)
        return EmitEqual(cg, left, right);
    else if(strcmp(op_tok, "!=")==0)
        return EmitNotEqual(cg, left, right);
    else 
        Assert(0);
    return NULL;
}

Location* EqualityExpr::EmitEqual(CodeGenerator* cg, Expr* left, Expr* right) {
    Location* lhs = left->Emit(cg);
    Location* rhs = right->Emit(cg);
    if(left->GetType()->IsEquivalentTo(Type::stringType)) 
        return cg->GenBuiltInCall(StringEqual, lhs, rhs);
    else
        return cg->GenBinaryOp("==", lhs, rhs);
}

Location* EqualityExpr::EmitNotEqual(CodeGenerator* cg, Expr* left, Expr* right) {
    const char* zero = cg->NewLabel();
    const char* one = cg->NewLabel();
    Location* result = cg->GenTempVar();
    Location* equal = EmitEqual(cg, left, right);
    cg->GenIfZ(equal, zero);
    cg->GenAssign(result, cg->GenLoadConstant(0));
    cg->GenGoto(one);
    cg->GenLabel(zero);
    cg->GenAssign(result, cg->GenLoadConstant(1));
    cg->GenLabel(one);
    return result;
}

Location* LogicalExpr::Emit(CodeGenerator* cg) {
    const char* op_tok = op->GetName();
    if(strcmp(op_tok, "&&")==0) 
        return EmitAnd(cg, left, right);
    else if(strcmp(op_tok, "||")==0)
        return EmitOr(cg, left, right);
    else if(strcmp(op_tok, "!")==0)
        return EmitNot(cg, right);
    else 
        Assert(0);
    return NULL;
}

Location* LogicalExpr::EmitAnd(CodeGenerator* cg, Expr* left, Expr* right) {
    Location* lhs = left->Emit(cg);
    Location* rhs = right->Emit(cg);
    return cg->GenBinaryOp("&&", lhs, rhs);
}

Location* LogicalExpr::EmitOr(CodeGenerator* cg, Expr* left, Expr* right) {
    Location* lhs = left->Emit(cg);
    Location* rhs = right->Emit(cg);
    return cg->GenBinaryOp("||", lhs, rhs);
}

Location* LogicalExpr::EmitNot(CodeGenerator* cg, Expr* right) {
    const char* one = cg->NewLabel();
    const char* zero = cg->NewLabel();
    Location* result = cg->GenTempVar();
    Location* rhs = right->Emit(cg);
    cg->GenIfZ(rhs, zero);
    cg->GenAssign(result, cg->GenLoadConstant(0));
    cg->GenGoto(one);
    cg->GenLabel(zero);
    cg->GenAssign(result, cg->GenLoadConstant(1));
    cg->GenLabel(one);
    return result;
}

Location* AssignExpr::Emit(CodeGenerator* cg) {
    Location* rhs = right->Emit(cg);
    ArrayAccess* arrayAccess = dynamic_cast<ArrayAccess*>(left);
    Location* lhs = arrayAccess ? arrayAccess->EmitStore(cg, rhs) : left->Emit(cg);
    cg->GenAssign(lhs, rhs);
    return lhs;
}

Location* This::Emit(CodeGenerator* cg) {
    return NULL;
}

ArrayAccess::ArrayAccess(yyltype loc, Expr *b, Expr *s) : LValue(loc) {
    Assert(b!=NULL && s!=NULL);
    (base=b)->SetParent(this); 
    (subscript=s)->SetParent(this);
}

Location* ArrayAccess::Emit(CodeGenerator* cg) {  
    return EmitLoad(cg);
}

Location* ArrayAccess::EmitLoad(CodeGenerator* cg) {
    return cg->GenLoad(EmitAddr(cg), CodeGenerator::VarSize);
}

Location* ArrayAccess::EmitAddr(CodeGenerator* cg) {
    Location* addr = base->Emit(cg);
    Location* sub = subscript->Emit(cg);
    EmitRuntimeCheck(cg, addr, sub);
    Location* elemSize = cg->GenLoadConstant(CodeGenerator::VarSize);
    Location* offset = cg->GenBinaryOp("*", sub, elemSize);
    return cg->GenBinaryOp("+", addr, offset);
}

void ArrayAccess::EmitRuntimeCheck(CodeGenerator* cg, Location* addr, Location* sub) {
    const char* passCheck = cg->NewLabel();
    Location* zero = cg->GenLoadConstant(0);
    Location* size = cg->GenLoad(addr);
    Location* lessThanZero = cg->GenBinaryOp("<", sub, zero);
    Location* greaterThanSize = cg->GenBinaryOp("<", size, sub);
    Location* equalToSize = cg->GenBinaryOp("==", size, sub);
    Location* geSize = cg->GenBinaryOp("||", greaterThanSize, equalToSize);
    Location* outOfBounds = cg->GenBinaryOp("||", lessThanZero, geSize);
    cg->GenIfZ(outOfBounds, passCheck);
    Location* error = cg->GenLoadConstant(err_arr_out_of_bounds);
    cg->GenBuiltInCall(PrintString, error);
    cg->GenBuiltInCall(Halt);
    cg->GenLabel(passCheck);    
}

Location* ArrayAccess::EmitStore(CodeGenerator* cg, Location* val) {
    Location* addr = EmitAddr(cg);
    cg->GenStore(addr, val, CodeGenerator::VarSize);
    return cg->GenLoad(addr, CodeGenerator::VarSize);
}

FieldAccess::FieldAccess(Expr *b, Identifier *f) 
  : LValue(b? Join(b->GetLocation(), f->GetLocation()) : *f->GetLocation()) {
    Assert(f != NULL); // b can be be NULL (just means no explicit base)
    base = b; 
    if (base) base->SetParent(this); 
    (field=f)->SetParent(this);
}

Location* FieldAccess::Emit(CodeGenerator* cg) {
    if(base) {

    }
    else {
        Decl* d = GetFieldDecl(field, scope);
        VarDecl* v = dynamic_cast<VarDecl*>(d);
        Assert(v != NULL);
        return v->GetMemLoc();
    }
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
    if(base) {
        ArrayType* array = dynamic_cast<ArrayType*>(base->GetType());
        if(array != NULL && strcmp(field->GetName(), "length")==0) {
            Type* elemType = array->GetElemType();
            Location* sizeOfType = cg->GenLoadConstant(elemType->GetMemBytes());
            Location* memBytes = cg->GenLoad(base->Emit(cg));
            return cg->GenBinaryOp("/", memBytes, sizeOfType);
        }
    }
    else {
        Decl* d = Program::gScope->table->Lookup(field->GetName());
        FnDecl* f = dynamic_cast<FnDecl*>(d);
        Assert(f != NULL);
        int n = actuals->NumElements();
        for(int i = 0; i < n; i++) {
            Expr* actual = actuals->Nth(i);
            cg->GenPushParam(actual->Emit(cg));
        }
        bool hasReturnValue = !f->GetReturnType()->IsEquivalentTo(Type::voidType);
        Location* returnValue = cg->GenLCall(f->GetLabel(), hasReturnValue);
        cg->GenPopParams(n * CodeGenerator::VarSize);
        return returnValue;
    }
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
    Location* sizeOfType = cg->GenLoadConstant(elemType->GetMemBytes());
    Location* memBytes = cg->GenBinaryOp("*", size->Emit(cg), sizeOfType);    
    return cg->GenBuiltInCall(Alloc, memBytes);
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
    if(left)
        return GetMemBytesBinary();
    else
        return GetMemBytesUnary();
}

int ArithmeticExpr::GetMemBytesBinary() {
    return left->GetMemBytes() + right->GetMemBytes() + CodeGenerator::VarSize;
}

int ArithmeticExpr::GetMemBytesUnary() {
    return right->GetMemBytes() + 2 * CodeGenerator::VarSize;
}

int RelationalExpr::GetMemBytes() {
    const char* op_tok = op->GetName();
    if(strcmp(op_tok, "<")==0)
        return GetMemBytesLess();
    else if(strcmp(op_tok, "<=")==0) 
        return GetMemBytesLessEqual();
    else if(strcmp(op_tok, ">")==0) 
        return GetMemBytesLess();
    else if(strcmp(op_tok, ">=")==0) 
        return GetMemBytesLessEqual();
    else 
        Assert(0);
    return 0;
}

int RelationalExpr::GetMemBytesLess() {
    return left->GetMemBytes() + right->GetMemBytes() + CodeGenerator::VarSize;
}

int RelationalExpr::GetMemBytesLessEqual() {
    return left->GetMemBytes() + right->GetMemBytes() + 3 * CodeGenerator::VarSize;
}

int EqualityExpr::GetMemBytes() {
    const char* op_tok = op->GetName();
    if(strcmp(op_tok, "==")==0)
        return GetMemBytesEqual();
    else if(strcmp(op_tok, "!=")==0)
        return GetMemBytesNotEqual();
    else 
        Assert(0);
    return 0;
}

int EqualityExpr::GetMemBytesEqual() {
    return left->GetMemBytes() + right->GetMemBytes() + CodeGenerator::VarSize;
}

int EqualityExpr::GetMemBytesNotEqual() {
    return left->GetMemBytes() + right->GetMemBytes() + 4 * CodeGenerator::VarSize;
}

int LogicalExpr::GetMemBytes() {
    const char* op_tok = op->GetName();
    if(strcmp(op_tok, "&&")==0) 
        return GetMemBytesAnd();
    else if(strcmp(op_tok, "||")==0)
        return GetMemBytesOr();
    else if(strcmp(op_tok, "!")==0)
        return GetMemBytesNot();
    else 
        Assert(0);
    return 0;
}

int LogicalExpr::GetMemBytesAnd() {
    return left->GetMemBytes() + right->GetMemBytes() + CodeGenerator::VarSize;
}

int LogicalExpr::GetMemBytesOr() {
    return left->GetMemBytes() + right->GetMemBytes() + CodeGenerator::VarSize;
}

int LogicalExpr::GetMemBytesNot() {
    return right->GetMemBytes() + 3 * CodeGenerator::VarSize;
}

int AssignExpr::GetMemBytes() {
    ArrayAccess* arrayAccess = dynamic_cast<ArrayAccess*>(left);
    if(arrayAccess)
        return arrayAccess->GetMemBytesStore() + right->GetMemBytes();
    else
        return right->GetMemBytes();
}

int This::GetMemBytes() {
    return 0;
}

int ArrayAccess::GetMemBytes() {    
    return GetMemBytesLoad();
}

int ArrayAccess::GetMemBytesLoad() {
    return GetMemBytesAddr() + CodeGenerator::VarSize;
}

int ArrayAccess::GetMemBytesAddr() {
    return base->GetMemBytes() + subscript->GetMemBytes() + 
    GetMemBytesRuntimeCheck() + 3 * CodeGenerator::VarSize;
}

int ArrayAccess::GetMemBytesRuntimeCheck() {
    return 8 * CodeGenerator::VarSize;
}

int ArrayAccess::GetMemBytesStore() {
    return GetMemBytesAddr() + CodeGenerator::VarSize;
}

int FieldAccess::GetMemBytes() {
    return 0;
}

int Call::GetMemBytes() {
    if(base) {
        ArrayType* array = dynamic_cast<ArrayType*>(base->GetType());
        if(array != NULL && strcmp(field->GetName(), "length")==0) 
            return base->GetMemBytes() + 3 * CodeGenerator::VarSize;       
    }
    else {
        Decl* d = Program::gScope->table->Lookup(field->GetName());
        FnDecl* f = dynamic_cast<FnDecl*>(d);
        Assert(f != NULL);
        bool hasReturnValue = !f->GetReturnType()->IsEquivalentTo(Type::voidType);
        if(hasReturnValue) 
            return GetMemBytesActuals() + CodeGenerator::VarSize;
        else
            return GetMemBytesActuals();
    }
    return 0;
}

int Call::GetMemBytesActuals() {
    int memBytes = 0;
    for(int i = 0, n = actuals->NumElements(); i < n; i++)
        memBytes += actuals->Nth(i)->GetMemBytes();
    return memBytes;
}

int NewExpr::GetMemBytes() {
    return 0;
}

int NewArrayExpr::GetMemBytes() {
    return size->GetMemBytes() + 3 * CodeGenerator::VarSize;
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
