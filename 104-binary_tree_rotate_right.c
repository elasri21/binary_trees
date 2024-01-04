#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: the binary tree
 * Return: the new root after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
binary_tree_t *new_root, *tmp;
if (tree == NULL || tree->left == NULL)
return (NULL);
new_root = tree->left;
tmp = new_root->right;
new_root->right = tree;
tree->left = tmp;
if (tmp != NULL)
tmp->parent = tree;
tmp = tree->parent;
tree->parent = new_root;
new_root->parent = tmp;
if (tmp != NULL)
{
if (tmp->left == tree)
tmp->left = new_root;
else
tmp->right = new_root;
}
return (new_root);
}
