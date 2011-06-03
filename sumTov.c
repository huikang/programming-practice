/*
 * Find all pairs of intergers within an array which sum to 
 * a given value V.
 */

#include "util.h"

int input[4] = {1, 2, 3, 4};
static V = 100;

int main(int argc, char **argv) {
  int rc = 1;
	int key = 0;
	
	key = hash_int(input[0]);
	printf("key=%d\n", key);
	
	key = hash_int(input[1]);
	printf("key=%d\n", key);
	
  return rc;
}
