#include <iostream>
#include <cstring>
#include "Chapter6.hpp"

int main(int argc, char **argv) {
	//if(argc != 3) return 2;
	std::string res;
	for(int i = 1; i < argc; ++i)
		res += argv[i];
	std::cout << res << std::endl;
	
	std::cout << "Testing my sum: " << my_sum({1, 2, 3, 4, 5}) << std::endl;
	return 0;
}
