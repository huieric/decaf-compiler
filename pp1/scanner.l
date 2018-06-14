 /* File:  scanner.l
 * ----------------
 * Lex input file to generate the scanner for the compiler.
 */

%{
#include <ctype.h>
#include <string.h>
#include "scanner.h"
#include "utility.h" // for PrintDebug()
#include "errors.h"
#include <vector>
using namespace std;

YYSTYPE yylval;  // manually declared for pp1, later Yacc provides
struct yyltype yylloc; // manually dclared for pp1, later Yacc provides

static int curLineNum, curColNum;
vector<const char*> savedLines;

static void DoBeforeEachAction(); 
#define YY_USER_ACTION DoBeforeEachAction();
#define TAB_SIZE 4
%}

 /* States
 * ------
 * A little winkle on states is the COPY exclusive state which 
 * I added to first match each line and copy it to the list of lines 
 * read before reprocessing it. This allows us to print the entire 
 * line later to provide context on errors.
 */
%s N
%x COPY COMM 
%option stack

 /* Definition */
WHITESPACE          ([ \t]+)
NEWLINE             (\r|\n|\r\n)
SINGLE_COMMENT      ("//"[^\r\n]*)
BEG_COMMENT         ("/*")
END_COMMENT         ("*/")
IDENTIFIER          ([A-Za-z][A-Za-z0-9_]*)
DEC_INTEGER         ([0-9]+)
HEX_INTEGER         (0[xX][0-9A-Fa-f]+)
INTEGER             ({DEC_INTEGER}|{HEX_INTEGER})
BEG_STRING          (\"[^"\n]*)
STRING              ({BEG_STRING}\")
EXPONENT            ([Ee][+-]?{DEC_INTEGER})
DOUBLE_NUM          ([0-9]+\.[0-9]*)
DOUBLE_SCI          ({DOUBLE_NUM}{EXPONENT})
OPERATOR            ([-+/*%=.,;!<>()[\]{}:])

%%
<COPY>.*           { char curLine[512]; 
                     savedLines.push_back(strdup(yytext)); 
                     curColNum = 1; 
                     yy_pop_state();
                     yyless(0); }
<COPY><<EOF>>      { yy_pop_state(); }                     
<*>{NEWLINE}       { curLineNum++; 
                     curColNum = 1;
                     if(YYSTATE==COPY)
                        savedLines.push_back("");
                     else
                        yy_push_state(COPY); }
[ ]+               { /* ignore all spaces */ }
<*>[\t]            { curColNum += TAB_SIZE-curColNum%TAB_SIZE + 1; }      

 /* Comments */
{SINGLE_COMMENT}            { /* Just ignore */ }
{BEG_COMMENT}               { BEGIN(COMM); }
<COMM>{END_COMMENT}         { BEGIN(N); }
<COMM><<EOF>>               { 
                                ReportError::UntermComment(); 
                                return 0;
                            }
<COMM>.                     { /* Just ignore */ }                            

 /* Keywords */
"int"              { return T_Int; }
"double"           { return T_Double; }
"bool"             { return T_Bool; }
"string"           { return T_String; }
"void"             { return T_Void;}
"break"            { return T_Break; }
"class"            { return T_Class; }
"else"             { return T_Else; }
"extends"          { return T_Extends; }
"for"              { return T_For; }
"if"               { return T_If; }
"new"              { return T_New; }
"null"             { return T_Null; }
"return"           { return T_Return; }
"this"             { return T_This; }
"while"            { return T_While; }
"static"           { return T_Static; }
"Print"            { return T_Print; }
"ReadInteger"      { return T_ReadInteger; }
"ReadLine"         { return T_ReadLine; }
"instanceof"       { return T_InstanceOf; }
"NewArray"         { return T_NewArray; }
"implements"       { return T_Implements; }
"interface"        { return T_Interface; }
"switch"           { return T_Switch; }
"case"             { return T_Case; }
"default"          { return T_Default; }

 /* Operator and Separator */
"<="               { return T_LessEqual; }
">="               { return T_GreaterEqual; }
"=="               { return T_Equal; }
"!="               { return T_NotEqual; }
"&&"               { return T_And; }
"||"               { return T_Or; }
"[]"               { return T_Dims; }
"++"               { return T_Increment; }
"--"               { return T_Decrement; }
{OPERATOR}         { return yytext[0]; }

 /* Constants */
"true"              { yylval.boolConstant = (yytext[0]=='t'); return T_BoolConstant; }
"false"             { yylval.boolConstant = (yytext[0]=='t');  return T_BoolConstant; }
{DEC_INTEGER}       { yylval.integerConstant = strtol(yytext, NULL, 10); return T_IntConstant; }
{HEX_INTEGER}       { yylval.integerConstant = strtol(yytext, NULL, 16); return T_IntConstant; }
{DOUBLE_NUM}        { yylval.doubleConstant = atof(yytext); return T_DoubleConstant; }
{DOUBLE_SCI}        { yylval.doubleConstant = atof(yytext); return T_DoubleConstant; }
{STRING}            { yylval.stringConstant = strdup(yytext); return T_StringConstant; }
{BEG_STRING}        { ReportError::UntermString(&yylloc, yytext); }

 /* Identifier */
{IDENTIFIER}       { if(strlen(yytext)>MaxIdentLen)
                        ReportError::LongIdentifier(&yylloc, yytext);
                     strncpy(yylval.identifier, yytext, MaxIdentLen);
                     yylval.identifier[MaxIdentLen] = '\0';
                     return T_Identifier; }

 /* Default rule (error) */
.                   { 
                        ReportError::UnrecogChar(&yylloc, yytext[0]); 
                    }
%%
 /* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated lex.yy.c file.
 * This section is where you put definitions of helper functions.
 */


 /* Function: InitScanner
 * ---------------------
 * This function will be called before any calls to yylex().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the scanner (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yy_flex_debug that controls whether flex prints debugging information
 * about each token and what rule was matched. If set to false, no information
 * is printed. Setting it to true will give you a running trail that might
 * be helpful when debugging your scanner. Please be sure the variable is
 * set to false when submitting your final version.
 */
void InitScanner()
{
    PrintDebug("lex", "Initializing scanner");
    // yy_flex_debug = false;
    yy_flex_debug = IsDebugOn("lex");
    BEGIN(N);
    yy_push_state(COPY); // copy first line at start
    curLineNum = 1;
    curColNum = 1;
}


 /* Function: DoBeforeEachAction()
 * ------------------------------
 * This function is installed as the YY_USER_ACTION. This is a place
 * to group code common to all actions.
 */
static void DoBeforeEachAction()
{
    yylloc.first_line = curLineNum;
    yylloc.first_column = curColNum;
    yylloc.last_column = curColNum + yyleng - 1;
    curColNum += yyleng;
}
