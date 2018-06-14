/* File: parser.y
 * --------------
 * Bison input file to generate the parser for the compiler.
 *
 * pp4: add parser rules and tree construction from your past projects. 
 *      You should not need to make any significant changes in the parser itself. 
 *      After parsing completes, if no errors were found, the parser calls
 *      program->Emit() to kick off the code generation pass. The
 *      interesting work happens during the tree traversal.
 */

%{

#include "scanner.h" // for yylex
#include "parser.h"
#include "errors.h"

void yyerror(const char *msg); // standard error-handling routine

%}

%union {
    int integerConstant;
    bool boolConstant;
    char *stringConstant;
    double doubleConstant;
    char identifier[MaxIdentLen+1]; // +1 for terminating null
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
    List<CaseStmt*> *caseStmts;
    CaseStmt *caseStmt;
    DefaultStmt *defaultStmt;
}


/* Tokens
 * ------
 * Here we tell yacc about all the token types that we are using.
 * Bison will assign unique numbers to these and export the #define
 * in the generated y.tab.h header file.
 */
%token   T_Void T_Bool T_Int T_Double T_String T_Class 
%token   T_LessEqual T_GreaterEqual T_Equal T_NotEqual T_Dims T_Increment T_Decrement
%token   T_And T_Or T_Null T_Extends T_This T_Interface T_Implements
%token   T_While T_For T_If T_Else T_Return T_Break T_Switch T_Case T_Default
%token   T_New T_NewArray T_Print T_ReadInteger T_ReadLine T_Static T_InstanceOf

%token   <identifier> T_Identifier
%token   <stringConstant> T_StringConstant 
%token   <integerConstant> T_IntConstant
%token   <doubleConstant> T_DoubleConstant
%token   <boolConstant> T_BoolConstant

%token UMINUS
%token NOELSE

/* Non-terminal types
 * ------------------
 * In order for yacc to assign/access the correct field of $$, $1, we
 * must to declare which field is appropriate for the non-terminal.
 * As an example, this first type declaration establishes that the DeclList
 * non-terminal uses the field named "declList" in the yylval union. This
 * means that when we are setting $$ for a reduction for DeclList ore reading
 * $n which corresponds to a DeclList nonterminal we are accessing the field
 * of the union named "declList" which is of type List<Decl*>.
 * pp2: You'll need to add many of these of your own.
 */
%type <declList>  DeclList 
%type <decl>      Decl
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
%type <switchStmt> SwitchStmt
%type <caseStmts> CaseStmts
%type <caseStmt> CaseStmt
%type <defaultStmt> DefaultStmt

/* Precedence Assignment */
%nonassoc NOELSE
%nonassoc T_Else

%nonassoc '='
%left T_Or
%left T_And
%nonassoc T_Equal T_NotEqual
%nonassoc '<' T_LessEqual '>' T_GreaterEqual
%left '+' '-' 
%left '*' '/' '%'
%nonassoc '!' UMINUS T_Increment T_Decrement
%nonassoc '[' '.'
%left T_Dims


%start Program

%%
/* Rules
 * -----
 * All productions and actions should be placed between the start and stop
 * %% markers which delimit the Rules section.
	 
 */
Program   :    DeclList             { 
                                        @1; 
                                        /* pp2: The @1 is needed to convince 
                                        * yacc to set up yylloc. You can remove 
                                        * it once you have other uses of @n*/
                                        Program *program = new Program($1);
                                        // if no errors, advance to next phase
                                        if (ReportError::NumErrors() == 0) 
                                            program->Check();  
                                        if (ReportError::NumErrors() == 0) 
                                            program->Emit();                                        
                                    }
          ;

DeclList  :    DeclList Decl        { ($$=$1)->Append($2); }
          |    Decl                 { ($$ = new List<Decl*>)->Append($1); }
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
    : Type Identifier { $$=new VarDecl($2, $1); }
    ;

VariableList
    : Variable { ($$=new List<VarDecl*>)->Append($1); }
    | VariableList ',' Variable { ($$=$1)->Append($3); }
    ;

LValue
    : Identifier { $$=new FieldAccess(NULL, $1); }
    | Expr '.' Identifier { $$=new FieldAccess($1, $3); }
    | Expr '[' Expr ']' { $$=new ArrayAccess(@$, $1, $3); }
    ;
    
