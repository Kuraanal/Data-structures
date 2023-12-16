#include <string.h>
#include <stdlib.h>
#include "hash.h"

unsigned int hash_word(char* string)
{
    unsigned int sum = 0;

    for(int i =0; i < strlen(string); i++)
    {
        sum += ((string[i]) * 67);
    }
    sum *= 277;
    sum = sum % HASH_TABLE_SIZE;

    return sum;
}

void init_table(string_node** hash_table)
{
    for(int i =0; i < HASH_TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
    return;
}

string_node* create_node(char* word)
{
    string_node* node = malloc(sizeof(string_node));

    node->word = strdup(word);;
    node->next = NULL;

    return node;
}

int hash_insert(string_node** table, char* word)
{
    char* tmpstring = strdup(word);

    string_node* tmpnode = hash_find(table, tmpstring);

    free(tmpstring);

    if(tmpnode != NULL)
        return 0;

    unsigned int hash_value = hash_word(word);


    string_node* node = create_node(word);

    if(node == NULL)
        return 0;

    if(table[hash_value] == NULL)
        table[hash_value] = node;
    else
    {

        node->next = table[hash_value];
        table[hash_value] = node;
    }

    return 1;
}

string_node* hash_find(string_node** table, char* value)
{
    unsigned int hash_value = hash_word(value);

    string_node* tmpnode = table[hash_value];

    while(tmpnode != NULL)
    {
        if(strcmp(tmpnode->word, value) == 0)
            return tmpnode;
        
        tmpnode = tmpnode->next;
    }
    
    return NULL;
}

void hash_print(string_node **table)
{
    for(int i =0; i < HASH_TABLE_SIZE; i++)
    {
        printf("%i\t| ", i);

        if(table[i] == NULL)
        {
            printf("---\n");
            continue;
        }
        // else
        // {
            string_node* tmpnode = table[i];

            while (tmpnode != NULL)
            {
                printf("%s-> ", tmpnode->word);
                tmpnode = tmpnode->next;
            }
        // }
        printf("\n");
    }
}

int hash_free_node(string_node* node)
{
    free(node->word);
    free(node);

    return 1;
}

int hash_free_table(string_node** table)
{
    string_node* tmpnode;

    for(int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        if(table[i] == NULL)
            continue;

        while (table[i] != NULL) 
        {
            tmpnode = table[i];
            table[i] = table[i]->next;
            hash_free_node(tmpnode);
        }
    }

    return 1;
}