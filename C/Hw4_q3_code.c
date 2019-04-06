/*
Emily Binnicker
UIN: 524003728
CSCE 206 - 503
Assignment 3
*/

#include <stdio.h>

/*
This program allows a user to input a date and the output is the day of the week that date falls. Switch statements are used to calculate number of days into the year and which day of the week. 
*/

int main()
{
    int m, d, num, wk;
    
    printf("Input the month: ");
    scanf("%d", &m);
    printf("Input the day: ");
    scanf("%d", &d);
	
	
    switch(m)
    {
        case 1: 
            num = d;
            break;
        case 2:
            num = 31 + d;
            break;
        case 3:
            num = 59 + d;
            break;
        case 4:
            num = 90 + d;
            break;
        case 5:
            num = 120 + d;
            break;
        case 6:
            num = 151 + d;
            break;
        case 7:
            num = 181 + d;
            break;
        case 8:
            num = 212 + d;
            break;
        case 9:
            num = 243 + d;
            break;
        case 10:
            num = 273 + d;
            break;
        case 11:
            num = 304 + d;
            break;
        case 12:
            num = 334 + d;
            break;
    }
    
    wk = (num%7);
    
    switch(wk)
    {
        case 1:
            printf("%d/%d/17 is Sunday!", m,d);
            break;
        case 2:
            printf("%d/%d/17 is Monday!", m,d);
            break;
        case 3:
            printf("%d/%d/17 is Tuesday!", m,d);
            break;
        case 4:
            printf("%d/%d/17 is Wednesday!", m,d);
            break;
        case 5:
            printf("%d/%d/17 is Thursday!", m,d);
            break;
        case 6:
            printf("%d/%d/17 is Friday!", m,d);
            break;
        case 0:
            printf("%d/%d/17 is Saturday!", m,d);
            break;
    }
    
}