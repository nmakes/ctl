# The C-Template Library

## Generic Programming

C++ uses templates to enable the convinience of type definitions at compile time. This enables generic programming while still maintaining the robustness of a strongly typed language.

But, C doesn't have such features. How do we solve it for C?

## Enter: ctemplate.

The idea is to use the power of `void*` pointers to develop an interface which acts like a generic data type. Standard data structure and algorithm implementations will exploit the `ctemplate` interface, while the user will provide elementary functions such as a comparator and an assignment function.

Let's demonstrate by example. Suppose we have an integer array as follows:

```
#include <ctl.c>

int arr[] = {9, 3, 7, 5, 6, 4, 8, 2}; // the user wants to sort an integer array
int length = 8; // defines the length of the array
```

We would like to sort the array above without writing a custom sort function. We now use `ctemplate`s to leave the sorting task to the library. First, we must define the `compare` and `assign` functions knowing that we perform sorting on an `int` array.

```
int compare(ctemplate left, ctemplate right)
{
	// we know that the data is of type int (we want to sort an integer array)
	int l = *(int*) left.ptr; 
	int r = *(int*) right.ptr;

	// compares the left and the right arguments and produce the sign of the difference
	if(l<r){return -1;}
	else if(l>r){return +1;} 
	else{return 0;}
}

int assign(ctemplate left, ctemplate right) // finally, to perform write, the library expects an assignment operator
{
	// the user knows that the data is of type int and performs assignment
	*(int*) left.ptr = *(int*) right.ptr;
}
```

The sort function call is simply called by passing a `ctemplate` wrapper for the integer array. We specify both the base address and the size of each element in the array.

```
// Calling the following lines, sorts the array.

ctemplate wrapper = {arr, sizeof(int)};
ctl_merge_sort( wrapper, length, compare, assign );
```

