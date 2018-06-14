/* File: ast_stmt.h
 * ----------------
 * The Stmt class and its subclasses are used to represent
 * statements in the parse tree.  For each statment in the
 * language (for, if, return, etc.) there is a corresponding
 * node class for that construct. 
 *
 * pp3: You will need to extend the Stmt classes to implement
 * semantic analysis for rules pertaining to statements.
 */


#ifndef _H_ast_stmt
#define _H_ast_stmt

#include "list.h"
#include "ast.h"
#include "hashtable.h"

class Decl;
class VarDecl;
class Expr;
class IntConstant; // for SwitchStmt
class LoopStmt;
class ClassDecl;
class FnDecl;

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
     
  public:
     Program(List<Decl*> *declList);
     void Check();

     void BuildScope();
};

class Stmt : public Node
{
  protected:
    Scope* scope;

  public:
     Stmt() : Node(), scope(new Scope) {}
     Stmt(yyltype loc) : Node(loc), scope(new Scope) {}

     virtual void BuildScope(Scope* p);
     virtual void Check() = 0;
};

class StmtBlock : public Stmt 
{
  protected:
    List<VarDecl*> *decls;
    List<Stmt*> *stmts;
    
  public:
    StmtBlock(List<VarDecl*> *variableDeclarations, List<Stmt*> *statements);

    void BuildScope(Scope* parent);
    void Check();
};
  
class ConditionalStmt : public Stmt
{
  protected:
    Expr *test;
    Stmt *body;
  
  public:
    ConditionalStmt(Expr *testExpr, Stmt *body);

    virtual void BuildScope(Scope* parent);
    virtual void Check();
};

class LoopStmt : public ConditionalStmt 
{
  public:
    LoopStmt(Expr *testExpr, Stmt *body)
            : ConditionalStmt(testExpr, body) {}

    virtual void BuildScope(Scope* parent);
};

class ForStmt : public LoopStmt 
{
  protected:
    Expr *init, *step;
  
  public:
    ForStmt(Expr *init, Expr *test, Expr *step, Stmt *body);
};

class WhileStmt : public LoopStmt 
{
  public:
    WhileStmt(Expr *test, Stmt *body) : LoopStmt(test, body) {}
};

class IfStmt : public ConditionalStmt 
{
  protected:
    Stmt *elseBody;
  
  public:
    IfStmt(Expr *test, Stmt *thenBody, Stmt *elseBody);

    void BuildScope(Scope* parent);
    void Check();
};

class BreakStmt : public Stmt 
{
  public:
    BreakStmt(yyltype loc) : Stmt(loc) {}

    void Check();
};

class ReturnStmt : public Stmt  
{
  protected:
    Expr *expr;
  
  public:
    ReturnStmt(yyltype loc, Expr *expr);

    void BuildScope(Scope* parent);
    void Check();
};

class PrintStmt : public Stmt
{
  protected:
    List<Expr*> *args;
    
  public:
    PrintStmt(List<Expr*> *arguments);

    void BuildScope(Scope* parent);
    void Check();
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

    virtual void BuildScope(Scope* parent);
    virtual void Check();
};

class CaseStmt : public SwitchLabel
{  
  public:
    CaseStmt(IntConstant *label, List<Stmt*> *stmts) : SwitchLabel(label, stmts) {}
};

class DefaultStmt : public SwitchLabel
{
  public:
    DefaultStmt(List<Stmt*> *stmts) : SwitchLabel(stmts) {}
};

class SwitchStmt : public Stmt
{
  protected:
    Expr *num;
    List<CaseStmt*> *caseStmts;
    DefaultStmt *defaultStmt;

  public:
    SwitchStmt(Expr *num, List<CaseStmt*> *caseStmts, DefaultStmt *defaultStmt);

    void BuildScope(Scope* parent);
    void Check();
};

#endif
