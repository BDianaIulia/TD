// SampleLexer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "cminus.h"
#include "AST.h"
#include <errno.h>

//extern int yylex(void);
extern int yyparse(void);
extern FILE* yyin;
extern int yydebug;
extern ASTNode* astRoot;
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
							"COMMA" };

int main()
{
	/*int tokenValue = 0;
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
	}*/
	//int lexUnit = 0;
	yydebug = 0;
	yyin = fopen("input.csrc", "rt");
	if (yyin != NULL)
	{
		int result = yyparse();
		switch (result)
		{
		case 0:
			printf("Parse successfull.\n");
			break;

		case 1:
			printf("Invalid input encountered\n");
			break;

		case 2:
			printf("Out of memory\n");
			break;

		default:
			break;
		}
		HashTable* symbolsTable = createSymbolsTable(astRoot);
		fclose(yyin);
	}
	else
	{
		printf("Fisier inexistent");
	}

}
