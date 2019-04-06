//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//                              UTILITIES 121                               //
//                             utilities121.cpp                             //
//                                                                          //
// Written By :                         Environment :                       //
// Date ......:                         Compiler ...:                       //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//                                #includes                                 //
//////////////////////////////////////////////////////////////////////////////
#include "utilities121.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <random>
#include <cstdlib>

//////////////////////////////////////////////////////////////////////////////
//                           Function Definitions                           //
//////////////////////////////////////////////////////////////////////////////
/*****************************************************************************
*                              void pause(void)                              *
*                                                                            *
*       Description ....: Delay the system so that the user can read what    *
*                         is written to standard output.                     *
*                                                                            *
*                                                                            *
* Written By : Michael R. Nowak         Environment : Mac OS X 10.10.5       *
* Date ......: 2017/10/01               Compiler ...: Homebrew GCC 6.3.0_1   *
*****************************************************************************/
void pause(void)
{
    std::string temp;
    std::cout << std::endl << "[Press RETURN to continue]" << std::endl;
    std::getline(std::cin, temp);
}

/*****************************************************************************
*                            char upchar(char c)                             *
*                                                                            *
*       Description ....:Upper case character to lower case					 *
*                                                                            *
*                                                                            *
* Written By :Binnicker, Brown, Waters  Environment :compute                 *
* Date ......:9/27/18                 Compiler ...:putty 11                  *
*****************************************************************************/
char upchar(char c){
	static_cast<int>(c);
	if ((c<=90) && (c>=65)){
		c = c+32;
		static_cast<char>(c);
	}
	return c;
}

/*****************************************************************************
*                            char lowchar(char c)                            *
*                                                                            *
*       Description ....:Lower case character to upper case					 *
*                                                                            *
*                                                                            *
* Written By :Binnicker, Brown, Waters  Environment :compute                 *
* Date ......:9/27/18                 Compiler ...:putty 11                  *
*****************************************************************************/
char lowchar(char c){
	static_cast<int>(c);
	if ((c<=122) && (c>=97)){
		c = c-32;
		static_cast<char>(c);
	}
	return c;
}


/*****************************************************************************
*                    string upperStr(string s)                     *
*                                                                            *
*       Description ....:each char in a string to upper case				 *
*                                                                            *
*                                                                            *
* Written By :Binnicker, Brown, Waters  Environment :compute                 *
* Date ......:9/27/18                 Compiler ...:putty 11                  *
*****************************************************************************/
std::string upperStr(std::string s){
	std::string t;
	for (int i = 0; i < s.size(); i++){
		char c = upchar(s[i]);
		t.push_back(c);
	}
	return t;
	
}



/*****************************************************************************
*                    std::std::string lowerStr(std::std::string s)                     *
*                                                                            *
*       Description ....:each char in a string to lower case				 *
*                                                                            *
*                                                                            *
* Written By :Binnicker, Brown, Waters  Environment :compute                 *
* Date ......:9/27/18                 Compiler ...:putty 11                  *
*****************************************************************************/
std::string lowerStr(std::string s){
	std::string t;
	for (int i = 0; i < s.size(); i++){
		char c = upchar(s[i]);
		t.push_back(c);
	}
	return t;
	
}

/*****************************************************************************
*                         std::std::string to_str(int i)                          *
*                                                                            *
*       Description ....:int to string with string stream                    *
*                                                                            *
*                                                                            *
* Written By :Binnicker, Brown, Waters  Environment :compute                 *
* Date ......:9/27/18                 Compiler ...:putty 11                  *
*****************************************************************************/
std::string toStr(int n)
{
	std::string nS;	
	std::stringstream my_ss;
    my_ss << n; 
	my_ss >> nS;
    return nS;
	
}

/*****************************************************************************
*                        std::std::string to_str(double d)                   *
*                                                                            *
*       Description ....:double to string with string stream                 *
*                                                                            *
*                                                                            *
* Written By :Binnicker, Brown, Waters  Environment :compute                 *
* Date ......:9/27/18                 Compiler ...:putty 11                  *
*****************************************************************************/
std::string toStr(double d)
{
	std::string dS;	
	std::stringstream my_ss;
    my_ss << d; 
	my_ss >> dS;
    return dS;
	
}

