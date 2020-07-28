#include "ctemplate.h"

#ifndef __CTEMPLATE_SORTING_H
#define __CTEMPLATE_SORTING_H



/*
	Search utilities using templates
*/

ctl_size_t ctl_selection_sort(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate)); // Pointer to the comparator function

#endif