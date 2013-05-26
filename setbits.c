//
//  setbits.c
//
//  Given two 32 bit numbers, N and M, and 2 bit positions, i and j. Write
//  a method set all bits between i and j in N equal to M.
//
//  Created by Hui Kang on 8/24/12.
//
//

#include <stdio.h>
#include <math.h>


unsigned int setbits(unsigned int, int, int, unsigned int);

int main(int argc, char *argv[])
{
	unsigned int x, y, r;
	unsigned short p, n;
	
	x = 0x501c;
	y = 0x6a;
	p = 10;
	n = 4;
    printf("Convert 0x%x bit positions (%d %d) to 0x%x\n", x, p, n, y);
	r = setbits(x, p, n, y);
	printf("result = %u (0x%x)\n", r, r);
    return 0;
}

/*	
 * xxxx..1111..xxxxx
 * r = 1111..yyyy..11111
 * So we should turn x to the format of xxxx 1111 xxxx
 * y to the format of 1111...yyyy...1111
 */

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
	unsigned int mask;
	int result;
	
	/* 
     * create the mask of 1111..100000, for x
	 * so we can get the desired x by "or"
	 */
	mask = (unsigned int)(pow(2, n) - 1) << (p - n + 1);
	printf("mask=0x%x\n", mask);

	x = x | mask;
	printf("new x = %u\n", x);

	/* get the last n bit of y */
	y = y & (unsigned int)(pow(2, n) - 1);
	printf("y = %u\n", y);

	/* create the mask of 1111..0000...1111 for y
	 * so we can get the y 
	 */
	mask = (~0) << (p+1);
	printf("mask=0x%x\n", mask);
	mask = mask | (unsigned int)(pow(2, p - n + 1) - 1);
	printf("mask=0x%x\n", mask);
	
	y = (y << (p - n + 1)) | mask;
	printf("y = %u\n", y);
	
	return result = x & y;
}
