#ifndef STACKDT

#define STACKDT

#include "linked-list.h"

typedef struct stack
{
    node *head;
    int size;
} stack;

stack *init_stack();
int stack_push(stack *stack, int value);
int stack_pop(stack *stack);

#endif