//
//  tree.h
//  
//
//  Created by Hui Kang on 4/1/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _tree_h
#define _tree_h

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	struct _node *left;
	struct _node *right;
	struct _node *parent;
	int val;
} node;

void build_binary_tree(node **root, int *input, int size);

void traverse_tree_post(node *root);

#endif
