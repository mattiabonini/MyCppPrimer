#include <fstream>
#include <iostream>
#include "StrBlob.hpp"

int main() {
	std::ifstream file("input_StrBlob.txt");
	if(!file) {
		std::cerr << "Not able to open the file" << std::endl;
		return -1;
	}
	
	std::string line;
	StrBlob m;
	while(getline(file, line))
		m.push_back(line);
	
	std::cout << std::endl << "OUTPUT" << std::endl;
	for(auto beg = m.begin(); beg != m.end(); beg.incr())
		std::cout << beg.deref() << std::endl;
	
	return 0;
}
		
