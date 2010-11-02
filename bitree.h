/*
 *  bitree.h
 *  
 *
 *  Created by Hui Kang on 10/31/10.
 *  Copyright 2010 Stony Brook University. All rights reserved.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _node {
	struct Node *left;
	struct Node *rright;
	
	struct Node *parent;
} Node;

/* insert a node to the binary tree */
void insert(struct Node *root, struct Node *cn);

