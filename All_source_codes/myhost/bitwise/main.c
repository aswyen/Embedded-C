/*
 * main.c
 *
 *  Created on: Mar 16, 2023
 *      Author: Alec
 */


#include <stdio.h>


void bitwise(int a, int b){
	printf(" OP: A        B        OUT\n");
	printf("AND: %08X %08X %08X\n", a, b, a&b);
	printf(" OR: %08X %08X %08X\n", a, b, a|b);
	printf("XOR: %08X %08X %08X\n", a, b, a^b);
	printf("NOT: %08X %08X %08X %08X\n", a, b, ~a, ~b);
}


int main(void){

	int a, b = 0;

	printf("Enter two integers:");
	scanf("%d %d", &a, &b);

	bitwise(a,b);


	return 0;
}
