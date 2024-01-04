#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * sibling - get the sibling
 * @node: the node to get its sibling
 * Return: the sibling of the node
 */
binary_tree_t *sibling(binary_tree_t *node)
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
/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: the node that is looking for its uncle
 * Return: the uncle is found. NULL otherwise
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
binary_tree_t *parent, *uncle;
if (node == NULL)
return (NULL);
parent = node->parent;
uncle = sibling(parent);
if (uncle == NULL)
return (NULL);
else
return (uncle);
}
