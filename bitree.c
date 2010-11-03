/*
 *  bitree.c
 *  
 *
 *  Created by Hui Kang on 10/31/10.
 *  Copyright 2010 Stony Brook University. All rights reserved.
 *
 */

#include "bitree.h"

#define TRUE 1;
#define FALSE 0;

static Node *root;
void insert(Node **,  Node *);

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
	
	root = NULL;
	
	printf("%ld\n", sizeof(Node));
	return 1;
}

void printout(Node * tree) {
	if(tree->left) printout(tree->left);
	printf("%d\n",tree->val);
	if(tree->right) printout(tree->right);
}

/********** Operation functions ********************/
void insert(Node **root,  Node *item) {
	if (!(*root)) {
		*root = item;
		return;
	}
	printf("insert\n");
	if(item->val<(*root)->val)
		insert(&(*root)->left, item);
	else if(item->val>(*root)->val)
		insert(&(*root)->right, item);
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
			Node *curr;
			curr = (Node *) malloc(sizeof(Node));
			curr->left = curr->right = NULL;
			curr->val = tmp;
			num_data++;
			insert(&root, curr);
		}
	}
	printout(root);
	printf("%d integer(s) in total.\n", num_data);
	fclose(file);
	return rc;
}
