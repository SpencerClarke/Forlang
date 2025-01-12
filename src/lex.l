%{
	#include "parser.tab.h"
	#include <string.h>
	#include <stddef.h>

	void strtoupr(char *s)
	{
		while(*s != '\0')
		{
			if(*s >= 'a' && *s <= 'z')
			{
				*s = *s - 'a' + 'A';
			}
			s++;
		}
	}
%}

%option yylineno
%option caseless
%option noinput
%option nounput

LETTER [a-zA-Z]
DIGIT [0-9]
IDENT {LETTER}(({LETTER}|{DIGIT}|_)*)
STRING (\'([^\']*)\')|(\"([^\"]*)\")
ICONST {DIGIT}+
RCONST {DIGIT}*\.{DIGIT}+
SCONST (\'([^\']*)\')|(\"([^\"]*)\")

%%
{RCONST} {
	char *end;
	double dval;
	errno = 0;
	dval = strtod(yytext, &end);
	if(errno == ERANGE)
	{
		fprintf(stderr, "lex: RCONST '%s' is too large to convert to a double\n", yytext);
		exit(3);
	}
	if(*end != '\0')
	{
		fprintf(stderr, "lex: RCONST '%s' is too large to convert to a double\n", yytext);
		exit(3);
	}
	yylval.dval = dval;
	return RCONST;
}
{ICONST} {
	char *end;
	errno = 0;
	long intval;
	intval = strtol(yytext, &end, 10);
	if(errno == ERANGE)
	{
		fprintf(stderr, "lex: ICONST '%s' is too large to convert to an int\n", yytext);
		exit(3);
	}
	if(*end != '\0')
	{
		fprintf(stderr, "lex: ICONST '%s' is too large to convert to an int\n", yytext);
		exit(3);
	}
	if(intval > INT_MAX)
	{
		fprintf(stderr, "lex: ICONST '%s' is too large to convert to an int\n", yytext);
		exit(3);
	}
	yylval.intval = intval;
	return ICONST;
}
{SCONST} {
	size_t i;
	yylval.strval = malloc(strlen(yytext) - 1);
	if(yylval.strval == NULL)
	{
		fprintf(stderr, "lex: failed to alloc\n");
		exit(3);
	}
	for(i = 0; i < strlen(yytext) - 2; i++)
	{
		yylval.strval[i] = yytext[i + 1];
	}
	yylval.strval[i] = '\0';
	return SCONST;
}

program {
	return PROGRAM;
}

end {
	return END;
}

else {
	return ELSE;
}

if {
	return IF;
}

integer {
	return INTEGER;
}

real {
	return REAL;
}

character {
	return CHARACTER;
}

print {
	return PRINT;
}

len {
	return LEN;
}

then {
	return THEN;
}
do {
	return DO;
}
while {
	return WHILE;
}
\+ {
	return PLUS;
}

- {
	return MINUS;
}

\*\*  {
    return POW;
}

\* {
	return MULT;
}

\/ {
	return DIV;
}

==  {
    return EQ;
}

=   {
    return ASSOP;
}

\<   {
    return LTHAN;
}

>   {
    return GTHAN;
}
\/\/  {
    return CAT;
}
,   {
    return COMMA;
}

\(   {
	return LPAREN;
}

\)   {
    return RPAREN;
}

\::   {
    return DCOLON;
}

\?  {
    return DEF;
}

{IDENT} {
	yylval.strval = malloc(strlen(yytext) + 1);
	if(yylval.strval == NULL)
	{
		fprintf(stderr, "lex: failed to alloc\n");
		exit(3);
	}
	strcpy(yylval.strval, yytext);
	strtoupr(yylval.strval);
	return IDENT;
}
!.* {
}

[ \t\r\n]  { 

}
.      {
	fprintf(stderr, "lex: invalid character %u\n", *yytext);
	exit(2);
}
%%
