%{
#include <string.h>
#include "scanner.h"
#include "utility.h"
#include "errors.h"
#include "parser.h"
#include <vector>
using namespace std;

#define TAB_SIZE 8

/* Global variables */
static int curLineNum, curColNum;
vector<const char*> savedLines;

static void DoBeforeEachAction();
#define YY_USER_ACTION DoBeforeEachAction();

FILE *scanner_log;
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
<COPY>.*           { char curLine[512]; 
                     savedLines.push_back(strdup(yytext)); 
                     curColNum = 1; 
                     yy_pop_state();
                     yyless(0); }
<COPY><<EOF>>      { yy_pop_state(); }                     
<*>\n              { curLineNum++; 
                     curColNum = 1;
                     if(YYSTATE==COPY)
                        savedLines.push_back("");
                     else
                        yy_push_state(COPY); }
[ ]+               { /* ignore all spaces */ }
<*>[\t]            { curColNum += TAB_SIZE-curColNum%TAB_SIZE + 1; }      

 /* Comment */
{COMMENT}          { /* Just ignore */ }

 /* Keywords */
"int"              { fprintf(scanner_log, "(%s, TYPEINT)\n", yytext); return INT; }
"double"           { fprintf(scanner_log, "(%s, TYPEDOUBLE)\n", yytext); return DOUBLE; }
"bool"             { fprintf(scanner_log, "(%s, TYPEBOOL)\n", yytext); return BOOL; }
"string"           { fprintf(scanner_log, "(%s, TYPESTRING)\n", yytext); return STRING; }
"void"             { fprintf(scanner_log, "(%s, TYPEVOID)\n", yytext); return VOID;}
"break"            { fprintf(scanner_log, "(%s, KEYBREAK)\n", yytext); return BREAK; }
"class"            { fprintf(scanner_log, "(%s, KEYCLASS)\n", yytext); return CLASS; }
"else"             { fprintf(scanner_log, "(%s, KEYELSE)\n", yytext); return ELSE; }
"extends"          { fprintf(scanner_log, "(%s, KEYEXTENDS)\n", yytext); return EXTENDS; }
"for"              { fprintf(scanner_log, "(%s, KEYFOR)\n", yytext); return FOR; }
"if"               { fprintf(scanner_log, "(%s, KEYIF)\n", yytext); return IF; }
"new"              { fprintf(scanner_log, "(%s, KEYNEW)\n", yytext); return NEW; }
"null"             { fprintf(scanner_log, "(%s, KEYNULL)\n", yytext); return NULLCONSTANT; }
"return"           { fprintf(scanner_log, "(%s, KEYRETURN)\n", yytext); return RETURN; }
"this"             { fprintf(scanner_log, "(%s, KEYTHIS)\n", yytext); return THIS; }
"while"            { fprintf(scanner_log, "(%s, KEYWHILE)\n", yytext); return WHILE; }
"static"           { fprintf(scanner_log, "(%s, KEYSTATIC)\n", yytext); return STATIC; }
"Print"            { fprintf(scanner_log, "(%s, KEYPRINT)\n", yytext); return PRINT; }
"ReadInteger"      { fprintf(scanner_log, "(%s, KEYREADINTEGER)\n", yytext); return READINTEGER; }
"ReadLine"         { fprintf(scanner_log, "(%s, KEYREADLINE)\n", yytext); return READLINE; }
"instanceof"       { fprintf(scanner_log, "(%s, KEYINSTANCEOF)\n", yytext); return INSTANCEOF; }
"NewArray"         { fprintf(scanner_log, "(%s, KEYNEWARRAY)\n", yytext); return NEWARRAY; }
"implements"       { fprintf(scanner_log, "(%s, KEYIMPLEMENTS)\n", yytext); return IMPLEMENTS; }
"interface"        { fprintf(scanner_log, "(%s, KEYINTERFACE)\n", yytext); return INTERFACE; }

 /* Operator and Separator */
"+"                { fprintf(scanner_log, "(%s, OPADD)\n", yytext); return '+'; }
"-"                { fprintf(scanner_log, "(%s, OPSUB)\n", yytext); return '-'; }
"*"                { fprintf(scanner_log, "(%s, OPMUL)\n", yytext); return '*'; }
"/"                { fprintf(scanner_log, "(%s, OPDIV)\n", yytext); return '/'; }
"%"                { fprintf(scanner_log, "(%s, OPMOD)\n", yytext); return '%'; }
"="                { fprintf(scanner_log, "(%s, OPASSIGN)\n", yytext); return '='; }
"<"                { fprintf(scanner_log, "(%s, LESS)\n", yytext); return '<'; }
"<="               { fprintf(scanner_log, "(%s, LESSEQUAL)\n", yytext); return LE_OP; }
">"                { fprintf(scanner_log, "(%s, GREATER)\n", yytext); return '>'; }
">="               { fprintf(scanner_log, "(%s, GREATEREQUAL)\n", yytext); return GE_OP; }
"=="               { fprintf(scanner_log, "(%s, EQUAL)\n", yytext); return EQ_OP; }
"!="               { fprintf(scanner_log, "(%s, NOTEQUAL)\n", yytext); return NE_OP; }
"&&"               { fprintf(scanner_log, "(%s, LOGICALAND)\n", yytext); return AND_OP; }
"||"               { fprintf(scanner_log, "(%s, LOGICALOR)\n", yytext); return OR_OP; }
"!"                { fprintf(scanner_log, "(%s, LOGICALNOT)\n", yytext); return NOT_OP; }
";"                { fprintf(scanner_log, "(%s, SEMICOLON)\n", yytext); return yytext[0]; }
","                { fprintf(scanner_log, "(%s, COMMA)\n", yytext); return yytext[0]; }
"."                { fprintf(scanner_log, "(%s, PTR)\n", yytext); return yytext[0]; }
"["                { fprintf(scanner_log, "(%s, LEFTBRACKET)\n", yytext); return yytext[0]; }
"]"                { fprintf(scanner_log, "(%s, RIGHTBRACKET)\n", yytext); return yytext[0]; }
"("                { fprintf(scanner_log, "(%s, LEFTPAREN)\n", yytext); return yytext[0]; }
")"                { fprintf(scanner_log, "(%s, RIGHTPAREN)\n", yytext); return yytext[0]; }
"{"                { fprintf(scanner_log, "(%s, LEFTBRACE)\n", yytext); return yytext[0]; }
"}"                { fprintf(scanner_log, "(%s, RIGHTBRACE)\n", yytext); return yytext[0]; }

 /* Constants */
"true"             { fprintf(scanner_log, "(%s, CONSTANTTRUE)\n", yytext); yylval.boolConstant = (yytext[0]=='t'); return BOOLCONSTANT; }
"false"            { fprintf(scanner_log, "(%s, CONSTANTFALSE)\n", yytext); yylval.boolConstant = (yytext[0]=='t');  return BOOLCONSTANT; }
{DEC_INTEGER}      { fprintf(scanner_log, "(%s, CONSTANTINTD)\n", yytext); yylval.intConstant = strtol(yytext, NULL, 10); return INTCONSTANT; }
{HEX_INTEGER}      { fprintf(scanner_log, "(%s, CONSTANTINTH)\n", yytext); yylval.intConstant = strtol(yytext, NULL, 16); return INTCONSTANT; }
{STRING_LITERAL}   { fprintf(scanner_log, "(%s, CONSTANTSTR)\n", yytext); yylval.stringConstant = strdup(yytext); return STRING_LITERAL; }
{DOUBLE_NUM}       { fprintf(scanner_log, "(%s, CONSTANTDOUBLE)\n", yytext); yylval.doubleConstant = atof(yytext); return DOUBLECONSTANT; }
{DOUBLE_SCI}       { fprintf(scanner_log, "(%s, CONSTANTDOUBLESCI)\n", yytext); yylval.doubleConstant = atof(yytext); return DOUBLECONSTANT; }

 /* Identifier */
{IDENTIFIER}       { fprintf(scanner_log, "(%s, IDENTIFIER)\n", yytext); 
                     if(strlen(yytext)>MaxIdentLen)
                        ReportError::LongIdentifier(&yylloc, yytext);
                     strncpy(yylval.identifier, yytext, MaxIdentLen);
                     yylval.identifier[MaxIdentLen] = '\0';
                     return IDENTIFIER; }

 /* Default rule */
.                 { fprintf(scanner_log, "*** Error : Unredognized characters\n"); ReportError::UnrecogChar(&yylloc, yytext[0]); }
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