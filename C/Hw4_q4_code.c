/*
Emily Binnicker
UIN: 524003728
CSCE 206 - 503
Assignment 3
*/

#include <stdio.h>

/*
This program allows a user to choose how many positive integers they would like to enter. The output is the second largest number inputted. This is done using a for loop with nested if statements that hold the 2 largest values.
*/

int main()
{
    int num, i, a, b, c;
    a = 0;
    b = 0;
    
    printf("Input the number of integers you want to input: ");
    scanf("%d", &num);
    
    for (i=0;i<num;i++){
        printf("\nInput Integer: ");
        scanf("%d", &c);
		
		
        
        if (c>b && c>a){
            b = a;
			a = c;
        }else if (c>b){
            b = c;
        }
    }
    
    printf("%d", b);
}