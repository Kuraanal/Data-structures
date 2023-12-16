#ifndef HASHDT
#define HASHDT

#include <stdio.h>

#define HASH_TABLE_SIZE 256
#define MAX_NAME_SIZE 45

typedef struct string_node
{
    char* word;
    struct string_node *next;
} string_node;

void init_table(string_node** hash_table);
string_node* create_node(char* word);

unsigned int hash_word(char* string);
int hash_insert(string_node** table, char* word);
int hash_delete(string_node** table, char* word);

void hash_print(string_node** table);
string_node* hash_find(string_node** table, char* value);

int hash_free_node(string_node* node);
int hash_free_table(string_node** table);

#endif