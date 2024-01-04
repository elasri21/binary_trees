#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_sibling - get the sibling of a node
 * @node: the node to get its sibling
 * Return: the sibling of the node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
binary_tree_t *parent, *left, *right;
if (node == NULL)
return (NULL);
parent = node->parent;
if (parent == NULL)
return (NULL);
left = parent->left;
right = parent->right;
if (left == NULL || right == NULL)
return (NULL);
if (node == left)
return (right);
else if (node == right)
return (left);
else
return (NULL);
}
