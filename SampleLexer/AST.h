#define MAX_NODE_TYPE 50
#define MAX_EXTRA_DATA 50

typedef struct astNode {
	char type[MAX_NODE_TYPE];
	int numLinks;
	char extraData[MAX_EXTRA_DATA];
	struct astNode** links;
}ASTNode;

ASTNode* createDefaultNode(const char* nodeName, unsigned int linksCount);
ASTNode* resizeNodeLinks(ASTNode* nodeToResize, unsigned int newSize);
ASTNode* createListNode(const char* listName, ASTNode* firstLink);
void addLinkToList(ASTNode* listNode, ASTNode* linkToAdd);
ASTNode* createProgramUnitNode(ASTNode* declaration);
ASTNode* createDeclarationNode(ASTNode* varFunDeclaration);
ASTNode* createIfStatement(ASTNode* expression, ASTNode* thenStatement, ASTNode* elseStatement);
ASTNode* createFunctionDeclarationNode(ASTNode* typeSpecifier, const char* functionName, ASTNode* params, ASTNode* compoundStatement);
ASTNode* createTypeSpecifier(const char* typeName);
ASTNode* createVarDeclaration(ASTNode* typeSpecifier, const char* varName, int value);
ASTNode* createCompoundStatement(ASTNode* localDeclList, ASTNode* statementList);
ASTNode* createStatementNode(ASTNode* statementDeclaration);
ASTNode* createExpressionStatement(ASTNode* expressionDeclaration);
ASTNode* createReturnStatement(ASTNode* expressionDeclaration);
ASTNode* createExpressionNode(ASTNode* expressionDeclaration);
ASTNode* createParametersDeclarationNode(ASTNode* parametersDeclaration);

void printAst(ASTNode* ast, int level);