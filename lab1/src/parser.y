/* File: parser.y
 * --------------
 * Bison input file to generate the parser for the compiler.
 *
 */

%{
#include "scanner.h"
#include "parser.h"
#include "errors.h"

void yyerror(const char *msg);

FILE *parser_log;
%}

/* yylval
 * ------
 * Here we define the type of the yylval global variable that is used by
 * the scanner to store attribute information about the token just scanned
 * and thus communicate that information to the parser.
 *
 */

%union {
    int intConstant;
    bool boolConstant;
    char *stringConstant;
    double doubleConstant;
    char identifier[MaxIdentLen+1];
    Decl *decl;
    List<Decl*> *declList;
    Type *type;
    VarDecl *varDecl;
    FnDecl *fnDecl;
    Identifier *identObj;
    List<NamedType*> *nTList;
    ClassDecl *classDecl;
    NamedType *extendsClause;
    InterfaceDecl *ifaceDecl;
    List<VarDecl*> *varDecls;
    List<Stmt*> *statements;
    Stmt* stmt;
    PrintStmt *printStmt;
    List<Expr*> *exprList;
    Expr *expr;
    StmtBlock *stmtBlock;
    LValue *lvalue;
    Call *call;
    IfStmt *ifStmt;
    WhileStmt *whileStmt;
    ForStmt *forStmt;
    ReturnStmt *returnStmt;
    BreakStmt *breakStmt;
    SwitchStmt *switchStmt;
    List<Case*> *caseStmts;
    Case *caseStmt;
    Default *defaultStmt;
}

/* declare tokens */
%token INT DOUBLE BOOL STRING VOID NULLCONSTANT
%token BREAK CLASS ELSE EXTENDS FOR IF NEW RETURN THIS WHILE STATIC 
%token PRINT READINTEGER READLINE INSTANCEOF NEWARRAY IMPLEMENTS INTERFACE
%token LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP NOT_OP

%token <identifier> IDENTIFIER
%token <stringConstant> STRING_LITERAL
%token <intConstant> INTCONSTANT
%token <doubleConstant> DOUBLECONSTANT
%token <boolConstant> BOOLCONSTANT

// these are virtual tokens that aren't really parsed.
// used for precedence operations
%token UMINUS
%token NOELSE

/* Non-terminal types
 * ------------------
 * In order for yacc to assign/access the correct field of $$, $1, we
 * must to declare which field is appropriate for the non-terminal.
 * As an example, this first type declaration establishes that the DeclList
 * non-terminal uses the field named "declList" int hte yylval union. This
 * means that when we are setting $$ for a reduction for DeclList or reading 
 * $n which corresponds to a DeclList non-terminal we are accessing the field 
 * of the union named "declList" which is of type List<Decl*>.
 *
 */
%type <declList> DeclList
%type <decl> Decl
%type <varDecl> VariableDecl
%type <varDecl> Variable
%type <identObj> Identifier
%type <varDecls> VariableList
%type <type> Type
%type <varDecls> Formals
%type <fnDecl> FunctionDecl
%type <classDecl> ClassDecl
%type <extendsClause> ExtendsClause
%type <nTList> ImplementsClause
%type <nTList> InterfaceList
%type <declList> FieldList
%type <decl> Field
%type <ifaceDecl> InterfaceDecl
%type <declList> PrototypeList
%type <decl> Prototype
%type <stmtBlock> StmtBlock
%type <varDecls>  VariableDeclList
%type <statements> StmtList
%type <stmt> Stmt
%type <exprList> ExprList
%type <ifStmt> IfStmt
%type <whileStmt> WhileStmt
%type <forStmt> ForStmt
%type <returnStmt> ReturnStmt
%type <breakStmt> BreakStmt
%type <printStmt> PrintStmt
%type <expr> Expr
%type <lvalue> LValue
%type <call> Call
%type <exprList> Actuals
%type <expr> Constant

/* Precedence Assignment */
%right '='
%left OR_OP
%left AND_OP
%nonassoc EQ_OP NE_OP
%nonassoc '<' '>' LE_OP GE_OP
%left '+' '-' 
%left '*' '/' '%'
%nonassoc NOT_OP UMINUS
%nonassoc '[' '.'
%nonassoc ')' NOELSE
%nonassoc ELSE

