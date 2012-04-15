#include <stdlib.h>
#include <stdio.h>

int len_str(char *str) {
	int end = 0;
	while (str[end++] != '\0');
	return end;
}

void reverseStr(char *str) {
	int end, start;

	end = start = 0;
	while (str[end++] != '\0');
	
	end--; end--;
	while (start < end) {
		char tmp = str[end];
		str[end] = str[start];
        str[start] = tmp;
		start++; end--;
	}
}

int main(int argc, char *argv) {
	char input[6] = "hello";
	int len;

	len = len_str(input);
	reverseStr(input);
	printf("len is %d\n", len);
	printf("Reversed str is %s.\n", input);
}
