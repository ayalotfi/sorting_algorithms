#include "sort.h"

/**
 * print_array - Affiche un tableau d'entiers.
 * @tableau: Tableau d'entiers.
 * @taille: Taille du tableau.
 */

void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	} printf("\n");
}
