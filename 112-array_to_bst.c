#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: address of the first element in the array
 * @size: size of the array
 * Return: A bst
 */
bst_t *array_to_bst(int *array, size_t size)
{
bst_t *bst = NULL;
size_t i, j;
if (array == NULL)
return (NULL);
for (i = 0; i < size; i++)
{
for (j = 0; j < i; j++)
{
if (array[j] == array[i])
break;
}
if (j == i)
{
if (bst_insert(&bst, array[i]) == NULL)
return (NULL);
}
}
return (bst);
}
