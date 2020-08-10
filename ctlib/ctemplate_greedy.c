#include "ctemplate_greedy.h"


ctemplate ctl_fractional_knapsack( // returns a float array in template
	ctemplate values,
	ctemplate weights,
	ctl_size_t length,
	float (*divide)(ctemplate, ctemplate));
{
	ctemplate solution = {malloc(sizeof(float) * length), sizeof(float)};
	ctemplate value_per_weight = {malloc(sizeof(float) * length), sizeof(float)};

	for(ctl_size_t i = 0; i<length; i++)
	{
		(*(float*)ctl_next(value_per_weight, i).ptr) = divide(ctl_next(values, i), ctl_next(weights, i));
	}

	free(value_per_weight.ptr);

	fprintf(stderr, "CTL_WARNING::ctl_fractional_knapsack: malloc'd memory for fractional knapsack solution. Remember to free the solution pointer.\n");

	return solution;
}