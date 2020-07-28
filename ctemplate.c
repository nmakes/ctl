#include <stdio.h>
// #include "ctemplate.h"



typedef unsigned long int ctl_size_t;



typedef struct
{
	void * ptr;
	ctl_size_t size;
} TEMPLATE;


ctl_size_t ctl_size(TEMPLATE t)
{
	return t.size;
}


TEMPLATE ctl_next(
	TEMPLATE t, // Reference to the TEMPLATE
	ctl_size_t n) // How many steps to move in memory
{
	void * p = (void*) (  (char*) t.ptr + n * t.size  );
	TEMPLATE t_new = {p, t.size};
	return t_new;
}


TEMPLATE ctl_prev(
	TEMPLATE t, // Reference to the TEMPLATE
	ctl_size_t n) // How many steps to move in memory
{
	void * p = (void*) (  (char*) t.ptr - n * t.size  );
	TEMPLATE t_new = {p, t.size};
	return t_new;
}


ctl_size_t ctl_binary_search(
		TEMPLATE arr, // TEMPLATE containing a pointer to the starting address of the sorted array (and size)
		ctl_size_t length, // Length of the array
		TEMPLATE key, // TEMPLATE containing pointer to the value to be searched for
		int (*compare)(TEMPLATE, TEMPLATE)) // Pointer to the comparator function
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



/*
	User Defined Area:
		- The user defines custom functions and utility functions that the library can use.
		- Here we show a simple binary search application using an int array and the compare function
*/



int demo_compare(TEMPLATE a, TEMPLATE b)
{
	// User knows that the array is an int array. 
	// Thus, user first parses the TEMPLATEs to obtain the integer values.

	int a1 = (* ((int*) a.ptr));
	int a2 = (* ((int*) b.ptr));

	// The library requires the compare function to yield 0, if the values match,
	// Otherwise, it must return negative or positive based on the comparison

	if(a1==a2)
	{
		return 0;
	}
	else if(a1 < a2)
	{
		return -1;
	}
	else // that is, if(a1 > a2)
	{
		return 1;
	}
}


void demo_binary_search(int * a, int N, int key)
{
	// Create a TEMPLATE for a - to be used by the library
	TEMPLATE 		t_a = {a, sizeof(int)};
	ctl_size_t 		t_N = N;
	TEMPLATE 		t_key = {&key, sizeof(int)};

	// Run the binary search algorithm
	ctl_size_t 		pos = ctl_binary_search(t_a, t_N, t_key, &demo_compare);

	if(pos == N)
	{
		printf("Number %d not found\n", key);
	}
	else
	{
		printf("Found number %d at position: %ld\n", key, pos);
	}
}


int main()
{
	// Create an array
	int a[] = {1, 6, 7, 15, 18, 24, 39, 45, 50, 62, 88, 100};
	int N = sizeof(a) / sizeof(int);

	demo_binary_search(a, N, 39);

	demo_binary_search(a, N, 25);

	demo_binary_search(a, N, 1);

	demo_binary_search(a, N, 19);
}