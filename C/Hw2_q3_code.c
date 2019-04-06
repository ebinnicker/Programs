/*
Emily Binnicker
UIN: 524003728
CSCE 206 - 503
Assignment 2
*/

#include <stdio.h>


/*This program follows the Fibonacci sequence. The user inputs a number index and the output
the Fibonacci number. If the user inputs 1 or 0 they must enter a valid number (>1)
*/
int main(void)
{
	int n, a, b, c, i; //n is the user input; a, b, and c are used for the to calculate the fibonacci number; i is the counter variable
	
	//user input for the index value
	printf("Input the index of the Fibonacci number you want to calculate: ");
	scanf("%d", &n);
	a = 0;
	b = 1;
	
	//index value must be 1 or 0, loops until this condition is met.
	while (n<=1)
	{
		printf("Illegal input!\n");
		printf("Input the index of the Fibonacci number you want to calculate: ");
		scanf("%d", &n);
		return n;
	}
	
	a = 0;
	b = 1;	
	
	
	//produces the Fibonacci value by calculating previous two values.
	for(i=2;i<=n; i++){
		c = a+b;
		a = b;
		b = c;
	}
	printf("Fibonacci number of index %d is %d", n,b);
	
	
	return 0;
	
	
	
	
}