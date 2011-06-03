/*
 * Search for a substring in a sorted strings S. S may contain empty characters.
 * Use binary search
 */

#include "util.h"

char *str[] = {"a", """", """", "b", "cd", """"};
char *key = "x";

// char *s={"x", """"};

int search(char **string, char * val, int first, int last) {
	printf("%s\n", string[3]);
	return 1;
}

int main(int argc, char **argv) {
  int length = strlen(str[0]);
	
	printf("Input string: %c\n", str[0][0]);
	printf("String length: %i\n", length);
	
	search(str, key, 0, length-1);
	
	return 1;
}