%start Program

%%
Program
    : DeclList {
                    Program *program = new Program($1);
                    program->SetParent(NULL);
                    for(int i = 0; i < $1->NumElements(); i++) {
                        program->addChild($1->Nth(i));
                    }                    
                    program->setNodeName("Program");                    
                    if(ReportError::NumErrors()==0)
                        program->Check();                    
                    if(ReportError::NumErrors()==0)
                        program->Emit();                    
                    program->printTree(0);
               }
    ;

DeclList
    : DeclList Decl { ($$=$1)->Append($2); }
    | Decl          { ($$=new List<Decl*>)->Append($1); }
    ;

Decl
    : VariableDecl { $$=$1; }
    | FunctionDecl { $$=$1; }
    | ClassDecl { $$=$1; }
    | InterfaceDecl { $$=$1; }
    ;

VariableDecl
    : Variable ';' { $$=$1; }
    ;

Variable
    : Type Identifier { $$=new VarDecl($2, $1); 
                        $$->addChild($1);    
                        $$->addChild($2);
                        $$->setNodeName("Variable");
                      }
    ;

VariableList
    : Variable { ($$=new List<VarDecl*>)->Append($1); }
    | VariableList ',' Variable { ($$=$1)->Append($3); }
    ;

LValue
    : Identifier { $$=new FieldAccess(NULL, $1); 
                   $$->addChild($1);
                   $$->setNodeName("LValue");
                 }
    | Expr '.' Identifier { $$=new FieldAccess($1, $3); 
                            $$->addChild($1);
                            $$->addChild(new Node("."));
                            $$->addChild($3);
                            $$->setNodeName("LValue");
                          }
    | Expr '[' Expr ']' { $$=new ArrayAccess(@$, $1, $3); 
                          $$->addChild($1);
                          $$->addChild(new Node("["));
                          $$->addChild($3);
                          $$->addChild(new Node("]"));
                          $$->setNodeName("LValue");
                        }
    ;
    
Type
    : INT { $$=Type::intType; 
            $$->addChild(new Node("INT"));
            $$->setNodeName("Type");
          }
    | DOUBLE { $$=Type::doubleType; 
               $$->addChild(new Node("DOUBLE"));
               $$->setNodeName("Type");
             }
    | BOOL { $$=Type::boolType; 
             $$->addChild(new Node("BOOL"));
             $$->setNodeName("Type");
           }
    | STRING { $$=Type::stringType; 
               $$->addChild(new Node("STRING"));
               $$->setNodeName("Type");
             }
    | Identifier { $$=new NamedType($1); 
                   $$->addChild(new Node("Identifier"));
                   $$->setNodeName("Type");
                 }
    | Type '[' ']' { $$=new ArrayType(@1, $1); 
                     $$->addChild($1);
                     $$->addChild(new Node("["));
                     $$->addChild(new Node("]"));
                     $$->setNodeName("Type");
                   }
    ;

Identifier
    : IDENTIFIER { $$=new Identifier(@1, $1);
                   $$->setNodeName("Identifier");
                 }
    ;
    
Formals
    : /* Empty */ { $$=new List<VarDecl*>; }
    | VariableList { $$=$1; }
    ;

FunctionDecl
    : Type Identifier '(' Formals ')' StmtBlock { $$=new FnDecl($2, $1, $4); $$->SetFunctionBody($6); 
                                                  $$->addChild($1);
                                                  $$->addChild($2);
                                                  $$->addChild(new Node("("));
                                                  if($4->NumElements() > 0) {
                                                      for(int i = 0; i < $4->NumElements()-1; i++) {
                                                        $$->addChild($4->Nth(i));
                                                        $$->addChild(new Node(","));
                                                    }
                                                    $$->addChild($4->Nth($4->NumElements()-1));
                                                  }                                                  
                                                  $$->addChild(new Node(")"));
                                                  $$->addChild($6);
                                                  $$->setNodeName("FunctionDecl");
                                                }
    | VOID Identifier '(' Formals ')' StmtBlock { $$=new FnDecl($2, Type::voidType, $4); $$->SetFunctionBody($6); 
                                                  $$->addChild(new Node("VOID"));
                                                  $$->addChild($2);
                                                  $$->addChild(new Node("("));
                                                  if($4->NumElements() > 0) {
                                                      for(int i = 0; i < $4->NumElements()-1; i++) {
                                                        $$->addChild($4->Nth(i));
                                                        $$->addChild(new Node(","));
                                                    }
                                                    $$->addChild($4->Nth($4->NumElements()-1));
                                                  }                                            
                                                  $$->addChild(new Node(")"));
                                                  $$->addChild($6);                                                  
                                                  $$->setNodeName("FunctionDecl");
                                                }
    ;

