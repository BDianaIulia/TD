#include "AST.h"
#include "Hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define CAPACITY 50000 // Size of the Hash Table
#define GLOBAL "global"

//The hash function from djb2 algorithm 
unsigned long hash_function(char* str) {
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash % 1000;
}

typedef struct LinkedList LinkedList;
// Define the Linkedlist here
struct LinkedList {
	Ht_item* item;
	LinkedList* next;
};

// Define the Hash Table here
struct HashTable {
	// Contains an array of pointers
	// to items
	Ht_item** items;
	LinkedList** overflow_buckets;
	int size;
	int count;
};

// Define the Hash Table Item here
struct Ht_item {
	char* key;
	struct SymTableEntry* value;
};

static LinkedList* allocate_list() {
	// Allocates memory for a Linkedlist pointer
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	return list;
}

static LinkedList* linkedlist_insert(LinkedList* list, Ht_item* item) {
	// Inserts the item onto the Linked List
	if (!list) {
		LinkedList* head = allocate_list();
		head->item = item;
		head->next = NULL;
		list = head;
		return list;
	}

	else if (list->next == NULL) {
		LinkedList* node = allocate_list();
		node->item = item;
		node->next = NULL;
		list->next = node;
		return list;
	}

	LinkedList* temp = list;
	while (temp->next->next) {
		temp = temp->next;
	}

	LinkedList* node = allocate_list();
	node->item = item;
	node->next = NULL;
	temp->next = node;

	return list;
}

static Ht_item* linkedlist_remove(LinkedList* list) {
	// Removes the head from the linked list
	// and returns the item of the popped element
	if (!list)
		return NULL;
	if (!list->next)
		return NULL;
	LinkedList* node = list->next;
	LinkedList* temp = list;
	temp->next = NULL;
	list = node;
	Ht_item* it = NULL;
	memcpy(temp->item, it, sizeof(Ht_item));
	free(temp->item->key);
	free(temp->item->value);
	free(temp->item);
	free(temp);
	return it;
}

static void free_linkedlist(LinkedList* list) {
	LinkedList* temp = list;
	while (list) {
		temp = list;
		list = list->next;
		free(temp->item->key);
		free(temp->item->value);
		free(temp->item);
		free(temp);
	}
}

static LinkedList** create_overflow_buckets(HashTable* table) {
	// Create the overflow buckets; an array of linkedlists
	LinkedList** buckets = (LinkedList**)calloc(table->size, sizeof(LinkedList*));
	for (int i = 0; i < table->size; i++)
		buckets[i] = NULL;
	return buckets;
}

static void free_overflow_buckets(HashTable* table) {
	// Free all the overflow bucket lists
	LinkedList** buckets = table->overflow_buckets;
	for (int i = 0; i < table->size; i++)
		free_linkedlist(buckets[i]);
	free(buckets);
}


Ht_item* create_item(char* key, struct SymTableEntry* value) {
	// Creates a pointer to a new hash table item
	Ht_item* item = (Ht_item*)malloc(sizeof(Ht_item));
	item->key = (char*)malloc(strlen(key) + 1);
	strcpy(item->key, key);

	item->value = (struct SymTableEntry*)malloc(sizeof(struct SymTableEntry));
	memcpy(item->value, value, sizeof(struct SymTableEntry));

	return item;
}

HashTable* create_table(int size) {
	// Creates a new HashTable
	HashTable* table = (HashTable*)malloc(sizeof(HashTable));
	table->size = size;
	table->count = 0;
	table->items = (Ht_item**)calloc(table->size, sizeof(Ht_item*));
	for (int i = 0; i < table->size; i++)
		table->items[i] = NULL;
	table->overflow_buckets = create_overflow_buckets(table);

	return table;
}

void free_item(Ht_item* item) {
	// Frees an item
	free(item->key);
	free(item->value);
	free(item);
}

void free_table(HashTable* table) {
	// Frees the table
	for (int i = 0; i < table->size; i++) {
		Ht_item* item = table->items[i];
		if (item != NULL)
			free_item(item);
	}

	free_overflow_buckets(table);
	free(table->items);
	free(table);
}

