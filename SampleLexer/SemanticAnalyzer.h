#pragma once
#define MAX_SYMBOL_NAME 255

typedef enum { Local = 0, Global } IdentifierScope;
typedef enum { TypeInteger, TypeVoid } Type;
typedef enum { Function = 0, VarDeclaration } SymbolType;

struct SymTableEntry {
	char symbolName[MAX_SYMBOL_NAME];
	Type dataType;
	SymbolType symbolType; //specifica daca este functie, variabila sau tip de date
	IdentifierScope symbolScope;
	char contextName[MAX_SYMBOL_NAME];
};
