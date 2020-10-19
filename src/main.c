#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sort.h"

#define FROM_STRING_LENGTH 7
#define TO_STRING_LENGTH 5

#define LESS_THAN_ONE_PARAMS -1
#define MORE_THAN_TWO_PARAMS -2
#define REPEAT_PARAM -3
#define INCORRECT_PARAMS -4

#define INPUT_LIMIT 100

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		return LESS_THAN_ONE_PARAMS;
	}
	else if (argc > 3)
	{
		return MORE_THAN_TWO_PARAMS;
	}

	long long from_value = 0, to_value = 0;
	int from_count = 0, to_count = 0;

	for (int i = 1; i < argc; i++)
	{
		if (strncmp(argv[i], "--from=", FROM_STRING_LENGTH) == 0)
		{
			from_value = strtoll(argv[i] + FROM_STRING_LENGTH, NULL, 10);
			from_count += 1;
		}
		else if (strncmp(argv[i], "--to=", TO_STRING_LENGTH) == 0)
		{
			to_value = strtoll(argv[i] + TO_STRING_LENGTH, NULL, 10);
			to_count += 1;
		}
	}

	if (from_count > 1 || to_count > 1)
	{
		return REPEAT_PARAM;
	}
	else if (from_count == 0 && to_count == 0) 
	{
		return INCORRECT_PARAMS;
	}

	long long input[INPUT_LIMIT];
	long long input_copy[INPUT_LIMIT];
	int input_count = 0;

	for (int k = 0; k < INPUT_LIMIT; k++)
	{
		long long input_value;
		char c;

		if (scanf("%lld%c", &input_value, &c) != 2)
		{
			break;
		}

		if (from_count == 1 && input_value <= from_value)
		{
			fprintf(stdout, "%lld ", input_value);
		}
		else if (to_count == 1 && input_value >= to_value)
		{
			fprintf(stderr, "%lld ", input_value);
		}
		else
		{
			input[input_count] = input_value;
			input_copy[input_count] = input_value;
			input_count++;
		}

		if (c != ' ')
		{
			break;
		}
	}

	bubblesort(input, input_count);
	int change_count = 0;

	for (int i = 0; i < input_count; i++)
	{
		if (input[i] != input_copy[i])
		{
			change_count++;
		}
	}

	printf("\n");

	return change_count;
}
