/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "src/parser.y" /* yacc.c:339  */

#include "scanner.h"
#include "parser.h"
#include "errors.h"

void yyerror(const char *msg);

FILE *parser_log;

#line 76 "obj/y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 25 "src/parser.y" /* yacc.c:355  */

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

#line 232 "obj/y.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 263 "obj/y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   792

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  207

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    48,     2,     2,
      55,    51,    46,    44,    53,    45,    50,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    52,
      42,    41,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   142,   142,   158,   159,   163,   164,   165,   166,   170,
     174,   182,   183,   187,   191,   197,   207,   210,   213,   216,
     219,   225,   234,   243,   244,   248,   263,   281,   303,   304,
     312,   313,   317,   318,   322,   323,   327,   328,   332,   345,
     346,   350,   365,   383,   397,   398,   402,   403,   407,   411,
     413,   414,   415,   416,   417,   418,   419,   423,   424,   428,
     436,   449,   460,   470,   479,   488,   501,   506,   515,   523,
     540,   546,   547,   548,   550,   551,   552,   557,   562,   566,
     570,   574,   578,   582,   586,   590,   594,   598,   602,   606,
     610,   614,   619,   623,   626,   637,   650,   668,   669,   673,
     681,   689,   697,   705
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "DOUBLE", "BOOL", "STRING",
  "VOID", "NULLCONSTANT", "BREAK", "CLASS", "ELSE", "EXTENDS", "FOR", "IF",
  "NEW", "RETURN", "THIS", "WHILE", "STATIC", "PRINT", "READINTEGER",
  "READLINE", "INSTANCEOF", "NEWARRAY", "IMPLEMENTS", "INTERFACE", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "NOT_OP", "IDENTIFIER",
  "STRING_LITERAL", "INTCONSTANT", "DOUBLECONSTANT", "BOOLCONSTANT",
  "UMINUS", "NOELSE", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'['", "'.'", "')'", "';'", "','", "']'", "'('", "'{'", "'}'",
  "$accept", "Program", "DeclList", "Decl", "VariableDecl", "Variable",
  "VariableList", "LValue", "Type", "Identifier", "Formals",
  "FunctionDecl", "ClassDecl", "ExtendsClause", "ImplementsClause",
  "InterfaceList", "FieldList", "Field", "InterfaceDecl", "PrototypeList",
  "Prototype", "StmtBlock", "VariableDeclList", "StmtList", "Stmt",
  "ExprList", "IfStmt", "WhileStmt", "ForStmt", "ReturnStmt", "BreakStmt",
  "PrintStmt", "Expr", "Call", "Actuals", "Constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    61,    60,    62,    43,    45,    42,    47,    37,    91,
      46,    41,    59,    44,    93,    40,   123,   125
};
# endif

#define YYPACT_NINF -48

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-48)))

#define YYTABLE_NINF -21

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-21)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     350,   -48,   -48,   -48,   -48,   -26,   -26,   -26,   -48,    13,
     350,   -48,   -48,   -32,     5,   -48,   -48,   -48,   -48,   -29,
      33,    -1,   -48,   -48,   -48,     6,    -2,   122,   -26,    34,
     -48,   -48,   122,   -48,     9,     5,    15,   -48,   -26,     7,
      12,    21,   122,   -48,    22,   -48,    26,   -48,   -26,   -48,
       5,   -48,    22,   -48,   -48,   -48,   -26,    18,    19,    27,
     -48,    99,   -48,   -48,   -48,   -48,   -48,   122,   122,   -48,
      29,    28,    31,   -26,   186,   -48,    32,    54,    55,    56,
      63,   314,   -48,   -48,   -48,   -48,   314,   -48,   314,   -48,
      81,   -25,   -48,    67,   150,   -48,   -48,   -48,   -48,   -48,
     -48,   421,   -48,   -48,    78,    79,   -48,   218,   314,   -48,
     -48,    76,   447,   314,   314,    89,    90,   314,   -47,   -47,
     551,   314,   314,   -48,   -48,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   -26,
     -48,    91,    93,   314,   473,   576,   -48,   601,   -20,   676,
     -48,   -48,   394,   -48,   676,    95,    98,   742,   742,   709,
     709,   718,   685,   742,   742,   129,   129,   -47,   -47,   -47,
     366,    97,   -48,   -48,   499,   314,   150,   150,   101,   314,
     122,   -48,   -48,   314,   250,   525,   139,   -48,   -48,   676,
     -15,   109,   150,   626,   282,   150,   -48,   -48,   -48,   150,
     150,   651,   -48,   -48,   -48,   150,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    17,    18,    19,     0,     0,     0,    22,     0,
       2,     4,     5,     0,     0,    20,     6,     7,     8,     0,
      28,     0,     1,     3,     9,     0,    10,    23,     0,    30,
      39,    21,    23,    11,    24,     0,     0,    29,     0,     0,
       0,     0,     0,    10,     0,    32,    31,    34,     0,    38,
       0,    40,     0,    12,    44,    26,     0,     0,     0,     0,
      25,    46,    33,    27,    36,    37,    35,    23,    23,   103,
       0,     0,     0,     0,     0,    73,     0,     0,     0,     0,
       0,     0,   102,    99,   100,   101,     0,    48,     0,    45,
      72,    13,    56,     0,    46,    50,    51,    52,    54,    53,
      55,     0,    74,    71,     0,     0,    68,     0,     0,    93,
      66,    13,     0,     0,     0,     0,     0,     0,    90,    81,
       0,     0,    97,    43,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,    67,     0,     0,    57,
      91,    92,     0,    75,    70,    98,     0,    83,    85,    86,
      87,    88,    89,    82,    84,    76,    77,    78,    79,    80,
       0,    14,    42,    41,     0,     0,     0,     0,     0,     0,
       0,    95,    15,    97,     0,     0,    59,    61,    69,    58,
       0,     0,     0,     0,     0,     0,    94,    96,    62,     0,
       0,     0,    60,    64,    63,     0,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -48,   -48,   -48,   151,   -14,   298,   -48,   -48,     1,     0,
      -3,   105,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -40,   -48,    75,   187,    59,   -48,   -48,   -48,   -48,
     -48,   -48,   -37,   -48,     8,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    34,    90,    35,   111,
      36,    16,    17,    29,    39,    46,    57,    66,    18,    40,
      51,    92,    61,    93,    94,   155,    95,    96,    97,    98,
      99,   100,   101,   102,   156,   103
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      15,    14,   138,   139,    55,    19,    20,    21,     8,   -20,
      15,    14,    60,    22,    26,     1,     2,     3,     4,    48,
      24,     1,     2,     3,     4,     5,    27,    15,    37,    41,
     122,   178,    15,   179,    25,    43,   196,   112,    45,     8,
      15,    50,    15,    64,   118,    28,     8,    89,    58,   119,
      59,   120,     8,    32,    25,    30,    62,    15,    14,    38,
      31,    91,    42,    47,   104,   105,    44,    15,    15,    49,
     144,   145,    52,   109,    67,    63,   147,   149,    54,    56,
     152,   106,    68,   107,   154,   149,   108,   113,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,     1,     2,     3,     4,   174,    69,    70,   114,
     115,   116,    71,    72,    73,    74,    75,    76,   117,    77,
      78,    79,   121,    80,   123,     1,     2,     3,     4,   141,
     142,   122,    81,     8,    82,    83,    84,    85,   185,   171,
     150,   151,   189,   172,    86,   173,   149,   193,   179,   181,
     195,    87,   183,   188,    88,    54,     8,   201,    69,    70,
     197,    23,    65,    71,    72,    73,    74,    75,    76,   124,
      77,    78,    79,   148,    80,   135,   136,   137,   138,   139,
      15,   190,     0,    81,     8,    82,    83,    84,    85,     0,
       0,   191,     0,     0,    69,    86,     0,     0,     0,     0,
       0,    73,    87,    75,     0,    88,    54,    78,    79,     0,
      80,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       8,    82,    83,    84,    85,     0,    69,     0,     0,     0,
       0,    86,     0,    73,     0,    75,     0,     0,   110,    78,
      79,    88,    80,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     8,    82,    83,    84,    85,     0,    69,     0,
       0,     0,     0,    86,     0,    73,     0,    75,     0,     0,
     143,    78,    79,    88,    80,     0,     0,     0,     0,     0,
       0,     0,     0,    81,     8,    82,    83,    84,    85,     0,
      69,     0,     0,     0,     0,    86,     0,    73,     0,    75,
       0,   192,     0,    78,    79,    88,    80,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     8,    82,    83,    84,
      85,     0,    69,     0,     0,    33,     0,    86,     0,    73,
      33,    75,     0,   200,     0,    78,    79,    88,    80,     0,
      53,     0,     0,     0,     0,     0,     0,    81,     8,    82,
      83,    84,    85,     1,     2,     3,     4,     5,     0,    86,
       6,     0,     0,   186,   187,    33,    33,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     7,     0,     0,   198,
       0,     0,   202,     0,     8,     0,   203,   204,     0,     0,
       0,     0,   206,   125,   126,   127,   128,   129,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,     0,     0,
     182,   125,   126,   127,   128,   129,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,   180,   125,   126,
     127,   128,   129,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,   140,   125,   126,   127,   128,   129,   130,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,   146,
     125,   126,   127,   128,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,     0,   175,   125,   126,   127,   128,
     129,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,   184,   125,   126,   127,   128,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,     0,   194,   125,   126,
     127,   128,   129,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   153,   125,   126,   127,   128,   129,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   176,   125,   126,
     127,   128,   129,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   177,   125,   126,   127,   128,   129,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   199,   125,   126,
     127,   128,   129,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   205,   125,   126,   127,   128,   129,   130,     0,
       0,     0,   125,   126,   127,   128,   129,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   125,   126,   -21,   -21,
       0,     0,     0,     0,     0,   125,   126,   127,   128,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   -21,
     -21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -21,   -21,   133,   134,   135,   136,
     137,   138,   139
};