Type
    : T_Int { $$=Type::intType; }
    | T_Double { $$=Type::doubleType; }
    | T_Bool { $$=Type::boolType; }
    | T_String { $$=Type::stringType; }
    | Identifier { $$=new NamedType($1); }
    | Type T_Dims { $$=new ArrayType(@1, $1); }
    ;

Identifier
    : T_Identifier { $$=new Identifier(@1, $1); }
    ;
    
Formals
    : /* Empty */ { $$=new List<VarDecl*>; }
    | VariableList { $$=$1; }
    ;

FunctionDecl
    : Type Identifier '(' Formals ')' StmtBlock { $$=new FnDecl($2, $1, $4); $$->SetFunctionBody($6); }
    | T_Void Identifier '(' Formals ')' StmtBlock { $$=new FnDecl($2, Type::voidType, $4); $$->SetFunctionBody($6); }
    ;

ClassDecl
    : T_Class Identifier ExtendsClause ImplementsClause '{' FieldList '}' {   $$=new ClassDecl($2, $3, $4, $6); }
    ;

ExtendsClause
    : /* Empty */ { $$=NULL; }
    | T_Extends Identifier { $$=new NamedType($2); }
    ;

ImplementsClause
    : /* Empty */   { $$=new List<NamedType*>; }
    | T_Implements InterfaceList { $$=$2;  }
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
    : T_Interface Identifier '{' PrototypeList '}' { $$=new InterfaceDecl($2, $4); }
    ;

PrototypeList
    : /* Empty */ { $$=new List<Decl*>; }
    | PrototypeList Prototype { ($$=$1)->Append($2); }
    ;

Prototype
    : Type Identifier '(' Formals ')' ';' { $$=new FnDecl($2, $1, $4);  }
    | T_Void Identifier '(' Formals ')' ';' { $$=new FnDecl($2, Type::voidType, $4); }
    ;

StmtBlock
    : '{' VariableDeclList StmtList '}' { $$=new StmtBlock($2, $3); }
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
    : ';' { $$=new EmptyExpr(); }
    | Expr ';' { $$=$1; }
    | IfStmt { $$=$1; }
    | WhileStmt { $$=$1; }
    | ForStmt { $$=$1; }
    | BreakStmt { $$=$1; }
    | ReturnStmt { $$=$1; }
    | PrintStmt { $$=$1; }
    | SwitchStmt { $$=$1; }
    | StmtBlock { $$=$1; }
    ;

ExprList
    : Expr { ($$=new List<Expr*>)->Append($1); }
    | ExprList ',' Expr { ($$=$1)->Append($3); }
    ;

IfStmt
    : T_If '(' Expr ')' Stmt %prec NOELSE { $$=new IfStmt($3, $5, NULL); }
    | T_If '(' Expr ')' Stmt T_Else Stmt { $$=new IfStmt($3, $5, $7); }
    ;

WhileStmt
    : T_While '(' Expr ')' Stmt { $$=new WhileStmt($3, $5); }
    ;

ForStmt
    : T_For '(' ';' Expr ';' ')' Stmt { $$=new ForStmt(new EmptyExpr(), $4, new EmptyExpr(), $7); }
    | T_For '(' Expr ';' Expr ';' ')' Stmt { $$=new ForStmt($3, $5, new EmptyExpr(), $8); }
    | T_For '(' ';' Expr ';' Expr ')' Stmt { $$=new ForStmt(new EmptyExpr(), $4, $6, $8); }
    | T_For '(' Expr ';' Expr ';' Expr ')' Stmt { $$=new ForStmt($3, $5, $7, $9); }
    ;

ReturnStmt
    : T_Return ';' { $$=new ReturnStmt(@$, new EmptyExpr()); }
    | T_Return Expr ';' { $$=new ReturnStmt(@2, $2); }
    ;

BreakStmt
    : T_Break ';' { $$=new BreakStmt(@1); }
    ;

PrintStmt
    : T_Print '(' ExprList ')' ';' { $$=new PrintStmt($3); }
    ;

