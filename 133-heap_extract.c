#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * get_height - get the height of a binary tree
 * @tree: tree root
 * Return: tree height. 0 otherwise
 */
size_t get_height(const heap_t *tree)
{
size_t l_h = 0, r_h = 0;
if (!tree)
return (0);
if (tree->left)
l_h = 1 + get_height(tree->left);
if (tree->right)
r_h = 1 + get_height(tree->right);
if (l_h > r_h)
return (l_h);
return (r_h);
}
/**
 * pre_order - traverse the tree in preorder
 * @tree: tree root
 * @node: last node in the traversal process
 * @height: tree height
 * Return: Nothing
 */
void pre_order(heap_t *tree, heap_t **node, size_t height)
{
if (!tree)
return;
if (!height)
*node = tree;
height--;
pre_order(tree->left, node, height);
pre_order(tree->right, node, height);
}
/**
 * heap_ify - heapifies a heap tree
 * @root: tree root
 * Return: Nothing
 */
void heap_ify(heap_t *root)
{
int data;
heap_t *tmp1, *tmp2;
if (!root)
return;
tmp1 = root;
while (1)
{
if (!tmp1->left)
break;
if (!tmp1->right)
tmp2 = tmp1->left;
else
{
if (tmp1->left->n > tmp1->right->n)
tmp2 = tmp1->left;
else
tmp2 = tmp1->right;
}
if (tmp1->n > tmp2->n)
break;
data = tmp1->n;
tmp1->n = tmp2->n;
tmp2->n = data;
tmp1 = tmp2;
}
}
/**
 * heap_extract - extracts the root node of a MBH
 * @root: tree root
 * Return: data part of the root. 0 otherwise
 */
int heap_extract(heap_t **root)
{
int data;
heap_t *heap_r, *node;
if (!root || !*root)
return (0);
heap_r = *root;
data = heap_r->n;
if (!heap_r->left && !heap_r->right)
{
*root = NULL;
free(heap_r);
return (data);
}
pre_order(heap_r, &node, get_height(heap_r));
heap_r->n = node->n;
if (node->parent->right)
node->parent->right = NULL;
else
node->parent->left = NULL;
free(node);
heap_ify(heap_r);
*root = heap_r;
return (data);
}