static const yytype_int16 yycheck[] =
{
       0,     0,    49,    50,    44,     5,     6,     7,    34,    34,
      10,    10,    52,     0,    14,     3,     4,     5,     6,     7,
      52,     3,     4,     5,     6,     7,    55,    27,    28,    32,
      55,    51,    32,    53,    49,    35,    51,    74,    38,    34,
      40,    40,    42,    57,    81,    12,    34,    61,    48,    86,
      50,    88,    34,    55,    49,    56,    56,    57,    57,    25,
      54,    61,    53,    56,    67,    68,    51,    67,    68,    57,
     107,   108,    51,    73,    55,    57,   113,   114,    56,    53,
     117,    52,    55,    55,   121,   122,    55,    55,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,     3,     4,     5,     6,   143,     8,     9,    55,
      55,    55,    13,    14,    15,    16,    17,    18,    55,    20,
      21,    22,    41,    24,    57,     3,     4,     5,     6,    51,
      51,    55,    33,    34,    35,    36,    37,    38,   175,   139,
      51,    51,   179,    52,    45,    52,   183,   184,    53,    51,
      11,    52,    55,    52,    55,    56,    34,   194,     8,     9,
      51,    10,    57,    13,    14,    15,    16,    17,    18,    94,
      20,    21,    22,   114,    24,    46,    47,    48,    49,    50,
     180,   180,    -1,    33,    34,    35,    36,    37,    38,    -1,
      -1,   183,    -1,    -1,     8,    45,    -1,    -1,    -1,    -1,
      -1,    15,    52,    17,    -1,    55,    56,    21,    22,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    -1,     8,    -1,    -1,    -1,
      -1,    45,    -1,    15,    -1,    17,    -1,    -1,    52,    21,
      22,    55,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    -1,     8,    -1,
      -1,    -1,    -1,    45,    -1,    15,    -1,    17,    -1,    -1,
      52,    21,    22,    55,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    -1,
       8,    -1,    -1,    -1,    -1,    45,    -1,    15,    -1,    17,
      -1,    51,    -1,    21,    22,    55,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      38,    -1,     8,    -1,    -1,    27,    -1,    45,    -1,    15,
      32,    17,    -1,    51,    -1,    21,    22,    55,    24,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,     3,     4,     5,     6,     7,    -1,    45,
      10,    -1,    -1,   176,   177,    67,    68,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,   192,
      -1,    -1,   195,    -1,    34,    -1,   199,   200,    -1,    -1,
      -1,    -1,   205,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      54,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    53,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    52,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    10,    26,    34,    59,
      60,    61,    62,    63,    66,    67,    69,    70,    76,    67,
      67,    67,     0,    61,    52,    49,    67,    55,    12,    71,
      56,    54,    55,    63,    64,    66,    68,    67,    25,    72,
      77,    68,    53,    67,    51,    67,    73,    56,     7,    57,
      66,    78,    51,    63,    56,    79,    53,    74,    67,    67,
      79,    80,    67,    57,    62,    69,    75,    55,    55,     8,
       9,    13,    14,    15,    16,    17,    18,    20,    21,    22,
      24,    33,    35,    36,    37,    38,    45,    52,    55,    62,
      65,    67,    79,    81,    82,    84,    85,    86,    87,    88,
      89,    90,    91,    93,    68,    68,    52,    55,    55,    67,
      52,    67,    90,    55,    55,    55,    55,    55,    90,    90,
      90,    41,    55,    57,    81,    27,    28,    29,    30,    31,
      32,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      52,    51,    51,    52,    90,    90,    52,    90,    83,    90,
      51,    51,    90,    51,    90,    83,    92,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    67,    52,    52,    90,    52,    51,    51,    51,    53,
      53,    51,    54,    55,    52,    90,    82,    82,    52,    90,
      66,    92,    51,    90,    52,    11,    51,    51,    82,    51,
      51,    90,    82,    82,    82,    51,    82
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    61,    61,    62,
      63,    64,    64,    65,    65,    65,    66,    66,    66,    66,
      66,    66,    67,    68,    68,    69,    69,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    77,
      77,    78,    78,    79,    80,    80,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    84,
      84,    85,    86,    86,    86,    86,    87,    87,    88,    89,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    91,    91,    92,    92,    93,
      93,    93,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     2,
       2,     1,     3,     1,     3,     4,     1,     1,     1,     1,
       1,     3,     1,     0,     1,     6,     6,     7,     0,     2,
       0,     2,     1,     3,     0,     2,     1,     1,     5,     0,
       2,     6,     6,     4,     0,     2,     0,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     5,
       7,     5,     7,     8,     8,     9,     2,     3,     2,     5,
       3,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     2,     6,     4,     6,     0,     1,     1,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 142 "src/parser.y" /* yacc.c:1646  */
    {
                    Program *program = new Program((yyvsp[0].declList));
                    program->SetParent(NULL);
                    for(int i = 0; i < (yyvsp[0].declList)->NumElements(); i++) {
                        program->addChild((yyvsp[0].declList)->Nth(i));
                    }                    
                    program->setNodeName("Program");                    
                    if(ReportError::NumErrors()==0)
                        program->Check();                    
                    if(ReportError::NumErrors()==0)
                        program->Emit();                    
                    program->printTree(0);
               }
#line 1711 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 158 "src/parser.y" /* yacc.c:1646  */
    { ((yyval.declList)=(yyvsp[-1].declList))->Append((yyvsp[0].decl)); }
#line 1717 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 159 "src/parser.y" /* yacc.c:1646  */
    { ((yyval.declList)=new List<Decl*>)->Append((yyvsp[0].decl)); }
#line 1723 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 163 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl)=(yyvsp[0].varDecl); }
#line 1729 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 164 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl)=(yyvsp[0].fnDecl); }
#line 1735 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 165 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl)=(yyvsp[0].classDecl); }
#line 1741 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 166 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl)=(yyvsp[0].ifaceDecl); }
#line 1747 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 170 "src/parser.y" /* yacc.c:1646  */
    { (yyval.varDecl)=(yyvsp[-1].varDecl); }
#line 1753 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 174 "src/parser.y" /* yacc.c:1646  */
    { (yyval.varDecl)=new VarDecl((yyvsp[0].identObj), (yyvsp[-1].type)); 
                        (yyval.varDecl)->addChild((yyvsp[-1].type));    
                        (yyval.varDecl)->addChild((yyvsp[0].identObj));
                        (yyval.varDecl)->setNodeName("Variable");
                      }
#line 1763 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 182 "src/parser.y" /* yacc.c:1646  */
    { ((yyval.varDecls)=new List<VarDecl*>)->Append((yyvsp[0].varDecl)); }
#line 1769 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 183 "src/parser.y" /* yacc.c:1646  */
    { ((yyval.varDecls)=(yyvsp[-2].varDecls))->Append((yyvsp[0].varDecl)); }
#line 1775 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 187 "src/parser.y" /* yacc.c:1646  */
    { (yyval.lvalue)=new FieldAccess(NULL, (yyvsp[0].identObj)); 
                   (yyval.lvalue)->addChild((yyvsp[0].identObj));
                   (yyval.lvalue)->setNodeName("LValue");
                 }
#line 1784 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 191 "src/parser.y" /* yacc.c:1646  */
    { (yyval.lvalue)=new FieldAccess((yyvsp[-2].expr), (yyvsp[0].identObj)); 
                            (yyval.lvalue)->addChild((yyvsp[-2].expr));
                            (yyval.lvalue)->addChild(new Node("."));
                            (yyval.lvalue)->addChild((yyvsp[0].identObj));
                            (yyval.lvalue)->setNodeName("LValue");
                          }
#line 1795 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 197 "src/parser.y" /* yacc.c:1646  */
    { (yyval.lvalue)=new ArrayAccess((yyloc), (yyvsp[-3].expr), (yyvsp[-1].expr)); 
                          (yyval.lvalue)->addChild((yyvsp[-3].expr));
                          (yyval.lvalue)->addChild(new Node("["));
                          (yyval.lvalue)->addChild((yyvsp[-1].expr));
                          (yyval.lvalue)->addChild(new Node("]"));
                          (yyval.lvalue)->setNodeName("LValue");
                        }
#line 1807 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 207 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type)=Type::intType; 
            (yyval.type)->setNodeName("Type (int)");
          }
