/*
 * GIT test - B
 * GIT test - C
 * GIT test - D
 *
 * some change
 */

#include <stdlib.h>
#include <stdio.h>

#define VALID_GROUPIP(x)	( x>0 && x<10000 )? 1: 0

static int selectBucket2(int current, int total, int buckets, int ratios[]) {
	
	int bucket = -1;
	int unit = 0;
	int i = 0;
	for (; i < buckets; i++) {
		unit += ratios[i];
	}
	int *selector = (int *)malloc(sizeof(int) * buckets);
	
	int remainder;
	remainder = current % unit;
	
	i=0;
	for (; i<buckets; i++) {
		int j=0;
		for (; j < ratios[i]; j++) {
			selector[i]++;
		}
	}
	
	// Accumulate the selector value
	for (i = 1; i < buckets; i++) {
		selector[i] += selector[i - 1];
	}	
	
	for (i = 0; i < buckets; i++) {
		printf("%d\n", selector[i]);
	}
	
	bucket = 0;
	for (; bucket < buckets; bucket++)
		if (remainder < selector[bucket])
			break;
	return bucket;
}

static int selectBucket(int current, int total, int buckets, int ratios[]) {
	
	int unit = 0;
	int i = 0;
	for (; i < buckets; i++) {
		unit += ratios[i];
	}
	int *selector_unit = (int *)malloc(sizeof(int) * unit);
	int *selector = (int *)malloc(sizeof(int) * buckets);
	int base = total / unit;
	int remainder = total % unit;
	
	printf("remainder=%d\n", remainder);
	memset(selector, 0, sizeof(int)*buckets);
	memset(selector_unit, 0, sizeof(int)*unit);
	
	// Assign the bucket size to the selector
	i = 0;
	for (; i < unit; i++) {
		selector_unit[i] = base;
		if (i < remainder)
			++selector_unit[i];
		printf("%d\n", selector_unit[i]);
	}

	i = 0;
	int j = 0;
	int start = 0;
	for (; i < buckets; i++) {
		int index = 0;
		for (; index < ratios[i]; index++, j++) {
			selector[i] += selector_unit[j];
			//printf("j=%d, selectunit=%d\n", j, selector_unit[j]);
		}
		//printf("%d\n", selector[i]);
	}
	
	printf("\n");
	// Accumulate the selector value
	for (i = 1; i < buckets; i++) {
		selector[i] += selector[i - 1];
	}
	i=0;
	for (i = 0; i < buckets; i++) {
		printf("%d\n", selector[i]);
	}
	int bucket = 0;
	for (; bucket < buckets; bucket++)
		if (current < selector[bucket])
			break;
	
	free(selector);
	free(selector_unit);
	return bucket;
}

int main(int argc, char **argv)
{
	printf("Hello, I am a tester\n");
	VALID_GROUPIP(100);
	
	printf("valid=%d \n", VALID_GROUPIP(100));
	printf("end\n");
	
	if ( VALID_GROUPIP(100) ) {
		printf("I am valid.\n");
	}
	
	int i = 0;
	int ratios[] = {3, 1};
	/*ratios[0] = 4;
	ratios[1] = 1;
	ratios[2] = 2;*/
	for (; i < 100; i++)
		printf("curr=%d, select=%d\n", i, selectBucket2(i, 100, 2,ratios));
}
