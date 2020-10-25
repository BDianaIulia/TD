// SampleLexer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "cminus.h"
#include <errno.h>

extern FILE* yyin;
extern int yylex(void);
const char* lexUnits[] = { "IF",
							"ELSE",
							"RETURN",
							"INT",
							"VOID",
							"WHILE",
							"ID",
							"NUM",
							"LESS_OR_EQUAL",
							"GREATER_OR_EQUAL",
							"EQUAL",
							"NOT_EQUAL",
							"LEFT_PRNTS",
							"RIGHT_PRNTS",
							"LEFT_BRACKET",
							"RIGHT_BRACKET",
							"LEFT_BRACE",
							"RIGHT_BRACE",
							"ADD",
							"SUBSTRACT",
							"MULTIPLY",
							"DIVIDE",
							"MOD",
							"LESS",
							"GREATER",
							"ASSIGN",
							"SEMICOLON",
							"COMMA"};

int main()
{
	int tokenValue = 0;
	yyin = fopen("input.csrc", "rt");
	if (yyin != NULL)
	{
		while ((tokenValue = yylex()) != 0)
		{
			printf(" -> TOKEN ID: %d; Token Value: %s \n", tokenValue, lexUnits[tokenValue - 1]);
		}
	}
	else
	{
		printf("Fisierul de intrare nu poate fi deschis. Erorare: %d", errno);
	}

}
