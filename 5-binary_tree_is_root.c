#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_is_root - checks if a given node is the root
 * @node: node to be checked
 * Return: 1 on success. 0 otherewise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
if (node == NULL)
return (0);
if (node->parent == NULL)
return (1);
return (0);
}
