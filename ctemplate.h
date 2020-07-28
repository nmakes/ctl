#pragma once

/*
	Defining standard names for types
*/

typedef unsigned long int ctl_size_t;

typedef struct
{
	void * ptr;
	ctl_size_t size;
} ctemplate;



/*
	Basic library functions for the ctemplate type
*/

ctl_size_t ctl_size(ctemplate t);


ctemplate ctl_next(
	ctemplate t, // Reference to the ctemplate
	ctl_size_t n); // How many steps to move in memory


ctemplate ctl_prev(
	ctemplate t, // Reference to the ctemplate
	ctl_size_t n); // How many steps to move in memory


ctl_size_t ctl_binary_search(
		ctemplate arr, // ctemplate containing a pointer to the starting address of the sorted array (and size)
		ctl_size_t length, // Length of the array
		ctemplate key, // ctemplate containing pointer to the value to be searched for
		int (*compare)(ctemplate, ctemplate)); // Pointer to the comparator function