SwitchStmt
    : T_Switch '(' Expr ')' '{' CaseStmts '}' { $$=new SwitchStmt($3, $6, NULL); }
    | T_Switch '(' Expr ')' '{' CaseStmts DefaultStmt '}' { $$=new SwitchStmt($3, $6, $7); }
    ;

CaseStmts
    : CaseStmt { ($$=new List<CaseStmt*>)->Append($1); }
    | CaseStmts CaseStmt { ($$=$1)->Append($2); }
    ;

CaseStmt
    : T_Case T_IntConstant ':' StmtList { $$=new CaseStmt(new IntConstant(@2, $2), $4); }    
    ;

DefaultStmt
    : T_Default ':' StmtList { $$=new DefaultStmt($3); }
    ;

Expr
    : LValue '=' Expr { $$=new AssignExpr($1, new Operator(@2, "="), $3); }
    | Constant { $$=$1; }
    | LValue { $$=$1; }
    | LValue T_Increment { $$=new PostfixExpr($1, new Operator(@2, "++")); }
    | LValue T_Decrement { $$=new PostfixExpr($1, new Operator(@2, "--")); }
    | T_This { $$=new This(@1); }
    | Call { $$=$1; }
    | '(' Expr ')' { $$=$2; }
    | Expr '+' Expr { $$=new ArithmeticExpr($1, new Operator(@2, "+"), $3); }
    | Expr '-' Expr { $$=new ArithmeticExpr($1, new Operator(@2, "-"), $3); }
    | Expr '*' Expr { $$=new ArithmeticExpr($1, new Operator(@2, "*"), $3); }
    | Expr '/' Expr { $$=new ArithmeticExpr($1, new Operator(@2, "/"), $3); }
    | Expr '%' Expr { $$=new ArithmeticExpr($1, new Operator(@2, "%"), $3); }
    | '-' Expr %prec UMINUS { $$=new ArithmeticExpr(new Operator(@1, "-"), $2); }
    | Expr '<' Expr { $$=new RelationalExpr($1, new Operator(@2, "<"), $3); }
    | Expr T_LessEqual Expr { $$=new RelationalExpr($1, new Operator(@2, "<="), $3); }
    | Expr '>' Expr { $$=new RelationalExpr($1, new Operator(@2, ">"), $3); }
    | Expr T_GreaterEqual Expr { $$=new RelationalExpr($1, new Operator(@2, ">="), $3); }
    | Expr T_Equal Expr { $$=new EqualityExpr($1, new Operator(@2, "=="), $3); }
    | Expr T_NotEqual Expr { $$=new EqualityExpr($1, new Operator(@2, "!="), $3); }
    | Expr T_And Expr { $$=new LogicalExpr($1, new Operator(@2, "&&"), $3); }
    | Expr T_Or Expr { $$=new LogicalExpr($1, new Operator(@2, "||"), $3); }
    | '!' Expr { $$=new LogicalExpr(new Operator(@1, "!"), $2); }
    | T_ReadInteger '(' ')' { $$=new ReadIntegerExpr(@$); }
    | T_ReadLine '(' ')' { $$=new ReadLineExpr(@$); }
    | T_New Identifier { $$=new NewExpr(@$, new NamedType($2)); }
    | T_NewArray '(' Expr ',' Type ')' { $$=new NewArrayExpr(@$, $3, $5); }
    ;

Call
    : Identifier '(' Actuals ')' { $$=new Call(@$, NULL, $1, $3); }
    | Expr '.' Identifier '(' Actuals ')' { $$=new Call(@$, $1, $3, $5); }
    ;

Actuals
    : /* Empty */ { $$=new List<Expr*>; }
    | ExprList { $$=$1; }
    ;

Constant
    : T_IntConstant { $$=new IntConstant(@1, $1); }
    | T_DoubleConstant { $$=new DoubleConstant(@1, $1); }
    | T_BoolConstant  {   $$=new BoolConstant(@1, $1); }
    | T_StringConstant    {   $$=new StringConstant(@1, $1); }
    | T_Null  {   $$=new NullConstant(@1); }
    ;

%%

/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */

/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparse().  It is designed
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
void InitParser()
{
   PrintDebug("parser", "Initializing parser");
//    yydebug = false;
   yydebug = IsDebugOn("parser");
}
