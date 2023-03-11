#include <iostream>
#include<string>
#include<regex>

int main() {
	std::string pattern{"[[:alpha:]]*([^c]ei)[[:alpha:]]*"};
	// std::string pattern{"[^c]ei"}; // It provides only the pattern
	std::regex r(pattern, std::regex::icase);
	
	std::string test{"receipt freind theif receive"};
	
	for(std::sregex_iterator it(test.begin(), test.end(), r), end_it; it != end_it; ++it) {
		std::cout << it->str() << "\n";
	}
	
	return 0;
}
