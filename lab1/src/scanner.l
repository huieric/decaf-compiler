%{
#include <string.h>
#include "scanner.h"
#include "utility.h"
#include "errors.h"
#include "parser.h"
#include <vector>
using namespace std;

/* Global variables */
static int curLineNum, curColNum;
vector<const char*> savedLines;

static void DoBeforeEachAction();
#define YY_USER_ACTION DoBeforeEachAction();
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
COMMENT             ("//"[^\r\n]*{NEWLINE})
IDENTIFIER          ([A-Za-z][A-Za-z0-9_]*)
DEC_INTEGER         ([0-9]+)
HEX_INTEGER         (0[xX][0-9A-Fa-f]+)
INTEGER             ({DEC_INTEGER}|{HEX_INTEGER})
STRING_LITERAL      (\"[^{NEWLINE}\"]*\")
EXPONENT            ([Ee][+-]?{DEC_INTEGER})
DOUBLE_NUM          ([0-9]+\.[0-9]*)
DOUBLE_SCI          ({DOUBLE_NUM}{EXPONENT})

%%
 /* Comment or WhiteSpace */
{WHITESPACE}       { /* Just ignore */ }
{NEWLINE}          { /* Just ignore */ }
{COMMENT}          { /* Just ignore */ }

 /* Keywords */
"int"              { printf("(%s, TYPEINT)\n", yytext); return INT; }
"bool"             { printf("(%s, TYPEBOOL)\n", yytext); return BOOL; }
"string"           { printf("(%s, TYPESTRING)\n", yytext); return STRING; }
"void"             { printf("(%s, TYPEVOID)\n", yytext); return VOID;}
"break"            { printf("(%s, KEYBREAK)\n", yytext); return BREAK; }
"class"            { printf("(%s, KEYCLASS)\n", yytext); return CLASS; }
"else"             { printf("(%s, KEYELSE)\n", yytext); return ELSE; }
"extends"          { printf("(%s, KEYEXTENDS)\n", yytext); return EXTENDS; }
"for"              { printf("(%s, KEYFOR)\n", yytext); return FOR; }
"if"               { printf("(%s, KEYIF)\n", yytext); return IF; }
"new"              { printf("(%s, KEYNEW)\n", yytext); return NEW; }
"null"             { printf("(%s, KEYNULL)\n", yytext); return NULLCONSTANT; }
"return"           { printf("(%s, KEYRETURN)\n", yytext); return RETURN; }
"this"             { printf("(%s, KEYTHIS)\n", yytext); return THIS; }
"while"            { printf("(%s, KEYWHILE)\n", yytext); return WHILE; }
"static"           { printf("(%s, KEYSTATIC)\n", yytext); return STATIC; }
"Print"            { printf("(%s, KEYPRINT)\n", yytext); return PRINT; }
"ReadInteger"      { printf("(%s, KEYREADINTEGER)\n", yytext); return READINTEGER; }
"ReadLine"         { printf("(%s, KEYREADLINE)\n", yytext); return READLINE; }
"instanceof"       { printf("(%s, KEYINSTANCEOF)\n", yytext); return INSTANCEOF; }

 /* Operator and Separator */
"+"                { printf("(%s, OPADD)\n", yytext); return '+'; }
"-"                { printf("(%s, OPSUB)\n", yytext); return '-'; }
"*"                { printf("(%s, OPMUL)\n", yytext); return '*'; }
"/"                { printf("(%s, OPDIV)\n", yytext); return '/'; }
"%"                { printf("(%s, OPMOD)\n", yytext); return '%'; }
"="                { printf("(%s, OPASSIGN)\n", yytext); return '='; }
"<"                { printf("(%s, LESS)\n", yytext); return '<'; }
"<="               { printf("(%s, LESSEQUAL)\n", yytext); return LE_OP; }
">"                { printf("(%s, GREATER)\n", yytext); return '>'; }
">="               { printf("(%s, GREATEREQUAL)\n", yytext); return GE_OP; }
"=="               { printf("(%s, EQUAL)\n", yytext); return EQ_OP; }
"!="               { printf("(%s, NOTEQUAL)\n", yytext); return NE_OP; }
"&&"               { printf("(%s, LOGICALAND)\n", yytext); return AND_OP; }
"||"               { printf("(%s, LOGICALOR)\n", yytext); return OR_OP; }
"!"                { printf("(%s, LOGICALNOT)\n", yytext); return NOT_OP; }
";"                { printf("(%s, SEMICOLON)\n", yytext); return yytext[0]; }
","                { printf("(%s, COMMA)\n", yytext); return yytext[0]; }
"."                { printf("(%s, PTR)\n", yytext); return yytext[0]; }
"["                { printf("(%s, LEFTBRACKET)\n", yytext); return yytext[0]; }
"]"                { printf("(%s, RIGHTBRACKET)\n", yytext); return yytext[0]; }
"("                { printf("(%s, LEFTPAREN)\n", yytext); return yytext[0]; }
")"                { printf("(%s, RIGHTPAREN)\n", yytext); return yytext[0]; }
"{"                { printf("(%s, LEFTBRACE)\n", yytext); return yytext[0]; }
"}"                { printf("(%s, RIGHTBRACE)\n", yytext); return yytext[0]; }

 /* Constants */
"true"             { printf("(%s, CONSTANTTRUE)\n", yytext); yylval.boolConstant = (yytext[0]=='t'); return BOOLCONSTANT; }
"false"            { printf("(%s, CONSTANTFALSE)\n", yytext); yylval.boolConstant = (yytext[0]=='t');  return BOOLCONSTANT; }
{DEC_INTEGER}      { printf("(%s, CONSTANTINTD)\n", yytext); yylval.intConstant = strtol(yytext, NULL, 10); return INTCONSTANT; }
{HEX_INTEGER}      { printf("(%s, CONSTANTINTH)\n", yytext); yylval.intConstant = strtol(yytext, NULL, 16); return INTCONSTANT; }
{STRING_LITERAL}   { printf("(%s, CONSTANTSTR)\n", yytext); yylval.stringConstant = strdup(yytext); return STRING_LITERAL; }
{DOUBLE_NUM}       { printf("(%s, CONSTANTDOUBLE)\n", yytext); yylval.doubleConstant = atof(yytext); return DOUBLECONSTANT; }
{DOUBLE_SCI}       { printf("(%s, CONSTANTDOUBLESCI)\n", yytext); yylval.doubleConstant = atof(yytext); return DOUBLECONSTANT; }

 /* Identifier */
{IDENTIFIER}       { printf("(%s, IDENTIFIER)\n", yytext); 
                     if(strlen(yytext)>MaxIdentLen)
                        ReportError::LongIdentifier(&yylloc, yytext);
                     strncpy(yylval.identifier, yytext, MaxIdentLen);
                     yylval.identifier[MaxIdentLen] = '\0';
                     return IDENTIFIER; }

 /* Default rule */
.                 { printf("*** Error : Unredognized characters\n"); ReportError::UnrecogChar(&yylloc, yytext[0]); }
%%

/* Function: InitScanner
 * ---------------------
 * This function will be called before any calls to yylex (). It is designed
 * to give you an opportunity to do anything that must be done to initialize 
 * the scanner (set golbal variables, configure starting state, etc.). One 
 * thing it already does for you is assign the value of the global variable 
 * yy_flex_debug that controls whether flex prints debugging information 
 * is printed. Setting it to true will give you a running trail that might 
 * be helpful when debugging your scanner. Please be sure the variable is 
 * set to false when submitting your final version.
*/
void InitScanner() {
    PrintDebug("lex", "Initializing scanner");
    yy_flex_debug = false;
    BEGIN(N);
    yy_push_state(COPY); // copy first line at start
    curLineNum = 1;
    curColNum = 1;
}

/* Function: DoBeforeEachAction
 * ----------------------------
 * This function is installed as the YY_USER_ACTION. This is a place
 * to group code common to all actions.
 * On each match, we fill in the fields to record its location and
 * update our column counter.
*/
static void DoBeforeEachAction() {
    yylloc.first_line = curLineNum;
    yylloc.first_column = curColNum;
    yylloc.last_column = curColNum + yyleng - 1;
    curColNum += yyleng;
} 

/* Function: GetLineNumbered
 * -------------------------
 * Returns string  with contents of line numbered n or NULL if the 
 * contents of that line are not available. Our scanner copies 
 * each line scanned and appends each to a list so we can later 
 * retrieve them to report the context for errors.
*/
const char *GetLineNumbered(int num) {
    if(num<=0 || num>savedLines.size())
        return NULL;
    return savedLines[num-1];
 }