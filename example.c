#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "src/linked-list.h"

int main(void)
{
    struct list *mainList;
    mainList = init_list();

    srand( time( NULL ) );

    for (int i = 0; i < 10; i++)
    {
        int value = (i +1) * (rand() % 11);
        list_pushend(mainList, value);
    } // [x, x, x, ...]

    list_print(mainList);

    if(list_popend(mainList))
        printf("Successfully poped end node.\n");
    else
        printf("Error poping end node\n");

    list_print(mainList);

    if(list_popstart(mainList))
        printf("Successfully poped start node.\n");
    else
        printf("Error poping start node.\n");

    list_print(mainList);

    printf("Sorting list\n");
    list_sort(mainList);

    list_print(mainList);

    node *found = list_find(mainList, 20);

    if(found == NULL)
        printf("Node not found.\n");
    else
        printf("Found node with value %d. next node value is: %d\n", found->value, found->next->value);

    found = list_before(mainList, 20);

    if(found == NULL)
        printf("Node not found.\n");
    else
        printf("Found node before value %d. previous Node value is: %d\n", found->next->value, found->value);

    free(found);

    if(list_remove(mainList, 20) == 0)
        printf("Error removing 20.\n");
    else
        printf("Node with value 20 removed\n");

    if(list_replace(mainList, 25, 666))
        printf("Change value 25 to 666\n");
    else
        printf("Error changing value 25 to 666\n");

    list_print(mainList);

    list_clear(mainList);
    // []

    list_print(mainList);


    for (int i = 0; i < 5; i++)
    {
        list_pushstart(mainList, i);
    }
    // [4, 3, 2, 1, 0, ]


    list_print(mainList);

    if(list_insert_after(mainList, 50, 3))
        printf("Added 50 after value 3\n");
    else
        printf("Error adding 50 after node 3\n");

    if(list_insert_before(mainList, 60, 0))
        printf("Added 60 before 0\n");
    else
        printf("Error adding 60 before 0\n");

    list_print(mainList);

    list_clear(mainList);
    free(mainList);
    return 0;
}