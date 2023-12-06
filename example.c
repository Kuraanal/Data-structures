#include <stdio.h>
#include <stdlib.h>
#include "src/linked-list.h"

int main(void)
{
    struct list *mainList;
    mainList = init_list();

    for (int i = 0; i < 5; i++)
    {
        list_pushend(mainList, i);
    }
    // [0, 1, 2, 3, 4, ]

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