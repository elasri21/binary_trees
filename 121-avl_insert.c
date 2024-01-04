#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
size_t get_height(const binary_tree_t *tree);
int tree_balancer(const binary_tree_t *tree);
avl_t *avl_insert_hepler(avl_t **tree, avl_t *parent,
avl_t **newnode, int value);
/**
 * get_height - gets the height of a node
 * @tree: node to get its height
 * Return: the height of the node passed as arg
 */
size_t get_height(const binary_tree_t *tree)
{
if (tree != NULL)
{
size_t l_h = 0, r_h = 0;
l_h = tree->left ? 1 + get_height(tree->left) : 1;
r_h = tree->right ? 1 + get_height(tree->right) : 1;
return ((l_h > r_h) ? l_h : r_h);
}
return (0);
}

/**
 * tree_balancer - calculates the balance of a avl
 * @tree: tree root
 * Return: the balance factor of the tree
 */
int tree_balancer(const binary_tree_t *tree)
{
return (tree != NULL ? get_height(tree->left) - get_height(tree->right) : 0);
}
/**
 * avl_insert_helper - helps to insert in a avl
 * @tree: root of avl
 * @parent: parent of node to be inserted
 * @newnode: node to be inserted
 * @value: value to be stored at the newnode
 * Return: the new root after inserting and balancing
 */
avl_t *avl_insert_hepler(avl_t **tree, avl_t *parent,
avl_t **newnode, int value)
{
int factor;
if (*tree == NULL)
return (*newnode = binary_tree_node(parent, value));
if ((*tree)->n > value)
{
(*tree)->left = avl_insert_hepler(&(*tree)->left, *tree, newnode, value);
if ((*tree)->left == NULL)
return (NULL);
}
else if ((*tree)->n < value)
{
(*tree)->right = avl_insert_hepler(&(*tree)->right, *tree, newnode, value);
if ((*tree)->right == NULL)
return (NULL);
}
else
return (*tree);
factor = tree_balancer(*tree);
if (factor > 1 && (*tree)->left->n > value)
*tree = binary_tree_rotate_right(*tree);
else if (factor < -1 && (*tree)->right->n < value)
*tree = binary_tree_rotate_left(*tree);
else if (factor > 1 && (*tree)->left->n < value)
{
(*tree)->left = binary_tree_rotate_left((*tree)->left);
*tree = binary_tree_rotate_right(*tree);
}
else if (factor < -1 && (*tree)->right->n > value)
{
(*tree)->right = binary_tree_rotate_right((*tree)->right);
*tree = binary_tree_rotate_left(*tree);
}
return (*tree);
}
/**
 * avl_insert - inserts a node in a avl
 * @tree: root of avl
 * @value: Tvalue of the node to be inserted
 * Return: inserted node. NULL if failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
avl_t *newnode = NULL;
if (tree == NULL)
return (NULL);
if (*tree == NULL)
{
*tree = binary_tree_node(NULL, value);
return (*tree);
}
avl_insert_hepler(tree, *tree, &newnode, value);
return (newnode);
}
