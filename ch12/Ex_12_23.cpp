#include <iostream>
#include <string>
#include <cstring>

int main() {
	// C string
	const char *c1{"A string"};
	const char *c2 = ", another string";
	
	auto size = strlen(c1) + strlen(c2) + 1;
	char *res = new char[size];
	for(auto i = 0; i != strlen(c1); ++i) res[i] = c1[i];
	for(auto i = 0; i != strlen(c2); ++i) res[i + strlen(c1)] = c2[i];
	for(auto i = 0; i < size; ++i) std::cout << res[i];
	std::cout << std::endl;
	
	delete[] res;
	
	// C++ STL strings
	std::string s(std::string(c1) + std::string(c2));
	std::cout << "C++: " << s << std::endl;
	
	return 0;
}