void handle_collision(HashTable* table, unsigned long index, Ht_item* item) {
	LinkedList* head = table->overflow_buckets[index];

	if (head == NULL) {
		// We need to create the list
		head = allocate_list();
		head->item = item;
		table->overflow_buckets[index] = head;
		return;
	}
	else {
		// Insert to the list
		table->overflow_buckets[index] = linkedlist_insert(head, item);
		return;
	}
}

void ht_insert(HashTable* table, char* key, struct SymTableEntry* value) {
	// Create the item
	Ht_item* item = create_item(key, value);

	// Compute the index
	unsigned long index = hash_function(key);

	Ht_item* current_item = table->items[index];

	if (current_item == NULL) {
		// Key does not exist.
		if (table->count == table->size) {
			// Hash Table Full
			printf("Insert Error: Hash Table is full\n");
			// Remove the create item
			free_item(item);
			return;
		}

		// Insert directly
		table->items[index] = item;
		table->count++;
	}

	else {
		// Scenario 1: We only need to update value
		if (strcmp(current_item->key, key) == 0) {
			table->items[index]->value = value;
			return;
		}

		else {
			// Scenario 2: Collision
			handle_collision(table, index, item);
			return;
		}
	}
}

struct SymTableEntry* ht_search(HashTable* table, char* key) {
	// Searches the key in the hashtable
	// and returns NULL if it doesn't exist
	int index = hash_function(key);
	Ht_item* item = table->items[index];
	LinkedList* head = table->overflow_buckets[index];

	// Ensure that we move to items which are not NULL
	while (item != NULL) {
		if (strcmp(item->key, key) == 0)
			return item->value;
		if (head == NULL)
			return NULL;
		item = head->item;
		head = head->next;
	}
	return NULL;
}

void ht_delete(HashTable* table, char* key) {
	// Deletes an item from the table
	int index = hash_function(key);
	Ht_item* item = table->items[index];
	LinkedList* head = table->overflow_buckets[index];

	if (item == NULL) {
		// Does not exist. Return
		return;
	}
	else {
		if (head == NULL && strcmp(item->key, key) == 0) {
			// No collision chain. Remove the item
			// and set table index to NULL
			table->items[index] = NULL;
			free_item(item);
			table->count--;
			return;
		}
		else if (head != NULL) {
			// Collision Chain exists
			if (strcmp(item->key, key) == 0) {
				// Remove this item and set the head of the list
				// as the new item

				free_item(item);
				LinkedList* node = head;
				head = head->next;
				node->next = NULL;
				table->items[index] = create_item(node->item->key, node->item->value);
				free_linkedlist(node);
				table->overflow_buckets[index] = head;
				return;
			}

			LinkedList* curr = head;
			LinkedList* prev = NULL;

			while (curr) {
				if (strcmp(curr->item->key, key) == 0) {
					if (prev == NULL) {
						// First element of the chain. Remove the chain
						free_linkedlist(head);
						table->overflow_buckets[index] = NULL;
						return;
					}
					else {
						// This is somewhere in the chain
						prev->next = curr->next;
						curr->next = NULL;
						free_linkedlist(curr);
						table->overflow_buckets[index] = head;
						return;
					}
				}
				curr = curr->next;
				prev = curr;
			}

		}
	}
}

void print_search(HashTable* table, char* key) {
	struct SymTableEntry* val;
	if ((val = ht_search(table, key)) == NULL) {
		printf("%s does not exist\n", key);
		return;
	}
	else {
		printf("Key:%s, Value:%s\n", key, val);
	}
}

void printSymTableEntry(struct SymTableEntry* item)
{
	printf("\t{\n\tSymbol Name: %s, \n\tData type: %s, \n\tSymbol type: %s, \n\tSymbol scope: %s, \n\tContext name: %s \n\t}",
		item->symbolName, item->dataType == TypeInteger ? "INT" : "VOID" ,
		item->symbolType == Function ? "Function" : "Var declaration",
		item->symbolScope == Local ? "Local" : "Global",
		item->contextName);
}

void print_table(HashTable* table) {
	printf("\n-------------------\n");
	for (int i = 0; i < table->size; i++) {
		if (table->items[i]) {
			printf("Index:%d, Key:%s, Value:\n", i, table->items[i]->key);
			printSymTableEntry(table->items[i]->value);
			if (table->overflow_buckets[i]) {
				printf(" => Overflow Bucket => ");
				LinkedList* head = table->overflow_buckets[i];
				while (head) {
					printf("Key:%s, Value ", head->item->key);
					printSymTableEntry(head->item->value);
					head = head->next;
				}
			}
			printf("\n");
		}
	}
	printf("-------------------\n");
}

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

