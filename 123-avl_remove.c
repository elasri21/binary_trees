#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
void get_balance(avl_t **tree);
int min_node(bst_t *tree);
int del_node(bst_t *tree);
bst_t *del_bst(bst_t *tree, int value);
/**
 * get_balance - get balance of a tree
 * @tree: the avl tree
 * Return: tree's balanc factor
 */
void get_balance(avl_t **tree)
{
int factor;
if (tree == NULL || *tree == NULL)
return;
if ((*tree)->left == NULL && (*tree)->right == NULL)
return;
get_balance(&(*tree)->left);
get_balance(&(*tree)->right);
factor = binary_tree_balance((const binary_tree_t *)*tree);
if (factor > 1)
*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
else if (factor < -1)
*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * min_node - get the min node from the tree
 * @tree: avl tree
 * Return: min node of the tree
 */
int min_node(bst_t *tree)
{
int data = 0;
if (tree == NULL)
return (0);
else
{
data = min_node(tree->left);
if (data == 0)
return (tree->n);
return (data);
}
}
/**
 *del_node - removes a node froma tree
 *@tree: tree node to be removed
 *Return: data part of min node or 0
 */
int del_node(bst_t *tree)
{
int children = 0;
if (!tree->left && !tree->right)
{
if (tree->parent->right == tree)
tree->parent->right = NULL;
else
tree->parent->left = NULL;
free(tree);
return (0);
}
else if ((!tree->left && tree->right) || (!tree->right && tree->left))
	{
if (!tree->left)
{
if (tree->parent->right == tree)
tree->parent->right = tree->right;
else
tree->parent->left = tree->right;
tree->right->parent = tree->parent;
}
if (!tree->right)
{
if (tree->parent->right == tree)
tree->parent->right = tree->left;
else
tree->parent->left = tree->left;
tree->left->parent = tree->parent;
}
free(tree);
return (0);
}
else
{
children = min_node(tree->right);
tree->n = children;
return (children);
}
}
/**
 * del_bst - deletes a node from bst
 * @tree: tree root
 * @value: data part of node to be deleted
 * Return: new root of the tree after deletion
 */
bst_t *del_bst(bst_t *tree, int value)
{
int children = 0;
if (tree == NULL)
return (NULL);
if (value < tree->n)
del_bst(tree->left, value);
else if (value > tree->n)
del_bst(tree->right, value);
else if (value == tree->n)
{
children = del_node(tree);
if (children != 0)
del_bst(tree->right, children);
}
else
return (NULL);
return (tree);
}

/**
 * avl_remove - deletes a node from a AVL tree
 * @root: tree root
 * @value: data part of the node to be removed
 * Return: new root of the tree after deletion
 */
avl_t *avl_remove(avl_t *root, int value)
{
avl_t *newroot = (avl_t *) del_bst((bst_t *) root, value);
if (newroot == NULL)
return (NULL);
get_balance(&newroot);
return (newroot);
}
