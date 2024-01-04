#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * is_full - checks if a tree is full recursively
 * @tree: the binary tree
 * Return: 1 on success. 0 otherwise
 */
int is_full(const binary_tree_t *tree)
{
if (tree != NULL)
{
if ((tree->left != NULL && tree->right == NULL) ||
(tree->left == NULL && tree->right != NULL) ||
is_full(tree->left) == 0 ||
is_full(tree->right) == 0)
return (0);
}
return (1);
}
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: the binary tree
 * Return: 1 on successs. 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (is_full(tree));
}
