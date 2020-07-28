#include "ctemplate.h"

#ifndef __CTEMPLATE_SEARCHING_H
#define __CTEMPLATE_SEARCHING_H



/*
	Search utilities using templates
*/

ctl_size_t ctl_binary_search(
		ctemplate arr, // ctemplate containing a pointer to the starting address of the sorted array (and size)
		ctl_size_t length, // Length of the array
		ctemplate key, // ctemplate containing pointer to the value to be searched for
		int (*compare)(ctemplate, ctemplate)); // Pointer to the comparator function


ctl_size_t ctl_linear_search(
		ctemplate arr, // ctemplate containing a pointer to the starting address of the sorted array (and size)
		ctl_size_t length, // Length of the array
		ctemplate key, // ctemplate containing pointer to the value to be searched for
		int (*compare)(ctemplate, ctemplate)); // Pointer to the comparator function

#endif