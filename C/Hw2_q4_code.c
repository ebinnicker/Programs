/*
Emily Binnicker
UIN: 524003728
CSCE 206 - 503
Assignment 2
*/

#include <stdio.h>


int main(void)
{
	int i, j;
	for (i=1; i<10; i++){
		printf("\n");
		
		for (j=1; j<10; j++){
			if (i>j){
				printf("\t");
			}
			else{
				printf("%d*%d=%d\t", i,j,i*j);
			}
			
		}
		
		
	}

return 0;


}