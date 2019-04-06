#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <cmath>

using namespace std;

int main() {
    srand(std::chrono::duration_cast<std::chrono::milliseconds>
     (std::chrono::system_clock::now().time_since_epoch()).count()%2000000000); 
    // needed to autograde some test cases in Mimir
	
	int dig;
	std::cout << "Enter number of digits in code (3, 4 or 5): ";
	cin >> dig;
	
	while ((dig!=0)&&(dig!=3)&&(dig!=4)&&(dig!=5)){
		std::cout << "Enter number of digits in code (3, 4 or 5): ";
		cin >> dig;
	}
	
	int num;
	int max;
	
	//code to be guess by random or by user
	if (dig == 0){
		std::cout << "Enter code: ";
		cin >> num;
		std::cout << "Enter number of digits in code: ";
		cin >> dig;
	}else{
		if (dig==3)
			max = 10*10*10;
		else if (dig == 4)
			max = 10*10*10*10;
		else if (dig == 5)
			max = 10*10*10*10*10;
		num = (rand()%(max- 0 + 1))+ 0;
	}
	
	//conver int to string to iterate each char (digit) into a vector as an integer again
	vector <int> code(dig);
	
	std::string numS;
	std::stringstream my_ss;
	my_ss << num;
	my_ss >> numS;
	
	//converts numbers that start with 0s and the number into code vector of integers
	if (numS.size()<dig){
		int t = dig - numS.size();
		while (t>=0){
			code.at(t-1) = 0;
			t = t-1;
		}
		for (t;t<numS.size(); t++)
			code.at(t) = (static_cast<int>(numS[t]))-48;
	}else{
		for (int i = 0;i<numS.size();i++){
			code.at(i) = (static_cast<int>(numS[i]))-48;
		}
	}
	
	//output number to guess
	std::cout<<"Number to guess: "<<code.at(0);
	for (int z = 1; z<=code.size()-1;z++){
		std::cout<<"-"<<code.at(z);
	}
	std::cout<<endl;
	
	//counts bulls and cows with nested for loops by testing each guess iteration to the other iterations of the code
	int bulls=0;
	int cows=0;
	string guessS;
	vector <int> G(dig);
	int count=1;
	
		//to ensure each number is different in the guess
	while (count != 0){
		std::cout<<"Enter Guess: ";
		cin>>guessS;
		count = 0;
		//input guessS string into G vector
		if (guessS.size()<dig){
			int t = dig - guessS.size();
			while (t>0){
				G.at(t-1) = 0;
				t = t-1;
			}
			for (t;t<guessS.size(); t++)
				G.at(t) = (static_cast<int>(guessS[t]))-48;
		}else if (guessS.size()>dig){
			while (guessS.size()>dig){
				cout<<"You can only enter "<<dig<<" digits."<<endl;
				cout<<"Enter Guess: ";
				cin>>guessS;
			}
			for (int i = 0;i<guessS.size();i++){
				G.at(i) = (static_cast<int>(guessS[i]))-48;
			}
		}else{
			for (int i = 0;i<guessS.size();i++){
				G.at(i) = (static_cast<int>(guessS[i]))-48;
			}
		}
		//test for repeats in guess
		for (int i=0; i<guessS.size()-1;i++){
			for (int j=1; j<guessS.size();j++){
				if (guessS[i]==guessS[j])
					count = count+1;
			}
		}
		cout<<"count"<<count<<endl;
		if (count>0)
			cout<<"Each number must be different."<<endl;
	}

	while (bulls != dig){
		//tests for bulls and cows
		for (int j = 0; j < guessS.size(); j++){
			if (G.at(j)==code.at(j))
				bulls = bulls + 1;
			else{
				for (int k = 0; k < code.size(); k++){
					if (guessS.at(j) == code.at(k))
						cows = cows + 1;
				}
			}
		}
		std::cout << bulls << " bulls" << endl;
		std::cout << cows << " cows" << endl;
	}
	
	std::cout << bulls << " bulls... "<<code.at(0);
	for (int z = 1; z < code.size(); z++){
		std::cout<<"-"<<code.at(z);
	}
	
	std::cout<<" is correct!"<<endl;
	
	
	
	
}

