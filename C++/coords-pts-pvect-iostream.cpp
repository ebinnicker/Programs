#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main(int argv, char* argc[])
{
	
	if (argv != 2) {
        cerr << "Usage: ./a.out filename.dat" << endl;
        return 1;
    }
    string inputFile = argc[1];
    cout << "File with input data : " << inputFile << endl;
	
	vector <int> xvect;
	vector <int> yvect;
	vector <int> dpoint;
	
	ifstream inFS;
	inFS.open(inputFile);
	int x;
	int y;
	char z;
	int minTemp = 1000;
	int ind;
	int dist;

	
	int i=0;
	while(!inFS.eof()){
		inFS >> x;
		xvect.at(i) = x;
		inFS >> z;
		inFS >> y;
		yvect.at(i) = y;
		i = i+1;
	}
	
	i=0;
	int j=0;
	while(i<xvect.size()){
		while(j<xvect.size()){
			dist = sqrt(pow(((xvect.at(i)) - (xvect.at(j))),2)+(pow((yvect.at(i)-yvect.at(j)),2)));
			cout << "distance" << dist<< endl;
			if ((dist!=0) && (dist<minTemp)){
				minTemp = dist;
				ind = j;
			}
			j = j+1;
		}
		inFS << xvect.at(i);
		inFS<< "," ;
		inFS<< yvect.at(i);
		inFS << ","; 
		inFS << ind<;
		inFS<<endl;
		i = i+1;
	}
	
	cout << "close"<< endl;
	inFS.close();  
	
	
    return 0;
}