ClassDecl
    : CLASS Identifier ExtendsClause ImplementsClause '{' FieldList '}' { $$=new ClassDecl($2, $3, $4, $6); 
                                                                          
                                                                        }
    ;

ExtendsClause
    : /* Empty */ { $$=NULL; }
    | EXTENDS Identifier { $$=new NamedType($2); }
    ;

ImplementsClause
    : /* Empty */ { $$=new List<NamedType*>; }
    | IMPLEMENTS InterfaceList { $$=$2; }
    ;

InterfaceList
    : Identifier { ($$=new List<NamedType*>)->Append(new NamedType($1)); }
    | InterfaceList ',' Identifier { ($$=$1)->Append(new NamedType($3)); }
    ;
    
FieldList
    : /* Empty */ { $$=new List<Decl*>; }
    | FieldList Field { ($$=$1)->Append($2); }
    ;

Field
    : VariableDecl { $$=$1; }
    | FunctionDecl { $$=$1; }
    ;

InterfaceDecl
    : INTERFACE Identifier '{' PrototypeList '}' { $$=new InterfaceDecl($2, $4); }
    ;

PrototypeList
    : /* Empty */ { $$=new List<Decl*>; }
    | PrototypeList Prototype { ($$=$1)->Append($2); }
    ;

Prototype
    : Type Identifier '(' Formals ')' ';' { $$=new FnDecl($2, $1, $4); }
    | VOID Identifier '(' Formals ')' ';' { $$=new FnDecl($2, NULL, $4); }
    ;

StmtBlock
    : '{' VariableDeclList StmtList '}' { $$=new StmtBlock($2, $3); 
                                          $$->addChild(new Node("{"));
                                          for(int i = 0; i < $2->NumElements(); i++) {
                                              $$->addChild($2->Nth(i));
                                          }
                                          for(int i = 0; i < $3->NumElements(); i++) {
                                              $$->addChild($3->Nth(i));
                                          }                                          
                                          $$->addChild(new Node("}"));
                                          $$->setNodeName("StmtBlock");
                                        }
    ;

VariableDeclList
    : /* Empty */ { $$=new List<VarDecl*>; }
    | VariableDeclList VariableDecl { ($$=$1)->Append($2); }
    ;

StmtList
    : /* Empty */ { $$=new List<Stmt*>; }
    | Stmt StmtList { ($$=$2)->InsertAt($1, 0); }
    ;

Stmt
    : ';' { $$=new EmptyExpr();
            // $$->addChild(new Node(";"));
            // $$->setNodeName("Stmt");
          }
    | Expr ';' { $$=$1;                  
               }
    | IfStmt { $$=$1; }
    | WhileStmt { $$=$1; }
    | ForStmt { $$=$1; }
    | BreakStmt { $$=$1; }
    | ReturnStmt { $$=$1; }
    | PrintStmt { $$=$1; }
    | StmtBlock { $$=$1; }
    ;

ExprList
    : Expr { ($$=new List<Expr*>)->Append($1); }
    | ExprList ',' Expr { ($$=$1)->Append($3); }
    ;

IfStmt
    : IF '(' Expr ')' Stmt %prec NOELSE { $$=new IfStmt($3, $5, NULL); 
                                          $$->addChild(new Node("IF"));
                                          $$->addChild(new Node("("));
                                          $$->addChild($3);
                                          $$->addChild(new Node(")"));
                                          $$->addChild($5);
                                          $$->setNodeName("IfStmt");
                                        }
    | IF '(' Expr ')' Stmt ELSE Stmt { $$=new IfStmt($3, $5, $7); 
                                       $$->addChild(new Node("IF"));
                                          $$->addChild(new Node("("));
                                          $$->addChild($3);
                                          $$->addChild(new Node(")"));
                                          $$->addChild($5);
                                          $$->addChild(new Node("ELSE"));
                                          $$->addChild($7);
                                          $$->setNodeName("IfStmt");
                                     }
    ;

