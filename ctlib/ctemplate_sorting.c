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



ctemplate ctl_arg_selection_sort(
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

	fprintf(stderr, "CTL_WARNING::ctl_arg_selection_sort: This function is currently buggy - doesn't give correct solution. Check algo.\n");

	ctemplate soln = { malloc(sizeof(ctl_size_t) * length), sizeof(ctl_size_t) };
	for(ctl_size_t i=0; i<length; i++)
	{
		* (ctl_size_t*) ctl_next(soln, i).ptr = i;
	}

	ctl_size_t pos;
	ctl_size_t p1, p2;
	for (ctl_size_t i=0; i<length; i++)
	{
		pos = i;
		for (ctl_size_t j=i+1; j<length; j++)
		{
			p1 = * (ctl_size_t*) ctl_next(soln, j).ptr;
			p2 = * (ctl_size_t*) ctl_next(soln, pos).ptr;
			if (compare(ctl_next(arr, p1), ctl_next(arr, p2)) < 0)
			{
				pos = j;
			}
		}
		p1 = * (ctl_size_t*) ctl_next(soln, pos).ptr;
		ctl_deep_swap(ctl_next(soln, i), ctl_next(soln, p1), &ctl_assign_ctl_size_t);
	}

	fprintf(stderr, "CTL_WARNING::ctl_arg_selection_sort: malloc'd memory for argsort solution. Remember to free the solution pointer.\n");

	return soln;
}



void ctl_insertion_sort(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)) // Pointer to the assign function (for deepswap)
{
	/*
		Algorithm: stable, adaptive, O(n^2)

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
		Algorithm: stable, adaptive, O(n^2)

		For i = {0, 1, 2, ..., length-1}
		{
			flag = 0;
			For j = {length-1, length-2, ..., i}
			{
				if (compare(A[j], A[j-1]) < 0)
				{
					swap(A[j], A[j-1]);
					flag = 1;
				}
			}
		}
	*/

	int flag = 0;

	for (ctl_size_t i=0; i<length; i++)
	{
		flag = 0;
		for (ctl_size_t j=length-1; j>i; j--)
		{
			if (compare(ctl_next(arr, j), ctl_next(arr, j-1)) < 0)
			{
				ctl_deep_swap(ctl_next(arr, j), ctl_next(arr, j-1), assign);
				flag = 1;
			}
		}

		if(flag == 0) break;
	}
}



