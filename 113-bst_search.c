#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * bst_search - looks for a value in a bst
 * @tree: the root of bst
 * @value: the value to look for
 * Return: node containing the value. NULL otherwise
 */
bst_t *bst_search(const bst_t *tree, int value)
{
if (tree == NULL)
return (NULL);
if (tree->n == value)
return ((bst_t *)tree);
else if (tree->n > value)
return (bst_search(tree->left, value));
else if (tree->n < value)
return (bst_search(tree->right, value));
else
return (NULL);
}
