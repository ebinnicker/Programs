/*
Emily Binnicker
UIN: 524003728
CSCE 206 - 503
Assignment 2
*/

#include <stdio.h>


//This program allows the user to input an integer less than 300
//The program then outputs if the integer is a prime number or not
int main(void)
{
	int user, i, count;
	
	printf("Input the integer you want to test: ");
	scanf("%d", &user);
	
	i = 1;
	while (i<=user){
		if ((user%i)==0){
			count = count+1;
		}
		i = i+1;
	}
	
	if (count == 2){
		printf("%d is a prime!", user);
	}
	else{
		printf("%d is not a prime!", user);
	}
	
	
}