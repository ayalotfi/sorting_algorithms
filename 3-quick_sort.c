#include "sort.h"

/**
 * * tri_rapide_rec - Trie un tableau d'entiers par ordre croissant en utilisant le tri rapide.
 * @tableau: Tableau d'entiers.
 * @taille: Taille du tableau.
 * @tableau_initial: Tableau initial.
 * @taille_initiale: Taille du tableau initial.
 **/

void quick_sort_rec(int *array_init, size_t size_init, int *array, size_t size)
{
	size_t j, a;
	int b;
	int i = -1, n, p = array[size - 1];

	if (array && size > 1)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] < p)
			{
				i++;
				a = i;
				if (a != j && array[j] != array[a])
				{
					n = array[j];
					array[j] = array[i];
					array[i] = n;
					print_array(array_init, size_init);
				}
			}
		} b = size;
		if (b - 1 != i + 1 && array[b - 1] != array[i + 1])
		{
			array[size - 1] = array[i + 1];
			array[i + 1] = p;
			print_array(array_init, size_init);
		}
		if (i > 0)
		{
			quick_sort_rec(array_init, size_init, array, i + 1);
		} quick_sort_rec(array_init, size_init, array + i + 2,  size - (i + 2));
	}
}

/**
 * @quick_sort -> trie un tableau d'entiers par ordre croissant.
 * @Tableau d'entiers.
 * @Taille du tableau.
**/

void quick_sort(int *array, size_t size)
{
	int *_array;
	size_t _size;

	if (array)
	{
		_array = array;
		_size = size;
		quick_sort_rec(_array, _size, array, size);
	}
}
