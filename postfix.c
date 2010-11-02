/*
 *  postfix.c
 *  
 *  Convert infix to postfix
 *  Usage: 45 + 89 [EOF]
 *
 *  Created by Hui Kang on 8/5/10.
 *  Copyright 2010 Stony Brook University. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *next;
};

static struct node *head;
static struct node *z;
static struct node *t;

void stackinit() {
	head = (struct node*) malloc(sizeof *head);
	z= (struct node*) malloc(sizeof *z);
	head->next = z;
	head->key = 0;
	z->next = z;
}

void push(int v) {
	t = (struct node*) malloc(sizeof *t);
	t->key = v; t->next = head->next;
	head->next = t;
}

int pop() {
	int x;
	
	t = head->next; head->next = t->next;
	x = t->key;
	free(t);
	return x;
}

int stackempty() {
	return head->next == z;
}

int main() {
	char c;
	
	for (stackinit(); scanf("%1s", &c) != EOF; ) {
		if (c == ')') printf("%1c", (char)pop());
		if (c == '+') push((int) c);
		if (c == '*') push((int) c);
		while (c>='0' && c<='9') {
			printf("%1c", c); scanf("%1c", &c);
		}
		if (c!='(') {
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}