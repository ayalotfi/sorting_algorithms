#include "sort.h"

/**
 * swap -> Échange deux éléments.
 * @arr: Tableau.
 * @item1: Premier élément.
 * @item2: Deuxième élément.
 * @order: 1: Ordre croissant, 0: Ordre décroissant.
 */

void swap(int arr[], int item1, int item2, int order)
{
	int i;

	if (order == (arr[item1] > arr[item2]))
	{
		i = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = i;
	}
}

/**
 * merge -> Trie un tableau d'entiers par ordre croissant ou décroissant.
 * @arr: Tableau.
 * @low: Premier élément.
 * @nelemnt: Nombre d'éléments.
 * @order: 1: Ordre croissant, 0: Ordre décroissant.
 */

void merge(int arr[], int low, int nelemnt, int order)
{
	int m, i;

	if (nelemnt > 1)
	{
		m = nelemnt / 2;
		for (i = low; i < low + m; i++)
			swap(arr, i, i + m, order);
		merge(arr, low, m, order);
		merge(arr, low + m, m, order);
	}
}

/**
 *  bitonicsort -> Trie un tableau d'entiers par ordre croissant ou décroissant (algorithme bitonique).
 * @arr: Tableau.
 * @low: Premier élément.
 * @nelemnt: Nombre d'éléments.
 * @order: 1: Ordre croissant, 0: Ordre décroissant.
 * @size: Taille du tableau.
 */

void bitonicsort(int arr[], int low, int nelemnt, int order, int size)
{
	int m;

	if (nelemnt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		} m = nelemnt / 2;
		bitonicsort(arr, low, m, 1, size);
		bitonicsort(arr, low + m, m, 0, size);
		merge(arr, low, nelemnt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
	}
}

/**
 * bitonic_sort -> Trie un tableau d'entiers par ordre croissant (algorithme bitonique).
 * @array: Tableau d'entiers.
 * @size: Taille du tableau.
 */

void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
