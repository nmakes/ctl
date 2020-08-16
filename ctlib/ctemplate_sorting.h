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

ctemplate ctl_arg_selection_sort(
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

void ctl_topk_sort(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	ctl_size_t k, // value of k (number of top elements to be sorted)
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

void ctl_topk_sort(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	ctl_size_t k,
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)); // Pointer to the assign function (for deepswap)

void ctl_merge_sort_merge(
	ctemplate arr,
	ctl_size_t ll, 
	ctl_size_t hl,
	ctl_size_t lr,
	ctl_size_t hr,
	ctemplate scratch,
	int (*compare)(ctemplate, ctemplate),
	void (*assign)(ctemplate, ctemplate));

void ctl_merge_sort_recursive(
	ctemplate arr,
	ctl_size_t low, 
	ctl_size_t high,
	ctemplate scratch,
	int (*compare)(ctemplate, ctemplate),
	void (*assign)(ctemplate, ctemplate));

void ctl_merge_sort(
	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
	ctl_size_t length, // Length of the array
	int (*compare)(ctemplate, ctemplate), // Pointer to the comparator function
	void (*assign)(ctemplate, ctemplate)); // Pointer to the assign function (for deepswap)

// TODO: Implement count sort after implementing lists (chaining required)
// void ctl_count_sort(
// 	ctemplate arr, // ctemplate containing a pointer to the starting address of the array (and element size)
// 	ctl_size_t length, // Length of the array
// 	int (*get)(ctemplate)); // Pointer to the get function

int ctl_is_sorted( // checks if the array is sorted
	ctemplate arr, // ctemplate containing a pointer to the starting address of the sorted array (and size)
	ctl_size_t length, // Length of the array
	int(*compare)(ctemplate, ctemplate)); // Pointer to the comparator function

void ctl_reverse( // reverses the array
	ctemplate arr, // ctemplate containing a pointer to the starting address of the sorted array (and size)
	ctl_size_t length, // Length of the array
	void (*assign)(ctemplate, ctemplate)); // Pointer to the assign function (for deepswap)

void ctl_rotate_inplace( // shifts the array (circular) by the amount
	ctemplate arr, // ctemplate containing a pointer to the starting address of the sorted array (and size)
	ctl_size_t length, // Length of the array
	ctl_size_t count, // Number of shifts to perform
	void (*assign)(ctemplate, ctemplate)); // Pointer to the assign function (for deepswap)

#endif