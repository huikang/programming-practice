#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int value;
  struct node_t *next;
} node_t;

void print_list(node_t *head)
{
  node_t *tmp = head;
  while (tmp) {
    printf("%d ", tmp->value);
    tmp = tmp->next;
  }
	printf("\n");
}

void dealloc_list(node_t *head)
{
  node_t *tmp = head;
  node_t *next = tmp;
  while (next) {
    printf("free %d\n", next->value);
    tmp = next;
    next = next->next;
    free(tmp);
  }
}

void reverse_list(node_t **head)
{
	int i = 0;
  node_t *previous = NULL;
  node_t *current = *head;
  node_t *forward;

	while (current != NULL) {
		printf("round %d\n", i++);
  	forward = current->next;
    current->next = previous;
    previous = current;
    current = forward;
  }
	
	*head = previous;
	printf("Reverse done\n");
	printf("head %d\n", previous->value);
}

node_t *head;

int main(int argc, char *argv[])
{
  int i;
  node_t *tmp;
  
  /* Initialize a linked list */
  tmp = malloc(sizeof(node_t));
  tmp->value = 0;
  tmp->next = NULL;
  head = tmp;
  
  for (i = 1; i < 5; i++) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = i;
    new_node->next = NULL;
    
    tmp->next = new_node;
    tmp = new_node;
  }
  
  print_list(head);
  
  reverse_list(&head);
  
	print_list(head);
  dealloc_list(head);
  return 0;
}
