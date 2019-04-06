/*
Emily Binnicker
UIN: 524003728
CSCE 206 - 503
Assignment 3
*/

#include <stdio.h>

/*
This program uses recursion to follow the Fibonacci sequence. This allows a user to input an index and out the related Fibonacci number.
*/

//this function calcuates the fibonacci number by index location
int fib(int x, int a, int b, int c)
{
	int i = 2;
	c = a+b;
	a = b;
	b = c;
	
	if (i==x){
		return b;
	}
	else{
		x = x-1;
		fib(x,a,b,c);
	}
	
}

//the main function handles the user inputs and what will be outputted.
int main ()
{
	int index, ans, a, b, c, i;
	a = 0;
	b = 1;
	c = 0;
	
	
	printf("Input the index of the Fibonacci number you want to calculate: ");
	scanf("%d", &index);
	
	while (index<=1)
	{
		printf("Illegal input!\n");
		printf("Input the index of the Fibonacci number you want to calculate: ");
		scanf("%d", &index);
		return index;
	}
	
	ans = fib(index,a,b,c);
	printf("Fibonacci number of index %d is %d", index, ans);
}