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

struct _node {
	struct _node *left;
	struct _node *right;
	
	struct _node *parent;
	
	int val;
};

typedef struct _node Node;
