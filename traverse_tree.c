//
//  traverse_tree.c
//  
//
//  Created by Hui Kang on 4/1/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "tree.h"

#define NUM 20 /* array size */

static int a_int[NUM];

int main(int argc, char *argv[]) {
  node *root;
  int i;
  
  for (i = 0; i < NUM; i++) {
    a_int[i] = rand() % 1000;
  }
  
  build_binary_tree(&root, a_int, NUM);

  traverse_tree_post(root);
  
  //free_tree(root);
}
