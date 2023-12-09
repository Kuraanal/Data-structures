#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack *init_stack()
{
    stack *newStack = malloc(sizeof(stack));

    if(newStack == NULL)
        return NULL;

    newStack->head = NULL;
    newStack->size = 0;

    return newStack;
}

int stack_push(stack *stack, int value)
{
    node *newnode = create_node(value);

    if(newnode == NULL)
        return 0;

    stack->size++;

    if(stack->head == NULL)
    {
        stack->head = newnode;
        return 1;
    }

    newnode->next = stack->head;
    stack->head = newnode;

    return 1;
}

int stack_pop(stack *stack)
{
    if(stack->head == NULL)
        return 0;

    node *tmpnode = stack->head;
    int value = tmpnode->value;
    
    stack->head = tmpnode->next;
    free(tmpnode);
    stack->size--;

    return value;
}