WhileStmt
    : WHILE '(' Expr ')' Stmt { $$=new WhileStmt($3, $5); 
                                $$->addChild(new Node("WHILE"));
                                $$->addChild(new Node("("));
                                $$->addChild($3);
                                $$->addChild(new Node(")"));
                                $$->addChild($5);
                                $$->setNodeName("WhileStmt");
                              }
    ;

ForStmt
    : FOR '(' ';' Expr ';' ')' Stmt { $$=new ForStmt(new EmptyExpr(), $4, new EmptyExpr(), $7); 
                                      $$->addChild(new Node("FOR"));
                                      $$->addChild(new Node("("));
                                      $$->addChild(new Node(";"));
                                      $$->addChild($4);
                                      $$->addChild(new Node(";"));
                                      $$->addChild(new Node(")"));
                                      $$->addChild($7);
                                      $$->setNodeName("ForStmt");
                                    }
    | FOR '(' Expr ';' Expr ';' ')' Stmt { $$=new ForStmt($3, $5, new EmptyExpr(), $8); $$->addChild(new Node("FOR"));
                                      $$->addChild(new Node("("));
                                      $$->addChild($3);
                                      $$->addChild(new Node(";"));
                                      $$->addChild($5);
                                      $$->addChild(new Node(";"));
                                      $$->addChild(new Node(")"));
                                      $$->addChild($8);
                                      $$->setNodeName("ForStmt");}
    | FOR '(' ';' Expr ';' Expr ')' Stmt { $$=new ForStmt(new EmptyExpr(), $4, $6, $8); $$->addChild(new Node("FOR"));
                                      $$->addChild(new Node("("));
                                      $$->addChild(new Node(";"));
                                      $$->addChild($4);
                                      $$->addChild(new Node(";"));
                                      $$->addChild($6);
                                      $$->addChild(new Node(")"));
                                      $$->addChild($8);
                                      $$->setNodeName("ForStmt");}
    | FOR '(' Expr ';' Expr ';' Expr ')' Stmt { $$=new ForStmt($3, $5, $7, $9); $$->addChild(new Node("FOR"));
                                      $$->addChild(new Node("("));
                                      $$->addChild($3);
                                      $$->addChild(new Node(";"));
                                      $$->addChild($5);
                                      $$->addChild(new Node(";"));
                                      $$->addChild($7);
                                      $$->addChild(new Node(")"));
                                      $$->addChild($9);
                                      $$->setNodeName("ForStmt");}
    ;

ReturnStmt
    : RETURN ';' { $$=new ReturnStmt(@$, new EmptyExpr()); 
                   $$->addChild(new Node("RETURN"));
                   $$->addChild(new Node(";"));
                   $$->setNodeName("ReturnStmt");
                 }
    | RETURN Expr ';' { $$=new ReturnStmt(@2, $2); 
                        $$->addChild(new Node("RETURN"));
                        $$->addChild($2);
                        $$->addChild(new Node(";"));
                        $$->setNodeName("ReturnStmt");
                      }
    ;

BreakStmt
    : BREAK ';' { $$=new BreakStmt(@1); 
                  $$->addChild(new Node("BREAK"));
                  $$->addChild(new Node(";"));
                  $$->setNodeName("BreakStmt");
                }
    ;

PrintStmt
    : PRINT '(' ExprList ')' ';' { $$=new PrintStmt($3); 
                                   $$->addChild(new Node("PRINT"));
                                   $$->addChild(new Node("("));
                                   if($3->NumElements() > 0) {
                                       for(int i = 0; i < $3->NumElements()-1; i++) {
                                           $$->addChild($3->Nth(i));
                                           $$->addChild(new Node(","));
                                       } 
                                       $$->addChild($3->Nth($3->NumElements()-1));
                                   }
                                   $$->addChild(new Node(")"));
                                   $$->addChild(new Node(";"));
                                   $$->setNodeName("PrintStmt");
                                 }
    ;

