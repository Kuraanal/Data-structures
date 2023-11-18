

typedef struct node{
    int value;
    struct node *next;
} node;

typedef struct list
{
    struct node *head;
    struct node *tail;
    struct node *current;
    int length;
} list;

//
int list_clear(list *list);

//
int list_insertAt(int index, list *list, node *node);

//
int list_removeAt(int index, list *list);

//
int list_reverse(list *list);

//
int list_sort(list *list);

//
int list_print(list *list);

//
int list_add(list *list, node *node);

//
int list_find(list *list, int value);

//
list *init_list(void);
