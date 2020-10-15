#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sort.h"

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		return -1;
	}
	else if (argc > 3)
	{
		return -2;
	}

	long long from_value = 0, to_value = 0;
	int from_count = 0, to_count = 0;

	for (int i = 1; i < argc; i++)
	{
		if (strncmp(argv[i], "--from=", 7) == 0)
		{
			from_value = strtoll(argv[i] + 7, NULL, 10);
			from_count += 1;
		}
		else if (strncmp(argv[i], "--to=", 5) == 0)
		{
			to_value = strtoll(argv[i] + 5, NULL, 10);
			to_count += 1;
		}
	}

	if (from_count > 1 || to_count > 1)
	{
		return -3;
	}
	else if (from_count == 0 && to_count == 0 && argc == 3)
	{
		return -4;
	}

	long long input[100];
	long long input_copy[100];
	int input_count = 0;

	for (int k = 0; k < 100; k++)
	{
		long long input_value;

		if (scanf("%lld", &input_value) == 0)
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

		char c = getchar();
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
