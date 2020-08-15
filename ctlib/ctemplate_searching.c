#include "ctemplate_searching.h"


ctl_size_t ctl_binary_search(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the sorted array (and element size)
	ctl_size_t length, // Length of the array
	ctemplate key, // ctemplate containing pointer to the value to be searched for
	int (*compare)(ctemplate, ctemplate)) // Pointer to the comparator function
{
	ctl_size_t lo=0, hi=length-1, mid=(lo+hi)/2;
	int comp;

	while(lo<=hi)
	{
		mid = (lo+hi)/2;
		comp = (*compare)(key, ctl_next(arr, mid));

		if ( comp == 0 )
		{
			return mid;
		}
		else if( comp < 0 )
		{
			hi = mid-1;
		}
		else if( comp > 0 )
		{
			lo = mid+1;
		}
	}

	return length;
}


ctl_size_t ctl_linear_search(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the sorted array (and size)
	ctl_size_t length, // Length of the array
	ctemplate key, // ctemplate containing pointer to the value to be searched for
	int (*compare)(ctemplate, ctemplate)) // Pointer to the comparator function
{
	ctl_size_t i=0;
	int comp;

	for(ctl_size_t i=0; i<length; i++)
	{
		comp = (*compare)(key, ctl_next(arr, i));
		if(comp == 0)
		{
			return i;
		}
	}

	return length;
}


ctl_size_t ctl_linear_search_transpose( // Performs transposition after searching (for faster next access)
	ctemplate arr, // ctemplate containing a pointer to the starting address of the sorted array (and size)
	ctl_size_t length, // Length of the array
	ctemplate key, // ctemplate containing pointer to the value to be searched for
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)) // Pointer to the assign function (for deepswap)
{
	ctl_size_t index = ctl_linear_search(arr, length, key, compare);

	ctl_size_t new_index = index - 1;

	if ( (index < length) && (index > 0))
	{
		ctl_deep_swap( ctl_next(arr, index), ctl_next(arr, new_index), assign );
		return new_index;
	}
	else
	{
		return index;
	}

}


ctl_size_t ctl_linear_search_transpose_exponential( // Performs exponential transposition after searching
	ctemplate arr, // ctemplate containing a pointer to the starting address of the sorted array (and size)
	ctl_size_t length, // Length of the array
	ctemplate key, // ctemplate containing pointer to the value to be searched for
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)) // Pointer to the assign function (for deepswap)
{
	ctl_size_t index = ctl_linear_search(arr, length, key, compare);

	ctl_size_t new_index = index / 2;

	if ( (index < length) && (index > 0))
	{
		ctl_deep_swap( ctl_next(arr, index), ctl_next(arr, new_index), assign );
		return new_index;
	}
	else
	{
		return index;
	}

}


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
	void (*assign)(ctemplate, ctemplate))
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


ctemplate ctl_max(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)) // Pointer to the assign function (for deepswap)
{
	ctemplate temp;
	assign(temp, ctl_next(arr, 0));

	for(ctl_size_t i=0; i<length; i++)
	{
		if( compare(ctl_next(arr, i), temp) > 0 )
		{
			assign(temp, ctl_next(arr, i));
		}
	}

	return temp;
}


ctl_size_t ctl_arg_max(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)) // Pointer to the assign function (for deepswap)
{
	ctl_size_t pos = 0;

	for(ctl_size_t i=0; i<length; i++)
	{
		if( compare(ctl_next(arr, i), ctl_next(arr, pos)) > 0 )
		{
			pos = i;
		}
	}

	return pos;
}


ctemplate ctl_min(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)) // Pointer to the assign function (for deepswap)
{
	ctemplate temp;
	assign(temp, ctl_next(arr, 0));

	for(ctl_size_t i=0; i<length; i++)
	{
		if( compare(ctl_next(arr, i), temp) < 0 )
		{
			assign(temp, ctl_next(arr, i));
		}
	}

	return temp;
}


ctl_size_t ctl_arg_min(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)) // Pointer to the assign function (for deepswap)
{
	ctl_size_t pos = 0;

	for(ctl_size_t i=0; i<length; i++)
	{
		if( compare(ctl_next(arr, i), ctl_next(arr, pos)) < 0 )
		{
			pos = i;
		}
	}

	return pos;
}



// ctl_size_t * ctl_arg_topk(
// 	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
// 	ctl_size_t length, // Length of the array
// 	ctl_size_t k, // value of k (number of top elements to be obtained)
// 	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
// 	void (*assign)(ctemplate, ctemplate)) // Pointer to the assign function (for deepswap)
// {
// 	// returns a list of indices of the topK elements

// 	ctl_assert(k>=1, "At least one element must be returned.");

// 	char * done = (char*)malloc(length);
// 	for(ctl_size_t i=0; i<length; i++) 
// 		done[i] = 0;

// 	ctl_size_t * argtopk = (ctl_size_t*) malloc(sizeof(ctl_size_t) * k);

// 	ctl_size_t largest = 0, temp;
// 	for(ctl_size_t i=0; i<length; i++)
// 	{
// 		if(compare(ctl_next(arr, i), ctl_next(arr, largest)) > 0)
// 		{
// 			largest = i;
// 		}
// 	}

// 	for(ctl_size_t i=0; i<k; i++)
// 	{
// 		temp = largest;
// 		for(ctl_size_t j=0; j<length; j++)
// 		{
// 			if(done[j] != 0)
// 			{
// 				if(compare(temp, ctl_next(arr, j)) < 0)
// 				{
// 					argtopk[i] = j;
// 				}
// 			}
// 		}
// 	}


// }