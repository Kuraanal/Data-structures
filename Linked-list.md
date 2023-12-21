# Singly Linked List in C

This C code provides a basic implementation of a singly linked list with various operations to manipulate the list.

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

### List
```c
typedef struct list
{
    struct node *head;
    struct node *tail;
    int length;
} list;
```

The `list` structure maintains the head and tail pointers of the linked list, along with the length of the list.

![Linked List](/images/Linked-List.png)
## Functions

### Initialization
```c
list *init_list();
```
- Initializes an empty linked list and returns a pointer to the list.

### Node Creation
```c
node *create_node(int value);
```
- Creates a new node with the specified value and returns a pointer to the new node.

### Search Operations
```c
node *list_find(list *list, int value);
node *list_before(list *list, int value);
```
- `list_find`: Searches for a node with the given value in the list and returns a pointer to that node.
- `list_before`: Searches for the node before the one with the given value and returns a pointer to that node.

### Print and Clear
```c
int list_print(list *list);
int list_clear(list *list);
```
- `list_print`: Prints the values of all nodes in the list.
- `list_clear`: Clears the entire list and frees the memory allocated for nodes.

### Deletion Operations
```c
int list_popstart(list *list);
int list_popend(list *list);
int list_remove(list *list, int value);
```
- `list_popstart`: Removes the first node from the list.
- `list_popend`: Removes the last node from the list.
- `list_remove`: Removes the node with the specified value from the list.

![Linked List - Remove functions](/images/Linked-List%20Remove.png)
### Insertion Operations
```c
int list_pushstart(list *list, int value);
int list_pushend(list *list, int value);
int list_insert_after(list *list, int value, int valueBefore);
int list_insert_before(list *list, int value, int valueAfter);
```
- `list_pushstart`: Inserts a new node with the given value at the beginning of the list.
- `list_pushend`: Inserts a new node with the given value at the end of the list.
- `list_insert_after`: Inserts a new node with the given value after the node with the specified value.
- `list_insert_before`: Inserts a new node with the given value before the node with the specified value.

![Linked List - Insert Functions](/images/Link-List%20Insert.png)
### Modification Operations
```c
int list_replace(list *list, int oldvalue, int newvalue);
int list_sort(list *list);
```
- `list_replace`: Replaces the first occurrence of a specific value with a new value in the list.
- `list_sort`: Sorts the list in ascending order based on the node values.