#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
queue_t *create_item(binary_tree_t *item);
void empty_queue(queue_t *h);
void push_item(binary_tree_t *item, queue_t *h,
queue_t **t);
void pop_item(queue_t **h);

/**
 * create_item - creates an item to be added to the queue.
 * @item: a binary tree node to create a queue item from.
 * Return: queue item or null on failure
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
 * empty_queue - empties a queue
 * @h: the queue front
 * Return: Nothing
 */
void empty_queue(queue_t *h)
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
 * push_item - adds items to the queue
 * @item: item to be added
 * @h: front of the queue.
 * @t: tain of the queue.
 * Return: Nothing
 */
void push_item(binary_tree_t *item, queue_t *h,
queue_t **t)
{
queue_t *newitem;
newitem = create_item(item);
if (newitem == NULL)
{
empty_queue(h);
exit(1);
}
(*t)->next = newitem;
*t = newitem;
}

/**
 * pop_item - removes item from queue.
 * @h: front of the queue.
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
 * binary_tree_is_complete - checks if a tree is complete
 * @tree: the tree to be checked
 * Return: 1 on success. 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
queue_t *h, *t;
unsigned char fg = 0;
if (tree == NULL)
return (0);
h = t = create_item((binary_tree_t *)tree);
if (h == NULL)
exit(1);
while (h != NULL)
{
if (h->item->left != NULL)
{
if (fg == 1)
{
empty_queue(h);
return (0);
}
push_item(h->item->left, h, &t);
}
else
fg = 1;
if (h->item->right != NULL)
{
if (fg == 1)
{
empty_queue(h);
return (0);
}
push_item(h->item->right, h, &t);
}
else
fg = 1;
pop_item(&h);
}
return (1);
}
