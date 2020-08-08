#include "ctemplate.h"

#ifndef __CTEMPLATE_SORTING_H
#define __CTEMPLATE_SORTING_H



/*
	Search utilities using templates
*/

void ctl_selection_sort(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)); // Pointer to the assign function (for deepswap)

void ctl_insertion_sort(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)); // Pointer to the assign function (for deepswap)

void ctl_bubble_sort(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)); // Pointer to the assign function (for deepswap)

void ctl_quick_sort(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)); // Pointer to the assign function (for deepswap) 

void ctl_quick_sort_recursive(
	ctemplate arr,
	ctl_size_t low,
	ctl_size_t high,
	int (*compare)(ctemplate, ctemplate),
	void (*assign)(ctemplate, ctemplate));

ctl_size_t ctl_quick_sort_partition(
	ctemplate arr,
	ctl_size_t low,
	ctl_size_t high,
	int (*compare)(ctemplate, ctemplate),
	void (*assign)(ctemplate, ctemplate));

#endif