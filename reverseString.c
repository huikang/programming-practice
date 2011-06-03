/*
 *  reverseString.h
 *  
 *
 *  Created by hkang on 12/5/10.
 *  Copyright 2010 Stony Brook University. All rights reserved.
 *
 */

#include "util.h"

char input[]="Input";

int main(int argc, char *argv[]) {
	int len=strlen(input);
	int i = 0;;
	char tmp;
	char *array_pt;
	
	/* This is a constant string, you can not modify
	 * its content.
	 */
	char *ptr_array = "Pointer array";
	printf("Pointer array pointer=%p\n", ptr_array);
	char *ptr = ptr_array;
	printf("Pointer array array=%p\n", ptr);

	printf("Increased Pointer array array=%p\n", ptr);
	printf("size of ptr on a 64bit machine =%lu\n", sizeof(long));
	
	/* ptr[0] = 'A'; */ /* This is error. */;
	ptr = input;
	tmp = input[0];
	ptr[0] = 'A'; /* This is OK. */
	ptr[0] = tmp;

	while (i < len/2) {
		tmp = input[len - 1 - i];		
		input[len- 1 - i] = input[i];
		input[i] = tmp;
		i++;
	}
	
	printf("Reversed string: %s\n", input);
		
	return 1;
}
