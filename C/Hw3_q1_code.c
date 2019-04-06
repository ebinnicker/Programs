/*
Emily Binnicker
UIN: 524003728
CSCE 206 - 503
Assignment 3
*/

#include <stdio.h>

/*
The main function asks the user to calculate the the area of a Circle, Triangle, or Rectangle. The user is able
to choose using the switch function. The user must input a 1, 2 or 3 to continue. The area of the shape is then printed out 
for the user.
*/
int main(void)
{
	int user;
	double radius, base, height, width, area;
	
	printf("Select the shape you want to calculate the area of: \n");
	printf("1.Circle\n2.Triangle\n3.Rectangle\n");
	scanf("%d", &user);
	
	//while loop to ensure the user inputs a 1, 2, or 3.
	while ((user<1) || (user>3)){
		printf("Illegal input! Please reinput!\n");
		scanf("%d", &user);
	}
	
	//switch function used to allow the user to choose which shape and to calculate the area within each case
	switch(user)
	{
		case 1:
		printf("Please input the radius of the circle: ");
		scanf("%lf", &radius);
		while (positive_checker(radius)==0){
			printf("Illegal input! Please reinput!\n");
			printf("Please input the radius of the circle: ");
			scanf("%lf",&radius);
		}
		area = 3.14 * (radius * radius);
		printf("The area of the circle is: %f", area);
		break;
		
		case 2:
		printf("Please input the base of the triangle: ");
		scanf("%lf", &base);
		while (positive_checker(base)==0){
			printf("Illegal input! Please reinput!\n");
			printf("Please input the base of the triangle: ");
			scanf("%lf",&base);
		}
		printf("Please input the height of the triangle: ");
		scanf("%lf", &height);
		while (positive_checker(height)==0){
			printf("Illegal input! Please reinput!\n");
			printf("Please input the height of the triangle: ");
			scanf("%lf",&height);
		}
		area = .5*(base*height);
		printf("The area of the triangle is: %f", area);
		break;
		
		case 3:
		printf("Please input the width of the rectangle: ");
		scanf("%lf", &width);
		while (positive_checker(width)==0){
			printf("Illegal input! Please reinput!\n");
			printf("Please input the width of the rectangle: ");
			scanf("%lf",&width);
		}
		printf("Please input the height of the rectangle: ");
		scanf("%lf", &height);
		while (positive_checker(height)==0){
			printf("Illegal input! Please reinput!\n");
			printf("Please input the height of the rectangle: ");
			scanf("%lf",&height);
		}
		area = width*height;
		printf("The area of the rectangle is: %f", area);
		break;
	}
	
}

/*
positive_checker() function checks if the number input from the user is positive. If it is positive,
a 1 is returned. If it is negative, a 0 is returned.
*/
int positive_checker(double num)
{
	if (num>0){
		return 1;
	}
	else{
		return 0;
	}
	
}