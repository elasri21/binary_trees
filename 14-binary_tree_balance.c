#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * tree_height - calculates the height of a tree
 * @tree: the binary tree
 * Return: the height of a tree
 */
int tree_height(const binary_tree_t *tree)
{
int l_h = 0, r_h = 0;
if (tree == NULL)
return (0);
l_h = tree->left ? 1 + tree_height(tree->left) : 1;
r_h = tree->right ? 1 + tree_height(tree->right) : 1;
return ((l_h > r_h) ? l_h : r_h);
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: the binary tree
 * Return: the balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
int l_h, r_h;
if (tree == NULL)
return (0);
l_h = tree_height(tree->left);
r_h = tree_height(tree->right);
return (l_h - r_h);
}
