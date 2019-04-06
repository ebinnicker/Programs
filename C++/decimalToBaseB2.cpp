#include <iostream>
#include <sstream>
#include <string>
using namespace std;

char digit_to_char(int);

int main (int argc, char *argv[])
{
    cout << "Enter a decimal value : ";
    int dval;
    cin >> dval;
    cout << "Enter a base (2-16) : ";
    int base;
    cin >> base;
	while (base < 2 || base > 16){
		cout << "Enter a base (2-16) : ";
		cin >> base;
	}
		
    cout << "\nBase-10 value : " << dval << '\n';

    // (3) perform conversion
    string cval;
	int mod;
	char modC;
	
	if (base>dval){
		if (dval>=10){
			if (dval == 10)
				modC = 'A';
			else if (dval == 11)
				modC = 'B';
			else if (dval == 12)
				modC = 'C';
			else if (dval == 13)
				modC = 'D';
			else if (dval == 14)
				modC = 'E';
			else if (dval == 15)
				modC = 'F';
		}else{
			modC = digit_to_char(dval);
		}
		cval.push_back(modC);
	}else{
		while (dval > 0){	
			mod = dval%base;
			dval = dval/base;
			if (mod>=10){
				if (mod == 10)
					modC = 'A';
				else if (mod == 11)
					modC = 'B';
				else if (mod == 12)
					modC = 'C';
				else if (mod == 13)
					modC = 'D';
				else if (mod == 14)
					modC = 'E';
				else
					modC = 'F';
			}else{
				modC = digit_to_char(mod);
				cval.push_back(modC);
			}
		}
			
	}
	
	// store result in a string
    // ... while some condition (remember, we continue to take mod base and subsequently divide dval by base until we reach zero...), pushing back the mod int value encoded as a character to string...
    /* Remember, we are storing the result in a string opposed to vector<int> because base some bases use characters as digits.  You can convert a digit (i.e., 0-9) to a character by calling the digit_to_char() function; for instance, if int i = 1 contains the digit that you'd like to convert (in this case, 1), writing the expression char c = digit_to_char(i) would initialize c with the character '1'.  You could then push_back c to cval (i.e., cval.push_back(c);)... When using a base larger then 10, A encodes 10 (so push back 'A' if you find a remainder of 10), B encodes 11, C encodes 12, D encodes 13, E encodes 14, and F encodes 15.  Therefore, we can convert digits int val 0-9 to 0-9 char val and store in string; if 10, 11, 12, 13, 14, or 15, we can store A, B, C, D, E, or F in that string respectively (instead of 10,...,15).  */

    // (4) reverse result stored in string
    // ... use for loop to do this...
	string rev_val;
	for (int i = cval.length()-1; i>=0; i--){
		rev_val.push_back(cval.at(i));
	}

    // (5) Print result...
    if (cval.size() == 0)
        cout << "Base-" << base << " value : " << 0 << endl;
    else
        cout << "Base-" << base << " value : " << rev_val << endl;
    if (cval.size() ==0)
		cout << "Digits required : 0" << endl;
	else
		cout << "Digits required : " << cval.size() << endl;

    return 0;
}

char digit_to_char(int i)
{
    stringstream ss;
    ss << i; char c; ss >> c;
    return c;
}