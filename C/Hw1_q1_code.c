/*
Emily Binnicker
UIN: 524003728
CSCE 206 - 503
Assignment 1
*/


#include <stdio.h>


//This program takes the mile for Monday - Friday that the user
//inputs and finds the sum and average. This data is the output.
int main(void)
{
	float m,t,w,h,f;
	float sum, average;
	
	printf("Input the miles for Monday: ");
	scanf("%f", &m);
	printf("Input the miles for Tuesday: ");
	scanf("%f", &t);
	printf("Input the miles for Wednesday: ");
	scanf("%f", &w);
	printf("Input the miles for Thursday: ");
	scanf("%f", &h);
	printf("Input the miles for Friday: ");
	scanf("%f", &f);
	
	sum = (m+t+w+h+f);
	printf("Sum = %.2f miles\n", sum);
	average = sum/5;
	printf("Average = %.2f miles", average);
	
	return 0;
	
}