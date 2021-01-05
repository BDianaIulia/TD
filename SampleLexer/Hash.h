#include "SemanticAnalyzer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashTable HashTable;
typedef struct Ht_item Ht_item;

Ht_item* create_item(char* key, struct SymTableEntry* value);

HashTable* create_table(int size);

//void free_item(Ht_item* item);
//
//void free_table(HashTable* table);
//
//void handle_collision(HashTable* table, unsigned long index, Ht_item* item);
//
void ht_insert(HashTable* table, char* key, struct SymTableEntry* value);
//
//SymTableEntry* ht_search(HashTable* table, char* key);
//
//void ht_delete(HashTable* table, char* key);
//
//void print_search(HashTable* table, char* key);
//
void print_table(HashTable* table);
