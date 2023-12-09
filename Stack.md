# Stack in C

This C code provides a basic implementation of a Stack with minimum operations to operate it.

## Data Structures

### Node
```c
typedef struct node
{
    int value;
    struct node *next;
} node;
```
The `node` structure represents a node in the linked list. It contains an integer value and a pointer to the next node in the list.

### Stack
```c
typedef struct stack
{
    node *head;
    int size;
} stack;
```
The `stack` structure maintains the head pointer of the linked list and the size of the stack.

## Functions

### Initialization
```c
stack *init_stack();
```
- Initializes an empty stack and returns a pointer to the stack.

### Push Operation
```c
int stack_push(stack *stack, int value);
```
- Pushes a new element with the given value onto the top of the stack.

### Pop Operation
```c
int stack_pop(stack *stack);
```
- Pops the element from the top of the stack and returns its value.