/*
Emily Binnicker
UIN: 524003728
CSCE 206 - 503
Assignment 3
*/

#include <stdio.h>
#include <ctype.h>

/*
This program allows a user to continuously enter characters until a comma is entered, which will terminate the program. If the user inputs a lower case, an upper case is the output. If the user inputs an upper case, a lower case is the output. If a digit is the input, the ascii value is outputted. This is done through a while loop with nested if-else statements.
*/

int main()
{
	char user, ans, in;
	
	printf("Input a character: ");
	scanf("%c", &in);
	user = in;
  
	while (user != ','){
		
		if (user>='A' && user<='Z'){
            ans = tolower(user);
            printf("%c\n", ans);
        }
        else if (user>='a' && user<='z'){
            ans = toupper(user);
            printf("%c\n", ans);
        }
        else{
            printf("%c\n", user);
        }
		printf("Input a Character: ");
		scanf("%c", &in);
		user = in;

    }
    
}