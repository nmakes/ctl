#include <stdio.h>
#include "ctl.c"

/*
	Sort Demo:
		- The user defines custom functions and utility functions that the library can use.
		- Here we show a simple binary search application using an int array and the compare function
*/

void demo_assign(ctemplate a, ctemplate b) // performs a deep copy
{
	// User knows that the template is for int.
	// Thus, user first parses the ctemplates to obtain the integer values.
	// Performs assignment accordingly

	*((int*) a.ptr) = *((int*) b.ptr);
}

int demo_compare(ctemplate a, ctemplate b)
{
	// User knows that the array is an int array. 
	// Thus, user first parses the ctemplates to obtain the integer values.

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

void demo_selection_sort(int * a, int N)
{
	// Create a ctemplate for a - to be used by the library
	ctemplate 		t_a = {a, sizeof(int)};
	ctl_size_t 		t_N = N;

	ctl_selection_sort(t_a, t_N, &demo_compare, &demo_assign);
}

void demo_insertion_sort(int * a, int N)
{
	// Create a ctemplate for a - to be used by the library
	// ctemplate 		t_a = {a, sizeof(int)};
	// ctl_size_t 		t_N = N;

	ctl_insertion_sort((ctemplate){a, sizeof(int)}, N, &demo_compare, &demo_assign);
}

void demo_bubble_sort(int * a, int N)
{
	ctl_bubble_sort( (ctemplate){a, sizeof(int)}, N, &demo_compare, &demo_assign );
}

void demo_quick_sort(int * a, int N)
{
	ctl_quick_sort( (ctemplate){a, sizeof(int)}, N, &demo_compare, &demo_assign );
}

int main()
{
	// Create an array
	int a[] = {24, 6, 7, 62, 18, 1, 50, 100, 39, 15, 88, 45};
	int N = sizeof(a) / sizeof(int);

	int m1 = 34;
	int m2 = 87;

	printf("Two numbers: %d %d\n", m1, m2);

	ctemplate t1 = {&m1, sizeof(int)};
	ctemplate t2 = {&m2, sizeof(int)};

	ctl_deep_swap(t1, t2, demo_assign);

	printf("After deepswap: %d %d\n", m1, m2);

	printf("Original Array:\n");
	for(int i=0; i<N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	// demo_selection_sort(a, N);
	// demo_insertion_sort(a, N);
	// demo_bubble_sort(a, N);
	demo_quick_sort(a, N);


	printf("After Sorting Array:\n");
	for(int i=0; i<N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}