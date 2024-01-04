#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
bst_t *min_node(bst_t *tree);
bst_t *del_node(bst_t *tree, bst_t *node);
bst_t *bst_removal(bst_t *tree, bst_t *node, int value);
/**
 * min_node - gets the node with minimum value
 * @tree: bst root
 * Return: node with minimum value
 */
bst_t *min_node(bst_t *tree)
{
while (tree->left != NULL)
tree = tree->left;
return (tree);
}

/**
 * del_node - removes a node from a bst
 * @tree: bst root
 * @node: node to remove
 * Return: new root after deletion
 */
bst_t *del_node(bst_t *tree, bst_t *node)
{
bst_t *parent = node->parent, *successor = NULL;
if (node->left == NULL)
{
if (parent != NULL && parent->left == node)
parent->left = node->right;
else if (parent != NULL)
parent->right = node->right;
if (node->right != NULL)
node->right->parent = parent;
free(node);
return (parent == NULL ? node->right : tree);
}
if (node->right == NULL)
{
if (parent != NULL && parent->left == node)
parent->left = node->left;
else if (parent != NULL)
parent->right = node->left;
if (node->left != NULL)
node->left->parent = parent;
free(node);
return (parent == NULL ? node->left : tree);
}
successor = min_node(node->right);
node->n = successor->n;
return (del_node(tree, successor));
}

/**
 * bst_removal - removes a node from bst recurcively
 * @tree: bst root
 * @node: node to remove
 * @value: value contained in the node
 * Return: the new root after deletion
 */
bst_t *bst_removal(bst_t *tree, bst_t *node, int value)
{
if (node != NULL)
{
if (node->n == value)
return (del_node(tree, node));
if (node->n > value)
return (bst_removal(tree, node->left, value));
return (bst_removal(tree, node->right, value));
}
return (NULL);
}

/**
 * bst_remove - removes a bst node
 * @root: bst root
 * @value: value of the node to be removed
 * Return: new root after deletion
 */
bst_t *bst_remove(bst_t *root, int value)
{
return (bst_removal(root, root, value));
}
