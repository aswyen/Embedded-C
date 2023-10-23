/*
 * main.c
 *
 *  Created on: Mar 12, 2023
 *      Author: Alec
 */


#include<stdio.h>

int main(void){

	int val1, val2 = 0;

	printf("Enter two integer values separated by a space:");

	scanf("%d %d", &val1, &val2);

	if(val1 > val2){
		printf("%d > %d\n", val1, val2);
	}else if(val2 > val1){
		printf("%d < %d\n", val1, val2);
	}else{
		printf("%d == %d\n", val1, val2);
	}



	return 0;
}