#line 1815 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 210 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type)=Type::doubleType; 
               (yyval.type)->setNodeName("Type (double)");
             }
#line 1823 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 213 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type)=Type::boolType; 
             (yyval.type)->setNodeName("Type (bool)");
           }
#line 1831 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 216 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type)=Type::stringType; 
               (yyval.type)->setNodeName("Type (string)");
             }
#line 1839 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 219 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type)=new NamedType((yyvsp[0].identObj)); 
                   char *node_name = new char[128];
                   sprintf(node_name, "Type (Class %s)", (yyvsp[0].identObj)->GetName());
                   (yyval.type)->setNodeName(node_name);
                   delete node_name;
                 }
#line 1850 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 225 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type)=new ArrayType((yylsp[-2]), (yyvsp[-2].type)); 
                     char *node_name = new char[128];
                     sprintf(node_name, "Type (%s array)", (yyvsp[-2].type)->GetName());
                     (yyval.type)->setNodeName(node_name);
                     delete node_name;
                   }
#line 1861 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 234 "src/parser.y" /* yacc.c:1646  */
    { (yyval.identObj)=new Identifier((yylsp[0]), (yyvsp[0].identifier));
                    char *node_name = new char[128];
                     sprintf(node_name, "Identifier (%s)", (yyvsp[0].identifier));
                     (yyval.identObj)->setNodeName(node_name);
                     delete node_name;
                 }
