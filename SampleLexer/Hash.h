#pragma once
#include "SemanticAnalyzer.h"

typedef struct HashTable HashTable;
HashTable* create_table(int size);

typedef struct Ht_item Ht_item;
Ht_item* create_item(char* key, SymTableEntry* value);

void ht_insert(HashTable* table, char* key, SymTableEntry* value);
SymTableEntry* ht_search(HashTable* table, char* key);
void ht_delete(HashTable* table, char* key);

void print_search(HashTable* table, char* key);
void print_table(HashTable* table);

void free_item(Ht_item* item);
void free_table(HashTable* table);