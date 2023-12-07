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

    list_sort(mainList);

    list_print(mainList);

    list_clear(mainList);
    // []

    for (int i = 0; i < 5; i++)
    {
        list_pushstart(mainList, i);
    }
    // [4, 3, 2, 1, 0, ]

    list_print(mainList);

    return 0;
}