/*
 * This file implment different sorting algorithms
 *
 */

#include "util.h"

typedef int item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))

#define exchange(A, B) { item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exchange(A, B)

void insertion_sort(item a[], int l, int r)
{
  int i, j;

  for (i=)
}

int main(int argc, char *argv[])
{
  
  return 0;
}
