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
#line 11 "parser.y" /* yacc.c:339  */


/* Just like lex, the text within this first region delimited by %{ and %}
 * is assumed to be C/C++ code and will be copied verbatim to the y.tab.c
 * file ahead of the definitions of the yyparse() function. Add other header
 * file inclusions or C++ variable declarations/prototypes that are needed
 * by your code here.
 */
#include "scanner.h" // for yylex
#include "parser.h"
#include "errors.h"

void yyerror(const char *msg); // standard error-handling routine


#line 82 "y.tab.c" /* yacc.c:339  */

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    T_Void = 258,
    T_Bool = 259,
    T_Int = 260,
    T_Double = 261,
    T_String = 262,
    T_Class = 263,
    T_LessEqual = 264,
    T_GreaterEqual = 265,
    T_Equal = 266,
    T_NotEqual = 267,
    T_Dims = 268,
    T_Increment = 269,
    T_Decrement = 270,
    T_And = 271,
    T_Or = 272,
    T_Null = 273,
    T_Extends = 274,
    T_This = 275,
    T_Interface = 276,
    T_Implements = 277,
    T_While = 278,
    T_For = 279,
    T_If = 280,
    T_Else = 281,
    T_Return = 282,
    T_Break = 283,
    T_Switch = 284,
    T_Case = 285,
    T_Default = 286,
    T_New = 287,
    T_NewArray = 288,
    T_Print = 289,
    T_ReadInteger = 290,
    T_ReadLine = 291,
    T_Static = 292,
    T_InstanceOf = 293,
    T_Identifier = 294,
    T_StringConstant = 295,
    T_IntConstant = 296,
    T_DoubleConstant = 297,
    T_BoolConstant = 298,
    UMINUS = 299,
    NOELSE = 300
  };
#endif
/* Tokens.  */
#define T_Void 258
#define T_Bool 259
#define T_Int 260
#define T_Double 261
#define T_String 262
#define T_Class 263
#define T_LessEqual 264
#define T_GreaterEqual 265
#define T_Equal 266
#define T_NotEqual 267
#define T_Dims 268
#define T_Increment 269
#define T_Decrement 270
#define T_And 271
#define T_Or 272
#define T_Null 273
#define T_Extends 274
#define T_This 275
#define T_Interface 276
#define T_Implements 277
#define T_While 278
#define T_For 279
#define T_If 280
#define T_Else 281
#define T_Return 282
#define T_Break 283
#define T_Switch 284
#define T_Case 285
#define T_Default 286
#define T_New 287
#define T_NewArray 288
#define T_Print 289
#define T_ReadInteger 290
#define T_ReadLine 291
#define T_Static 292
#define T_InstanceOf 293
#define T_Identifier 294
#define T_StringConstant 295
#define T_IntConstant 296
#define T_DoubleConstant 297
#define T_BoolConstant 298
#define UMINUS 299
#define NOELSE 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 41 "parser.y" /* yacc.c:355  */

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

#line 248 "y.tab.c" /* yacc.c:355  */
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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 279 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   846

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  227

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,     2,     2,    53,     2,     2,
      60,    61,    51,    49,    58,    50,    56,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,    57,
      47,    46,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,     2,    63,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   174,   174,   186,   187,   191,   192,   193,   194,   198,
     202,   206,   207,   211,   212,   213,   217,   218,   219,   220,
     221,   222,   226,   230,   231,   235,   236,   240,   244,   245,
     249,   250,   254,   255,   259,   260,   264,   265,   269,   273,
     274,   278,   279,   283,   287,   288,   292,   293,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   310,   311,
     315,   316,   320,   324,   325,   326,   327,   331,   332,   336,
     340,   344,   345,   349,   350,   354,   358,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   392,   393,   397,   398,   402,   403,
     404,   405,   406
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Void", "T_Bool", "T_Int", "T_Double",
  "T_String", "T_Class", "T_LessEqual", "T_GreaterEqual", "T_Equal",
  "T_NotEqual", "T_Dims", "T_Increment", "T_Decrement", "T_And", "T_Or",
  "T_Null", "T_Extends", "T_This", "T_Interface", "T_Implements",
  "T_While", "T_For", "T_If", "T_Else", "T_Return", "T_Break", "T_Switch",
  "T_Case", "T_Default", "T_New", "T_NewArray", "T_Print", "T_ReadInteger",
  "T_ReadLine", "T_Static", "T_InstanceOf", "T_Identifier",
  "T_StringConstant", "T_IntConstant", "T_DoubleConstant",
  "T_BoolConstant", "UMINUS", "NOELSE", "'='", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "'['", "'.'", "';'", "','", "']'", "'('",
  "')'", "'{'", "'}'", "':'", "$accept", "Program", "DeclList", "Decl",
  "VariableDecl", "Variable", "VariableList", "LValue", "Type",
  "Identifier", "Formals", "FunctionDecl", "ClassDecl", "ExtendsClause",
  "ImplementsClause", "InterfaceList", "FieldList", "Field",
  "InterfaceDecl", "PrototypeList", "Prototype", "StmtBlock",
  "VariableDeclList", "StmtList", "Stmt", "ExprList", "IfStmt",
  "WhileStmt", "ForStmt", "ReturnStmt", "BreakStmt", "PrintStmt",
  "SwitchStmt", "CaseStmts", "CaseStmt", "DefaultStmt", "Expr", "Call",
  "Actuals", "Constant", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,    61,    60,    62,    43,
      45,    42,    47,    37,    33,    91,    46,    59,    44,    93,
      40,    41,   123,   125,    58
};
# endif

