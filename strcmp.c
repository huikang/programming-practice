/*
 *  strcmp.c
 *		
 *	Compare the two strings.
 *
 *  Created by hkang on 12/3/10.
 *  Copyright 2010 Stony Brook University. All rights reserved.
 *
 */

#include "util.h"

char s1[] = "Heh";
char s2[] = "H";

int main(int argc, char ** argv) {
	int rc = 1;
	int i = 0;
	char op;
	
	for (i = 0; s1[i]==s2[i]; i++) {
		if (s1[i] == '\0') {
			printf("Move to end.\n");
			rc = 0;
			op = '=';
			break;
		}
	}
	
	/* Out of loop, not Equal */
	if (s1[i] > s2[i]) {
		rc = 1;
		op = '>';
	}
	else if (s1[i] < s2[i]) {
		rc = -1;
		op = '<';
	}
	
	printf("%s %c %s\n", s1, op, s2);
	return 1;
}
