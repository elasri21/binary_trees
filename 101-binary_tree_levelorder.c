#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
queue_t *create_item(binary_tree_t *item);
void empty_a_queue(queue_t *h);
void push_unit(binary_tree_t *item, queue_t *h,
queue_t **t, void (*func)(int));
void pop_item(queue_t **h);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
/**
 * create_item - creates an item for the queue
 * @item: tree node to create item from it
 * Return: queue item on success. NULL otherwise
 */
queue_t *create_item(binary_tree_t *item)
{
queue_t *newitem;
newitem = malloc(sizeof(queue_t));
if (newitem == NULL)
return (NULL);
newitem->item = item;
newitem->next = NULL;
return (newitem);
}
/**
 * empty_a_queue - frees a queue
 * @h: the front of the queue
 * Return: Nothing
 */
void empty_a_queue(queue_t *h)
{
queue_t *tmp;
while (h != NULL)
{
tmp = h->next;
free(h);
h = tmp;
}
}
/**
 * push_unit - pushes nodes to the queue
 * @item: the node to be pushed
 * @h: the front of the queue
 * @t: the queue tail
 * @func: function to be apply on each item
 * Return: Nothing
 */
void push_unit(binary_tree_t *item, queue_t *h,
queue_t **t, void (*func)(int))
{
queue_t *newitem;
func(item->n);
if (item->left != NULL)
{
newitem = create_item(item->left);
if (newitem == NULL)
{
empty_a_queue(h);
exit(1);
}
(*t)->next = newitem;
*t = newitem;
}
if (item->right != NULL)
{
newitem = create_item(item->right);
if (newitem == NULL)
{
empty_a_queue(h);
exit(1);
}
(*t)->next = newitem;
*t = newitem;
}
}
/**
 * pop_item - rwmoves an item from a queue
 * @h: the front of a queue
 * Return: Nothing
 */
void pop_item(queue_t **h)
{
queue_t *tmp;
tmp = (*h)->next;
free(*h);
*h = tmp;
}
/**
 * binary_tree_levelorder - goes through a tree using level-order traversal
 * @tree: the tree to go throgh
 * @func: the function to be upply on each node
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree,
void (*func)(int))
{
queue_t *h, *t;
if (tree == NULL || func == NULL)
return;
h = t = create_item((binary_tree_t *)tree);
if (h == NULL)
return;
while (h != NULL)
{
push_unit(h->item, h, &t, func);
pop_item(&h);
}
}
