/* File: ast_stmt.h
 * ----------------
 * The Stmt class and its subclasses are used to represent
 * statements in the parse tree.  For each statment in the
 * language (for, if, return, etc.) there is a corresponding
 * node class for that construct. 
 *
 * pp4: You will need to extend the Stmt classes to implement
 * code generation for statements.
 */


#ifndef _H_ast_stmt
#define _H_ast_stmt

#include "list.h"
#include "ast.h"
#include "hashtable.h"

class Decl;
class VarDecl;
class Expr;
class IntConstant; // for SwitchLabel
class LoopStmt;
class ClassDecl;
class FnDecl;
class Location;
class CodeGenerator;
  
class Scope
{
  private:
    Scope* parent;

  public:
    Hashtable<Decl*> *table;
    ClassDecl* classDecl;
    FnDecl* fnDecl;
    LoopStmt* loopStmt;

  public:
    Scope() : table(new Hashtable<Decl*>), classDecl(NULL), fnDecl(NULL) {}

    void SetParent(Scope* p) { parent = p; }
    Scope* GetParent() { return parent; }

    void SetClassDecl(ClassDecl* c) { classDecl = c; }
    ClassDecl* GetClassDecl() { return classDecl; }

    void SetFnDecl(FnDecl* f) { fnDecl = f; }
    FnDecl* GetFnDecl() { return fnDecl; }

    void SetLoopStmt(LoopStmt* l) { loopStmt = l; }
    LoopStmt* GetLoopStmt() { return loopStmt; }

    int AddDecl(Decl* d);
};

class Program : public Node
{
  public:
    static Scope* gScope;

  protected:
     List<Decl*> *decls;
     CodeGenerator* codeGenerator;
     
  public:
     Program(List<Decl*> *declList);
     void BuildScope();
     void Check();
     void Emit();
};

class Stmt : public Node
{
  protected: 
    Scope* scope;

  public:
     Stmt() : Node(), scope(new Scope) {}
     Stmt(yyltype loc) : Node(loc), scope(new Scope) {}

     virtual Location* Emit(CodeGenerator* cg) = 0;
     virtual void BuildScope(Scope* p);
     virtual int GetMemBytes() = 0;
};

class StmtBlock : public Stmt 
{
  protected:
    List<VarDecl*> *decls;
    List<Stmt*> *stmts;
    
  public:
    StmtBlock(List<VarDecl*> *variableDeclarations, List<Stmt*> *statements);

    Location* Emit(CodeGenerator* cg);
    void BuildScope(Scope* parent);
    int GetMemBytes();
};

  
class ConditionalStmt : public Stmt
{
  protected:
    Expr *test;
    Stmt *body;
  
  public:
    ConditionalStmt(Expr *testExpr, Stmt *body);

    virtual Location* Emit(CodeGenerator* cg);
    virtual void BuildScope(Scope* parent);    
};

class LoopStmt : public ConditionalStmt 
{
  protected:
    const char* break_label;

  public:
    LoopStmt(Expr *testExpr, Stmt *body)
            : ConditionalStmt(testExpr, body) {}

    virtual Location* Emit(CodeGenerator* cg);
    virtual void BuildScope(Scope* parent);
    void SetBreak(const char* b) { break_label = b; }
    const char* GetBreak() { return break_label; }
};

class ForStmt : public LoopStmt 
{
  protected:
    Expr *init, *step;    
  
  public:
    ForStmt(Expr *init, Expr *test, Expr *step, Stmt *body);

    Location* Emit(CodeGenerator* cg);
    int GetMemBytes();
    void BuildScope(Scope* parent);    
};

class WhileStmt : public LoopStmt 
{
  public:
    WhileStmt(Expr *test, Stmt *body) : LoopStmt(test, body) {}

    Location* Emit(CodeGenerator* cg);
    int GetMemBytes();
};

class IfStmt : public ConditionalStmt 
{
  protected:
    Stmt *elseBody;
  
  public:
    IfStmt(Expr *test, Stmt *thenBody, Stmt *elseBody);

    Location* Emit(CodeGenerator* cg);
    Location* EmitNoElse(CodeGenerator* cg);
    Location* EmitElse(CodeGenerator* cg);
    void BuildScope(Scope* parent);
    int GetMemBytes();
};

class BreakStmt : public Stmt 
{
  public:
    BreakStmt(yyltype loc) : Stmt(loc) {}

    Location* Emit(CodeGenerator* cg);
    int GetMemBytes() { return 0; }
};

class ReturnStmt : public Stmt  
{
  protected:
    Expr *expr;
  
  public:
    ReturnStmt(yyltype loc, Expr *expr);

    Location* Emit(CodeGenerator* cg);
    void BuildScope(Scope* parent);
    int GetMemBytes();
};

class PrintStmt : public Stmt
{
  protected:
    List<Expr*> *args;
    
  public:
    PrintStmt(List<Expr*> *arguments);

    Location* Emit(CodeGenerator* cg);
    void BuildScope(Scope* parent);
    int GetMemBytes();
};

class SwitchLabel : public Stmt
{
  protected:
    IntConstant *label;
    List<Stmt*> *stmts;
  
  public:
    SwitchLabel() { label = NULL; stmts = NULL; }
    SwitchLabel(IntConstant *label, List<Stmt*> *stmts);
    SwitchLabel(List<Stmt*> *stmts);

    virtual Location* Emit(CodeGenerator* cg);
    void BuildScope(Scope* parent);
};

class CaseStmt : public SwitchLabel
{  
  public:
    CaseStmt(IntConstant *label, List<Stmt*> *stmts) : SwitchLabel(label, stmts) {}

    Location* Emit(CodeGenerator* cg);
    int GetMemBytes();
};

class DefaultStmt : public SwitchLabel
{
  public:
    DefaultStmt(List<Stmt*> *stmts) : SwitchLabel(stmts) {}

    Location* Emit(CodeGenerator* cg);
    int GetMemBytes();
};

class SwitchStmt : public Stmt
{
  protected:
    Expr *num;
    List<CaseStmt*> *caseStmts;
    DefaultStmt *defaultStmt;

  public:
    SwitchStmt(Expr *num, List<CaseStmt*> *caseStmts, DefaultStmt *defaultStmt);

    Location* Emit(CodeGenerator* cg);
    void BuildScope(Scope* parent);
    int GetMemBytes();
};

#endif
