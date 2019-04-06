/*
Emily Binnicker
UIN: 524003728
CSCE 206 - 503
Assignment 3
*/

#include <stdio.h>
#include <math.h>


/*
The purpose of this program is to allow the user to input a binary number and the resulting output is the decimal integer. 
*/


int main(void)
{
	int user, bin, dec, count, a, b, tf;	
	
	dec = 0;
	count = 0;
	tf = 1;
	
	printf("Input a binary number: ");
	scanf("%d", &user);
	
	bin = user;
	
	//this part of the program tests that the inputed value is a binary number
	a = bin%10;	
	if (a ==1 || a==0){
		tf = 1;
	}
	else{
		tf = 0;
	}
	
	//if it is not a binary number then it enters this loop requiring the user to continue to input a value until it is a binary number
	while (tf==0){
		printf("Illegal input, please input again: ");
		scanf("%d", &user);
		bin=user;
		a = bin%10;
		if (a ==1 || a==0){
			tf = 1;
		}
		else{
			tf = 0;
		}
		
	}
	
	//this while loop converts the binary number into a decimal number
	while ((tf == 1)&&(bin>0)){
		
		
		b = bin%2;
		dec = dec+b*pow(2,count);
		bin = bin/10;
		
		count+=1;
		
	}
	
	printf("The decimal number of %d is %d", user, dec);
}