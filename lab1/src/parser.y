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
                    if(ReportError::NumErrors()==0)
                        program->Check();
                    if(ReportError::NumErrors()==0)
                        program->Emit();
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
    : INT { $$=Type::intType; }
    | DOUBLE { $$=Type::doubleType; }
    | BOOL { $$=Type::boolType; }
    | STRING { $$=Type::stringType; }
    | Identifier { $$=new NamedType($1); }
    | Type '[' ']' { $$=new ArrayType(@1, $1); }
    ;

Identifier
    : IDENTIFIER { $$=new Identifier(@1, $1); }
    
Formals
    : /* Empty */ { $$=new List<VarDecl*>; }
    | VariableList { $$=$1; }
    ;

FunctionDecl
    : Type Identifier '(' Formals ')' StmtBlock { $$=new FnDecl($2, $1, $4); $$->SetFunctionBody($6); }
    | VOID Identifier '(' Formals ')' StmtBlock { $$=new FnDecl($2, Type::voidType, $4); $$->SetFunctionBody($6); }
    ;

ClassDecl
    : CLASS Identifier ExtendsClause ImplementsClause '{' FieldList '}' { $$=new ClassDecl($2, $3, $4, $6); }
    ;

ExtendsClause
    : /* Empty */ { $$=NULL; }
    | EXTENDS Identifier { $$=new NamedType($2); }
    ;
ImplementsClause
    : /* Empty */ { $$=new List<NamedType*>; }
    | IMPLEMENTS InterfaceList { $$=$2; }

InterfaceList
    : Identifier { ($$=new List<NamedType*>)->Append(new NamedType($1)); }
    | InterfaceList ',' Identifier { ($$=$1)->Append(new NamedType($3)); }
    
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

Prototype
    : Type Identifier '(' Formals ')' ';' { $$=new FnDecl($2, $1, $4); }
    | VOID Identifier '(' Formals ')' ';' { $$=new FnDecl($2, NULL, $4); }

StmtBlock
    : '{' VariableDeclList StmtList '}' { $$=new StmtBlock($2, $3); }
    ;

VariableDeclList
    : /* Empty */ { $$=new List<VarDecl*>; }
    | VariableDeclList VariableDecl { ($$=$1)->Append($2); }

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
    | StmtBlock { $$=$1; }
    ;

ExprList
    : Expr { ($$=new List<Expr*>)->Append($1); }
    | ExprList ',' Expr { ($$=$1)->Append($3); }
    ;

IfStmt
    : IF '(' Expr ')' Stmt %prec NOELSE { $$=new IfStmt($3, $5, NULL); }
    | IF '(' Expr ')' Stmt ELSE Stmt { $$=new IfStmt($3, $5, $7); }
    ;

WhileStmt
    : WHILE '(' Expr ')' Stmt { $$=new WhileStmt($3, $5); }
    ;

ForStmt
    : FOR '(' ';' Expr ';' ')' Stmt { $$=new ForStmt(new EmptyExpr(), $4, new EmptyExpr(), $7); }
    | FOR '(' Expr ';' Expr ';' ')' Stmt { $$=new ForStmt($3, $5, new EmptyExpr(), $8); }
    | FOR '(' ';' Expr ';' Expr ')' Stmt { $$=new ForStmt(new EmptyExpr(), $4, $6, $8); }
    | FOR '(' Expr ';' Expr ';' Expr ')' Stmt { $$=new ForStmt($3, $5, $7, $9); }
    ;

ReturnStmt
    : RETURN ';' { $$=new ReturnStmt(@$, new EmptyExpr()); }
    | RETURN Expr ';' { $$=new ReturnStmt(@2, $2); }
    ;

BreakStmt
    : BREAK ';' { $$=new BreakStmt(@1); }
    ;

PrintStmt
    : PRINT '(' ExprList ')' ';' { $$=new PrintStmt($3); }
    ;

Expr
    : LValue '=' Expr { $$=new AssignExpr($1, new Operator(@2, "="), $3); }
    | Constant { $$=$1; }
    | LValue { $$=$1; }
    | THIS { $$=new This(@1); }
    | Call { $$=$1; }
    | '(' Expr ')' { $$=$2; }
    | Expr '+' Expr { $$=new ArithmeticExpr($1, new Operator(@2, "+"), $3); }
    | Expr '-' Expr { $$=new ArithmeticExpr($1, new Operator(@2, "-"), $3); }
    | Expr '*' Expr { $$=new ArithmeticExpr($1, new Operator(@2, "*"), $3); }
    | Expr '/' Expr { $$=new ArithmeticExpr($1, new Operator(@2, "/"), $3); }
    | Expr '%' Expr { $$=new ArithmeticExpr($1, new Operator(@2, "%"), $3); }
    | '-' Expr %prec UMINUS { $$=new ArithmeticExpr(new Operator(@1, "-"), $2); }
    | Expr '<' Expr { $$=new RelationalExpr($1, new Operator(@2, "<"), $3); }
    | Expr LE_OP Expr { $$=new RelationalExpr($1, new Operator(@2, "<="), $3); }
    | Expr '>' Expr { $$=new RelationalExpr($1, new Operator(@2, ">"), $3); }
    | Expr GE_OP Expr { $$=new RelationalExpr($1, new Operator(@2, ">="), $3); }
    | Expr EQ_OP Expr { $$=new EqualityExpr($1, new Operator(@2, "=="), $3); }
    | Expr NE_OP Expr { $$=new EqualityExpr($1, new Operator(@2, "!="), $3); }
    | Expr AND_OP Expr { $$=new LogicalExpr($1, new Operator(@2, "&&"), $3); }
    | Expr OR_OP Expr { $$=new LogicalExpr($1, new Operator(@2, "||"), $3); }
    | NOT_OP Expr { $$=new LogicalExpr(new Operator(@1, "!"), $2); }
    | READINTEGER '(' ')' { $$=new ReadIntegerExpr(@$); }
    | READLINE '(' ')' { $$=new ReadLineExpr(@$); }
    | NEW Identifier { $$=new NewExpr(@$, new NamedType($2)); }
    | NEWARRAY '(' Expr ',' Type ')' { $$=new NewArrayExpr(@$, $3, $5); }
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
    : INTCONSTANT { $$=new IntConstant(@1, $1); }
    | DOUBLECONSTANT { $$=new DoubleConstant(@1, $1); }
    | BOOLCONSTANT { $$=new BoolConstant(@1, $1); }
    | STRING_LITERAL { $$=new StringConstant(@1, $1); }
    | NULLCONSTANT { $$=new NullConstant(@1); }
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
    yydebug = true;
}