#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * tree_size - calculates the size of a tree
 * @tree: tree root
 * Return: size of the tree or 0 if tree is NULL;
 */
size_t tree_size(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (tree_size(tree->left) + tree_size(tree->right) + 1);
}
/**
 * is_complete - checks if tree is complete
 * @tree: tree root
 * @idx: index of the node
 * @children: number of children
 * Return: 1 on success. 0 otherwise
 */
int is_complete(const binary_tree_t *tree, int idx, int children)
{
if (tree == NULL)
return (1);
if (idx >= children)
return (0);
return (is_complete(tree->left, (2 * idx) + 1, children) &&
is_complete(tree->right, (2 * idx) + 2, children));
}
/**
 * binary_is_complete - checks if a binary tree is complete
 * @tree: tree root
 * Return: 1 on success. 0 otherwise
 */
int binary_is_complete(const binary_tree_t *tree)
{
size_t children;
if (tree == NULL)
return (0);
children = tree_size(tree);
return (is_complete(tree, 0, children));
}

/**
 * is_parent - checks if a node is parent
 * @tree: tree root
 * Return: 1 on success. 0 otherwise
 */
int is_parent(const binary_tree_t *tree)
{
if (tree == NULL)
return (1);
if (tree->n > tree->parent->n)
return (0);
return (is_parent(tree->left) && is_parent(tree->right));
}
/**
 * binary_tree_is_heap - checks if a tree is heap
 * @tree: tree root
 * Return: 1 on success. 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
if (!binary_is_complete(tree))
return (0);
return (is_parent(tree->left) && is_parent(tree->right));
}
