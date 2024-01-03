#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_leaves - calculates the number of leaves in a tree
 * @tree: the tree to calculate its leaves
 * Return: the number of leaves in a tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
size_t leaves = 0;
if (tree == NULL)
return (0);
if (tree->left != NULL && !tree->left->left && !tree->left->right)
{
leaves += 1;
binary_tree_leaves(tree->left);
}
if (tree->right != NULL && !tree->right->left && !tree->right->right)
{
leaves += 1;
binary_tree_leaves(tree->right);
}
return (leaves);
}
