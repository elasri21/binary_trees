#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_nodes - counts the number of nodes in a given tree
 * @tree: the given tree
 * Return: the number of node in a tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
size_t nodes = 0;
if (tree == NULL)
return (0);
if (tree->left || tree->right)
nodes += 1;
nodes += binary_tree_nodes(tree->left);
nodes += binary_tree_nodes(tree->right);
return (nodes);
}
