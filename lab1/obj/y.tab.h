/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_OBJ_Y_TAB_H_INCLUDED
# define YY_YY_OBJ_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    BOOL = 259,
    STRING = 260,
    VOID = 261,
    NULLCONSTANT = 262,
    BREAK = 263,
    CLASS = 264,
    ELSE = 265,
    EXTENDS = 266,
    FOR = 267,
    IF = 268,
    NEW = 269,
    RETURN = 270,
    THIS = 271,
    WHILE = 272,
    STATIC = 273,
    PRINT = 274,
    READINTEGER = 275,
    READLINE = 276,
    INSTANCEOF = 277,
    LE_OP = 278,
    GE_OP = 279,
    EQ_OP = 280,
    NE_OP = 281,
    AND_OP = 282,
    OR_OP = 283,
    NOT_OP = 284,
    IDENTIFIER = 285,
    STRING_LITERAL = 286,
    INTCONSTANT = 287,
    DOUBLECONSTANT = 288,
    BOOLCONSTANT = 289,
    UMINUS = 290,
    NOELSE = 291
  };
#endif
/* Tokens.  */
#define INT 258
#define BOOL 259
#define STRING 260
#define VOID 261
#define NULLCONSTANT 262
#define BREAK 263
#define CLASS 264
#define ELSE 265
#define EXTENDS 266
#define FOR 267
#define IF 268
#define NEW 269
#define RETURN 270
#define THIS 271
#define WHILE 272
#define STATIC 273
#define PRINT 274
#define READINTEGER 275
#define READLINE 276
#define INSTANCEOF 277
#define LE_OP 278
#define GE_OP 279
#define EQ_OP 280
#define NE_OP 281
#define AND_OP 282
#define OR_OP 283
#define NOT_OP 284
#define IDENTIFIER 285
#define STRING_LITERAL 286
#define INTCONSTANT 287
#define DOUBLECONSTANT 288
#define BOOLCONSTANT 289
#define UMINUS 290
#define NOELSE 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "src/parser.y" /* yacc.c:1909  */

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

#line 162 "obj/y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_OBJ_Y_TAB_H_INCLUDED  */
