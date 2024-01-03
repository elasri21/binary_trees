#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_height - calculates the height of a tree
 * @tree: the tree to get its height
 * Return: the height of the tree 
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t l_h, r_h;
if (tree == NULL)
return (0);
l_h = 0;
r_h = 0;
l_h = tree->left ? 1 + binary_tree_height(tree->left) : 0;
r_h = tree->right ? 1 + binary_tree_height(tree->right) : 0;
return ((l_h > r_h) ? l_h : r_h);
}
