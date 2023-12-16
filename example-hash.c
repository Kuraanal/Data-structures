#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "src/hash.h"

#define MAX_WORD_LENGTH 25

int main(void)
{
    string_node* hash_table[HASH_TABLE_SIZE];


    init_table(hash_table);

    FILE* dict = fopen("dictionary-5000.txt", "r");

    if(dict == NULL)
        return 1;

    char line[MAX_WORD_LENGTH];

    while (fgets(line, MAX_WORD_LENGTH, dict))
    {
        line[strcspn(line, "\n")] = '\0';
        line[strcspn(line, "\r")] = '\0';

        hash_insert(hash_table, line);
    }
    
    fclose(dict);

    string_node* tmpnode= NULL;


    printf("searching \'from\'\n");
    tmpnode = hash_find(hash_table, "from");

    if(tmpnode != NULL)
        printf("found node with value: %s\n", tmpnode->word);
    else
        printf("Node not found\n");

    hash_print(hash_table);

    hash_free_table(hash_table);

    return 0;
}