#line 1872 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 243 "src/parser.y" /* yacc.c:1646  */
    { (yyval.varDecls)=new List<VarDecl*>; }
#line 1878 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 244 "src/parser.y" /* yacc.c:1646  */
    { (yyval.varDecls)=(yyvsp[0].varDecls); }
#line 1884 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 248 "src/parser.y" /* yacc.c:1646  */
    { (yyval.fnDecl)=new FnDecl((yyvsp[-4].identObj), (yyvsp[-5].type), (yyvsp[-2].varDecls)); (yyval.fnDecl)->SetFunctionBody((yyvsp[0].stmtBlock)); 
                                                  (yyval.fnDecl)->addChild((yyvsp[-5].type));
                                                  (yyval.fnDecl)->addChild((yyvsp[-4].identObj));
                                                  (yyval.fnDecl)->addChild(new Node("("));
                                                  if((yyvsp[-2].varDecls)->NumElements() > 0) {
                                                      for(int i = 0; i < (yyvsp[-2].varDecls)->NumElements()-1; i++) {
                                                        (yyval.fnDecl)->addChild((yyvsp[-2].varDecls)->Nth(i));
                                                        (yyval.fnDecl)->addChild(new Node(","));
                                                    }
                                                    (yyval.fnDecl)->addChild((yyvsp[-2].varDecls)->Nth((yyvsp[-2].varDecls)->NumElements()-1));
                                                  }                                                  
                                                  (yyval.fnDecl)->addChild(new Node(")"));
                                                  (yyval.fnDecl)->addChild((yyvsp[0].stmtBlock));
                                                  (yyval.fnDecl)->setNodeName("FunctionDecl");
                                                }
#line 1904 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 263 "src/parser.y" /* yacc.c:1646  */
    { (yyval.fnDecl)=new FnDecl((yyvsp[-4].identObj), Type::voidType, (yyvsp[-2].varDecls)); (yyval.fnDecl)->SetFunctionBody((yyvsp[0].stmtBlock)); 
                                                  (yyval.fnDecl)->addChild(new Node("VOID"));
                                                  (yyval.fnDecl)->addChild((yyvsp[-4].identObj));
                                                  (yyval.fnDecl)->addChild(new Node("("));
                                                  if((yyvsp[-2].varDecls)->NumElements() > 0) {
                                                      for(int i = 0; i < (yyvsp[-2].varDecls)->NumElements()-1; i++) {
                                                        (yyval.fnDecl)->addChild((yyvsp[-2].varDecls)->Nth(i));
                                                        (yyval.fnDecl)->addChild(new Node(","));
                                                    }
                                                    (yyval.fnDecl)->addChild((yyvsp[-2].varDecls)->Nth((yyvsp[-2].varDecls)->NumElements()-1));
                                                  }                                            
                                                  (yyval.fnDecl)->addChild(new Node(")"));
                                                  (yyval.fnDecl)->addChild((yyvsp[0].stmtBlock));                                                  
                                                  (yyval.fnDecl)->setNodeName("FunctionDecl");
                                                }
#line 1924 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 281 "src/parser.y" /* yacc.c:1646  */
    {   (yyval.classDecl)=new ClassDecl((yyvsp[-5].identObj), (yyvsp[-4].extendsClause), (yyvsp[-3].nTList), (yyvsp[-1].declList));     
                                                                            (yyval.classDecl)->addChild(new Node("CLASS"));
                                                                            (yyval.classDecl)->addChild((yyvsp[-5].identObj));                                                                            
                                                                            if((yyvsp[-4].extendsClause)!=NULL) (yyval.classDecl)->addChild((yyvsp[-4].extendsClause));
                                                                            (yyval.classDecl)->addChild(new Node("IMPLEMENTS"));
                                                                            if((yyvsp[-3].nTList)->NumElements() > 0) {
                                                                                for(int i = 0; i < (yyvsp[-3].nTList)->NumElements()-1; i++) {
                                                                                    (yyval.classDecl)->addChild((yyvsp[-3].nTList)->Nth(i));
                                                                                    (yyval.classDecl)->addChild(new Node(","));
                                                                                }
                                                                                (yyval.classDecl)->addChild((yyvsp[-3].nTList)->Nth((yyvsp[-3].nTList)->NumElements()-1));
                                                                            }
                                                                            (yyval.classDecl)->addChild(new Node("{"));
                                                                            for(int i = 0; i < (yyvsp[-1].declList)->NumElements(); i++) {
                                                                                (yyval.classDecl)->addChild((yyvsp[-1].declList)->Nth(i));
                                                                            }
                                                                            (yyval.classDecl)->addChild(new Node("}"));
                                                                            (yyval.classDecl)->setNodeName("ClassDecl");
                                                                        }
#line 1948 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 303 "src/parser.y" /* yacc.c:1646  */
    { (yyval.extendsClause)=NULL; }
#line 1954 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 304 "src/parser.y" /* yacc.c:1646  */
    { (yyval.extendsClause)=new NamedType((yyvsp[0].identObj)); 
                           (yyval.extendsClause)->addChild(new Node("EXTENDS"));
                           (yyval.extendsClause)->addChild((yyvsp[0].identObj));
                           (yyval.extendsClause)->setNodeName("ExtendsClause");
                         }
#line 1964 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 312 "src/parser.y" /* yacc.c:1646  */
    { (yyval.nTList)=new List<NamedType*>; }
#line 1970 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 313 "src/parser.y" /* yacc.c:1646  */
    { (yyval.nTList)=(yyvsp[0].nTList);  }
#line 1976 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 317 "src/parser.y" /* yacc.c:1646  */
    { ((yyval.nTList)=new List<NamedType*>)->Append(new NamedType((yyvsp[0].identObj))); }
#line 1982 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 318 "src/parser.y" /* yacc.c:1646  */
    { ((yyval.nTList)=(yyvsp[-2].nTList))->Append(new NamedType((yyvsp[0].identObj))); }
#line 1988 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 322 "src/parser.y" /* yacc.c:1646  */
    { (yyval.declList)=new List<Decl*>; }
#line 1994 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 323 "src/parser.y" /* yacc.c:1646  */
    { ((yyval.declList)=(yyvsp[-1].declList))->Append((yyvsp[0].decl)); }
