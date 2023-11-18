#include <stdio.h>
#include <stdlib.h>
#include "src/linked-list.h"

int main(void)
{
    struct list *mainList;

    mainList = init_list();

    struct node *one = malloc(sizeof(node));
    one->value = 25;
    one->next= NULL;

    struct node *two = malloc(sizeof(node));
    two->value = 12;
    two->next = NULL;

    struct node *three = malloc(sizeof(node));
    three->value = 75;
    three->next = NULL;

    struct node *four = malloc(sizeof(node));
    four->value = 125;
    four->next = NULL;

    list_print(mainList);

    for (int i =0; i < 15; i++)
    {
        node *newNode = malloc(sizeof(node));
        newNode->value = i;
        newNode->next = NULL;
        list_add(mainList, newNode);
    }

    list_print(mainList);

    list_add(mainList, one);
    list_add(mainList, two);
    list_add(mainList, three);

    list_print(mainList);


    list_insertAt(10, mainList, four);

    list_print(mainList);

    list_removeAt(12, mainList);
    
    list_print(mainList);
    
    int foundAt;
    foundAt = list_find(mainList, 125);
    printf("found at: %d\n", foundAt);


    list_clear(mainList);

    foundAt = list_find(mainList, 10);
    printf("not found: %d\n", foundAt);

    list_print(mainList);

    return 0;
}