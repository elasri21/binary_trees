#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * get_size - get the tree size
 * @tree: tree root
 * Return: tree size. 0 on failure
 */
size_t get_size(const binary_tree_t *tree)
{
size_t l_s = 0, r_s = 0;
if (!tree)
return (0);
if (tree->left)
l_s = 1 + get_size(tree->left);
if (tree->right)
r_s = 1 + get_size(tree->right);
return (l_s + r_s);
}
/**
 * heap_to_sorted_array - creates a sorted array froma heap tree
 * @heap: heap tree
 * @size: size of the array
 * Return: sorted array.NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
int i, *sorted_array = NULL;
if (!heap || !size)
return (NULL);
*size = get_size(heap) + 1;
sorted_array = malloc(sizeof(int) * (*size));
if (!sorted_array)
return (NULL);
for (i = 0; heap; i++)
sorted_array[i] = heap_extract(&heap);
return (sorted_array);
}
