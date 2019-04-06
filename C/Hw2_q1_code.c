/*
Emily Binnicker
UIN: 524003728
CSCE 206 - 503
Assignment 2
*/

#include <stdio.h>

#define ON 125.75f
#define OFF 570.25f

//This program allows the user to input the name of a dining hall and how many on campus
//and off campus dining plans were purchased. 
//The program then outputs the revenue for each plan and the total revenue earned from both plans.

int main(void)
{
	char dining_hall_name[100]; //name of dining hall
	int on, off; //variables for plans sold
	double on_rev, off_rev, total_rev; //revenue variables
	
	printf("Input the name of the dining hall: ");
	scanf("%s", &dining_hall_name);
	printf("Input the number of OnCampus dining plans: ");
	scanf("%d", &on);
	printf("Input the number of OffCampus dining plans: ");
	scanf("%d", &off);
	
	on_rev = on * ON;
	off_rev = off * OFF;
	total_rev = on_rev+off_rev;
	
	printf("Dining Hall Name:\t\t\t\t %s\n", dining_hall_name);
	printf("OnCampus plans sold: \t\t\t\t %d\n", on);
	printf("OffCampus plans sold: \t\t\t\t %d\n", off);
	printf("Revenue from OnCampus plans: \t\t\t %.2lf\n", on_rev);
	printf("Revenue from OffCampus plans: \t\t\t %.2lf\n", off_rev);
	printf("Total Revenue earned in semester: \t\t %.2lf\n", total_rev);
	
	return 0;
	
}