#line 2000 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 327 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl)=(yyvsp[0].varDecl); }
#line 2006 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 328 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl)=(yyvsp[0].fnDecl); }
#line 2012 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 332 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ifaceDecl)=new InterfaceDecl((yyvsp[-3].identObj), (yyvsp[-1].declList)); 
                                                   (yyval.ifaceDecl)->addChild(new Node("INTERFACE"));
                                                   (yyval.ifaceDecl)->addChild((yyvsp[-3].identObj));
                                                   (yyval.ifaceDecl)->addChild(new Node("{"));
                                                   for(int i = 0; i < (yyvsp[-1].declList)->NumElements(); i++) {
                                                       (yyval.ifaceDecl)->addChild((yyvsp[-1].declList)->Nth(i));
                                                   }
                                                   (yyval.ifaceDecl)->addChild(new Node("}"));                                                                                                       
                                                   (yyval.ifaceDecl)->setNodeName("InterfaceDecl");
                                                 }
#line 2027 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 345 "src/parser.y" /* yacc.c:1646  */
    { (yyval.declList)=new List<Decl*>; }
#line 2033 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 346 "src/parser.y" /* yacc.c:1646  */
    { ((yyval.declList)=(yyvsp[-1].declList))->Append((yyvsp[0].decl)); }
#line 2039 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 350 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl)=new FnDecl((yyvsp[-4].identObj), (yyvsp[-5].type), (yyvsp[-2].varDecls)); 
                                            (yyval.decl)->addChild((yyvsp[-5].type));
                                            (yyval.decl)->addChild((yyvsp[-4].identObj));
                                            (yyval.decl)->addChild(new Node("("));
                                            if((yyvsp[-2].varDecls)->NumElements() > 0) {
                                                for(int i = 0; i < (yyvsp[-2].varDecls)->NumElements()-1; i++) {
                                                    (yyval.decl)->addChild((yyvsp[-2].varDecls)->Nth(i));
                                                    (yyval.decl)->addChild(new Node(","));
                                                }
                                                (yyval.decl)->addChild((yyvsp[-2].varDecls)->Nth((yyvsp[-2].varDecls)->NumElements()-1));
                                            }    
                                            (yyval.decl)->addChild(new Node(")"));
                                            (yyval.decl)->addChild(new Node(";"));
                                            (yyval.decl)->setNodeName("Prototype");
                                          }
#line 2059 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 365 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl)=new FnDecl((yyvsp[-4].identObj), NULL, (yyvsp[-2].varDecls)); 
                                            (yyval.decl)->addChild(new Node("VOID"));
                                            (yyval.decl)->addChild((yyvsp[-4].identObj));
                                            (yyval.decl)->addChild(new Node("("));
                                            if((yyvsp[-2].varDecls)->NumElements() > 0) {
                                                for(int i = 0; i < (yyvsp[-2].varDecls)->NumElements()-1; i++) {
                                                    (yyval.decl)->addChild((yyvsp[-2].varDecls)->Nth(i));
                                                    (yyval.decl)->addChild(new Node(","));
                                                }
                                                (yyval.decl)->addChild((yyvsp[-2].varDecls)->Nth((yyvsp[-2].varDecls)->NumElements()-1));
                                            }    
                                            (yyval.decl)->addChild(new Node(")"));
                                            (yyval.decl)->addChild(new Node(";"));
                                            (yyval.decl)->setNodeName("Prototype");
                                          }
#line 2079 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 383 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmtBlock)=new StmtBlock((yyvsp[-2].varDecls), (yyvsp[-1].statements)); 
                                          (yyval.stmtBlock)->addChild(new Node("{"));
                                          for(int i = 0; i < (yyvsp[-2].varDecls)->NumElements(); i++) {
                                              (yyval.stmtBlock)->addChild((yyvsp[-2].varDecls)->Nth(i));
                                          }
                                          for(int i = 0; i < (yyvsp[-1].statements)->NumElements(); i++) {
                                              (yyval.stmtBlock)->addChild((yyvsp[-1].statements)->Nth(i));
                                          }                                          
                                          (yyval.stmtBlock)->addChild(new Node("}"));
                                          (yyval.stmtBlock)->setNodeName("StmtBlock");
                                        }
#line 2095 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 397 "src/parser.y" /* yacc.c:1646  */
    { (yyval.varDecls)=new List<VarDecl*>; }
#line 2101 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 398 "src/parser.y" /* yacc.c:1646  */
    { ((yyval.varDecls)=(yyvsp[-1].varDecls))->Append((yyvsp[0].varDecl)); }
#line 2107 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 402 "src/parser.y" /* yacc.c:1646  */
    { (yyval.statements)=new List<Stmt*>; }
#line 2113 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 403 "src/parser.y" /* yacc.c:1646  */
    { ((yyval.statements)=(yyvsp[0].statements))->InsertAt((yyvsp[-1].stmt), 0); }
#line 2119 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 407 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=new EmptyExpr();
            // $$->addChild(new Node(";"));
            (yyval.stmt)->setNodeName("Stmt");
          }
#line 2128 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 411 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=(yyvsp[-1].expr);                  
               }
#line 2135 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 413 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=(yyvsp[0].ifStmt); }
#line 2141 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 414 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=(yyvsp[0].whileStmt); }
#line 2147 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 415 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=(yyvsp[0].forStmt); }
#line 2153 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 416 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=(yyvsp[0].breakStmt); }
#line 2159 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 417 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=(yyvsp[0].returnStmt); }
#line 2165 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 418 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=(yyvsp[0].printStmt); }
#line 2171 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 419 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=(yyvsp[0].stmtBlock); }
#line 2177 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 423 "src/parser.y" /* yacc.c:1646  */
    { ((yyval.exprList)=new List<Expr*>)->Append((yyvsp[0].expr)); }
#line 2183 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 424 "src/parser.y" /* yacc.c:1646  */
    { ((yyval.exprList)=(yyvsp[-2].exprList))->Append((yyvsp[0].expr)); }
#line 2189 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 428 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ifStmt)=new IfStmt((yyvsp[-2].expr), (yyvsp[0].stmt), NULL); 
                                          (yyval.ifStmt)->addChild(new Node("IF"));
                                          (yyval.ifStmt)->addChild(new Node("("));
                                          (yyval.ifStmt)->addChild((yyvsp[-2].expr));
                                          (yyval.ifStmt)->addChild(new Node(")"));
                                          (yyval.ifStmt)->addChild((yyvsp[0].stmt));
                                          (yyval.ifStmt)->setNodeName("IfStmt");
                                        }
