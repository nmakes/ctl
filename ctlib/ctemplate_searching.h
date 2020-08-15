#include "ctemplate.h"

#ifndef __CTEMPLATE_SEARCHING_H
#define __CTEMPLATE_SEARCHING_H



/*
	Search utilities using templates
*/

ctl_size_t ctl_binary_search(
		ctemplate arr, // ctemplate containing a pointer to the starting address of the sorted array (and element size)
		ctl_size_t length, // Length of the array
		ctemplate key, // ctemplate containing pointer to the value to be searched for
		int (*compare)(ctemplate, ctemplate)); // Pointer to the comparator function

ctl_size_t ctl_linear_search(
		ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
		ctl_size_t length, // Length of the array
		ctemplate key, // ctemplate containing pointer to the value to be searched for
		int (*compare)(ctemplate, ctemplate)); // Pointer to the comparator function

ctl_size_t ctl_linear_search_transpose( // Performs transposition after searching (for faster next access)
	ctemplate arr, // ctemplate containing a pointer to the starting address of the sorted array (and size)
	ctl_size_t length, // Length of the array
	ctemplate key, // ctemplate containing pointer to the value to be searched for
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)); // Pointer to the assign function (for deepswap)

ctl_size_t ctl_linear_search_transpose_exponential( // Performs exponential transposition after searching
	ctemplate arr, // ctemplate containing a pointer to the starting address of the sorted array (and size)
	ctl_size_t length, // Length of the array
	ctemplate key, // ctemplate containing pointer to the value to be searched for
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)); // Pointer to the assign function (for deepswap)

ctemplate ctl_max(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)); // Pointer to the assign function (for deepswap)

ctl_size_t ctl_arg_max(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)); // Pointer to the assign function (for deepswap)

ctemplate ctl_min(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)); // Pointer to the assign function (for deepswap)

ctl_size_t ctl_arg_min(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)); // Pointer to the assign function (for deepswap)


#endif