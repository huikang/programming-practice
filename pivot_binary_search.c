/*
 * Problem: find an element in an sorted array. Note that the array is rotated
 * once at a pivot.
 *
 */

#include <stdlib.h>
#include <stdio.h>

#define SIZE   10
#define PIVOT  3

static int int_array[SIZE];

void print_array(int int_array[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", int_array[i]);
	}
	printf("\n");
}

void insertion_sort(int int_array[], int n)
{
	int i, j;
	
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j > 0 && int_array[j] < int_array[j - 1]; j--) {
			int tmp = int_array[j];
			int_array[j] = int_array[j - 1];
			int_array[j - 1] = tmp;
		}
	}
}

int check_duplicate(int sorted_array[], int n)
{
	int i, rc;
	int tmp;
	
	rc = 0;
	tmp = sorted_array[0];
	for (i = 1; i < n; i++) {
		if (sorted_array[i] == tmp) {
			rc = 1;
			break;
		}
		else {
			tmp = sorted_array[i];
		}
	}
	return rc;
}

void create_array(int int_array[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		int_array[i] = rand() % 20;
}

int main(int argc, char *argv[])
{
	int duplicated = 1;
	int pivot;

	/* Generate an array of non-duplicated integer 
	 * Try until we get one
	 */
	while (duplicated) {
		create_array(int_array, SIZE);
		insertion_sort(int_array, SIZE);
		print_array(int_array, SIZE);
		duplicated = check_duplicate(int_array, SIZE);
	}

	pivot = PIVOT;
}
