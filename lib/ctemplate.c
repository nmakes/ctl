#include "ctemplate.h"

/*
	Defining basic library functions for the ctemplate type
*/

ctl_size_t ctl_size(ctemplate t)
{
	return t.size;
}


ctemplate ctl_next(
	ctemplate t, // Reference to the ctemplate
	ctl_size_t n) // How many steps to move in memory
{
	void * p = (void*) (  (char*) t.ptr + n * t.size  );
	ctemplate t_new = {p, t.size};
	return t_new;
}


ctemplate ctl_prev(
	ctemplate t, // Reference to the ctemplate
	ctl_size_t n) // How many steps to move in memory
{
	void * p = (void*) (  (char*) t.ptr - n * t.size  );
	ctemplate t_new = {p, t.size};
	return t_new;
}


void ctl_swap( // Performs a deep swap!
	ctemplate *t1, // First argument
	ctemplate *t2, // Second argument
	void (*assign)(ctemplate * larg, ctemplate * rarg)) // assign operator to copy data across congruent templates
{
	ctl_assert(t1->size == t2->size, "Template element size mismatch")

	ctemplate temp;
	temp.ptr = malloc(t1->size);
	temp.size = t1->size;

	assign(&temp, t1);
	assign(t1, t2);
	assign(t2, &temp);

	free(temp.ptr);
}


void ctl_assert(
	int condition, // Condition to assert
	char * message) // Message to throw if condition fails
{
	if (!condition)
	{
		printf("ERROR: Assert Failed with the message \"%s\"", message);
		exit(1);
	}
}