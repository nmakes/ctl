#include <stdio.h>
#include "ctlib/ctl.c"

/*
	Binary Search Demo:
		- The user defines custom functions and utility functions that the library can use.
		- Here we show a simple binary search application using an int array and the compare function
*/

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


void demo_assign(ctemplate a, ctemplate b)
{
	* (int*) a.ptr = * (int*) b.ptr;
}


void demo_binary_search(int * a, int N, int key)
{
	// Create a ctemplate for a - to be used by the library
	ctemplate 		t_a = {a, sizeof(int)};
	ctl_size_t 		t_N = N;
	ctemplate 		t_key = {&key, sizeof(int)};

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


void demo_linear_search(int * a, int N, int key)
{
	// Create a ctemplate for a - to be used by the library
	ctemplate 		t_a = {a, sizeof(int)};
	ctl_size_t 		t_N = N;
	ctemplate 		t_key = {&key, sizeof(int)};

	// Run the binary search algorithm
	ctl_size_t 		pos = ctl_linear_search(t_a, t_N, t_key, &demo_compare);

	if(pos == N)
	{
		printf("Number %d not found\n", key);
	}
	else
	{
		printf("Found number %d at position: %ld\n", key, pos);
	}
}


void demo_linear_search_transpose(int * a, int N, int key)
{
	// Create a ctemplate for a - to be used by the library
	ctemplate 		t_a = {a, sizeof(int)};
	ctl_size_t 		t_N = N;
	ctemplate 		t_key = {&key, sizeof(int)};

	// Run the binary search algorithm
	ctl_size_t 		pos = ctl_linear_search_transpose(t_a, t_N, t_key, &demo_compare, &demo_assign);

	if(pos == N)
	{
		printf("Number %d not found\n", key);
	}
	else
	{
		printf("Found number %d at position: %ld\n", key, pos);
	}
}


void demo_linear_search_transpose_exponential(int * a, int N, int key)
{
	// Create a ctemplate for a - to be used by the library
	ctemplate 		t_a = {a, sizeof(int)};
	ctl_size_t 		t_N = N;
	ctemplate 		t_key = {&key, sizeof(int)};

	// Run the binary search algorithm
	ctl_size_t 		pos = ctl_linear_search_transpose_exponential(t_a, t_N, t_key, &demo_compare, &demo_assign);

	if(pos == N)
	{
		printf("Number %d not found\n", key);
	}
	else
	{
		printf("Found number %d at position: %ld\n", key, pos);
	}
}

void plot(int * a, int N)
{
	printf("Array Is: ");

	for(int i=0; i<N; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n\n");
}

int main()
{
	// Create an array
	int a[] = {1, 6, 7, 15, 18, 24, 39, 45, 50, 62, 88, 100};
	int N = sizeof(a) / sizeof(int);

	plot(a, N);

	demo_binary_search(a, N, 39); plot(a, N);

	demo_binary_search(a, N, 25); plot(a, N);

	demo_linear_search(a, N, 88); plot(a, N);

	demo_linear_search_transpose(a, N, 18); plot(a, N);

	demo_linear_search_transpose_exponential(a, N, 24); plot(a, N);


}