#line 2202 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 436 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ifStmt)=new IfStmt((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt)); 
                                       (yyval.ifStmt)->addChild(new Node("IF"));
                                          (yyval.ifStmt)->addChild(new Node("("));
                                          (yyval.ifStmt)->addChild((yyvsp[-4].expr));
                                          (yyval.ifStmt)->addChild(new Node(")"));
                                          (yyval.ifStmt)->addChild((yyvsp[-2].stmt));
                                          (yyval.ifStmt)->addChild(new Node("ELSE"));
                                          (yyval.ifStmt)->addChild((yyvsp[0].stmt));
                                          (yyval.ifStmt)->setNodeName("IfStmt");
                                     }
#line 2217 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 449 "src/parser.y" /* yacc.c:1646  */
    { (yyval.whileStmt)=new WhileStmt((yyvsp[-2].expr), (yyvsp[0].stmt)); 
                                (yyval.whileStmt)->addChild(new Node("WHILE"));
                                (yyval.whileStmt)->addChild(new Node("("));
                                (yyval.whileStmt)->addChild((yyvsp[-2].expr));
                                (yyval.whileStmt)->addChild(new Node(")"));
                                (yyval.whileStmt)->addChild((yyvsp[0].stmt));
                                (yyval.whileStmt)->setNodeName("WhileStmt");
                              }
#line 2230 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 460 "src/parser.y" /* yacc.c:1646  */
    { (yyval.forStmt)=new ForStmt(new EmptyExpr(), (yyvsp[-3].expr), new EmptyExpr(), (yyvsp[0].stmt)); 
                                      (yyval.forStmt)->addChild(new Node("FOR"));
                                      (yyval.forStmt)->addChild(new Node("("));
                                      (yyval.forStmt)->addChild(new Node(";"));
                                      (yyval.forStmt)->addChild((yyvsp[-3].expr));
                                      (yyval.forStmt)->addChild(new Node(";"));
                                      (yyval.forStmt)->addChild(new Node(")"));
                                      (yyval.forStmt)->addChild((yyvsp[0].stmt));
                                      (yyval.forStmt)->setNodeName("ForStmt");
                                    }
#line 2245 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 470 "src/parser.y" /* yacc.c:1646  */
    { (yyval.forStmt)=new ForStmt((yyvsp[-5].expr), (yyvsp[-3].expr), new EmptyExpr(), (yyvsp[0].stmt)); (yyval.forStmt)->addChild(new Node("FOR"));
                                      (yyval.forStmt)->addChild(new Node("("));
                                      (yyval.forStmt)->addChild((yyvsp[-5].expr));
                                      (yyval.forStmt)->addChild(new Node(";"));
                                      (yyval.forStmt)->addChild((yyvsp[-3].expr));
                                      (yyval.forStmt)->addChild(new Node(";"));
                                      (yyval.forStmt)->addChild(new Node(")"));
                                      (yyval.forStmt)->addChild((yyvsp[0].stmt));
                                      (yyval.forStmt)->setNodeName("ForStmt");}
#line 2259 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 479 "src/parser.y" /* yacc.c:1646  */
    { (yyval.forStmt)=new ForStmt(new EmptyExpr(), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt)); (yyval.forStmt)->addChild(new Node("FOR"));
                                      (yyval.forStmt)->addChild(new Node("("));
                                      (yyval.forStmt)->addChild(new Node(";"));
                                      (yyval.forStmt)->addChild((yyvsp[-4].expr));
                                      (yyval.forStmt)->addChild(new Node(";"));
                                      (yyval.forStmt)->addChild((yyvsp[-2].expr));
                                      (yyval.forStmt)->addChild(new Node(")"));
                                      (yyval.forStmt)->addChild((yyvsp[0].stmt));
                                      (yyval.forStmt)->setNodeName("ForStmt");}
#line 2273 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 488 "src/parser.y" /* yacc.c:1646  */
    { (yyval.forStmt)=new ForStmt((yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt)); (yyval.forStmt)->addChild(new Node("FOR"));
                                      (yyval.forStmt)->addChild(new Node("("));
                                      (yyval.forStmt)->addChild((yyvsp[-6].expr));
                                      (yyval.forStmt)->addChild(new Node(";"));
                                      (yyval.forStmt)->addChild((yyvsp[-4].expr));
                                      (yyval.forStmt)->addChild(new Node(";"));
                                      (yyval.forStmt)->addChild((yyvsp[-2].expr));
                                      (yyval.forStmt)->addChild(new Node(")"));
                                      (yyval.forStmt)->addChild((yyvsp[0].stmt));
                                      (yyval.forStmt)->setNodeName("ForStmt");}
#line 2288 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 501 "src/parser.y" /* yacc.c:1646  */
    { (yyval.returnStmt)=new ReturnStmt((yyloc), new EmptyExpr()); 
                   (yyval.returnStmt)->addChild(new Node("RETURN"));
                   (yyval.returnStmt)->addChild(new Node(";"));
                   (yyval.returnStmt)->setNodeName("ReturnStmt");
                 }
#line 2298 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 506 "src/parser.y" /* yacc.c:1646  */
    { (yyval.returnStmt)=new ReturnStmt((yylsp[-1]), (yyvsp[-1].expr)); 
                        (yyval.returnStmt)->addChild(new Node("RETURN"));
                        (yyval.returnStmt)->addChild((yyvsp[-1].expr));
                        (yyval.returnStmt)->addChild(new Node(";"));
                        (yyval.returnStmt)->setNodeName("ReturnStmt");
                      }
#line 2309 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 515 "src/parser.y" /* yacc.c:1646  */
    { (yyval.breakStmt)=new BreakStmt((yylsp[-1])); 
                  (yyval.breakStmt)->addChild(new Node("BREAK"));
                  (yyval.breakStmt)->addChild(new Node(";"));
                  (yyval.breakStmt)->setNodeName("BreakStmt");
                }
#line 2319 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 523 "src/parser.y" /* yacc.c:1646  */
    { (yyval.printStmt)=new PrintStmt((yyvsp[-2].exprList)); 
                                   (yyval.printStmt)->addChild(new Node("PRINT"));
                                   (yyval.printStmt)->addChild(new Node("("));
                                   if((yyvsp[-2].exprList)->NumElements() > 0) {
                                       for(int i = 0; i < (yyvsp[-2].exprList)->NumElements()-1; i++) {
                                           (yyval.printStmt)->addChild((yyvsp[-2].exprList)->Nth(i));
                                           (yyval.printStmt)->addChild(new Node(","));
                                       } 
                                       (yyval.printStmt)->addChild((yyvsp[-2].exprList)->Nth((yyvsp[-2].exprList)->NumElements()-1));
                                   }
                                   (yyval.printStmt)->addChild(new Node(")"));
                                   (yyval.printStmt)->addChild(new Node(";"));
                                   (yyval.printStmt)->setNodeName("PrintStmt");
                                 }
