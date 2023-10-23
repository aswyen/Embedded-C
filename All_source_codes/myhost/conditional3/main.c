/*
 * main.c
 *
 *  Created on: Mar 12, 2023
 *      Author: Alec
 */

#include <stdio.h>

#define FIRST_THRESHOLD 9520
#define SECOND_THRESHOLD 38700
#define THIRD_THRESHOLD 82500

#define FIRST_RATE 0.0
#define SECOND_RATE 0.12
#define THIRD_RATE 0.22
#define FOURTH_FIXED 1000
#define FOURTH_RATE 0.32


int main(void){


	double income, tax = 0.0;

	printf("Marginal tax calculator!\n");
	printf("Brackets:\n");
	printf("Up to $9525: 0%%\n");
	printf("$9526 to $38700: 12%%\n");
	printf("$38701 to $82500: 22%%\n");
	printf("More than $82500: 32%% + $1000\n");
	printf("------------------------------\n");
	printf("Enter income:");

	scanf("%lf", &income);

	//First Braket
	if(income <= FIRST_THRESHOLD){
		tax = income * FIRST_RATE;
	}
	//Second Bracket
	else if(income > FIRST_THRESHOLD && income <= SECOND_THRESHOLD){
		tax = FIRST_THRESHOLD * FIRST_RATE;
		tax += (income - FIRST_THRESHOLD) * SECOND_RATE;
	}
	//Third Bracket
	else if(income > SECOND_THRESHOLD && income <= THIRD_THRESHOLD){
		tax = FIRST_THRESHOLD * FIRST_RATE;
		tax += (SECOND_THRESHOLD - FIRST_THRESHOLD) * SECOND_RATE;
		tax += (income - SECOND_THRESHOLD) * THIRD_RATE;
	}
	//Fourth Bracket
	else{
		tax = FIRST_THRESHOLD * FIRST_RATE;
		tax += (SECOND_THRESHOLD - FIRST_THRESHOLD) * SECOND_RATE;
		tax += (THIRD_THRESHOLD - SECOND_THRESHOLD) * THIRD_RATE;
		tax += ((income - THIRD_THRESHOLD) * FOURTH_RATE) + FOURTH_FIXED;
	}

	printf("Marginal Tax Owed: %.2lf", tax);

	return 0;
}

