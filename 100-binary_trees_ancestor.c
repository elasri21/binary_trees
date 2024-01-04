#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_trees_ancestor -  finds the lowest common ancestor of two nodes
 * @first: the first node to be checked
 * @second: the second node to be checked
 * Return: th lowest common ancestor of first and second
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
binary_tree_t *l_p, *r_p;
if (first == NULL || second == NULL)
return (NULL);
if (first == second)
return ((binary_tree_t *)second);
l_p = first->parent;
r_p = second->parent;
if (first == r_p || !l_p || (!l_p->parent && r_p))
return (binary_trees_ancestor(first, r_p));
else if (l_p == second || !r_p || (!r_p->parent && l_p))
return (binary_trees_ancestor(l_p, second));
return (binary_trees_ancestor(l_p, r_p));
}