#line 2338 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 540 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new AssignExpr((yyvsp[-2].lvalue), new Operator((yylsp[-1]), "="), (yyvsp[0].expr)); 
                        (yyval.expr)->addChild((yyvsp[-2].lvalue));
                        (yyval.expr)->addChild(new Node("="));
                        (yyval.expr)->addChild((yyvsp[0].expr));
                        (yyval.expr)->setNodeName("Expr");                        
                      }
#line 2349 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 546 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[0].expr); }
#line 2355 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 547 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[0].lvalue); }
#line 2361 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 548 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new This((yylsp[0])); (yyval.expr)->addChild(new Node("THIS"));
                 (yyval.expr)->setNodeName("Expr"); }
#line 2368 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 550 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[0].call); }
#line 2374 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 551 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[-1].expr); }
#line 2380 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 552 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new ArithmeticExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "+"), (yyvsp[0].expr)); 
                      (yyval.expr)->addChild((yyvsp[-2].expr)); 
                      (yyval.expr)->addChild(new Node("+")); 
                      (yyval.expr)->addChild((yyvsp[0].expr)); 
                      (yyval.expr)->setNodeName("Expr"); }
#line 2390 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 557 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new ArithmeticExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "-"), (yyvsp[0].expr)); 
                      (yyval.expr)->addChild((yyvsp[-2].expr)); 
                      (yyval.expr)->addChild(new Node("-")); 
                      (yyval.expr)->addChild((yyvsp[0].expr)); 
                      (yyval.expr)->setNodeName("Expr");}
#line 2400 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 562 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new ArithmeticExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "*"), (yyvsp[0].expr)); (yyval.expr)->addChild((yyvsp[-2].expr)); 
                      (yyval.expr)->addChild(new Node("*")); 
                      (yyval.expr)->addChild((yyvsp[0].expr)); 
                      (yyval.expr)->setNodeName("Expr");}
#line 2409 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 566 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new ArithmeticExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "/"), (yyvsp[0].expr)); (yyval.expr)->addChild((yyvsp[-2].expr)); 
                      (yyval.expr)->addChild(new Node("/")); 
                      (yyval.expr)->addChild((yyvsp[0].expr)); 
                      (yyval.expr)->setNodeName("Expr");}
#line 2418 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 570 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new ArithmeticExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "%"), (yyvsp[0].expr)); (yyval.expr)->addChild((yyvsp[-2].expr)); 
                      (yyval.expr)->addChild(new Node("%")); 
                      (yyval.expr)->addChild((yyvsp[0].expr)); 
                      (yyval.expr)->setNodeName("Expr");}
#line 2427 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 574 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new ArithmeticExpr(new Operator((yylsp[-1]), "-"), (yyvsp[0].expr));
                      (yyval.expr)->addChild(new Node("-")); 
                      (yyval.expr)->addChild((yyvsp[0].expr)); 
                      (yyval.expr)->setNodeName("Expr");}
#line 2436 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 578 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new RelationalExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "<"), (yyvsp[0].expr)); (yyval.expr)->addChild((yyvsp[-2].expr)); 
                      (yyval.expr)->addChild(new Node("<")); 
                      (yyval.expr)->addChild((yyvsp[0].expr)); 
                      (yyval.expr)->setNodeName("Expr");}
#line 2445 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 582 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new RelationalExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "<="), (yyvsp[0].expr)); (yyval.expr)->addChild((yyvsp[-2].expr)); 
                      (yyval.expr)->addChild(new Node("<=")); 
                      (yyval.expr)->addChild((yyvsp[0].expr)); 
                      (yyval.expr)->setNodeName("Expr");}
#line 2454 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 586 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new RelationalExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), ">"), (yyvsp[0].expr)); (yyval.expr)->addChild((yyvsp[-2].expr)); 
                      (yyval.expr)->addChild(new Node(">")); 
                      (yyval.expr)->addChild((yyvsp[0].expr)); 
                      (yyval.expr)->setNodeName("Expr");}
#line 2463 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 590 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new RelationalExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), ">="), (yyvsp[0].expr)); (yyval.expr)->addChild((yyvsp[-2].expr)); 
                      (yyval.expr)->addChild(new Node(">=")); 
                      (yyval.expr)->addChild((yyvsp[0].expr)); 
                      (yyval.expr)->setNodeName("Expr");}
#line 2472 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 594 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new EqualityExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "=="), (yyvsp[0].expr)); (yyval.expr)->addChild((yyvsp[-2].expr)); 
                      (yyval.expr)->addChild(new Node("==")); 
                      (yyval.expr)->addChild((yyvsp[0].expr)); 
                      (yyval.expr)->setNodeName("Expr");}
#line 2481 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 598 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new EqualityExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "!="), (yyvsp[0].expr)); (yyval.expr)->addChild((yyvsp[-2].expr)); 
                      (yyval.expr)->addChild(new Node("!=")); 
                      (yyval.expr)->addChild((yyvsp[0].expr)); 
                      (yyval.expr)->setNodeName("Expr");}
#line 2490 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 602 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new LogicalExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "&&"), (yyvsp[0].expr)); (yyval.expr)->addChild((yyvsp[-2].expr)); 
                      (yyval.expr)->addChild(new Node("&&")); 
                      (yyval.expr)->addChild((yyvsp[0].expr)); 
                      (yyval.expr)->setNodeName("Expr");}
#line 2499 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 606 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new LogicalExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "||"), (yyvsp[0].expr)); (yyval.expr)->addChild((yyvsp[-2].expr)); 
                      (yyval.expr)->addChild(new Node("||")); 
                      (yyval.expr)->addChild((yyvsp[0].expr)); 
                      (yyval.expr)->setNodeName("Expr");}
#line 2508 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 610 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new LogicalExpr(new Operator((yylsp[-1]), "!"), (yyvsp[0].expr));
                      (yyval.expr)->addChild(new Node("!")); 
                      (yyval.expr)->addChild((yyvsp[0].expr)); 
                      (yyval.expr)->setNodeName("Expr");}
