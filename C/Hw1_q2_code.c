/*
Emily Binnicker
UIN: 524003728
CSCE 206 - 503
Assignment 1
*/


#include <stdio.h>

//This program allows the user to input the price of 3 different
//items and how many they would like to purchase. The sum is found
//as well as adding a 10% tax. This total is displayed in the output.
int main(void)
{
	double price1, price2, price3, sum, tax, total;
	int num1, num2, num3;
	
	printf("Input the price of item1: $");
	scanf("%lf", &price1);
	printf("Input the number of item1 you bought: ");
	scanf("%d", &num1);
	printf("Input the price of item2: $");
	scanf("%lf", &price2);
	printf("Input the number of item2 you bought: ");
	scanf("%d", &num2);
	printf("Input the price of item3: $");
	scanf("%lf", &price3);
	printf("Input the number of item3 you bought: ");
	scanf("%d", &num3);
	
	sum = ((num1*price1)+(num2*price2)+(num3*price3));
	tax = (sum*.1);
	total = sum + tax;
	
	printf("Total cost = $%.2lf", total);

	return 0;
}