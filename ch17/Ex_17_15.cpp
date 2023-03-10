#include <iostream>
#include <regex>
#include <string>

using std::string;
using std::regex;

int main() {
	string pattern{"[[:alpha:]]*[^c]ei[[:alpha:]]*"};
	//string pattern{"[^c]ei"}; // Why does it work as before? Shouldn't it work just on 3 letters words?!
	regex r(pattern);
	std::smatch results;
	string in;
	
	while(std::cout << "Insert a word or q to quit: ", std::cin >> in) {
		if(in == "q") break;
		std::cout << "Does it present the pattern? " << std::boolalpha << 
			std::regex_search(in, results, r) << std::endl;
	}
	
	return 0;
}
		
