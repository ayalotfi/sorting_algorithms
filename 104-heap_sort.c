#include "sort.h"

/**
 *check_tree -> Vérifie l'arbre
 * @array: Tableau d'entiers
 * @size: Taille du tableau
 * @size_init: Taille initiale du tableau
 * @i: Index
 **/ 


void check_tree(int *array, size_t size_init, size_t size, size_t i)
{

	int n, b1, b2;
	size_t br1, br2;

	br1 = i * 2 + 1;
	br2 = br1 + 1;
	b1 = array[br1];
	b2 = array[br2];
	if (((br1 < size) && (br2 < size) &&
		(b1 >= b2 && b1 > array[i]))
		|| ((br1 == size - 1) && b1 > array[i]))
	{
		n = array[i];
		array[i] = b1;
		array[br1] = n;
		print_array(array, size_init);
	}
	else if ((br1 < size) && (br2 < size) &&
		(b2 > b1 && b2 > array[i]))
	{
		n = array[i];
		array[i] = b2;
		array[br2] = n;
		print_array(array, size_init);
	}
	if (br1 < size - 1)
		check_tree(array, size_init, size, br1);
	if (br2 < size - 1)
		check_tree(array, size_init, size, br2);
}

/**
 *  heap_sort -> Trie un tableau d'entiers par ordre croissant en utilisant le tri par tas
 * @array: Tableau d'entiers
 * @size: Taille du tableau
**/

void heap_sort(int *array, size_t size)
{
	size_t i, size_init = size;
	int n;

	if (!array)
		return;
	for (i = 0; i < size / 2 ; i++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - i);
	}
	for (i = 0; i < size_init - 1; i++)
	{
		n = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = n;
		print_array(array, size_init);
		check_tree(array, size_init, size - i - 1, 0);
	}
}
