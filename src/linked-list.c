#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

list *init_list()
{
    list *list = malloc(sizeof(list));

    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

node *create_node(int value)
{
    node *newnode = malloc(sizeof(node));

    if(newnode == NULL)
        return NULL;

    newnode->value = value;
    newnode->next = NULL;

    return newnode;
}

node *list_find(list *list, int value)
{
    if( list->head == NULL)
        return NULL;

    if(value == list->tail->value)
        return list->tail;

    if(value == list->head->value)
        return list->head;

    node *tmp = list->head;

    while (tmp->next != NULL)
    {
        if (tmp->value != value)
        {
            tmp = tmp->next;
            continue;
        }

        return tmp;
    }

    return NULL;
}

node *list_before(list *list, int value)
{
    if( list->head == NULL)
        return NULL;
    
    // if value is first return null
    if(list->head->value == value)
        return NULL;

    node *tmp = list->head;

    while (tmp->next != NULL)
    {
        if (tmp->next->value != value)
        {
            tmp = tmp->next;
            continue;
        }

        return tmp;
    }

    return NULL;
}

int list_clear(list *list)
{
   while (list->head != NULL)
   {
        node *tmp = list->head;
        list->head = list->head->next;
        free(tmp);

        if(list->tail == list->head)
            list->tail = list->head;
   }

    list->length = 0;

   return 1;
}

int list_print(list *list)
{
    node *tmp = list->head;

    printf("[");

    if (list->head != NULL)
    {
        while (1)
        {
            printf("%d, ", tmp->value);

            if (tmp == list->tail)
                break;

            tmp = tmp->next;
        }
    }

    printf("]\n");

    return 1;
}

int list_popstart(list *list)
{
    if(list->head == NULL)
        return 0;

    node *tmp = list->head;

    list->head = tmp->next;
    free(tmp);
    list->length--;

    return 1;
}

int list_popend(list *list)
{
    if( list->head == NULL)
        return 0;

    node *tmp = list->head;

    while (tmp->next !=  NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = NULL;
    free(list->tail);
    list->tail = tmp;

    list->length--;
}

int list_remove(list *list, int value)
{
    if(list->head == NULL)
        return 0;

    node *tmpbefore = list_before(list, value);

    if(tmpbefore == NULL)
        return 0;

    node *tmpremove = tmpbefore->next;

    if(tmpremove->next == NULL) // is tail
    {
        list->tail = tmpbefore;
        free(tmpremove);
    }
    else
    {
        tmpbefore->next = tmpremove->next;
        free(tmpremove);
    }

    list->length--;
}

int list_pushstart(list *list, int value)
{
    node *tmp = create_node(value);

    if(list->head == NULL)
    {
        list->head = tmp;
        list->tail = tmp;
        list->length++;

        return 1;
    }

    tmp->next = list->head;
    list->head = tmp;
    list->length++;

    return 1;
}

int list_pushend(list *list, int value)
{
    node *tmp = create_node(value);

    if(tmp == NULL)
        return 0;

    if(list->head == NULL)
    {
        list_pushstart(list, value);
        return 1;
    }

    list->tail->next = tmp;
    list->tail = tmp;

    list->length++;

    return 1;
}

int list_insert_after(list *list, int value, int valueBefore)
{
    if(list->head == NULL)
        return 0;

    if(valueBefore == list->tail->value)
    {
        list_pushend(list, value);
        return 1;
    }

    node *tmpbefore = list_find(list, valueBefore);

    if(tmpbefore == NULL)
        return 0;

    node *tmpnode = create_node(value);

    if(tmpnode == NULL)
        return 0;

    tmpnode->next = tmpbefore->next;
    tmpbefore->next = tmpnode;
    list->length++;

    return 1;
}

int list_insert_before(list *list, int value, int valueAfter)
{
    if(list->head == NULL)
        return 0;

    if(valueAfter == list->head->value)
    {
        list_pushstart(list, value);
        return 1;
    }

    node *tmpAfter = list_before(list, valueAfter);

    if(tmpAfter == NULL)
        return 0;

    node *tmpnode = create_node(value);

    if(tmpnode == NULL)
        return 0;

    tmpnode->next = tmpAfter->next;
    tmpAfter->next = tmpnode;
    list->length++;

    return 1;
}

int list_replace(list *list, int oldvalue, int newvalue)
{
    if(list->head == NULL)
        return 0;

    node *tmp = list_find(list, oldvalue);

    if(tmp == NULL)
        return 0;

    tmp->value = newvalue;
    return 1;
}