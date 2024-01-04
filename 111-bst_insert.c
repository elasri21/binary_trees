#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * bst_insert - insert a node in a bst
 * @tree: The root of the tree
 * @value: the data part of the node to be inserted
 * Return: The inserted node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
bst_t *act, *newnode;
if (tree == NULL)
return (NULL);
act = *tree;
if (act == NULL)
{
newnode = binary_tree_node(act, value);
if (newnode == NULL)
return (NULL);
return (*tree = newnode);
}
if (value < act->n)
{
if (act->left != NULL)
return (bst_insert(&act->left, value));
newnode = binary_tree_node(act, value);
if (newnode == NULL)
return (NULL);
return (act->left = newnode);
}
if (value > act->n)
{
if (act->right != NULL)
return (bst_insert(&act->right, value));
newnode = binary_tree_node(act, value);
if (newnode == NULL)
return (NULL);
return (act->right = newnode);
}
return (NULL);
}
