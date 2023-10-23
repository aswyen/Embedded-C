/*
 * main.c
 *
 *  Created on: Mar 2, 2023
 *      Author: Alec
 */

#define REQ_NUM_ARGS 3

#include <stdio.h>
#include <stdlib.h>
#include "math.h"

void echo(int a, int b, int res, char op){
	printf("%d = %d %c %d\n", res, a, op, b);
}

int main(int argv, char* argc[]){

	int a, b;

	if (argv != REQ_NUM_ARGS){
		printf("Usage: %s <a> <b>\n", argc[0]);
		return EXIT_FAILURE;
	}

	a = atoi(argc[1]);
    b = atoi(argc[2]);

	echo(a ,b, addi( a,  b), '+');
	echo(a, b, subi( a,  b), '-');
	echo(a, b, multi( a,  b), '*');
	echo(a, b, divi( a,  b), '/');


	return EXIT_SUCCESS;
}
