#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * half_tree - create a half tree
 * @tree: node's parent
 * @arr: array of values
 * @start: starting position
 * @end: end position
 * Return: avl tree with half of arr element
 */
avl_t *half_tree(avl_t *tree, int *arr, int start, int end)
{
avl_t *avl;
binary_tree_t *subtree;
int center = 0;
if (start <= end)
{
center = (start + end) / 2;
subtree = binary_tree_node((binary_tree_t *)tree, arr[center]);
if (subtree == NULL)
return (NULL);
avl = (avl_t *)subtree;
avl->left = half_tree(avl, arr, start, center - 1);
avl->right = half_tree(avl, arr, center + 1, end);
return (avl);
}
return (NULL);
}
/**
 * sorted_array_to_avl - creates an avl tree
 * @array: array of values to work with
 * @size: size of array
 * Return: created avl
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
if (array == NULL || size == 0)
return (NULL);
return (half_tree(NULL, array, 0, ((int)(size)) - 1));
}
