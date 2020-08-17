// Rough implementation of structures and algorithms (to include in the generic library)

#include <stdio.h>
#include <stdlib.h>


/*

	Set, Find, Union, Collapse.

*/

typedef struct
{
	int * e;
	int n;
} set;

set set_initialize(int n)
{
	set s;

	s.e = (int *) malloc(sizeof(int) * (n+1));
	s.n = n;

	for(int i=1; i<=n; i++)
	{
		s.e[i] = -1;
	}

	return s;
}

int set_find(set s, int n) // implemented as collapsing find
{
	if(s.e[n] < 0)
	{
		return n;
	}
	else
	{
		s.e[n] = set_find(s, s.e[n]);
		return s.e[n];
	}
}

void set_union(set s, int a, int b)
{
	if(s.e[a] < 0 && s.e[b] < 0)
	{
		if(s.e[a] < s.e[b])
		{
			s.e[a] = s.e[a] + s.e[b];
			s.e[b] = a;
		}
		else
		{
			s.e[b] = s.e[b] + s.e[a];
			s.e[a] = b;
		}
	}
	else
	{
		printf("ERROR: Both indices should pertain to head root nodes.\n", );
	}
}

void set_collapse(set s)
{
	int x;
	for(int i=1; i<=s.n; i++)
	{
		if(i>0)
		{
			set_find(s, i);
		}
	}
}


/*

	Graph algorithms:
	1. Shortest path - Dijkstra, Bellman Ford, Floyd-Warshall
	2. MST - Prim's, Kruskal's


*/