#define YYPACT_NINF -93

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-93)))

#define YYTABLE_NINF -21

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-21)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     353,   -34,   -93,   -93,   -93,   -93,   -34,   -34,   -93,    11,
     353,   -93,   -93,     6,    44,   -93,   -93,   -93,   -93,   -31,
      27,     7,   -93,   -93,   -93,   -93,     5,    19,   -34,    46,
     -93,    19,   -93,    12,    44,    10,   -93,   -34,    13,    15,
      16,    19,   -93,    18,   -93,    31,   -93,   -34,   -93,    44,
     -93,    18,   -93,   -93,   -93,   -34,    81,    32,    48,   -93,
     135,   -93,   -93,   -93,   -93,   -93,    19,    19,   -93,   -93,
      49,    50,    51,   734,    57,    55,   -34,    63,    64,    65,
      67,   -93,   -93,   -93,   -93,   786,   786,   -93,   786,   -93,
      47,     4,   -93,    68,   641,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   403,   -93,   -93,    71,    72,   786,   760,   786,
     -93,    74,   452,   -93,   786,   -93,   786,   786,    75,    76,
     -20,   -20,   189,   -93,   -93,   786,   786,   -93,   -93,   786,
     786,   786,   786,   786,   786,   786,   786,   786,   786,   786,
     786,   786,   786,   -34,   -93,    78,    88,   204,   786,   463,
     252,   -93,   267,   391,   -28,   534,   -93,   -93,   -93,   534,
      70,    77,   238,   238,   554,   554,   602,   544,   238,   238,
      66,    66,   -20,   -20,   -20,   378,    87,   -93,   -93,   641,
     474,   786,   641,    86,    19,   786,    92,   -93,   -93,   786,
     -93,   672,   523,   131,   142,    -9,   534,   -93,   100,   641,
     315,   703,   641,   124,   -15,   -93,   -93,   -93,   -93,   641,
     641,   330,   -93,   109,   115,   -93,   -93,   117,   -93,   -93,
     641,   641,   641,   -93,   -93,   -93,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    18,    16,    17,    19,     0,     0,    22,     0,
       2,     4,     5,     0,     0,    20,     6,     7,     8,     0,
      28,     0,     1,     3,     9,    21,    10,    23,     0,    30,
      39,    23,    11,    24,     0,     0,    29,     0,     0,     0,
       0,     0,    10,     0,    32,    31,    34,     0,    38,     0,
      40,     0,    12,    44,    26,     0,     0,     0,     0,    25,
      46,    33,    27,    36,    37,    35,    23,    23,   112,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,   108,   109,   110,     0,     0,    48,     0,    45,
      79,    13,    57,     0,    46,    50,    51,    52,    54,    53,
      55,    56,     0,    83,    78,     0,     0,     0,     0,     0,
      67,    13,     0,    69,     0,   102,     0,     0,     0,     0,
      90,    99,     0,    80,    81,     0,   106,    43,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,     0,     0,     0,     0,     0,
       0,    68,     0,     0,     0,    58,   100,   101,    84,    77,
     107,     0,    92,    94,    95,    96,    97,    98,    91,    93,
      85,    86,    87,    88,    89,     0,    14,    42,    41,     0,
       0,     0,     0,     0,     0,     0,     0,   104,    15,   106,
      62,     0,     0,    60,     0,     0,    59,    70,     0,     0,
       0,     0,     0,     0,     0,    73,   103,   105,    63,     0,
       0,     0,    61,     0,     0,    71,    74,     0,    65,    64,
       0,    46,    46,    72,    66,    75,    76
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   -93,   171,   -48,    85,   -93,   -93,     3,     0,
     -22,   126,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -11,   -93,   -92,     9,    69,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -21,   -93,   -35,   -93,     1,   -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    33,    90,    34,   111,
      35,    16,    17,    29,    38,    45,    56,    65,    18,    39,
      50,    92,    60,    93,    94,   160,    95,    96,    97,    98,
      99,   100,   101,   204,   205,   217,   102,   103,   161,   104
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      15,    19,   128,    14,    25,     8,    20,    21,    63,    40,
      15,    22,    89,    14,    26,   203,   214,   -20,    47,     2,
       3,     4,     5,     2,     3,     4,     5,    15,    36,    27,
     185,    15,    54,   186,    42,   142,   143,    44,   112,    15,
      59,    15,    49,   -20,   105,   106,    28,    57,   215,    58,
     120,   121,   206,   122,     8,    61,    15,    25,     8,    14,
      91,   123,   124,    24,   126,    31,    15,    15,    37,    30,
      41,    43,   147,   149,   150,    46,   115,    51,    48,   152,
      53,   153,   155,     8,     1,     2,     3,     4,     5,    55,
     159,   155,    66,   125,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,    67,   107,
     108,   109,    32,   180,   113,   114,    32,   139,   140,   141,
       8,   142,   143,   116,   117,   118,    52,   119,   185,   225,
     226,   127,   145,   146,   126,   177,   156,   157,   187,     2,
       3,     4,     5,   176,    62,   178,   192,   189,   194,   197,
     196,    32,    32,    68,   155,    69,   200,   202,    70,    71,
      72,   207,    73,    74,    75,   213,   211,    76,    77,    78,
      79,    80,   203,   221,     8,    81,    82,    83,    84,   222,
     223,    23,    64,   216,    15,    85,   154,   195,   190,    86,
     198,   193,    87,     0,     0,    88,     0,    53,   129,   130,
     131,   132,     0,     0,     0,   133,   134,     0,   208,     0,
       0,   212,     0,   129,   130,   131,   132,     0,   218,   219,
     133,   134,     0,     0,     0,     0,     0,     0,     0,   224,
       0,     0,     0,     0,     0,     0,   135,   136,   137,   138,
     139,   140,   141,     0,   142,   143,     0,   -21,   -21,     0,
     158,   135,   136,   137,   138,   139,   140,   141,     0,   142,
     143,   129,   130,   131,   132,   179,     0,     0,   133,   134,
       0,     0,     0,     0,     0,     0,   129,   130,   131,   132,
       0,     0,     0,   133,   134,   -21,   -21,   137,   138,   139,
     140,   141,     0,   142,   143,     0,     0,     0,     0,   135,
     136,   137,   138,   139,   140,   141,     0,   142,   143,     0,
       0,     0,     0,   182,   135,   136,   137,   138,   139,   140,
     141,     0,   142,   143,   129,   130,   131,   132,   183,     0,
       0,   133,   134,     0,     0,     0,     0,     0,     0,   129,
     130,   131,   132,     0,     0,     0,   133,   134,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     3,     4,
       5,     6,   135,   136,   137,   138,   139,   140,   141,     0,
     142,   143,     0,     0,     7,     0,   209,   135,   136,   137,
     138,   139,   140,   141,     0,   142,   143,   129,   130,   131,
     132,   220,     8,     0,   133,   134,     0,     0,     0,     0,
     129,   130,   131,   132,     0,     0,     0,   133,   134,     0,
       0,     0,   129,   130,   131,   132,     0,     0,     0,   133,
     134,     0,     0,     0,     0,   135,   136,   137,   138,   139,
     140,   141,     0,   142,   143,     0,     0,   188,   135,   136,
     137,   138,   139,   140,   141,     0,   142,   143,     0,   184,
     135,   136,   137,   138,   139,   140,   141,     0,   142,   143,
     144,   129,   130,   131,   132,     0,     0,     0,   133,   134,
       0,     0,   129,   130,   131,   132,     0,     0,     0,   133,
     134,     0,     0,   129,   130,   131,   132,     0,     0,     0,
     133,   134,     0,     0,     0,     0,     0,     0,     0,   135,
     136,   137,   138,   139,   140,   141,     0,   142,   143,   151,
     135,   136,   137,   138,   139,   140,   141,     0,   142,   143,
     181,   135,   136,   137,   138,   139,   140,   141,     0,   142,
     143,   191,   129,   130,   131,   132,     0,     0,     0,   133,
     134,     0,     0,   129,   130,   131,   132,     0,     0,     0,
     133,   134,     0,   129,   130,   131,   132,     0,     0,     0,
     133,     0,     0,   129,   130,   -21,   -21,     0,     0,     0,
     135,   136,   137,   138,   139,   140,   141,     0,   142,   143,
     201,   135,   136,   137,   138,   139,   140,   141,     0,   142,
     143,   135,   136,   137,   138,   139,   140,   141,     0,   142,
     143,   135,   136,   137,   138,   139,   140,   141,     0,   142,
     143,   129,   130,   131,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   135,
     136,   137,   138,   139,   140,   141,     0,   142,   143,    68,
       0,    69,     0,     0,    70,    71,    72,     0,    73,    74,
      75,     0,     0,    76,    77,    78,    79,    80,     0,     0,
       8,    81,    82,    83,    84,     0,     0,     0,     0,     0,
      68,    85,    69,     0,     0,    86,     0,     0,    87,     0,
       0,    88,     0,    53,    76,    77,     0,    79,    80,     0,
       0,     8,    81,    82,    83,    84,     0,     0,     0,     0,
       0,    68,    85,    69,     0,     0,    86,     0,     0,     0,
       0,     0,    88,   199,     0,    76,    77,     0,    79,    80,
       0,     0,     8,    81,    82,    83,    84,     0,     0,     0,
       0,     0,    68,    85,    69,     0,     0,    86,     0,     0,
       0,     0,     0,    88,   210,     0,    76,    77,     0,    79,
      80,     0,     0,     8,    81,    82,    83,    84,    68,     0,
      69,     0,     0,     0,    85,     0,     0,     0,    86,     0,
       0,   110,    76,    77,    88,    79,    80,     0,     0,     8,
      81,    82,    83,    84,    68,     0,    69,     0,     0,     0,
      85,     0,     0,     0,    86,     0,     0,   148,    76,    77,
      88,    79,    80,     0,     0,     8,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,    85,     0,     0,     0,
      86,     0,     0,     0,     0,     0,    88
};

