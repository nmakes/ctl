#include "ctemplate.h"

#ifndef __CTEMPLATE_GREEDY_H
#define __CTEMPLATE_GREEDY_H



void ctl_fractional_knapsack(
	ctemplate values,
	ctemplate weights,
	int (*compare)(ctemplate, ctemplate),
	int (*assign)(ctemplate, ctemplate),
	ctemplate solution);




#endif