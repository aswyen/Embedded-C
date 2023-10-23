/*
 * main.c
 *
 *  Created on: Mar 12, 2023
 *      Author: Alec
 */


#include <stdio.h>
#include "area.h"

int main(void){

	char option;
	int err = 0;
	double area = 0.0;

	printf("Select from the following options for area calculation:\n");
	printf("t - Triangle\n");
	printf("z - Trapezoid\n");
	printf("c - Circle\n");
	printf("r - Rectangle\n");
	printf("s - Square\n");

	scanf("%c", &option);

	switch(option){
	case 't':
		area = triangle();
		break;
	case 'z':
		area = trapezoid();
		break;
	case 'c':
		area = circle();
		break;
	case 'r':
		area = rectangle();
		break;
	case 's':
		area = square();
		break;
	default:
		printf("Input Error - not a valid option.\n");
	}
	if(!err){
		printf("Area is %lf", area);
	}


	return 0;
}
