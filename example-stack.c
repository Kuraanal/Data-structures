#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "src/stack.h"

#define NODE_NUMBER 20

int main(void)
{
    stack *mainStack;
    mainStack = init_stack();

    printf("Stack size: %d\n", mainStack->size);

    if(mainStack->head == NULL)
        printf("Stack is empty\n");
    else
        printf("peeking: %d\n", mainStack->head->value);
        
    srand( time( NULL ) );

    for (int i = 0; i < NODE_NUMBER; i++)
    {
        int value = (i +1) * (rand() % NODE_NUMBER);
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