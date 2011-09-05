/*
 *  util.h
 *  
 *
 *  Created by hkang on 12/3/10.
 *  Copyright 2010 Stony Brook University. All rights reserved.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define GOLDEN_RATIO_PRIME_32 0x9e370001UL
#define GOLDEN_RATIO_PRIME GOLDEN_RATIO_PRIME_32


unsigned long hash_int(int key) {
	printf("Hash key for %u\n", key);
	
	unsigned long hash = key * GOLDEN_RATIO_PRIME_32;
	
	return hash >> (32 - 10);
}
