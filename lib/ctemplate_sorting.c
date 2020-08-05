#include "ctemplate_sorting.h"

/*
	Search utilities using templates
*/

void ctl_selection_sort(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)) // Pointer to the assign function (for deepswap)
{
	/*
		Algorithm:

		For i = {0, 1, ..., length-1}
		{
			M = i;
			For j = {i+1, i+2, ..., length-1}
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
			if (compare(ctl_next(arr, j), ctl_next(arr, pos)) < 0)
			{
				pos = j;
			}
		}
		ctl_deep_swap(ctl_next(arr, i), ctl_next(arr, pos), assign);
	}
}



void ctl_insertion_sort(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)) // Pointer to the assign function (for deepswap)
{
	/*
		Algorithm:

		For i = {1, 2, ..., length}
		{
			For j = {i-1, i-2, ..., 0}
			{
				if (compare(A[j+1], A[j]) < 0)
				{
					swap(A[j], A[j+1]);
				}
				else
				{
					break;
				}
			}
		}
	*/
	for (ctl_size_t i=1; i<length; i++)
	{
		for (ctl_size_t j=i-1; j>=0; j--)
		{
			if (compare(ctl_next(arr, j+1), ctl_next(arr, j)) < 0)
			{
				ctl_deep_swap(ctl_next(arr, j+1), ctl_next(arr, j), assign);
			}
			else
			{
				break;
			}
		}
	}
}


void ctl_bubble_sort(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)) // Pointer to the assign function (for deepswap)
{
	/*
		Algorithm:

		For i = {0, 1, 2, ..., length-1}
		{
			For j = {length-1, length-2, ..., i}
			{
				if (compare(A[j], A[j-1]) < 0)
				{
					swap(A[j], A[j-1]);
				}
			}
		}
	*/

	for (ctl_size_t i=0; i<length; i++)
	{
		for (ctl_size_t j=length-1; j>i; j--)
		{
			if (compare(ctl_next(arr, j), ctl_next(arr, j-1)) < 0)
			{
				ctl_deep_swap(ctl_next(arr, j), ctl_next(arr, j-1), assign);
			}
		}
	}
}