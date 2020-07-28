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