#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node at the left of the tree
 * @parent: the parent of the node to be inserted
 * @value: the data part of the node
 * Return: the node inserted. NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *node;
if (parent == NULL)
return (NULL);
node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
if (node == NULL)
return (NULL);
node->n = value;
node->right = NULL;
node->parent = parent;
if (parent->left != NULL)
{
node->left = binary_tree_insert_left(node, parent->left->n);
if (node->left == NULL)
return (NULL);
parent->left = node;
}
else
{
node->left = NULL;
parent->left = node;
}
return (node);
}
