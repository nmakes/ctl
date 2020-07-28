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