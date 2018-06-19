/* File: ast_expr.h
 * ----------------
 * The Expr class and its subclasses are used to represent
 * expressions in the parse tree.  For each expression in the
 * language (add, call, New, etc.) there is a corresponding
 * node class for that construct. 
 *
 * pp4: You will need to extend the Expr classes to implement 
 * code generation for expressions.
 */


#ifndef _H_ast_expr
#define _H_ast_expr

#include "ast.h"
#include "ast_stmt.h"
#include "ast_type.h"
#include "list.h"

class NamedType; // for new
class Type; // for NewArray
class Location;
class CodeGenerator;

class Expr : public Stmt 
{ 
  public:
    Expr(yyltype loc) : Stmt(loc) {}
    Expr() : Stmt() {}

    ClassDecl* GetClassDecl(Scope* scope);
    Decl* GetFieldDecl(Identifier* id, Type* base);
    Decl* GetFieldDecl(Identifier* id, Scope* scope);

    virtual Type* GetType() = 0;
    virtual int GetMemBytes() = 0;
    virtual Location* Emit(CodeGenerator* cg) = 0;
};

/* This node type is used for those places where an expression is optional.
 * We could use a NULL pointer, but then it adds a lot of checking for
 * NULL. By using a valid, but no-op, node, we save that trouble */
class EmptyExpr : public Expr
{
  public:
    Type* GetType() { return Type::errorType; }
    Location* Emit(CodeGenerator* cg) { return NULL; }
    int GetMemBytes() { return 0; }    
};

class IntConstant : public Expr 
{
  protected:
    int value;
  
  public:
    IntConstant(yyltype loc, int val);

    Location* Emit(CodeGenerator* cg);    
    Type* GetType() { return Type::intType; }
    int GetMemBytes() { return 4; }
};

class DoubleConstant : public Expr 
{
  protected:
    double value;
    
  public:
    DoubleConstant(yyltype loc, double val);

    Location* Emit(CodeGenerator* cg);
    Type* GetType() { return Type::doubleType; }
    int GetMemBytes() { return 4; }
};

class BoolConstant : public Expr 
{
  protected:
    bool value;
    
  public:
    BoolConstant(yyltype loc, bool val);

    Location* Emit(CodeGenerator* cg);
    Type* GetType() { return Type::boolType; }
    int GetMemBytes() { return 4; }
};

class StringConstant : public Expr 
{ 
  protected:
    char *value;
    
  public:
    StringConstant(yyltype loc, const char *val);

    Location* Emit(CodeGenerator* cg);
    Type* GetType() { return Type::stringType; }
    int GetMemBytes() { return 4; }
};

class NullConstant: public Expr 
{
  public: 
    NullConstant(yyltype loc) : Expr(loc) {}

    Location* Emit(CodeGenerator* cg);
    Type* GetType() { return Type::nullType; }
    int GetMemBytes() { return 4; }
};

class Operator : public Node 
{
  protected:
    char tokenString[4];
    
  public:
    Operator(yyltype loc, const char *tok);
    friend ostream& operator<<(ostream& out, Operator *o) { return out << o->tokenString; }

    Location* Emit(CodeGenerator* cg);
    const char* GetName() { return tokenString; }
 };
 
class CompoundExpr : public Expr
{
  protected:
    Operator *op;
    Expr *left, *right; // left will be NULL if unary
    
  public:
    CompoundExpr(Expr *lhs, Operator *op, Expr *rhs); // for binary
    CompoundExpr(Operator *op, Expr *rhs);             // for unary
    CompoundExpr(Expr *lhs, Operator *op); // for postfix

    virtual Location* Emit(CodeGenerator* cg);
    virtual void BuildScope(Scope* parent);
    virtual Type* GetType();
};

class ArithmeticExpr : public CompoundExpr 
{
  public:
    ArithmeticExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    ArithmeticExpr(Operator *op, Expr *rhs) : CompoundExpr(op,rhs) {}

    Location* Emit(CodeGenerator* cg);
    Location* EmitBinary(CodeGenerator* cg, Expr* left, Expr* right);
    Location* EmitUnary(CodeGenerator* cg, Expr* right);
    Type* GetType();
    int GetMemBytes();
    int GetMemBytesBinary();
    int GetMemBytesUnary();
};

class RelationalExpr : public CompoundExpr 
{
  public:
    RelationalExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}

    Location* Emit(CodeGenerator* cg);
    Location* EmitLess(CodeGenerator* cg, Expr* left, Expr* right);
    Location* EmitLessEqual(CodeGenerator* cg, Expr* left, Expr* right);
    Type* GetType();
    int GetMemBytes();
    int GetMemBytesLess();
    int GetMemBytesLessEqual();
};

class EqualityExpr : public CompoundExpr 
{
  public:
    EqualityExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    const char *GetPrintNameForNode() { return "EqualityExpr"; }

