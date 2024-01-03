#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree node
 * @parent: parent of the new node
 * @value: the data part of the node
 * Return: the niew node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
if (node == NULL)
return (NULL);
node->n = value;
node->left = NULL;
node->right = NULL;
node->parent = parent;
return (node);
}
