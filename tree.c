//
//  tree.c
//  
//
//  Created by Hui Kang on 4/1/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include "tree.h"

void insert_tree(node **l, int x) {
  node *p;
  
  if (*l == NULL) {
    p = malloc(sizeof(node));
    p->val = x;
    p->left = p->right = NULL;
    *l = p;
    return;
  }
  
  if (x < (*l)->val)
    insert_tree(&((*l)->left), x);
  else
    insert_tree(&((*l)->right), x);  
}

/* Create a binary tree on an array of integer 
 */
void build_binary_tree(node **root, int *input, int size) {
  node *head;
  int i;
  
  printf("%s\n", __FUNCTION__);
  
  if (size == 0) {
    printf("array size is 0\n");
    return;
  }
  
  for (i = 0; i < size; i++) {
    insert_tree(&head, input[i]);
  }
  *root=head;
}

void traverse_tree_post(node *root) {
	node *tmp;
	
	if (!root)
		return;
	traverse_tree_post(root->left);
	traverse_tree_post(root->right);
	printf("%i ", root->val);
}

