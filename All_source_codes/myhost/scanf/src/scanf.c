/*
 ============================================================================
 Name        : scanf.c
 Author      : Alec
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int a, b, c = 0;
	double avg =0;

	printf("Enter 3 integer values separated by spaces:");

	scanf("%d %d %d", &a, &b, &c);

	avg = (a + b + c) / 3.0;

	printf("The average of %d, %d, %d is %lf\n", a, b, c, avg);


	return EXIT_SUCCESS;
}
