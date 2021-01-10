#include "Hash.h"
#include "SemanticAnalyzer.h"
#define MAX_NODE_TYPE 50
#define MAX_EXTRA_DATA 50

typedef struct astNode {
	char type[MAX_NODE_TYPE];
	int numLinks;
	char extraData[MAX_EXTRA_DATA];
	struct astNode** links;
}ASTNode;

HashTable* symbolsTable;

ASTNode* createDefaultNode(const char* nodeName, unsigned int linksCount);
ASTNode* resizeNodeLinks(ASTNode* nodeToResize, unsigned int newSize);
ASTNode* createListNode(const char* listName, ASTNode* firstLink);
void addLinkToList(ASTNode* listNode, ASTNode* linkToAdd);
ASTNode* createProgramUnitNode(ASTNode* declaration);
ASTNode* createDeclarationList(ASTNode* declarationList);
ASTNode* createDeclarationNode(ASTNode* varFunDeclaration);
ASTNode* createIfStatement(ASTNode* expression, ASTNode* thenStatement, ASTNode* elseStatement);
ASTNode* createWhileStatement(ASTNode* expression, ASTNode* statement);
ASTNode* createFunctionDeclarationNode(ASTNode* typeSpecifier, const char* functionName, ASTNode* params, ASTNode* compoundStatement);
ASTNode* createTypeSpecifier(const char* typeName);
ASTNode* createVarDeclaration(ASTNode* typeSpecifier, const char* varName, int value);
ASTNode* createCompoundStatement(ASTNode* localDeclList, ASTNode* statementList);
ASTNode* createStatementNode(ASTNode* statementDeclaration);
ASTNode* createExpressionStatement(ASTNode* expressionDeclaration);
ASTNode* createReturnStatement(ASTNode* expressionDeclaration);
ASTNode* createExpressionNode(ASTNode* expressionDeclaration);
ASTNode* createParametersDeclarationNode(ASTNode* parametersDeclaration);
ASTNode* createVarNode(const char* varName, ASTNode* expression);
ASTNode* createSimpleExpresion(ASTNode* additiveExpression, ASTNode* relop, ASTNode* additiveExpression2);
ASTNode* createAdditiveExpression(ASTNode* additiveExpression, ASTNode* addop, ASTNode* term);
ASTNode* createTerm(ASTNode* term, ASTNode* mulop, ASTNode* factor);
ASTNode* createNumNode(int value);
ASTNode* createCall(const char* varName, ASTNode* args);
ASTNode* createArgumentList(ASTNode* argsList, ASTNode* expressions);


void addSymbolsToTable(ASTNode* node, HashTable* table, char* contextName);
void buildSemanticAnalyzer(ASTNode* node, HashTable* table, char* contextName);

void printAst(ASTNode* ast, int level);

struct SymTableEntry buildASymTableEntry(const char *symbolName, Type dataType, SymbolType symbolType, IdentifierScope symbolScope, const char* contextName);
int checkSemanticAnalyzer(ASTNode* node, HashTable* table, char* contextName);
void createSemanticAnalyzer(ASTNode* node, HashTable* table, char* contextName);

void computeKey(char* returningKey, char elementName[MAX_EXTRA_DATA], char localContextName[MAX_SYMBOL_NAME]);