#line 2517 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 614 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new ReadIntegerExpr((yyloc));
                      (yyval.expr)->addChild(new Node("READINTEGER")); 
                      (yyval.expr)->addChild(new Node("(")); 
                      (yyval.expr)->addChild(new Node(")"));
                      (yyval.expr)->setNodeName("Expr");}
#line 2527 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 619 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new ReadLineExpr((yyloc)); (yyval.expr)->addChild(new Node("READLINE")); 
                      (yyval.expr)->addChild(new Node("(")); 
                      (yyval.expr)->addChild(new Node(")"));
                      (yyval.expr)->setNodeName("Expr"); }
#line 2536 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 623 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new NewExpr((yyloc), new NamedType((yyvsp[0].identObj))); (yyval.expr)->addChild(new Node("NEW")); 
                      (yyval.expr)->addChild((yyvsp[0].identObj));
                      (yyval.expr)->setNodeName("Expr");}
#line 2544 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 626 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new NewArrayExpr((yyloc), (yyvsp[-3].expr), (yyvsp[-1].type)); 
                      (yyval.expr)->addChild(new Node("NEWARRAY")); 
                      (yyval.expr)->addChild(new Node("(")); 
                      (yyval.expr)->addChild((yyvsp[-3].expr));
                      (yyval.expr)->addChild(new Node(","));
                      (yyval.expr)->addChild((yyvsp[-1].type));                      
                      (yyval.expr)->addChild(new Node(")"));
                      (yyval.expr)->setNodeName("Expr"); }
#line 2557 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 637 "src/parser.y" /* yacc.c:1646  */
    { (yyval.call)=new Call((yyloc), NULL, (yyvsp[-3].identObj), (yyvsp[-1].exprList)); 
                                   (yyval.call)->addChild((yyvsp[-3].identObj));
                                   (yyval.call)->addChild(new Node("("));
                                   if((yyvsp[-1].exprList)->NumElements() > 0) {
                                        for(int i = 0; i < (yyvsp[-1].exprList)->NumElements()-1; i++) {
                                            (yyval.call)->addChild((yyvsp[-1].exprList)->Nth(i));
                                            (yyval.call)->addChild(new Node(","));
                                        } 
                                        (yyval.call)->addChild((yyvsp[-1].exprList)->Nth((yyvsp[-1].exprList)->NumElements()-1));
                                    }
                                   (yyval.call)->addChild(new Node(")"));
                                   (yyval.call)->setNodeName("Call");
                                 }
#line 2575 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 650 "src/parser.y" /* yacc.c:1646  */
    { (yyval.call)=new Call((yyloc), (yyvsp[-5].expr), (yyvsp[-3].identObj), (yyvsp[-1].exprList)); 
                                            (yyval.call)->addChild((yyvsp[-5].expr));
                                            (yyval.call)->addChild(new Node("."));
                                            (yyval.call)->addChild((yyvsp[-3].identObj));
                                            (yyval.call)->addChild(new Node("("));
                                            if((yyvsp[-1].exprList)->NumElements() > 0) {
                                                for(int i = 0; i < (yyvsp[-1].exprList)->NumElements()-1; i++) {
                                                    (yyval.call)->addChild((yyvsp[-1].exprList)->Nth(i));
                                                    (yyval.call)->addChild(new Node(","));
                                                } 
                                                (yyval.call)->addChild((yyvsp[-1].exprList)->Nth((yyvsp[-1].exprList)->NumElements()-1));
                                            }
                                            (yyval.call)->addChild(new Node(")"));
                                            (yyval.call)->setNodeName("Call");
                                          }
#line 2595 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 668 "src/parser.y" /* yacc.c:1646  */
    { (yyval.exprList)=new List<Expr*>; }
#line 2601 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 669 "src/parser.y" /* yacc.c:1646  */
    { (yyval.exprList)=(yyvsp[0].exprList); }
#line 2607 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 673 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new IntConstant((yylsp[0]), (yyvsp[0].intConstant)); 
                    char *node_name = new char[128];
                     sprintf(node_name, "INTCONSTANT (%d)", (yyvsp[0].intConstant));
                     (yyval.expr)->setNodeName(node_name);                    
                    (yyval.expr)->addChild(new Node(node_name));
                    (yyval.expr)->setNodeName("Constant");
                    delete node_name;                    
                  }
#line 2620 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 681 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new DoubleConstant((yylsp[0]), (yyvsp[0].doubleConstant)); 
                       char *node_name = new char[128];
                       sprintf(node_name, "DOUBLECONSTANT (%lf)", (yyvsp[0].doubleConstant));
                       (yyval.expr)->setNodeName(node_name);                    
                       (yyval.expr)->addChild(new Node(node_name));
                       (yyval.expr)->setNodeName("Constant");
                       delete node_name;   
                     }
#line 2633 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 689 "src/parser.y" /* yacc.c:1646  */
    {   (yyval.expr)=new BoolConstant((yylsp[0]), (yyvsp[0].boolConstant)); 
                        char *node_name = new char[128];
                        sprintf(node_name, "BOOLCONSTANT (%s)", (yyvsp[0].boolConstant) ? "true" : "false");
                        (yyval.expr)->setNodeName(node_name);                    
                        (yyval.expr)->addChild(new Node(node_name));
                        (yyval.expr)->setNodeName("Constant");
                        delete node_name;   
                    }
#line 2646 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 697 "src/parser.y" /* yacc.c:1646  */
    {   (yyval.expr)=new StringConstant((yylsp[0]), (yyvsp[0].stringConstant)); 
                            char *node_name = new char[128];
                            sprintf(node_name, "STRING_LITERAL (%s)", (yyvsp[0].stringConstant));
                            (yyval.expr)->setNodeName(node_name);                    
                            (yyval.expr)->addChild(new Node(node_name));
                            (yyval.expr)->setNodeName("Constant");
                            delete node_name;
                        }
#line 2659 "obj/y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 705 "src/parser.y" /* yacc.c:1646  */
    {   (yyval.expr)=new NullConstant((yylsp[0])); 
                        char *node_name = new char[128];
                        sprintf(node_name, "NULLCONSTANT (null)");
                        (yyval.expr)->setNodeName(node_name);                    
                        (yyval.expr)->addChild(new Node(node_name));
                        (yyval.expr)->setNodeName("Constant");
                        delete node_name;
                    }
#line 2672 "obj/y.tab.c" /* yacc.c:1646  */
    break;


#line 2676 "obj/y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 715 "src/parser.y" /* yacc.c:1906  */


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
