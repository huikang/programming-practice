/*
 * GIT test - B
 * GIT test - C
 * 
 */

#include <stdlib.h>
#include <stdio.h>

#define VALID_GROUPIP(x)	( x>0 && x<10000 )? 1: 0

int main(int argc, char **argv)
{
	printf("Hello, I am a tester\n");
	VALID_GROUPIP(100);
	
	printf("valid=%d \n", VALID_GROUPIP(100));
	printf("end\n");
	
	if ( VALID_GROUPIP(100) ) {
		printf("I am valid.\n");
	}	 
}
