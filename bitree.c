/*
 *  bitree.c
 *  
 *
 *  Created by Hui Kang on 10/31/10.
 *  Copyright 2010 Stony Brook University. All rights reserved.
 *
 */

#include "bitree.h"

struct Node;

static int *int_data;

#define TRUE 1;
#define FALSE 0;

static struct Node *root;
void insert(struct Node *root, struct Node *cn);

/* help functions */
void usage() { printf("Please provide input data file.\n");}
int read_file(char *filename);

int main (int argc, char *argv[]) {
	int rval = 0;
	
	if (argc < 2) {
		usage();
		return 0;
	}
	
	rval=read_file(argv[1]);
	if (!rval) {
		printf("Failed to read file\n");
		return 0;
	}
	printf("File opened successfully.\n");
	
	root = (struct Node*) malloc(sizeof(Node));
	
	printf("%ld\n", sizeof(Node));
	return 1;
}

/********** Operation functions ********************/
void insert(struct Node *root, struct Node *cn) {
	
}

/********** Helper functions ***********************/
int read_file(char *filename) {
	FILE *file;
	char line[128];
	int rc = 1;
	int line_no=0;
	int num_data=0;
	
	printf("Open input file: %s\n", filename);
	if (!(file = fopen(filename, "r"))) {
		return rc = 0;
	}
	
	/* read each line from the input file */
	int initialized = FALSE;
	while (fgets(line, sizeof(line), file) != NULL) {
		if (!initialized) {
			int_data = (int *)malloc(sizeof(int));
			printf("init int_data\n");
			initialized = TRUE;
		}
		line_no++;
		int tmp;
		if (memchr(line, '.', sizeof(line)) != NULL) {
			printf("Line %d is not an integer\n", line_no);
			continue;
		}
		tmp=atoi(line);
		if ( tmp == 0) {
			printf("Line %d is not an integer\n", line_no);
		}
		else {
			// printf("Converted to %d\n", tmp);
			num_data++;
		}
	}
	
	printf("%d integer(s) in total.\n", num_data);
	fclose(file);
	return rc;
}
