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
node = binary_tree_node(parent, value);
if (node == NULL)
return (NULL);
if (parent->left != NULL)
{
node->left = parent->left;
parent->left->parent = node;
}
parent->left = node;
return (node);
}