ASTNode* createDeclarationList(ASTNode* declarationList)
{
	ASTNode* retNode = createDefaultNode("DeclarationList", 1);
	if (retNode)
	{
		retNode->links[0] = declarationList;
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

ASTNode* createWhileStatement(ASTNode* expression, ASTNode* statement)
{
	ASTNode* retNode = createDefaultNode("WhileStatement", 2);
	retNode->links[0] = expression;
	retNode->links[1] = statement;
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

ASTNode* createVarNode(const char* varName, ASTNode* expression)
{
	ASTNode* retNode = createDefaultNode("Variable", 1);
	if (retNode)
	{
		sprintf(retNode->extraData, "%s", varName);
		retNode->links[0] = expression;
	}
	return retNode;
}

ASTNode* createSimpleExpresion(ASTNode* additiveExpression, ASTNode* relop, ASTNode* additiveExpression2)
{
	ASTNode* retNode = createDefaultNode("SimpleExpresion", 3);

	if (retNode)
	{
		retNode->links[0] = additiveExpression;
		retNode->links[1] = relop;
		retNode->links[2] = additiveExpression2;
	}

	return retNode;
}

ASTNode* createAdditiveExpression(ASTNode* additiveExpression, ASTNode* addop, ASTNode* term)
{
	ASTNode* retNode = createDefaultNode("AdditiveExpression", 3);

	if (retNode)
	{
		retNode->links[0] = additiveExpression;
		retNode->links[1] = addop;
		retNode->links[2] = term;
	}

	return retNode;
}

ASTNode* createTerm(ASTNode* term, ASTNode* mulop, ASTNode* factor)
{
	ASTNode* retNode = createDefaultNode("Term", 3);

	if (retNode)
	{
		retNode->links[0] = term;
		retNode->links[1] = mulop;
		retNode->links[2] = factor;
	}

	return retNode;
}

ASTNode* createNumNode(int value)
{
	ASTNode* retNode = createDefaultNode("Number", 0);
	sprintf(retNode->extraData, "%s", value);
	return retNode;
}

ASTNode* createCall(const char* varName, ASTNode* args)
{
	ASTNode* retNode = createDefaultNode("Call", 1);

	if (retNode)
	{
		retNode->links[0] = args;
		if (varName)
			sprintf(retNode->extraData, "%s", varName);
	}

	return retNode;
}

ASTNode* createArgumentList(ASTNode* argsList, ASTNode* expressions)
{
	ASTNode* retNode = createDefaultNode("ArgumentList", 2);

	if (retNode)
	{
		retNode->links[0] = argsList;
		retNode->links[1] = expressions;
	}

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

HashTable* createSymbolsTable(ASTNode* ast)
{
	HashTable* symbolsTable = create_table(1000);

	addSymbolsToTable(ast, symbolsTable, GLOBAL);
	print_table(symbolsTable);

	buildSemanticAnalyzer(ast, symbolsTable, GLOBAL);

	return symbolsTable;
}

void computeKey(char* returningKey, char elementName[MAX_EXTRA_DATA], char localContextName[MAX_SYMBOL_NAME])
{
	strcpy(returningKey, elementName);
	strcat(returningKey, localContextName);
}

void addSymbolsToTable(ASTNode* node, HashTable* table, char* contextName)
{
	char localContextName[MAX_SYMBOL_NAME];
	if (node != NULL && table != NULL)
	{
		sprintf(localContextName, "%s", contextName);
		if (!stricmp(node->type, "FunctionDefinition"))
		{
			Type dataType;
			if (!strcmp(node->links[0]->extraData, "INT"))
				dataType = TypeInteger;
			else
				dataType = TypeVoid;

			struct SymTableEntry ste = buildASymTableEntry(node->extraData, dataType, Function, Global, localContextName);
			char key[2*MAX_EXTRA_DATA];
			computeKey(key, node->extraData, localContextName);
			
			//if is already declared
			if (ht_search(table, key) != NULL)
			{
				printf("\n\n ! The %s is already declared.", !stricmp(node->type, "FunctionDefinition") ? "function" : "variable");
				printf("\n Identifier %s: redefinition.", node->extraData);
			}
			else
				ht_insert(table, key, &ste);

			sprintf(localContextName, "%s", node->extraData);
		}
		else if (!stricmp(node->type, "VariableDeclaration"))
		{
			Type dataType;
			if (!strcmp(node->links[0]->extraData, "INT"))
				dataType = TypeInteger;
			else
				dataType = TypeVoid;

			IdentifierScope idenfScope = Global;
			if (strcmp(localContextName, GLOBAL))
				idenfScope = Local;

			struct SymTableEntry ste = buildASymTableEntry(node->extraData, dataType, VarDeclaration, idenfScope, localContextName);
			char key[2 * MAX_EXTRA_DATA];
			computeKey(key, node->extraData, localContextName);

			//if is already declared
			if (ht_search(table, key) != NULL)
			{
				printf("\n\n ! The %s is already declared.", !stricmp(node->type, "FunctionDefinition") ? "function" : "variable");
				printf("\n Identifier %s: redefinition.", node->extraData);
			}
			else
				ht_insert(table, key, &ste);
		}

		for (int i = 0; i < node->numLinks; i++)
		{
			addSymbolsToTable(node->links[i], table, localContextName);
		}
	}
}

void buildSemanticAnalyzer(ASTNode* node, HashTable* table, char* contextName)
{
	char localContextName[MAX_SYMBOL_NAME];
	if (node != NULL && table != NULL)
	{
		sprintf(localContextName, "%s", contextName);
		if (!stricmp(node->type, "FunctionDefinition"))
		{
			sprintf(localContextName, "%s", node->extraData);
		}
		else
		{
			checkSemanticAnalyzer(node, table, localContextName);
		}

		for (int i = 0; i < node->numLinks; i++)
		{
			buildSemanticAnalyzer(node->links[i], table, localContextName);
		}
	}
}

int checkSemanticAnalyzer(ASTNode* node, HashTable* table, char* contextName)
{
	if (node != NULL)
	{
		char localContextName[MAX_SYMBOL_NAME];
		sprintf(localContextName, "%s", contextName);

		//check if variable is defined
		if (!stricmp(node->type, "Variable") || !stricmp(node->type, "Call"))
		{
			if (!stricmp(node->type, "Call"))
				sprintf(localContextName, "%s", GLOBAL);

			char key[2 * MAX_EXTRA_DATA];
			computeKey(key, node->extraData, localContextName);

			if (ht_search(table, key) == NULL)
			{
				printf("\n\n ! The %s should be declared.", !stricmp(node->type, "Variable") ? "variable" : "function");
				printf("\n Identifier %s is undefined.", node->extraData);
				return 0;
			}
		}
		else if (!stricmp(node->type, "Expression"))
		{
			if (node->links != NULL && !stricmp(node->links[0]->type, "Call"))
			{
				if (node->numLinks < 2)
					return 1;
				char key[2 * MAX_EXTRA_DATA];
				computeKey(key, node->links[0]->extraData, GLOBAL);

				struct SymTableEntry* element = ht_search(table, key);

				char key2[2 * MAX_EXTRA_DATA];
				computeKey(key2, node->links[1]->extraData, localContextName);

				struct SymTableEntry* element2 = ht_search(table, key2);
				if (element != NULL && element2 != NULL)
				{
					if (element->dataType != element2->dataType) {
						printf("\n\n A returning value of %s cannot be used to initialize an entity of type %s.", element->dataType == TypeInteger ? "INT" : "VOID" , element2->dataType == TypeInteger ? "INT" : "VOID");
						printf("\n Returning value of function %s cannot be assigned to %s", node->links[0]->extraData, node->links[1]->extraData);
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

struct SymTableEntry buildASymTableEntry(const char *symbolName, Type dataType, SymbolType symbolType, IdentifierScope symbolScope, const char* contextName)
{
	struct SymTableEntry symTableEntry;
	strcpy(symTableEntry.symbolName, symbolName);
	symTableEntry.dataType = dataType;
	symTableEntry.symbolType = symbolType;
	symTableEntry.symbolScope = symbolScope;
	strcpy(symTableEntry.contextName, contextName);

	return symTableEntry;
}