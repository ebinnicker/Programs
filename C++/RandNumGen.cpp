#include <iostream>
#include <string>
#include <random>
#include <vector>
using namespace std;

int main()
{
	std::random_device r_dev{}; 
	std::default_random_engine d_engine{r_dev()};

	std::uniform_int_distribution<> my_uni_dist{0,5};
	int val = my_uni_dist(d_engine);
	vector<int> v(6);
	
	for n in v:
		
	return 0;
}