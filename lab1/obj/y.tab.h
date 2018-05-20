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
    DOUBLE = 259,
    BOOL = 260,
    STRING = 261,
    VOID = 262,
    NULLCONSTANT = 263,
    BREAK = 264,
    CLASS = 265,
    ELSE = 266,
    EXTENDS = 267,
    FOR = 268,
    IF = 269,
    NEW = 270,
    RETURN = 271,
    THIS = 272,
    WHILE = 273,
    STATIC = 274,
    PRINT = 275,
    READINTEGER = 276,
    READLINE = 277,
    INSTANCEOF = 278,
    NEWARRAY = 279,
    IMPLEMENTS = 280,
    INTERFACE = 281,
    LE_OP = 282,
    GE_OP = 283,
    EQ_OP = 284,
    NE_OP = 285,
    AND_OP = 286,
    OR_OP = 287,
    NOT_OP = 288,
    IDENTIFIER = 289,
    STRING_LITERAL = 290,
    INTCONSTANT = 291,
    DOUBLECONSTANT = 292,
    BOOLCONSTANT = 293,
    UMINUS = 294,
    NOELSE = 295
  };
#endif
/* Tokens.  */
#define INT 258
#define DOUBLE 259
#define BOOL 260
#define STRING 261
#define VOID 262
#define NULLCONSTANT 263
#define BREAK 264
#define CLASS 265
#define ELSE 266
#define EXTENDS 267
#define FOR 268
#define IF 269
#define NEW 270
#define RETURN 271
#define THIS 272
#define WHILE 273
#define STATIC 274
#define PRINT 275
#define READINTEGER 276
#define READLINE 277
#define INSTANCEOF 278
#define NEWARRAY 279
#define IMPLEMENTS 280
#define INTERFACE 281
#define LE_OP 282
#define GE_OP 283
#define EQ_OP 284
#define NE_OP 285
#define AND_OP 286
#define OR_OP 287
#define NOT_OP 288
#define IDENTIFIER 289
#define STRING_LITERAL 290
#define INTCONSTANT 291
#define DOUBLECONSTANT 292
#define BOOLCONSTANT 293
#define UMINUS 294
#define NOELSE 295

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

#line 170 "obj/y.tab.h" /* yacc.c:1909  */
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
