#include "sort.h"

/**
 * insertion_sort_list ->> Sorts a list of doubly linked int.
 * @list: doubly linked list.
 */

void insertion_sort_list(list_int_t **list)
{
	list_int_t *n;

	if (list == NULL || (*list)->next == NULL)
		return;
	n = (*list)->next;
	while (n)
	{
		while ((n->prev) && (n->prev->n > n->n))
		{
			n = swap_node(n, list);
			print_list(*list);
		} n = n->next;
	}
}

/**
 *swap_node ->> Switch two nodes.
 *@node: Node.
 *@list: Node list.
 *Return: Node.
 */

list_int_t *swap_node(list_int_t *node, list_int_t **list)
{
	list_int_t *prev = node->prev, *now = node;

	prev->next = now->next;
	if (now->next)
		now->next->prev = prev;
	now->next = prev;
	now->prev = prev->prev;
	prev->prev = now;
	if (now->prev)
		now->prev->next = now;
	else
		*list = now;
	return (now);
}
