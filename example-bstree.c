#include <stdio.h>
#include "src/bstree.h"

int main(void)
{

tree_node* root = bstree_create_node(5);

printf("root\ndata: %d\nleft: %p\tright: %p\n", root->data, root->left, root->right);

bstree_insert(root, 10);
bstree_insert(root, 8);
bstree_insert(root, 1);
bstree_insert(root, 3);
bstree_insert(root, 2);
bstree_insert(root, 12);

tree_node* search = bstree_search(root, 13);

if(search != NULL)
    printf("found node\ndata: %d\nleft: %p\tright: %p\n", search->data, search->left, search->right);
else
    printf("data not found\n");


return 0;
}