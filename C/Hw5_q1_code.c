/*
Emily Binnicker
UIN: 524003728
CSCE 206 - 503
Assignment 5
*/

#include <stdio.h>

/*
This program uses recursion to follow the Fibonacci sequence. This allows a user to input an index and out the related Fibonacci number.
*/

char initializeBoard(char board[3][3])
{
	int t, i;
	
	for (t=0; t<3; t++)
		for(i=0; i<3; i++)
			board[t][i] = ' ';
	
	printf("  1    2    3\n");
	
	for (t=0; t<3; t++)
	{
		printf("%d", (t+1));
		for(i=0; i<3; i++)
			printf("[%c]  ", board[t][i]);
		printf("\n");
	} return 0;
}

char makeMove(char board[3][3], char player)
{
	int r, c;
	
	printf("Enter the row and column you'd like to fill:");
		scanf("%d %d", &r, &c);
	board[r-1][c-1] = player;
	
	return 0;
}


char displayBoard(char board[3][3])
{
	int t, i;
	
	printf("  1    2    3\n");
	
	for (t=0; t<3; t++)
	{
		printf("%d", (t+1));
		for(i=0; i<3; i++)
			printf("[%c]  ", board[t][i]);
		printf("\n");
	} return 0;
}


int main (void)
{
	
	char board[3][3];
	board[3][3] = initializeBoard(board);
	
	int j=0;
	char player;

	for (j; j<9; j++)
	{
		if (j%2 == 0){
			player = 'o';
			board[3][3] = makeMove(board, player);
		}else{
			player = 'x';
			board[3][3] = makeMove(board, player);
		}
		
		board[3][3] = displayBoard(board);
		
		
	}
		
}
