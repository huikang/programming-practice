/*
 *  edit_dist.c
 *  
 *
 *  Created by hkang on 2/5/11.
 *  Copyright 2011 Stony Brook University. All rights reserved.
 *
 */

#include "util.h"

#define MAXLEN	100
#define	MATCH		0
#define INSERT	1
#define DELETE	2

typedef struct {
	int cost;
	int parent;
} cell;

cell m[MAXLEN+1][MAXLEN+1];

char s1[] = "aaaxx";
char s2[] = "aabdi";

int string_compare(char *, char *, int, int);
int match(char, char);
int indel(char);

int main(int argc, char** argv) {
	int d1, d2;
	int dist = 0;
	
	printf("s1=%s\n", s1);	
	
	d1 = strlen(s1);
	d2 = strlen(s2);
	
	dist = string_compare(s1, s2, d1-1, d2-1);
	printf("Edit distance is %d\n", dist);
	
	return 0;
}

int string_compare(char *s, char *t, int i, int j) {
	int k;
	int opt[3];
	int lowest_cost;
	
	if (i == 0) return (j * indel(' '));
	if (j == 0) return (i * indel(' '));
	printf("s=%s\n", s);
	opt[MATCH] = string_compare(s, t, i-1, j-1) + match(s[i], t[j]);
	opt[INSERT] = string_compare(s, t, i, j-1) + indel(t[j]);
	opt[DELETE] = string_compare(s, t, i-1, j) + indel(s[i]);
	
	lowest_cost = opt[MATCH];
	for (k=INSERT; k<=DELETE; k++) {
		if (opt[k] < lowest_cost) lowest_cost = opt[k];
	}
	
	return(lowest_cost);
}

int match(char a, char b) {
	if (  a == b ) {
		return 0;
	}
	else {
		return 1;
	}

}

int indel(char a) {
	return 1;
}