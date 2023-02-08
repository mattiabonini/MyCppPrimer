#include <iostream>
#include <string>
#include <cstdio>

using std::cin;

std::istream& read(std::istream& is) {
	int s; // std::string s
	while(is >> s)
		std::cout << s << std::endl;
	std::cout << "Inside the function: " << is.rdstate() << std::endl;
	is.clear();
	return is;
}

int main() {
	//printf("%i\n", EOF);
	std::cout << std::cin.rdstate() << std::endl;
	read(std::cin);
	std::cout << "Outside the function: "<< std::cin.rdstate() << std::endl;
	return 0;
}
	
