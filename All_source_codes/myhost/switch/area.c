/*
 * area.c
 *
 *  Created on: Mar 12, 2023
 *      Author: Alec
 */
#include <stdio.h>

#define PI 3.14159

double triangle(){
	double height, base, area = 0.0;
	printf("Enter Height and Base:");
	scanf("%lf %lf", &height, &base);

	area =(height * base) / 2;

	return area;
}

double trapezoid(){
	double a, b, height, area = 0.0;
	printf("Enter side A, B, and Height:");
	scanf("%lf %lf %lf", &a, &b, &height);

	area = height * ((a + b) / 2);

	return area;
}

double circle(){
	double radius, area = 0.0;
	printf("Enter Radius:");
	scanf("%lf", &radius);

	area = PI * (radius * radius);

	return area;
}

double rectangle(){
	double a, b, area = 0.0;
	printf("Enter Side A and B length:");
	scanf("%lf %lf", &a, &b);

	area = a * b;

	return area;

}

double square(){
	double a, area = 0.0;
	printf("Enter Side length:");
	scanf("%lf", &a);

	area = a * a;

	return area;

}

