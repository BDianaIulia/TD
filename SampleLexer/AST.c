#include "AST.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

ASTNode* createDefaultNode(const char* nodeName, unsigned int linksCount)
{
	ASTNode* retNode = (ASTNode*)malloc(sizeof(ASTNode));
	if (retNode)
	{
		memset(retNode, 0, sizeof(ASTNode));
		if (nodeName)
		{
			strcpy(retNode->type, nodeName);
		}
		retNode->numLinks = linksCount;
		if (linksCount > 0)
		{
			retNode->links = (ASTNode**)malloc(linksCount * sizeof(ASTNode*));
		}
	}
	return retNode;
}

ASTNode* resizeNodeLinks(ASTNode* nodeToResize, unsigned int newSize)
{
	if (nodeToResize->numLinks == 0)
	{
		nodeToResize->links = (ASTNode**)malloc(newSize * sizeof(ASTNode*));
	}
	else
	{
		nodeToResize->links = (ASTNode**)realloc(nodeToResize->links, newSize * sizeof(ASTNode*));
	}
	nodeToResize->numLinks = newSize;
	return nodeToResize;
}

ASTNode* createListNode(const char* listName, ASTNode* firstLink)
{
	ASTNode* retNode = createDefaultNode(listName, 1);
	retNode->links[0] = firstLink;
	return retNode;
}

void addLinkToList(ASTNode* listNode, ASTNode* linkToAdd)
{
	unsigned int numLinks = listNode->numLinks;
	resizeNodeLinks(listNode, numLinks + 1);
	listNode->links[numLinks] = linkToAdd;
}

ASTNode* createProgramUnitNode(ASTNode* declaration)
{
	ASTNode* retNode = createDefaultNode("ProgramUnit", 1);
	if (retNode)
	{
		retNode->links[0] = declaration;
	}

	return retNode;
}

ASTNode* createDeclarationNode(ASTNode* varFunDeclaration)
{
	ASTNode* retNode = createDefaultNode("Declaration", 1);
	if (retNode)
	{
		retNode->links[0] = varFunDeclaration;
	}
	return retNode;
}

ASTNode* createIfStatement(ASTNode* expression, ASTNode* thenStatement, ASTNode* elseStatement)
{
	ASTNode* retNode = createDefaultNode("IfStatement", 3);
	retNode->links[0] = expression;
	retNode->links[1] = thenStatement;
	retNode->links[2] = elseStatement;
	return retNode;
}

ASTNode* createFunctionDeclarationNode(ASTNode* typeSpecifier, const char* functionName, ASTNode* params, ASTNode* compoundStatement)
{
	ASTNode* retNode = createDefaultNode("FunctionDefinition", 3);

	if (retNode)
	{
		retNode->links[0] = typeSpecifier;
		retNode->links[1] = params;
		retNode->links[2] = compoundStatement;
		if (functionName)
			strcpy(retNode->extraData, functionName);
	}

	return retNode;
}

ASTNode* createTypeSpecifier(const char* typeName)
{
	ASTNode* retVal = createDefaultNode("TypeSpecifier", 0);
	if (typeName)
		sprintf(retVal->extraData, "%s", typeName);
	return retVal;
}

ASTNode* createVarDeclaration(ASTNode* typeSpecifier, const char* varName, int value)
{
	ASTNode* retNode = createDefaultNode("VariableDeclaration", 2);

	if (retNode)
	{
		retNode->links[0] = typeSpecifier;
		if (varName)
			sprintf(retNode->extraData, "%s", varName);
		retNode->links[1] = createDefaultNode("IntValue", 0);
		sprintf(retNode->links[1]->extraData, "%d", value);
	}

	return retNode;
}

ASTNode* createCompoundStatement(ASTNode* localDeclList, ASTNode* statementList)
{
	ASTNode* retNode = createDefaultNode("CompoundStatement", 2);
	retNode->links[0] = localDeclList;
	retNode->links[1] = statementList;
	return retNode;
}

ASTNode* createStatementNode(ASTNode* statementDeclaration)
{
	ASTNode* retNode = createDefaultNode("Statement", 1);
	retNode->links[0] = statementDeclaration;
	return retNode;
}

ASTNode* createExpressionStatement(ASTNode* expressionDeclaration)
{
	ASTNode* retNode = createDefaultNode("ExpressionStatement", 1);
	retNode->links[0] = expressionDeclaration;
	return retNode;
}

ASTNode* createReturnStatement(ASTNode* expressionDeclaration)
{
	ASTNode* retNode = createDefaultNode("ReturnStatement", 1);
	retNode->links[0] = expressionDeclaration;
	return retNode;
}

ASTNode* createExpressionNode(ASTNode* expressionDeclaration)
{
	ASTNode* retNode = createDefaultNode("Expression", 1);
	retNode->links[0] = expressionDeclaration;
	return retNode;
}

ASTNode* createParametersDeclarationNode(ASTNode* parametersDeclaration)
{
	ASTNode* retNode = createDefaultNode("Parameters", 1);
	retNode->links[0] = parametersDeclaration;
	return retNode;
}


void printAst(ASTNode* ast, int level)
{
	int idx = 0;
	if (ast)
	{
		for (idx = 0; idx < level; idx++)
		{
			printf(" ");
		}
		if (ast->type)
		{
			printf("%s ", ast->type);
		}
		if (ast->numLinks)
		{
			printf(" - %d - %s\n", ast->numLinks, ast->extraData);
		}
		else
		{
			printf(" - %s\n", ast->extraData);
		}
		for (idx = 0; idx < ast->numLinks; idx++)
		{

			printAst(ast->links[idx], level + 1);
		}
	}
}