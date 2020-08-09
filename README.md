# The C-Template Library

## Generic Programming

C++ uses templates to enable the convinience of type definitions at compile time. This enables generic programming while still maintaining the robustness of a strongly typed language.

But, C doesn't have such features. How do we solve it for C?

## Enter: ctemplate.

The idea is to use the power of `void*` pointers to develop an interface which acts like a generic data type. Standard data structure and algorithm implementations will exploit the `ctemplate` interface, while the user will provide elementary functions such as a `compar`ator and an `assign`ment functions.

A typical merge sort function call looks like this:

```
#include <ctl.c>

int arr[] = {9, 3, 7, 5, 6, 4, 8, 2}; // the user wants to sort an integer array
int length = 8; // defines the length of the array

int compare(ctemplate left, ctemplate right) // writes a utility to compare two ctemplates
{
	// the user knows that the data is of type int
	int l = *(int*) left.ptr; 
	int r = *(int*) right.ptr;

	// compares the left and the right arguments
	if(l<r){return -1;}
	else if(l>r){return +1;} 
	else{return 0;}
}

int assign(ctemplate left, ctemplate right) // finally, to perform write, the library expects an assignment operator
{
	// the user knows that the data is of type int and performs assignment
	*(int*) left.ptr = *(int*) right.ptr;
}

// Calling the following lines, sorts the array.

ctemplate wrapper = {arr, sizeof(int)};
ctl_merge_sort( wrapper, length, compare, assign );
```