static const yytype_int16 yycheck[] =
{
       0,     1,    94,     0,    13,    39,     6,     7,    56,    31,
      10,     0,    60,    10,    14,    30,    31,    13,     3,     4,
       5,     6,     7,     4,     5,     6,     7,    27,    28,    60,
      58,    31,    43,    61,    34,    55,    56,    37,    73,    39,
      51,    41,    39,    39,    66,    67,    19,    47,    63,    49,
      85,    86,    61,    88,    39,    55,    56,    13,    39,    56,
      60,    14,    15,    57,    60,    60,    66,    67,    22,    62,
      58,    61,   107,   108,   109,    62,    76,    61,    63,   114,
      62,   116,   117,    39,     3,     4,     5,     6,     7,    58,
     125,   126,    60,    46,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    60,    60,
      60,    60,    27,   148,    57,    60,    31,    51,    52,    53,
      39,    55,    56,    60,    60,    60,    41,    60,    58,   221,
     222,    63,    61,    61,    60,    57,    61,    61,    61,     4,
       5,     6,     7,   143,    63,    57,   181,    60,    62,    57,
     185,    66,    67,    18,   189,    20,   191,    26,    23,    24,
      25,    61,    27,    28,    29,    41,   201,    32,    33,    34,
      35,    36,    30,    64,    39,    40,    41,    42,    43,    64,
      63,    10,    56,   204,   184,    50,   117,   184,   179,    54,
     189,   182,    57,    -1,    -1,    60,    -1,    62,     9,    10,
      11,    12,    -1,    -1,    -1,    16,    17,    -1,   199,    -1,
      -1,   202,    -1,     9,    10,    11,    12,    -1,   209,   210,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    -1,     9,    10,    -1,
      61,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,     9,    10,    11,    12,    61,    -1,    -1,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,
      -1,    -1,    -1,    16,    17,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    -1,
      -1,    -1,    -1,    61,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,     9,    10,    11,    12,    61,    -1,
      -1,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    12,    -1,    -1,    -1,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    -1,    -1,    21,    -1,    61,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,     9,    10,    11,
      12,    61,    39,    -1,    16,    17,    -1,    -1,    -1,    -1,
       9,    10,    11,    12,    -1,    -1,    -1,    16,    17,    -1,
      -1,    -1,     9,    10,    11,    12,    -1,    -1,    -1,    16,
      17,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    -1,    -1,    59,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    -1,    58,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,     9,    10,    11,    12,    -1,    -1,    -1,    16,    17,
      -1,    -1,     9,    10,    11,    12,    -1,    -1,    -1,    16,
      17,    -1,    -1,     9,    10,    11,    12,    -1,    -1,    -1,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,     9,    10,    11,    12,    -1,    -1,    -1,    16,
      17,    -1,    -1,     9,    10,    11,    12,    -1,    -1,    -1,
      16,    17,    -1,     9,    10,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,     9,    10,    11,    12,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    18,
      -1,    20,    -1,    -1,    23,    24,    25,    -1,    27,    28,
      29,    -1,    -1,    32,    33,    34,    35,    36,    -1,    -1,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      18,    50,    20,    -1,    -1,    54,    -1,    -1,    57,    -1,
      -1,    60,    -1,    62,    32,    33,    -1,    35,    36,    -1,
      -1,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    18,    50,    20,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,    32,    33,    -1,    35,    36,
      -1,    -1,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    18,    50,    20,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    32,    33,    -1,    35,
      36,    -1,    -1,    39,    40,    41,    42,    43,    18,    -1,
      20,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    -1,
      -1,    57,    32,    33,    60,    35,    36,    -1,    -1,    39,
      40,    41,    42,    43,    18,    -1,    20,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    54,    -1,    -1,    57,    32,    33,
      60,    35,    36,    -1,    -1,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    21,    39,    66,
      67,    68,    69,    70,    73,    74,    76,    77,    83,    74,
      74,    74,     0,    68,    57,    13,    74,    60,    19,    78,
      62,    60,    70,    71,    73,    75,    74,    22,    79,    84,
      75,    58,    74,    61,    74,    80,    62,     3,    63,    73,
      85,    61,    70,    62,    86,    58,    81,    74,    74,    86,
      87,    74,    63,    69,    76,    82,    60,    60,    18,    20,
      23,    24,    25,    27,    28,    29,    32,    33,    34,    35,
      36,    40,    41,    42,    43,    50,    54,    57,    60,    69,
      72,    74,    86,    88,    89,    91,    92,    93,    94,    95,
      96,    97,   101,   102,   104,    75,    75,    60,    60,    60,
      57,    74,   101,    57,    60,    74,    60,    60,    60,    60,
     101,   101,   101,    14,    15,    46,    60,    63,    88,     9,
      10,    11,    12,    16,    17,    47,    48,    49,    50,    51,
      52,    53,    55,    56,    57,    61,    61,   101,    57,   101,
     101,    57,   101,   101,    90,   101,    61,    61,    61,   101,
      90,   103,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,    74,    57,    57,    61,
     101,    57,    61,    61,    58,    58,    61,    61,    59,    60,
      89,    57,   101,    89,    62,    73,   101,    57,   103,    61,
     101,    57,    26,    30,    98,    99,    61,    61,    89,    61,
      61,   101,    89,    41,    31,    63,    99,   100,    89,    89,
      61,    64,    64,    63,    89,    88,    88
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    68,    68,    68,    69,
      70,    71,    71,    72,    72,    72,    73,    73,    73,    73,
      73,    73,    74,    75,    75,    76,    76,    77,    78,    78,
      79,    79,    80,    80,    81,    81,    82,    82,    83,    84,
      84,    85,    85,    86,    87,    87,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    90,    90,
      91,    91,    92,    93,    93,    93,    93,    94,    94,    95,
      96,    97,    97,    98,    98,    99,   100,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   102,   102,   103,   103,   104,   104,
     104,   104,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     2,
       2,     1,     3,     1,     3,     4,     1,     1,     1,     1,
       1,     2,     1,     0,     1,     6,     6,     7,     0,     2,
       0,     2,     1,     3,     0,     2,     1,     1,     5,     0,
       2,     6,     6,     4,     0,     2,     0,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       5,     7,     5,     7,     8,     8,     9,     2,     3,     2,
       5,     7,     8,     1,     2,     4,     3,     3,     1,     1,
       2,     2,     1,     1,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     2,     6,     4,     6,     0,     1,     1,     1,
       1,     1,     1
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
#line 174 "parser.y" /* yacc.c:1646  */
    { 
                                      (yylsp[0]); 
                                      /* pp2: The @1 is needed to convince 
                                       * yacc to set up yylloc. You can remove 
                                       * it once you have other uses of @n*/
                                      Program *program = new Program((yyvsp[0].declList));
                                      // if no errors, advance to next phase
                                      if (ReportError::NumErrors() == 0) 
                                          program->Print(0);
                                    }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 186 "parser.y" /* yacc.c:1646  */
    { ((yyval.declList)=(yyvsp[-1].declList))->Append((yyvsp[0].decl)); }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 187 "parser.y" /* yacc.c:1646  */
    { ((yyval.declList) = new List<Decl*>)->Append((yyvsp[0].decl)); }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.decl)=(yyvsp[0].varDecl); }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval.decl)=(yyvsp[0].fnDecl); }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval.decl)=(yyvsp[0].classDecl); }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.decl)=(yyvsp[0].ifaceDecl); }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 198 "parser.y" /* yacc.c:1646  */
    { (yyval.varDecl)=(yyvsp[-1].varDecl); }
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 202 "parser.y" /* yacc.c:1646  */
    { (yyval.varDecl)=new VarDecl((yyvsp[0].identObj), (yyvsp[-1].type)); }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 206 "parser.y" /* yacc.c:1646  */
    { ((yyval.varDecls)=new List<VarDecl*>)->Append((yyvsp[0].varDecl)); }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 207 "parser.y" /* yacc.c:1646  */
    { ((yyval.varDecls)=(yyvsp[-2].varDecls))->Append((yyvsp[0].varDecl)); }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.lvalue)=new FieldAccess(NULL, (yyvsp[0].identObj)); }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.lvalue)=new FieldAccess((yyvsp[-2].expr), (yyvsp[0].identObj)); }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.lvalue)=new ArrayAccess((yyloc), (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval.type)=Type::intType; }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval.type)=Type::doubleType; }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 219 "parser.y" /* yacc.c:1646  */
    { (yyval.type)=Type::boolType; }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 220 "parser.y" /* yacc.c:1646  */
    { (yyval.type)=Type::stringType; }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.type)=new NamedType((yyvsp[0].identObj)); }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.type)=new ArrayType((yylsp[-1]), (yyvsp[-1].type)); }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.identObj)=new Identifier((yylsp[0]), (yyvsp[0].identifier)); }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 230 "parser.y" /* yacc.c:1646  */
    { (yyval.varDecls)=new List<VarDecl*>; }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval.varDecls)=(yyvsp[0].varDecls); }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 235 "parser.y" /* yacc.c:1646  */
    { (yyval.fnDecl)=new FnDecl((yyvsp[-4].identObj), (yyvsp[-5].type), (yyvsp[-2].varDecls)); (yyval.fnDecl)->SetFunctionBody((yyvsp[0].stmtBlock)); }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 236 "parser.y" /* yacc.c:1646  */
    { (yyval.fnDecl)=new FnDecl((yyvsp[-4].identObj), Type::voidType, (yyvsp[-2].varDecls)); (yyval.fnDecl)->SetFunctionBody((yyvsp[0].stmtBlock)); }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 240 "parser.y" /* yacc.c:1646  */
    {   (yyval.classDecl)=new ClassDecl((yyvsp[-5].identObj), (yyvsp[-4].extendsClause), (yyvsp[-3].nTList), (yyvsp[-1].declList)); }
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 244 "parser.y" /* yacc.c:1646  */
    { (yyval.extendsClause)=NULL; }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 245 "parser.y" /* yacc.c:1646  */
    { (yyval.extendsClause)=new NamedType((yyvsp[0].identObj)); }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval.nTList)=new List<NamedType*>; }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 250 "parser.y" /* yacc.c:1646  */
    { (yyval.nTList)=(yyvsp[0].nTList);  }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 254 "parser.y" /* yacc.c:1646  */
    { ((yyval.nTList)=new List<NamedType*>)->Append(new NamedType((yyvsp[0].identObj))); }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 255 "parser.y" /* yacc.c:1646  */
    { ((yyval.nTList)=(yyvsp[-2].nTList))->Append(new NamedType((yyvsp[0].identObj))); }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 259 "parser.y" /* yacc.c:1646  */
    { (yyval.declList)=new List<Decl*>; }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 260 "parser.y" /* yacc.c:1646  */
    { ((yyval.declList)=(yyvsp[-1].declList))->Append((yyvsp[0].decl)); }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval.decl)=(yyvsp[0].varDecl); }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 265 "parser.y" /* yacc.c:1646  */
    { (yyval.decl)=(yyvsp[0].fnDecl); }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 269 "parser.y" /* yacc.c:1646  */
    { (yyval.ifaceDecl)=new InterfaceDecl((yyvsp[-3].identObj), (yyvsp[-1].declList)); }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 273 "parser.y" /* yacc.c:1646  */
    { (yyval.declList)=new List<Decl*>; }
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 274 "parser.y" /* yacc.c:1646  */
    { ((yyval.declList)=(yyvsp[-1].declList))->Append((yyvsp[0].decl)); }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 278 "parser.y" /* yacc.c:1646  */
    { (yyval.decl)=new FnDecl((yyvsp[-4].identObj), (yyvsp[-5].type), (yyvsp[-2].varDecls));  }
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 279 "parser.y" /* yacc.c:1646  */
    { (yyval.decl)=new FnDecl((yyvsp[-4].identObj), Type::voidType, (yyvsp[-2].varDecls)); }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 283 "parser.y" /* yacc.c:1646  */
    { (yyval.stmtBlock)=new StmtBlock((yyvsp[-2].varDecls), (yyvsp[-1].statements)); }
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 287 "parser.y" /* yacc.c:1646  */
    { (yyval.varDecls)=new List<VarDecl*>; }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 288 "parser.y" /* yacc.c:1646  */
    { ((yyval.varDecls)=(yyvsp[-1].varDecls))->Append((yyvsp[0].varDecl)); }
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 292 "parser.y" /* yacc.c:1646  */
    { (yyval.statements)=new List<Stmt*>; }
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 293 "parser.y" /* yacc.c:1646  */
    { ((yyval.statements)=(yyvsp[0].statements))->InsertAt((yyvsp[-1].stmt), 0); }
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 297 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=new EmptyExpr(); }
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 298 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=(yyvsp[-1].expr); }
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 299 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=(yyvsp[0].ifStmt); }
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 300 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=(yyvsp[0].whileStmt); }
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 301 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=(yyvsp[0].forStmt); }
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 302 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=(yyvsp[0].breakStmt); }
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 303 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=(yyvsp[0].returnStmt); }
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 304 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=(yyvsp[0].printStmt); }
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 305 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=(yyvsp[0].switchStmt); }
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 306 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt)=(yyvsp[0].stmtBlock); }
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 310 "parser.y" /* yacc.c:1646  */
    { ((yyval.exprList)=new List<Expr*>)->Append((yyvsp[0].expr)); }
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 311 "parser.y" /* yacc.c:1646  */
    { ((yyval.exprList)=(yyvsp[-2].exprList))->Append((yyvsp[0].expr)); }
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 315 "parser.y" /* yacc.c:1646  */
    { (yyval.ifStmt)=new IfStmt((yyvsp[-2].expr), (yyvsp[0].stmt), NULL); }
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 316 "parser.y" /* yacc.c:1646  */
    { (yyval.ifStmt)=new IfStmt((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 320 "parser.y" /* yacc.c:1646  */
    { (yyval.whileStmt)=new WhileStmt((yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 324 "parser.y" /* yacc.c:1646  */
    { (yyval.forStmt)=new ForStmt(new EmptyExpr(), (yyvsp[-3].expr), new EmptyExpr(), (yyvsp[0].stmt)); }
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 325 "parser.y" /* yacc.c:1646  */
    { (yyval.forStmt)=new ForStmt((yyvsp[-5].expr), (yyvsp[-3].expr), new EmptyExpr(), (yyvsp[0].stmt)); }
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 326 "parser.y" /* yacc.c:1646  */
    { (yyval.forStmt)=new ForStmt(new EmptyExpr(), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 327 "parser.y" /* yacc.c:1646  */
    { (yyval.forStmt)=new ForStmt((yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 331 "parser.y" /* yacc.c:1646  */
    { (yyval.returnStmt)=new ReturnStmt((yyloc), new EmptyExpr()); }
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 332 "parser.y" /* yacc.c:1646  */
    { (yyval.returnStmt)=new ReturnStmt((yylsp[-1]), (yyvsp[-1].expr)); }
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 336 "parser.y" /* yacc.c:1646  */
    { (yyval.breakStmt)=new BreakStmt((yylsp[-1])); }
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 340 "parser.y" /* yacc.c:1646  */
    { (yyval.printStmt)=new PrintStmt((yyvsp[-2].exprList)); }
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 344 "parser.y" /* yacc.c:1646  */
    { (yyval.switchStmt)=new SwitchStmt((yyvsp[-4].expr), (yyvsp[-1].caseStmts), NULL); }
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 345 "parser.y" /* yacc.c:1646  */
    { (yyval.switchStmt)=new SwitchStmt((yyvsp[-5].expr), (yyvsp[-2].caseStmts), (yyvsp[-1].defaultStmt)); }
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 349 "parser.y" /* yacc.c:1646  */
    { ((yyval.caseStmts)=new List<CaseStmt*>)->Append((yyvsp[0].caseStmt)); }
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 350 "parser.y" /* yacc.c:1646  */
    { ((yyval.caseStmts)=(yyvsp[-1].caseStmts))->Append((yyvsp[0].caseStmt)); }
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 354 "parser.y" /* yacc.c:1646  */
    { (yyval.caseStmt)=new CaseStmt(new IntConstant((yylsp[-2]), (yyvsp[-2].integerConstant)), (yyvsp[0].statements)); }
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 358 "parser.y" /* yacc.c:1646  */
    { (yyval.defaultStmt)=new DefaultStmt((yyvsp[0].statements)); }
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 362 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new AssignExpr((yyvsp[-2].lvalue), new Operator((yylsp[-1]), "="), (yyvsp[0].expr)); }
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 363 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[0].expr); }
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 364 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[0].lvalue); }
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 365 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new PostfixExpr((yyvsp[-1].lvalue), new Operator((yylsp[0]), "++")); }
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 366 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new PostfixExpr((yyvsp[-1].lvalue), new Operator((yylsp[0]), "--")); }
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 367 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new This((yylsp[0])); }
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 368 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[0].call); }
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 369 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[-1].expr); }
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 370 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new ArithmeticExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "+"), (yyvsp[0].expr)); }
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 371 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new ArithmeticExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "-"), (yyvsp[0].expr)); }
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 372 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new ArithmeticExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "*"), (yyvsp[0].expr)); }
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 373 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new ArithmeticExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "/"), (yyvsp[0].expr)); }
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 374 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new ArithmeticExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "%"), (yyvsp[0].expr)); }
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 375 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new ArithmeticExpr(new Operator((yylsp[-1]), "-"), (yyvsp[0].expr)); }
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 376 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new RelationalExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "<"), (yyvsp[0].expr)); }
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 377 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new RelationalExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "<="), (yyvsp[0].expr)); }
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 378 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new RelationalExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), ">"), (yyvsp[0].expr)); }
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 379 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new RelationalExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), ">="), (yyvsp[0].expr)); }
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 380 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new EqualityExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "=="), (yyvsp[0].expr)); }
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 381 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new EqualityExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "!="), (yyvsp[0].expr)); }
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 382 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new LogicalExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "&&"), (yyvsp[0].expr)); }
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 383 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new LogicalExpr((yyvsp[-2].expr), new Operator((yylsp[-1]), "||"), (yyvsp[0].expr)); }
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 384 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new LogicalExpr(new Operator((yylsp[-1]), "!"), (yyvsp[0].expr)); }
#line 2331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 385 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new ReadIntegerExpr((yyloc)); }
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 386 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new ReadLineExpr((yyloc)); }
#line 2343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 387 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new NewExpr((yyloc), new NamedType((yyvsp[0].identObj))); }
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 388 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new NewArrayExpr((yyloc), (yyvsp[-3].expr), (yyvsp[-1].type)); }
#line 2355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 392 "parser.y" /* yacc.c:1646  */
    { (yyval.call)=new Call((yyloc), NULL, (yyvsp[-3].identObj), (yyvsp[-1].exprList)); }
