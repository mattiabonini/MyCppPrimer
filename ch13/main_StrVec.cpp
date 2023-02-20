#include "StrVec.hpp"
#include "String.hpp"
#include <vector>

using std::string;

int main() {
	String s("abc");
	std::string s2("abc");
	StrVec v1;
	
	std::vector<String> vec;
	std::vector<std::string> vec2;
	//vec.emplace_back("a"); // Doesn't call the extra copy constructor!
	vec.push_back("b"); 
	vec.push_back(std::move(s)); // Not yet defined!
	vec2.push_back(std::move(s2));
	s.print();
	s2 += "ciao";
	std::cout << std::endl << s2 << std::endl;
	
	//StrVec v2(std::initializer_list<std::string>(string("a"), string("b")));

	return 0;
}
