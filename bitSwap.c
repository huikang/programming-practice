/*
 *  bitSwap.c
 *  
 *
 *  Created by hkang on 12/6/10.
 *  Copyright 2010 Stony Brook University. All rights reserved.
 *
 */

#include "util.h"

static int a = 31;
static int b = 14;

int main(int argc, char *argv[]) {
	int count = 0;
	int c = a ^ b;
	
	for (; c!=0; c>>1) {
		count += c & 1;
	}
	
	printf("Count = %d\n", count);
	return 1;
}