Expr
    : LValue '=' Expr { $$=new AssignExpr($1, new Operator(@2, "="), $3); 
                        // $$->addChild($1);
                        // $$->addChild(new Node("="));
                        // $$->addChild($3);
                        // $$->setNodeName("Expr");                        
                      }
    | Constant { $$=$1; }
    | LValue { $$=$1; }
    | THIS { $$=new This(@1); $$->addChild(new Node("THIS"));
                 $$->setNodeName("Expr");}
    | Call { $$=$1; }
    | '(' Expr ')' { $$=$2; }
    | Expr '+' Expr { $$=new ArithmeticExpr($1, new Operator(@2, "+"), $3); 
                      $$->addChild($1); 
                      $$->addChild(new Node("+")); 
                      $$->addChild($3); 
                      $$->setNodeName("Expr"); }
    | Expr '-' Expr { $$=new ArithmeticExpr($1, new Operator(@2, "-"), $3); 
                      $$->addChild($1); 
                      $$->addChild(new Node("-")); 
                      $$->addChild($3); 
                      $$->setNodeName("Expr");}
    | Expr '*' Expr { $$=new ArithmeticExpr($1, new Operator(@2, "*"), $3); $$->addChild($1); 
                      $$->addChild(new Node("*")); 
                      $$->addChild($3); 
                      $$->setNodeName("Expr");}
    | Expr '/' Expr { $$=new ArithmeticExpr($1, new Operator(@2, "/"), $3); $$->addChild($1); 
                      $$->addChild(new Node("/")); 
                      $$->addChild($3); 
                      $$->setNodeName("Expr");}
    | Expr '%' Expr { $$=new ArithmeticExpr($1, new Operator(@2, "%"), $3); $$->addChild($1); 
                      $$->addChild(new Node("%")); 
                      $$->addChild($3); 
                      $$->setNodeName("Expr");}
    | '-' Expr %prec UMINUS { $$=new ArithmeticExpr(new Operator(@1, "-"), $2);
                      $$->addChild(new Node("-")); 
                      $$->addChild($2); 
                      $$->setNodeName("Expr");}
    | Expr '<' Expr { $$=new RelationalExpr($1, new Operator(@2, "<"), $3); $$->addChild($1); 
                      $$->addChild(new Node("<")); 
                      $$->addChild($3); 
                      $$->setNodeName("Expr");}
    | Expr LE_OP Expr { $$=new RelationalExpr($1, new Operator(@2, "<="), $3); $$->addChild($1); 
                      $$->addChild(new Node("<=")); 
                      $$->addChild($3); 
                      $$->setNodeName("Expr");}
    | Expr '>' Expr { $$=new RelationalExpr($1, new Operator(@2, ">"), $3); $$->addChild($1); 
                      $$->addChild(new Node(">")); 
                      $$->addChild($3); 
                      $$->setNodeName("Expr");}
    | Expr GE_OP Expr { $$=new RelationalExpr($1, new Operator(@2, ">="), $3); $$->addChild($1); 
                      $$->addChild(new Node(">=")); 
                      $$->addChild($3); 
                      $$->setNodeName("Expr");}
    | Expr EQ_OP Expr { $$=new EqualityExpr($1, new Operator(@2, "=="), $3); $$->addChild($1); 
                      $$->addChild(new Node("==")); 
                      $$->addChild($3); 
                      $$->setNodeName("Expr");}
    | Expr NE_OP Expr { $$=new EqualityExpr($1, new Operator(@2, "!="), $3); $$->addChild($1); 
                      $$->addChild(new Node("!=")); 
                      $$->addChild($3); 
                      $$->setNodeName("Expr");}
    | Expr AND_OP Expr { $$=new LogicalExpr($1, new Operator(@2, "&&"), $3); $$->addChild($1); 
                      $$->addChild(new Node("&&")); 
                      $$->addChild($3); 
                      $$->setNodeName("Expr");}
    | Expr OR_OP Expr { $$=new LogicalExpr($1, new Operator(@2, "||"), $3); $$->addChild($1); 
                      $$->addChild(new Node("||")); 
                      $$->addChild($3); 
                      $$->setNodeName("Expr");}
    | NOT_OP Expr { $$=new LogicalExpr(new Operator(@1, "!"), $2);
                      $$->addChild(new Node("!")); 
                      $$->addChild($2); 
                      $$->setNodeName("Expr");}
    | READINTEGER '(' ')' { $$=new ReadIntegerExpr(@$);
                      $$->addChild(new Node("READINTEGER")); 
                      $$->addChild(new Node("(")); 
                      $$->addChild(new Node(")"));
                      $$->setNodeName("Expr");}
    | READLINE '(' ')' { $$=new ReadLineExpr(@$); $$->addChild(new Node("READLINE")); 
                      $$->addChild(new Node("(")); 
                      $$->addChild(new Node(")"));
                      $$->setNodeName("Expr"); }
    | NEW Identifier { $$=new NewExpr(@$, new NamedType($2)); $$->addChild(new Node("NEW")); 
                      $$->addChild($2);
                      $$->setNodeName("Expr");}
    | NEWARRAY '(' Expr ',' Type ')' { $$=new NewArrayExpr(@$, $3, $5); 
                      $$->addChild(new Node("NEWARRAY")); 
                      $$->addChild(new Node("(")); 
                      $$->addChild($3);
                      $$->addChild(new Node(","));
                      $$->addChild($5);                      
                      $$->addChild(new Node(")"));
                      $$->setNodeName("Expr"); }
    ;

