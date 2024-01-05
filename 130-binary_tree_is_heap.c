#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
int get_balance(const binary_tree_t *tree);
size_t get_height(const binary_tree_t *tree);
int binary_is_perfect(const binary_tree_t *tree);
int is_perfect(const binary_tree_t *tree);
/**
 * get_height - get height of a tree
 * @tree: tree root
 * Return: height of a tree. 0 otherwise
 */
size_t get_height(const binary_tree_t *tree)
{
size_t l_h = 0, r_h = 0;
if (tree == NULL)
return (0);
else
{
if (tree->left == NULL && tree->right == NULL)
return (tree->parent != NULL);
if (tree)
{
l_h = tree->left ? 1 + get_height(tree->left) : 0;
r_h = tree->right ? 1 + get_height(tree->right) : 0;
}
return ((l_h > r_h) ? l_h : r_h);
}
}
/**
 * get_balance - calculates the balance of a tree
 * @tree: tree root
 * Return: the balance factor
 */
int get_balance(const binary_tree_t *tree)
{
int r_h = 0, l_h = 0, factor = 0;
if (tree)
{
l_h = ((int)get_height(tree->left));
r_h = ((int)get_height(tree->right));
factor = l_h - r_h;
}
return (factor);
}

/**
 * is_perfect - check if a tree is perfect
 * @tree: tree root
 * Return: 1 on success. 0 on failure
 */
int is_perfect(const binary_tree_t *tree)
{
int l_h = 0, r_h = 0;
if (tree->left && tree->right)
{
l_h = 1 + is_perfect(tree->left);
r_h = 1 + is_perfect(tree->right);
if (r_h == l_h && r_h != 0 && l_h != 0)
return (r_h);
return (0);
}
else if (!tree->left && !tree->right)
{
return (1);
}
else
{
return (0);
}
}
/**
 * binary_is_perfect - checkes if a binary tree is perfect
 * @tree: tree root
 * Return: 1 on success. 0 otherwise
 */
int binary_is_perfect(const binary_tree_t *tree)
{
int perfect = 0;
if (tree == NULL)
return (0);
else
{
perfect = is_perfect(tree);
if (perfect != 0)
return (1);
return (0);
}
}
/**
 * binary_tree_is_heap - check if a binary tree is heap
 * @tree: tree root
 * Return: 1 on success. 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
int factor;
if (tree == NULL)
return (0);
if (tree->left && tree->left->n > tree->n)
return (0);
if (tree->right && tree->right->n > tree->n)
return (0);
if (binary_is_perfect(tree))
return (1);
factor = get_balance(tree);
if (factor == 0)
{
return (binary_is_perfect(tree->left)
&& binary_tree_is_heap(tree->right));
}
if (factor == 1)
{
return (binary_tree_is_heap(tree->left)
&& binary_is_perfect(tree->right));
}
else
return (0);
}
