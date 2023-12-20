#ifndef BSTREEDT

#define BSTREEDT

typedef struct tree_node
{
    int data;
    struct tree_node* left;
    struct tree_node* right;
} tree_node;

tree_node* bstree_create_node(int value);
tree_node* bstree_search(tree_node* root, int value);

int bstree_insert(tree_node* root, int value);
int bstree_delete(tree_node* root,int value); 

#endif