#include "sort.h"

/**
 *  swap -> Échange deux éléments
* @array: Tableau
* @item1: Élément 1
* @item2: Élément 2
*/

void swap(int *array, ssize_t item1, ssize_t item2)
{
	int i;

	i = array[item1];
	array[item1] = array[item2];
	array[item2] = i;
}

/**
 * hoare_partition -> Schéma de partitionnement de Hoare
 * @array: Tableau
 * @first: Premier élément du tableau
 * @last: Dernier élément du tableau
 * @size: Taille du tableau
 * Retourne: La position de la partition
 */

int hoare_partition(int *array, int first, int last, int size)
{
	int a = first - 1, b = last + 1;
	int p = array[last];

	while (1)
	{
		do {
			a++;
		} while (array[a] < p);
		do {
			b--;
		} while (array[b] > p);
		if (a >= b)
			return (a);
		swap(array, a, b);
		print_array(array, size);
	}
}

/**
 * qs -> Algorithme de tri rapide (Quicksort)
 * @array: Tableau
 * @first: Premier élément du tableau
 * @last: Dernier élément du tableau
 * @size: Taille du tableau
 */

void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t p = 0;

	if (first < last)
	{
		p = hoare_partition(array, first, last, size);
		qs(array, first, p - 1, size);
		qs(array, p, last, size);
	}
}

/**
 * quick_sort_hoare -> Trie un tableau d'entiers par ordre croissant en utilisant le tri rapide (Quicksort) avec le schéma de Hoare
 * @array: Tableau d'entiers
 * @size: Taille du tableau
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
