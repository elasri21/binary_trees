#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * get_height - get the height of a tree
 * @tree: tree root
 * Return: height of the tree
 */
int get_height(const binary_tree_t *tree)
{
int l_h = 0, r_h = 0;
if (tree == NULL)
return (-1);
l_h = get_height(tree->left);
r_h = get_height(tree->right);
if (l_h > r_h)
return (l_h + 1);
return (r_h + 1);
}
/**
 * is_perfect - checks if a tree is perfect
 * @tree: tree root
 * Return: 1 on success. 0 otherwise
 */
int is_perfect(const binary_tree_t *tree)
{
if (tree && get_height(tree->left) == get_height(tree->right))
{
if (get_height(tree->left) == -1)
return (1);
if ((tree->left && !((tree->left)->left) && !((tree->left)->right))
&& (tree->right && !((tree->right)->left) && !((tree->right)->right)))
return (1);
if (tree && tree->left && tree->right)
return (is_perfect(tree->left) &&
is_perfect(tree->right));
}
return (0);
}
/**
 * swap_nodes - swaps nodes when child is greater than parent
 * @p_node: parent node
 * @c_node: child node
 * Return: Nothing
 */
void swap_nodes(heap_t **p_node, heap_t **c_node)
{
heap_t *node, *child, *node_child, *node_left, *node_right, *parent;
int left_right;
node = *p_node, child = *c_node;
if (child->n > node->n)
{
if (child->left)
child->left->parent = node;
if (child->right)
child->right->parent = node;
if (node->left == child)
node_child = node->right, left_right = 0;
else
node_child = node->left, left_right = 1;
node_left = child->left, node_right = child->right;
if (left_right == 0)
{
child->right = node_child;
if (node_child)
node_child->parent = child;
child->left = node;
}
else
{
child->left = node_child;
if (node_child)
node_child->parent = child;
child->right = node;
}
if (node->parent)
{
if (node->parent->left == node)
node->parent->left = child;
else
node->parent->right = child;
}
parent = node->parent, child->parent = parent;
node->parent = child, node->left = node_left;
node->right = node_right, *p_node = child;
}
}
/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: tree root
 * @value: data part of the node
 * Return: newnode that is inserted. NULL if no
 */
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *newnode;
if (*root == NULL)
{
*root = binary_tree_node(NULL, value);
return (*root);
}
if (is_perfect(*root) || !is_perfect((*root)->left))
{
if ((*root)->left)
{
newnode = heap_insert(&((*root)->left), value);
swap_nodes(root, &((*root)->left));
return (newnode);
}
else
{
newnode = (*root)->left = binary_tree_node(*root, value);
swap_nodes(root, &((*root)->left));
return (newnode);
}
}
if ((*root)->right)
{
newnode = heap_insert(&((*root)->right), value);
swap_nodes(root, (&(*root)->right));
return (newnode);
}
else
{
newnode = (*root)->right = binary_tree_node(*root, value);
swap_nodes(root, &((*root)->right));
return (newnode);
}
return (NULL);
}
