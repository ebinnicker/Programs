#include <iostream>
#include <string>
using namespace std;

int main()
{
	double input;
	int amt, quarters, dimes, nickels, pennies, total, mod, temp;
	
	cout << "Enter dollar amount: ";
	cin >> input;
	cout << "Amount requested: $" << input << endl;
	
	amt = input*100;
	if (amt >= 25){
		mod = amt%25;
		temp = amt - mod;
		quarters = temp/25;
	}
	else
		quarters = 0;
	
	amt = amt - (quarters*25);
	cout << "Quarters: " << quarters << endl;
	
	if (amt>=10){
		mod = amt%10;
		temp = amt - mod;
		dimes = temp/10;
	}
	else
		dimes = 0;
	amt = amt - (dimes*10);
	cout << "Dimes: " << dimes << endl;
	
	if (amt>=5){
		mod = amt%5;
		temp = amt - mod;
		nickels = temp/5;
	}
	else
		nickels = 0;
	amt = amt - (nickels*5);
	cout << "Nickels: " << nickels << endl;
	
	pennies = amt;
	cout << "Pennies: " << pennies << endl;
	cout << endl;
	total = quarters + dimes + nickels + pennies;
	cout << "Total coins used: " << total;
}