Call
    : Identifier '(' Actuals ')' { $$=new Call(@$, NULL, $1, $3); 
                                   $$->addChild($1);
                                   $$->addChild(new Node("("));
                                   if($3->NumElements() > 0) {
                                        for(int i = 0; i < $3->NumElements()-1; i++) {
                                            $$->addChild($3->Nth(i));
                                            $$->addChild(new Node(","));
                                        } 
                                        $$->addChild($3->Nth($3->NumElements()-1));
                                    }
                                   $$->addChild(new Node(")"));
                                   $$->setNodeName("Call");
                                 }
    | Expr '.' Identifier '(' Actuals ')' { $$=new Call(@$, $1, $3, $5); 
                                            $$->addChild($1);
                                            $$->addChild(new Node("."));
                                            $$->addChild($3);
                                            $$->addChild(new Node("("));
                                            if($5->NumElements() > 0) {
                                                for(int i = 0; i < $5->NumElements()-1; i++) {
                                                    $$->addChild($5->Nth(i));
                                                    $$->addChild(new Node(","));
                                                } 
                                                $$->addChild($5->Nth($5->NumElements()-1));
                                            }
                                            $$->addChild(new Node(")"));
                                            $$->setNodeName("Call");
                                          }
    ;

Actuals
    : /* Empty */ { $$=new List<Expr*>; }
    | ExprList { $$=$1; }
    ;

Constant
    : INTCONSTANT { $$=new IntConstant(@1, $1); 
                    $$->addChild(new Node("INTCONSTANT"));
                    $$->setNodeName("Constant");                    
                  }
    | DOUBLECONSTANT { $$=new DoubleConstant(@1, $1); $$->addChild(new Node("DOUBLECONSTANT"));
                    $$->setNodeName("Constant");}
    | BOOLCONSTANT { $$=new BoolConstant(@1, $1); $$->addChild(new Node("BOOLCONSTANT"));
                    $$->setNodeName("Constant");}
    | STRING_LITERAL { $$=new StringConstant(@1, $1); $$->addChild(new Node("STRING_LITERAL"));
                    $$->setNodeName("Constant");}
    | NULLCONSTANT { $$=new NullConstant(@1); $$->addChild(new Node("NULLCONSTANT"));   
                    $$->setNodeName("Constant");}
    ;

%%

/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparser(). It is designed 
 * to give you an opportunity to do anything that must be done to initialize 
 * the parser (set global variables, configure starting state, etc.). One 
 * thing it already does for you is assign the value of the global variable 
 * yydebug that controls whether yacc prints debugging information about 
 * parser actions (shift/reduce) and contents of state stack during parser. 
 * If set to false, no information is printed. Setting it to true will give 
 * you a running trail that might be helpful when debugging your parser. 
 * Please be sure the variable is set to false when submitting your final 
 * version.
 */
void InitParser() {
    PrintDebug("parser", "Initializing parser");
    yydebug = false;
}