void ctl_topk_sort(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	ctl_size_t k, // value of k (number of top elements to be sorted)
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)) // Pointer to the assign function (for deepswap)
{
	/*
		Algorithm: not stable, not adaptive, O(n*k)

		For i = {0, 1, ..., k-1}
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
	for (ctl_size_t i=0; i<k; i++)
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



ctl_size_t ctl_quick_sort_partition(
	ctemplate arr,
	ctl_size_t low,
	ctl_size_t high,
	int (*compare)(ctemplate, ctemplate),
	void (*assign)(ctemplate, ctemplate))
{
	ctl_size_t pivot = low;

	ctl_size_t i = low, j = high;

	while( i<j )
	{
		while ( (i<=high) && (compare(ctl_next(arr, i), ctl_next(arr, pivot)) <= 0))
		{
			i++;
		}

		while ( (j>=low) && (compare(ctl_next(arr, j), ctl_next(arr, pivot)) > 0))
		{
			j--;
		}

		if(i < j)
		{
			ctl_deep_swap(ctl_next(arr, j), ctl_next(arr, i), assign);
		}
	}

	ctl_deep_swap( ctl_next(arr, pivot), ctl_next(arr, j), assign );

	return j;
}


void ctl_quick_sort_recursive(
	ctemplate arr,
	ctl_size_t low,
	ctl_size_t high,
	int (*compare)(ctemplate, ctemplate),
	void (*assign)(ctemplate, ctemplate))
{
	if(low < high)
	{
		ctl_size_t j = ctl_quick_sort_partition(arr, low, high, compare, assign);
		ctl_quick_sort_recursive(arr, low, j-1, compare, assign);
		ctl_quick_sort_recursive(arr, j+1, high, compare, assign);
	}
}


void ctl_quick_sort(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)) // Pointer to the assign function (for deepswap)
{
	ctl_quick_sort_recursive(arr, 0, length-1, compare, assign);
}


void ctl_merge_sort_merge(
	ctemplate arr,
	ctl_size_t ll, 
	ctl_size_t hl,
	ctl_size_t lr,
	ctl_size_t hr,
	ctemplate scratch,
	int (*compare)(ctemplate, ctemplate),
	void (*assign)(ctemplate, ctemplate))
{
	ctl_size_t pos = ll;
	ctl_size_t i = ll, j = lr;

	while( (i<=hl) && (j<=hr) )
	{
		if( compare( ctl_next(arr, i), ctl_next(arr, j) ) < 0 )
		{
			assign( ctl_next(scratch, pos++), ctl_next(arr, i++) );
		}
		else
		{
			assign( ctl_next(scratch, pos++), ctl_next(arr, j++) );
		}
	}

	while( (i > hl) && (j <= hr) )
	{
		assign( ctl_next(scratch, pos++), ctl_next(arr, j++) );
	}

	while( (i <= hl) && (j > hr) )
	{
		assign( ctl_next(scratch, pos++), ctl_next(arr, i++) );
	}

	i = ll;

	while(i <= hr)
	{
		assign( ctl_next(arr, i), ctl_next(scratch, i) );
		i++;
	}
}


void ctl_merge_sort_recursive(
	ctemplate arr,
	ctl_size_t low, 
	ctl_size_t high,
	ctemplate scratch,
	int (*compare)(ctemplate, ctemplate),
	void (*assign)(ctemplate, ctemplate))
{
	if(low < high)
	{
		ctl_size_t mid = (low + high) / 2;
		ctl_merge_sort_recursive(arr, low, mid, scratch, compare, assign);
		ctl_merge_sort_recursive(arr, mid+1, high, scratch, compare, assign);
		ctl_merge_sort_merge(arr, low, mid, mid+1, high, scratch, compare, assign);
	}
}


void ctl_merge_sort(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)) // Pointer to the assign function (for deepswap)
{
	ctemplate scratch;
	scratch.ptr = malloc(arr.size * length);
	scratch.size = arr.size;
	
	ctl_merge_sort_recursive(arr, 0, length-1, scratch, compare, assign);

	free(scratch.ptr);
}


// TODO: Count sort after implementing list (chaining required in buckets)
// void ctl_count_sort(
// 	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
// 	ctl_size_t length, // Length of the array
// 	int (*get)(ctemplate)) // Pointer to the get function
// {
// 	ctl_longer_t v, max_elem = get(arr);

// 	for(ctl_longer_t i=0; i<length; i++)
// 	{
// 		v = get(ctl_next(arr, i));
// 		max_elem = max_elem > v ? max_elem : v;
// 	}

// 	ctl_longer_t * tab = (ctl_longer_t *) malloc( (max_elem+1) * sizeof(ctl_longer_t) );

// 	for(ctl_longer_t i=0; i<=max_elem; i++)
// 	{
// 		tab[i] = 0;
// 	}

// 	for(ctl_size_t i=0; i<length; i++)
// 	{
// 		tab[get(ctl_next(arr, i))]++;
// 	}

// 	ctl_size_t p = 0;
// 	for(ctl_longer_t i=0; i<=max_elem; i++)
// 	{
// 		if(tab[i] == 0)
// 		{
// 			continue;
// 		}
// 		else
// 		{
// 			while(tab[i]--)
// 			{

// 			}
// 		}
// 	}

// 	free(tab);
// }



int ctl_is_sorted( // checks if the array is sorted
	ctemplate arr, // ctemplate containing a pointer to the starting address of the sorted array (and size)
	ctl_size_t length, // Length of the array
	int(*compare)(ctemplate, ctemplate)) // Pointer to the comparator function
{
	if(length > 1)
	{
		for(ctl_size_t i=0; i<length-1; i++)
		{
			if(compare(ctl_next(arr, i), ctl_next(arr, i+1)) <= 0)
			{
				continue;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 1;
	}
}


void ctl_reverse( // reverses the array
	ctemplate arr, // ctemplate containing a pointer to the starting address of the sorted array (and size)
	ctl_size_t length, // Length of the array
	void (*assign)(ctemplate, ctemplate)) // Pointer to the assign function (for deepswap)
{
	for(ctl_size_t i=0; i<length/2; i++)
	{
		ctl_deep_swap( ctl_next(arr, i), ctl_next(arr, length-i-1), assign );
	}
}


void ctl_rotate_inplace( // shifts the array (circular) by the amount
	ctemplate arr, // ctemplate containing a pointer to the starting address of the sorted array (and size)
	ctl_size_t length, // Length of the array
	ctl_size_t count, // Number of shifts to perform
	void (*assign)(ctemplate, ctemplate)) // Pointer to the assign function (for deepswap)
{
	ctl_size_t dir = count > 0 ? 1 : -1;
	ctl_size_t mag = count > 0 ? count : -count;

	ctemplate temp = {malloc(arr.size), arr.size};

	for(int n=1; n<=mag; n++)
	{

		if(dir == 1) // shift right
		{
			assign(temp, ctl_next(arr, length-1));

			for(ctl_size_t i=length-1; i>0; i--)
			{
				assign(ctl_next(arr, i), ctl_next(arr, i-1));
			}

			assign(ctl_next(arr, 0), temp);
		}
		else // shift left
		{
			assign(temp, ctl_next(arr, 0));

			for(ctl_size_t i=0; i<length-1; i++)
			{
				assign(ctl_next(arr, i), ctl_next(arr, i+1));
			}

			assign(ctl_next(arr, length-1), temp);
		}
	}
}