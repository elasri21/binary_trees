#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
unsigned char leaf(const binary_tree_t *node);
size_t get_depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect(const binary_tree_t *tree, size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);
/**
 * leaf - check if a leaf
 * @node: a node to be checked
 * Return: 1 on success. 0 otherwise
 */
unsigned char leaf(const binary_tree_t *node)
{
return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}
/**
 * get_depth - get the depth of a node
 * @tree: the tree
 * Return: the depth of the tree
 */
size_t get_depth(const binary_tree_t *tree)
{
return (tree->parent != NULL ? 1 + get_depth(tree->parent) : 0);
}
/**
 * get_leaf - get the leaf node
 * @tree: the tree
 * Return: 1 on success. 0 otherwise
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
if (leaf(tree) == 1)
return (tree);
return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}
/**
 * is_perfect - checks if a tree is perfect recursivly
 * @tree: the tree
 * @l_d: depth of the leaf
 * @level: the level
 * Return: 1 on success. 0 otherwise
 */
int is_perfect(const binary_tree_t *tree, size_t l_d, size_t level)
{
if (leaf(tree))
return (level == l_d ? 1 : 0);
if (tree->left == NULL || tree->right == NULL)
return (0);
return (is_perfect(tree->left, l_d, level + 1) &&
is_perfect(tree->right, l_d, level + 1));
}
/**
 * binary_tree_is_perfect - checks if a tree is perfect
 * @tree: the tree to be checked
 * Return: 1 on success.0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (is_perfect(tree, get_depth(get_leaf(tree)), 0));
}