#line 2361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 393 "parser.y" /* yacc.c:1646  */
    { (yyval.call)=new Call((yyloc), (yyvsp[-5].expr), (yyvsp[-3].identObj), (yyvsp[-1].exprList)); }
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 397 "parser.y" /* yacc.c:1646  */
    { (yyval.exprList)=new List<Expr*>; }
#line 2373 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 398 "parser.y" /* yacc.c:1646  */
    { (yyval.exprList)=(yyvsp[0].exprList); }
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 402 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new IntConstant((yylsp[0]), (yyvsp[0].integerConstant)); }
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 403 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new DoubleConstant((yylsp[0]), (yyvsp[0].doubleConstant)); }
#line 2391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 404 "parser.y" /* yacc.c:1646  */
    {   (yyval.expr)=new BoolConstant((yylsp[0]), (yyvsp[0].boolConstant)); }
#line 2397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 405 "parser.y" /* yacc.c:1646  */
    {   (yyval.expr)=new StringConstant((yylsp[0]), (yyvsp[0].stringConstant)); }
#line 2403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 406 "parser.y" /* yacc.c:1646  */
    {   (yyval.expr)=new NullConstant((yylsp[0])); }
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2413 "y.tab.c" /* yacc.c:1646  */
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
#line 409 "parser.y" /* yacc.c:1906  */


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
