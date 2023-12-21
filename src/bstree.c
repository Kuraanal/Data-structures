#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

tree_node* bstree_create_node(int value)
{
    tree_node* tmpnode = malloc(sizeof(tree_node));
    tmpnode->data = value;
    tmpnode->left = NULL;
    tmpnode->right = NULL;

    return tmpnode;
}

int bstree_insert(tree_node* root, int value)
{
    if(root == NULL)
    {
        root = bstree_create_node(value);
        return 1;
    }

    tree_node* tmpnode = root;

    while (tmpnode != NULL)
    {
        if(tmpnode->data > value)
        {
            if(tmpnode->left == NULL)
            {
                tmpnode->left = bstree_create_node(value);
                return 1;
            }

            tmpnode = tmpnode->left;
        }
        else
        {
            if(tmpnode->right == NULL)
            {
                tmpnode->right = bstree_create_node(value);
                return 1;
            }

            tmpnode = tmpnode->right;
        }
    }
    
    return 0;
}

tree_node* bstree_search(tree_node* root, int value)
{
    if(root == NULL)
        return NULL;

    tree_node* tmpnode = root;

    while (tmpnode != NULL) 
    {
        if(tmpnode->data == value)
            return tmpnode;

        if(tmpnode->data > value)
        {
            tmpnode = tmpnode->left;
        }
        else{
            tmpnode = tmpnode->right;
        }
    }
    
    return NULL;
}