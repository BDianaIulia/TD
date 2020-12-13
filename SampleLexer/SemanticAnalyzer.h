#pragma once
#define MAX_SYMBOL_NAME 255

typedef enum IdentifierScope { Local = 0, Global };
typedef enum { TYPE_INTEGER, TYPE_VOID } Type;

typedef struct symTableEntry {
	char symbolName[MAX_SYMBOL_NAME];
	Type dataType;
	int symbolType;
	IdentifierScope symbolScope;
	char contextName[MAX_SYMBOL_NAME];

}SymTableEntry;