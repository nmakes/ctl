/*

	C-Template Library (CTL)
	Written by Naveen Venkat
	naveenvenkat.com

	@todo:
		- Add description
		- What is included / not included

*/

#include <stdlib.h>

#ifndef __CTEMPLATE_H
#define __CTEMPLATE_H



/*
	Defining standard names for types
*/

typedef long int ctl_size_t;

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


void ctl_assign_ctl_size_t(ctemplate left, ctemplate right);


void ctl_deep_swap( // Performs a deep swap!
	ctemplate t1, // First argument
	ctemplate t2, // Second argument
	void (*assign)(ctemplate, ctemplate)); // assign operator to copy data across congruent templates


void ctl_assert(
	int condition, // Condition to assert
	char * message); // Message to throw if condition fails


void ctl_exception(
	char * message);

#endif