#ifndef LINKEDLISTDT

#define LINKEDLISTDT
typedef struct node
{
    int value;
    struct node *next;
} node;

typedef struct list
{
    struct node *head;
    struct node *tail;
    int length;
} list;

list *init_list(); 
node *create_node(int value); 

node *list_find(list *list, int value); 
node *list_before(list *list, int value); 

int list_print(list *list);
int list_clear(list *list); 

int list_popstart(list *list); 
int list_popend(list *list); 
int list_remove(list *list, int value); 

int list_pushstart(list *list, int value); 
int list_pushend(list *list, int value); 
int list_insert_after(list *list, int value, int valueBefore); 
int list_insert_before(list *list, int value, int valueAfter); 

int list_replace(list *list, int oldvalue, int newvalue); 
int list_sort(list *list);

#endif