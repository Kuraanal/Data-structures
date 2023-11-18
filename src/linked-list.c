#include "linked-list.h"
#include <stdio.h>
#include <stdlib.h>

//
list *init_list()
{
    list *list = malloc(sizeof(list));

    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->current = list->head;
    list->tail = list->head;
    list->length = 0;

    return list;
}

//
int list_clear(list *list)
{
    do
    {
        if (list->head != NULL)
        {
            if (list->tail == list->head)
            {
                list->tail = NULL;
                list->current = NULL;
                list->head = NULL;
                break;
            }
            else if (list->current->next != list->tail)
            {
                list->current = list->current->next;
            }
            else
            {
                free(list->tail);

                list->tail = list->current;
                list->tail->next = NULL;
                list->current = list->head;
            }
        }
        else
        {
            break;
        }
    }
    while (1);

    list->tail = list->head;
    list->current = list->head;
    list->length = 0;
    return 1;
}

//
int list_insertAt(int index, list *list, node *node)
{
    if (list->head == NULL || list->length < index)
    {
        list_add(list, node);
        return 1;
    }

    if (index == 0)
    {
        node->next = list->head;
        list->head = node;
        list->current = list->head;
        return 1;
    }

    int counter = 0;
    list->current = list->head;

    while (counter < index - 1)
    {
        list->current = list->current->next;
        counter++;
    }

    node->next = list->current->next;
    list->current->next = node;

    list->length++;
    list->current = list->head;
    return 1;
}

//
int list_removeAt(int index, list *list)
{
    if (index > list->length || index < 0)
    {
        printf("index %i is out of bound\n", index);
        return 0;
    }

    int counter = 0;
    list->current = list->head;

    while (counter < index - 1)
    {
        list->current = list->current->next;
        counter++;
    }

    list->current->next = list->current->next->next;

    list->current = list->head;

    return 1;
}

//
int list_reverse(list *list)
{

    return 1;
}

//
int list_sort(list *list)
{

    return 1;
}

//
int list_print(list *list)
{
    printf("[");

    if (list->head != NULL)
    {
        do
        {
            printf("%i, ", list->current->value);

            if (list->current == list->tail)
            {
                break;
            }

            list->current = list->current->next;
        }
        while (1);
    }

    printf("]\n");

    list->current = list->head;
    return 1;
}

int list_add(list *list, node *node)
{
    if (list->head == NULL)
    {
        list->head = node;
        list->current = list->head;
        list->tail = list->head;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }

    list->length++;
    list->current = list->head;
    return 1;
}


int list_find(list *list, int value)
{
    int index = -1;

    if (list->head == NULL)
    {
        printf("List is empty\n");
        return index;
    }

    while (list->current->value != value)
    {
        list->current = list->current->next;
        index++;
    }

    if (index != -1)
    {
        index++;
    }

    list->current = list->head;
    return index;
}
