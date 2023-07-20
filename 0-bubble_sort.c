#include "sort.h"

/**
 * bubble_sort trie un tableau d'entiers par ordre croissant en utilisant l'algorithme du tri à bulles.
 *@Le tableau à trier.
 *@La taille du tableau.
 
 **/

void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size - i; j++)
		{
			if (array[j - 1] > array[j])
			{
				k = array[j];
				array[j] = array[j - 1];
				array[j - 1] = k;
				print_array(array, size);
			}
		}
	}
}
