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

int validMove(int r, int c, char board[3][3])
{
	int b;
	if (r>3 || r<1)
		b = 0;
	else if (board[r][c] != ' ')
		b = -1;
	else
		b = 1;
	return b;
}

char makeMove(char board[3][3], char player)
{
	int r, c, b;
	
	printf("Enter the row and column you'd like to fill:");
	scanf("%d %d", &r, &c);
	b = validMove(r,c, board);
	if (b == 0){
		while (b==0)
		{
			printf("That move is not on the board!");
			printf("Enter the row and column you'd like to fill:");
			scanf("%d %d", &r, &c);
			b = validMove(r,c, board);
		}
	}else if (b == -1){
		while (b == -1)
		{
			printf("That move has already been entered!");
			printf("Enter the row and column you'd like to fill:");
			scanf("%d %d", &r, &c);
			b = validMove(r,c,board);
		}
	}
		
	board[r-1][c-1] = player;
	
	return 0;
}

char makeComputerMove(char board[3][3], char player)
{
	if (board[0][0] == ' ')
		board[0][0] = 'x';
	else if (board[0][1] == ' ')
		board[0][1] = 'x';
	else if (board[1][0] == ' ')
		board[1][0] = 'x';
	else if (board[1][1] == ' ')
		board[1][1] = 'x';
	else if (board[2][0] == ' ')
		board[2][0] = 'x';
	else if (board[2][1] == ' ')
		board[2][1] = 'x';
	else if (board[0][2] == ' ')
		board[0][2] = 'x';
	else if (board[1][2] == ' ')
		board[1][2] = 'x';
	else (board[2][2] == ' ');
		board[2][2] = 'x';
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

int checkWinner(char board[3][3])
{
	int win = 0;
	if ((board[0][0]=='o')&&(board[0][1]=='o')&&(board[0][2]=='o')){
		return win = 1;
		printf("o wins");
	}
	else if ((board[0][0]=='x')&&(board[0][1]=='x')&&(board[0][2]=='x')){
		return win = 1;
		printf("x wins");
	}
	else if ((board[1][0]=='o')&&(board[1][1]=='o')&&(board[1][2]=='o')){
		return win = 1;
		printf("o wins");
	}
	else if ((board[1][0]=='x')&&(board[1][1]=='x')&&(board[1][2]=='x')){
		return win = 1;
		printf("x wins");
	}
	else if ((board[2][0]=='o')&&(board[2][1]=='o')&&(board[2][2]=='o')){
		return win = 1;
		printf("o wins");
	}
	else if ((board[2][0]=='x')&&(board[2][1]=='x')&&(board[2][2]=='x')){
		return win = 1;
		printf("x wins");
	}
	else if ((board[0][0]=='o')&&(board[1][0]=='o')&&(board[2][0]=='o')){
		return win = 1;
		printf("o wins");
	}
	else if ((board[0][0]=='x')&&(board[1][0]=='x')&&(board[2][0]=='x')){
		return win = 1;
		printf("x wins");
	}
	else if ((board[0][1]=='o')&&(board[1][1]=='o')&&(board[2][1]=='o')){
		return win = 1;
		printf("o wins");
	}
	else if ((board[0][1]=='x')&&(board[1][1]=='x')&&(board[2][1]=='x')){
		return win = 1;
		printf("x wins");
	}
	else if ((board[0][2]=='o')&&(board[1][2]=='o')&&(board[2][2]=='o')){
		return win = 1;
		printf("o wins");
	}
	else if ((board[0][2]=='x')&&(board[1][2]=='x')&&(board[2][2]=='o')){
		return win = 1;
		printf("x wins");
	}
	else if ((board[0][0]=='o')&&(board[1][1]=='o')&&(board[2][2]=='o')){
		return win = 1;
		printf("o wins");
	}
	else if ((board[0][0]=='x')&&(board[1][1]=='x')&&(board[2][2]=='x')){
		return win = 1;
		printf("x wins");
	}
	else if ((board[0][2]=='o')&&(board[1][1]=='o')&&(board[2][0]=='o')){
		return win = 1;
		printf("o wins");
	}
	else if ((board[0][2]=='x')&&(board[1][1]=='x')&&(board[2][0]=='x')){
		return win = 1;
		printf("x wins");
	}
	else
		return win;
}

int main (void)
{
	int g;
	printf("Enter 1 for one-player and 2 for two-player: ");
	scanf("%d", &g);
	
	char board[3][3];
	board[3][3] = initializeBoard(board);
	
	int j=0, win=0;
	char player;

	switch(g)
	{
		case 1: 
			while (j<9 && win==0)
			{
				if (j%2 == 0){
					player = 'o';
					board[3][3] = makeMove(board, player);
				}else{
					player = 'x';
					board[3][3] = makeMove(board, player);
				}
				board[3][3] = displayBoard(board);		
				win = checkWinner(board);		
				j++;		
			}
			break;
			
		case 2:
			while (j<9 && win==0)
			{
				if (j%2 == 0){
					player = 'o';
					board[3][3] = makeMove(board, player);
				}else{
					player = 'x';
					board[3][3] = makeComputerMove(board, player);
				}
				board[3][3] = displayBoard(board);		
				win = checkWinner(board);		
				j++;		
			}
			break;
		
		
		
	}
	
	while (j<9 && win==0)
	{
		if (j%2 == 0){
			player = 'o';
			board[3][3] = makeMove(board, player);
		}else{
			player = 'x';
			board[3][3] = makeMove(board, player);
		}
		
		board[3][3] = displayBoard(board);
		
		win = checkWinner(board);
		
		j++;
		
		
	}
		
}
