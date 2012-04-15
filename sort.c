/*
 * This file implment different sorting algorithms
 *
 */

#include "util.h"

typedef int item;
#define SIZE 1000

#define key(A) (A)
#define less(A, B) (key(A) < key(B))

#define exchange(A, B) { item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exchange(A, B)

static int int_array[SIZE];

void insertion_sort(int a[])
{
  int i, j;

  for (i = 1; i < SIZE; i++) {
		j = i;
		while (a[j] < a[j - 1] && (j-1) >= 0) {
			exchange(a[j], a[j - 1]);
			j--;
		}
	}
}

void shuffle(int a[]) {
	int i;
	int position;
	for (i = 0; i < SIZE; i++) {
		position = rand() % (SIZE - i + 1) + i;
		exchange(a[i], a[position]);
	}
}

void print_array(int a[]) {
	int i;
	for (i = 0; i < SIZE; i++)
		printf("%i ", int_array[i]);
	printf("\n");
}

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < SIZE; i++)
		int_array[i] = i; 
	shuffle(int_array);
	print_array(int_array);
	
	insertion_sort(int_array);
	print_array(int_array);

  return 0;
}
