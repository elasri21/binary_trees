#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_depth - calculates the depth of a tree
 * @tree: the tree to calculate its depth
 * Return: the depth of a tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
size_t depth = 0;
binary_tree_t *tmp;
if (tree == NULL)
return (0);
tmp = tree->parent;
while (tmp != NULL)
{
depth++;
tmp = tmp->parent;
}
return (depth);
}