/*****************************************************************************
*          int getint(int low, int high, std::std::string const& prompt)     *
*                                                                            *
*       Description ....: gets an integer value                              *
*                                                                            *
*                                                                            *
* Written By :Binnicker, Brown, Waters  Environment :compute                 *
* Date ......:9/27/18                 Compiler ...:putty 11                  *
*****************************************************************************/
int getint(int low, int high, std::string const& prompt){
	int x;
	std::cout << "Enter an integer value between " << low << " " << high << std::endl;
	std::cin >> x;
	while (!(std::cin.good()) || ((x<low)||(x>high))){
		if (std::cin.bad()){
			std::cout << "stream corrupted";
		}else if (std::cin.eof()){
			std::cout << "unexpected eof";
		}else if (!(std::cin.bad()) && (std::cin.fail())){
			std::cin.clear();
			std::cout << "input is invalid"<< std::endl;
			std::cout << "Enter an integer value between " << low << " " << high << std::endl;
			std::cin >> x;
		}else{
			std::cout << "input not in range" << std::endl;
			std::cout << "Enter an integer value between " << low << " " << high << std::endl;
			std::cin >> x;
		}
	}
	
	return x;
}

/*****************************************************************************
*            double getdouble(double low, double high, double tolerance,     *
*                                     double, std::std::string const& prompt)     *
*                                                                            *
*       Description ....: gets a double value                                *
*                                                                            *
*                                                                            *
* Written By :Binnicker, Brown, Waters  Environment :compute                 *
* Date ......:9/27/18                 Compiler ...:putty 11                  *
*****************************************************************************/
double getDouble(double low, double high, std::string const& prompt){
	double x;
	std::cout << "Enter an integer value between " << low << " " << high << std::endl;
	std::cin >> x;
	while (!(std::cin.good()) || ((x<low)||(x>high))){
		if (std::cin.bad()){
			std::cout << "stream corrupted";
		}else if (std::cin.eof()){
			std::cout << "unexpected eof";
		}else if (!(std::cin.bad()) && (std::cin.fail())){
			std::cin.clear();
			std::cout << "input is invalid"<< std::endl;
			std::cout << "Enter an integer value between " << low << " " << high << std::endl;
			std::cin >> x;
		}else{
			std::cout << "input not in range" << std::endl;
			std::cout << "Enter an integer value between " << low << " " << high << std::endl;
			std::cin >> x;
		}
	}
	
	return x;
}

/*****************************************************************************
*                        int randNo(int min, int max)                        *
*                                                                            *
*       Description ....:random integer b/t min and max                      *
*                                                                            *
*                                                                            *
* Written By :Binnicker, Brown, Waters  Environment :compute                 *
* Date ......:9/27/18                 Compiler ...:putty 11                  *
*****************************************************************************/
int randNo(int min, int max){
	int x;
	x = (rand()%(max - min + 1))+min;
	return x;
}

/*****************************************************************************
*                   double randDo(double min, double max)                    *
*                                                                            *
*       Description ....:random double b/t min and max                      *
*                                                                            *
*                                                                            *
* Written By :Binnicker, Brown, Waters  Environment :compute                 *
* Date ......:9/27/18                 Compiler ...:putty 11                  *
*****************************************************************************/
double randNo(double min, double max){
	double x;
	x = (double)rand() / RAND_MAX;
	x = min + x * (max-min);
	return x;
}

/*****************************************************************************
*                           void clearScreen(void)                           *
*                                                                            *
*       Description ....:clear screen                                        *
*                                                                            *
*                                                                            *
* Written By :Binnicker, Brown, Waters  Environment :compute                 *
* Date ......:9/27/18                 Compiler ...:putty 11                  *
*****************************************************************************/
void clearScreen(void){
	system("clear");
}

