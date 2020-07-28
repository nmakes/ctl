#include "ctemplate_sorting.h"

/*
	Search utilities using templates
*/

ctl_size_t ctl_selection_sort(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate)); // Pointer to the comparator function
{
	/*
		Algorithm:

		For i = {0, ..., length-1}
		{
			M = i;
			For j = {i+1, ..., length-1}
			{
				if (compare(A[M], A[j]) < 0)
				{
					M = j;
				}
			}
			swap(A[M], A[i]);
		}
	*/
	ctl_size_t pos;
	for (ctl_size_t i=0; i<length; i++)
	{
		pos = i;
		for (ctl_size_t j=i+1; j<length; j++)
		{
			if (compare(next(arr, pos), next(arr, j)) < 0)
			{
				pos = j;
			}
		}
		
	}
}