#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * array_to_heap - insert nodes in a tree using array
 * @array: array of values to be inserted
 * @size: size of the array
 * Return: tree on success. NULL otherwise
 */
heap_t *array_to_heap(int *array, size_t size)
{
heap_t *tree;
size_t i;
tree = NULL;
for (i = 0; i < size; i++)
{
heap_insert(&tree, array[i]);
}
return (tree);
}
