#include <stdlib.h>
#include "binary_trees.h"
/**
 * array_to_avl - construct an avl from a tree
 * @array: array of numbers to workwith
 * @size: size of the array
 * Return: built tree
 */
avl_t *array_to_avl(int *array, size_t size)
{
avl_t *avl = NULL;
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
if (avl_insert(&avl, array[i]) == NULL)
return (NULL);
}
}
return (avl);
}
