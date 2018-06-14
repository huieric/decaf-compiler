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

class Decl;
class VarDecl;
class Expr;
class IntConstant; // for SwitchLabel
  
class Program : public Node
{
  protected:
     List<Decl*> *decls;
     
  public:
     Program(List<Decl*> *declList);
     void Check();
     void Emit();
};

class Stmt : public Node
{
  public:
     Stmt() : Node() {}
     Stmt(yyltype loc) : Node(loc) {}
};

class StmtBlock : public Stmt 
{
  protected:
    List<VarDecl*> *decls;
    List<Stmt*> *stmts;
    
  public:
    StmtBlock(List<VarDecl*> *variableDeclarations, List<Stmt*> *statements);
};

  
class ConditionalStmt : public Stmt
{
  protected:
    Expr *test;
    Stmt *body;
  
  public:
    ConditionalStmt(Expr *testExpr, Stmt *body);
};

class LoopStmt : public ConditionalStmt 
{
  public:
    LoopStmt(Expr *testExpr, Stmt *body)
            : ConditionalStmt(testExpr, body) {}
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
};

class BreakStmt : public Stmt 
{
  public:
    BreakStmt(yyltype loc) : Stmt(loc) {}
};

class ReturnStmt : public Stmt  
{
  protected:
    Expr *expr;
  
  public:
    ReturnStmt(yyltype loc, Expr *expr);
};

class PrintStmt : public Stmt
{
  protected:
    List<Expr*> *args;
    
  public:
    PrintStmt(List<Expr*> *arguments);
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
};

#endif
