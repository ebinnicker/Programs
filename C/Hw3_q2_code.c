/*
Emily Binnicker
UIN: 524003728
CSCE 206 - 503
Assignment 3
*/

#include <stdio.h>

/*
The factr() fuction here takes the value n and tests if it is equal to 1. If it is not it uses recursion
to find the previous index of the sequence by following the pattern that the previous index plus n-1. 
This recursion repetition is continues until n=1, working backwords. When 1 is reached, the answer program works
forward adding each of the previous values until the index is reached. 
*/
int factr(int n){
	int answer;
	
	if(n==1) 
		return 1;
	answer = factr(n-1)+(n-1);
	return answer;


}

/*
The main function here asks the user to input the index to calculate. The factor function is then called and then returns
the a value (answer) to be printed out for the user.
*/
int main(void)
{
	int  n, a;
	printf("Input the index of the sequence you want to calculate: ");
	scanf("%d",&n);
	a = factr(n);
	printf("The number of index %d is %d", n,a);


}

