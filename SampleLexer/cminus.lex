%{
#include <stdio.h>
#include "cminus.tab.h"

void comment();
void warning();
%}

%%
"/*"		{comment();}

"else"		{return ELSE;}
"if"		{return IF;}
"int"		{return INT;}
"return" 	{return RETURN;}
"void" 		{return VOID;}
"while" 	{return WHILE;}

[a-zA-Z][a-zA-Z0-9_]* 	{return ID;}
[0-9]+					{return NUM;}

"<="		{return LESS_OR_EQUAL;}
">="		{return GREATER_OR_EQUAL;}
"=="		{return EQUAL;}
"!="		{return NOT_EQUAL;}

"("			{return LEFT_PRNTS;}
")"			{return RIGHT_PRNTS;}
"["			{return LEFT_BRACKET;}
"]"			{return RIGHT_BRACKET;}
"{"			{return LEFT_BRACE;}
"}"			{return RIGHT_BRACE;}
"+"			{return ADD;}
"-"			{return SUBSTRACT;}
"*"			{return MULTIPLY;}
"/"			{return DIVIDE;}
"%"			{return MOD;}
"<"			{return LESS;}
">"			{return GREATER;}
"="			{return ASSIGN;}
";"			{return SEMICOLON;}
","			{return COMMA;}

[ \s\t\n]+

.			{warning();}

%%

int yywrap(void)
{
	return 1;
}

void comment(void)
{
	char c, prev = 0;
  
	while ((c = input()) != 0)      
	{
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
}

void warning()
{
	printf("The string %s is not recognized" , yytext);
}


