#include <stdio.h>
#include <stdlib.h>

#define NUMNODE  (5)

typedef struct node {
  int key;
  struct node *next_node;
} node_t;

int gcd(u, v) {
  int t;

  while ( u > 0 ) {
    if ( u < v ) {
      t = u; u = v; v = t;
    }
    u = u - v;
  }
  return v;
}

int main(int argc, char *argv[]) {
  int x, y;
  node_t *n_list[NUMNODE];
  node_t nodes[NUMNODE];

  n_list[0] = (node_t *) malloc (sizeof(node_t));
  n_list[0]->key = 10;
  n_list[1] = (node_t *) malloc (sizeof(node_t));
  n_list[1]->key = 11;

  nodes[0].key = 110;

  while (scanf("%d %d", &x, &y) != EOF) {
    if (x > 0 && y > 0)
      printf("%d %d %d\n", x, y, gcd(x, y));
  }
}
