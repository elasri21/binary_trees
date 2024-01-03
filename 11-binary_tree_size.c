#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_size - calculates the size of a tree
 * @tree: the tree root
 * Return: the size of a tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
size_t t_s = 0;
if (tree == NULL)
return (0);
t_s += 1;
t_s += binary_tree_size(tree->left);
t_s +=  binary_tree_size(tree->right);
return (t_s);
}
