#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "src/stack.h"


int main(void)
{
    stack *mainStack;
    mainStack = init_stack();

    srand( time( NULL ) );

    for (int i = 0; i < 10; i++)
    {
        int value = (i +1) * (rand() % 11);
        stack_push(mainStack, value);
    }

    printf("Stack size: %d\n", mainStack->size);

    if(mainStack->head == NULL)
        printf("Stack is empty\n");
    else
        printf("peeking: %d\n", mainStack->head->value);

    while(mainStack->head != NULL)
    {
        printf("Poped %d\n", stack_pop(mainStack));
    }

    if(mainStack->head == NULL)
        printf("Stack is empty\n");
    else
        printf("peeking: %d\n", mainStack->head->value);

    printf("Stack size: %d\n", mainStack->size);

    free(mainStack);

    return 0;

}