    Location* Emit(CodeGenerator* cg);
    Location* EmitEqual(CodeGenerator* cg, Expr* left, Expr* right);
    Location* EmitNotEqual(CodeGenerator* cg, Expr* left, Expr* right);
    Type* GetType();
    int GetMemBytes();
    int GetMemBytesEqual();
    int GetMemBytesNotEqual();
};

class LogicalExpr : public CompoundExpr 
{
  public:
    LogicalExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    LogicalExpr(Operator *op, Expr *rhs) : CompoundExpr(op,rhs) {}
    const char *GetPrintNameForNode() { return "LogicalExpr"; }

    Location* Emit(CodeGenerator* cg);
    Location* EmitAnd(CodeGenerator* cg, Expr* left, Expr* right);
    Location* EmitOr(CodeGenerator* cg, Expr* left, Expr* right);
    Location* EmitNot(CodeGenerator* cg, Expr* right);
    Type* GetType();
    int GetMemBytes();
    int GetMemBytesAnd();
    int GetMemBytesOr();
    int GetMemBytesNot();
};

class AssignExpr : public CompoundExpr 
{
  public:
    AssignExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    const char *GetPrintNameForNode() { return "AssignExpr"; }

    Location* Emit(CodeGenerator* cg);
    Type* GetType();
    int GetMemBytes();
};

class LValue : public Expr 
{
  public:
    LValue(yyltype loc) : Expr(loc) {}
};

class This : public Expr 
{
  public:
    This(yyltype loc) : Expr(loc) {}

    Location* Emit(CodeGenerator* cg);
    Type* GetType();
    int GetMemBytes();
};

class ArrayAccess : public LValue 
{
  protected:
    Expr *base, *subscript;
    
  public:
    ArrayAccess(yyltype loc, Expr *base, Expr *subscript);

    Location* Emit(CodeGenerator* cg);
    Location* EmitLoad(CodeGenerator* cg);
    Location* EmitAddr(CodeGenerator* cg);
    Location* EmitStore(CodeGenerator* cg, Location* val);
    void EmitRuntimeCheck(CodeGenerator* cg, Location* addr, Location* subscript);
    void BuildScope(Scope* parent);
    Type* GetType();
    int GetMemBytes();
    int GetMemBytesLoad();
    int GetMemBytesAddr();
    int GetMemBytesRuntimeCheck();
    int GetMemBytesStore();
};

/* Note that field access is used both for qualified names
 * base.field and just field without qualification. We don't
 * know for sure whether there is an implicit "this." in
 * front until later on, so we use one node type for either
 * and sort it out later. */
class FieldAccess : public LValue 
{
  protected:
    Expr *base;	// will be NULL if no explicit base
    Identifier *field;
    
  public:
    FieldAccess(Expr *base, Identifier *field); //ok to pass NULL base

    Location* Emit(CodeGenerator* cg);
    void BuildScope(Scope* parent);
    Type* GetType();
    int GetMemBytes();
};

/* Like field access, call is used both for qualified base.field()
 * and unqualified field().  We won't figure out until later
 * whether we need implicit "this." so we use one node type for either
 * and sort it out later. */
class Call : public Expr 
{
  protected:
    Expr *base;	// will be NULL if no explicit base
    Identifier *field;
    List<Expr*> *actuals;
    
  public:
    Call(yyltype loc, Expr *base, Identifier *field, List<Expr*> *args);

    Location* Emit(CodeGenerator* cg);
    void BuildScope(Scope* parent);
    Type* GetType();
    int GetMemBytes(); 
    int GetMemBytesActuals();
};

class NewExpr : public Expr
{
  protected:
    NamedType *cType;
    
  public:
    NewExpr(yyltype loc, NamedType *clsType);

    Location* Emit(CodeGenerator* cg);
    Type* GetType();
    int GetMemBytes();
};

class NewArrayExpr : public Expr
{
  protected:
    Expr *size;
    Type *elemType;
    
  public:
    NewArrayExpr(yyltype loc, Expr *sizeExpr, Type *elemType);

    Location* Emit(CodeGenerator* cg);
    void BuildScope(Scope* parent);
    Type* GetType();
    int GetMemBytes();
};

class ReadIntegerExpr : public Expr
{
  public:
    ReadIntegerExpr(yyltype loc) : Expr(loc) {}

    Location* Emit(CodeGenerator* cg);
    Type* GetType();
    int GetMemBytes();
};

class ReadLineExpr : public Expr
{
  public:
    ReadLineExpr(yyltype loc) : Expr (loc) {}

    Location* Emit(CodeGenerator* cg);
    Type* GetType();
    int GetMemBytes();
};

class PostfixExpr : public CompoundExpr
{
  public:
    PostfixExpr(Expr *lhs, Operator *op) : CompoundExpr(lhs, op) {}

    Location* Emit(CodeGenerator* cg);
    Type* GetType();
    int GetMemBytes();
};    

#endif
