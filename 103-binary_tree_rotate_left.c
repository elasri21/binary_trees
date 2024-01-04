#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: the binary tree
 * Return: the new root after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
binary_tree_t *new_root, *tmp;
if (tree == NULL || tree->right == NULL)
return (NULL);
new_root = tree->right;
tmp = new_root->left;
new_root->left = tree;
tree->right = tmp;
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
