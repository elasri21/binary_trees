#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"
/**
 * is_bst - checks if a tree is bst recursively
 * @tree: the binary tree to be checked
 * @lowest: the lowest node
 * @highest: the highest node
 * Return: 1 on success. 0 onfailure
 */
int is_bst(const binary_tree_t *tree, int lowest, int highest)
{
if (tree != NULL)
{
if (tree->n < lowest || tree->n > highest)
return (0);
return (is_bst(tree->left, lowest, tree->n - 1) &&
is_bst(tree->right, tree->n + 1, highest));
}
return (1);
}
/**
 * binary_tree_is_bst - checks if a binary tree is bst
 * @tree: tree to be checked
 * Return: 1 on success. 0 on failure
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (is_bst(tree, INT_MIN, INT_MAX));
}
