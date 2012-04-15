#include<stdlib.h>
#include <stdio.h>

typedef struct stack_t {
  int *stack;
  int *minstack;
  int top_s;
  int top_m;
}stack_t;

int findmin(stack_t *stack) {
  int index = stack->top_m - 1;
  if (index < 0) {
    perror("Out of stack!!");
    exit(2);
  }
  int value = stack->minstack[stack->top_m - 1];
  return value;
}

void push (int number, stack_t* stack) {
  printf("push %d into stack\n", number);
  stack->stack[stack->top_s++] = number;

  if (stack->top_m == 0) {
    stack->minstack[stack->top_m++] = number;
  }
  else if (number <= stack->minstack[stack->top_m-1]){
    stack->minstack[stack->top_m++] = number;
  }
}

int pop(stack_t *stack) {
  int index = stack->top_s - 1;
  if (index < 0) {
    perror("Out of stack!");
    exit(2);
  }
  int value = stack->stack[index];

  if (value == findmin(stack)) {
    stack->top_m--;
  }
  stack->top_s--;
  return value;
}


int main () {

  int count = 0;
  int i = 0;
  
  /* Put the input number here. */
  int input[] = {3,2,3,4,5,6,1};
  while (input[i])
    i++;
  count = i;

  stack_t  stack; 
  stack.stack = (int*) malloc(sizeof(int) * count);
  if (!stack.stack)
    return 0;
  stack.minstack = (int*) malloc(sizeof(int) * count);
  if (!stack.minstack)
    return 0;
  stack.top_s = 0;
  stack.top_m = 0;
  stack.minstack[0] = 65535;

  /* push all number into stack. */
  for (i = 0; i < count; i++) {
    push(input[i], &stack);
  }
  printf("All number are pushed to the stack.\n\n");
  

  /* Do any number of pop and findmin here. */
  printf("min is %d\n", findmin(&stack));
  printf("pop is %d\n", pop(&stack));
  printf("min is %d\n", findmin(&stack));
  printf("pop is %d\n", pop(&stack));
  printf("min is %d\n", findmin(&stack));
  

  free(stack.stack);
  free(stack.minstack);
  return 1;
  
}
