#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"
size_t get_height(const binary_tree_t *tree);
int is_avl(const binary_tree_t *tree, int lowest, int highest);
/**
 * get_height - gets the height of a node or a tree
 * @tree: node to get its height
 * Return: the height of a node
 */
size_t get_height(const binary_tree_t *tree)
{
if (tree)
{
size_t l_h = 0, r_h = 0;
l_h = tree->left ? 1 + get_height(tree->left) : 1;
r_h = tree->right ? 1 + get_height(tree->right) : 1;
return ((l_h > r_h) ? l_h : r_h);
}
return (0);
}
/**
 * is_avl - checks if a bst is avl recursively
 * @tree: root of the tree
 * @lowest: lowest value stored in a node
 * @highest: highest value stored in a node
 * Return: 1 on success. 0 on failure
 */
int is_avl(const binary_tree_t *tree, int lowest, int highest)
{
size_t l_h, r_h, sub;
if (tree != NULL)
{
if (tree->n < lowest || tree->n > highest)
return (0);
l_h = get_height(tree->left);
r_h = get_height(tree->right);
sub = l_h > r_h ? l_h - r_h : r_h - l_h;
if (sub > 1)
return (0);
return (is_avl(tree->left, lowest, tree->n - 1) &&
is_avl(tree->right, tree->n + 1, highest));
}
return (1);
}
/**
 * binary_tree_is_avl - checks if a bst is avl
 * @tree: root of the tree
 * Return: 1 on success.0 on failure
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (is_avl(tree, INT_MIN, INT_MAX));
}
