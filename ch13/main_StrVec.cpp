#include "StrVec.hpp"
#include "String.hpp"
#include <vector>

using std::string;

int main() {
	String s("abc"), s2("def"), s3("ghi"), s4("jkl");
	std::string ssss = "abc", aaa("ciao");
	StrVec v1;
	
	std::vector<String> vec;
	std::vector<std::string> vec2;
	//vec.emplace_back("a"); // Doesn't call the extra copy constructor!
	//vec.push_back("b"); 
	std::cerr << "sono qui" << std::endl;
	vec.push_back(std::move(s));
	std::cerr << "ora qui" << std::endl;
	vec.push_back(std::move(s2));
	std::cerr << "we" << std::endl;
	vec.push_back(std::move(s3));
	std::cerr << "daje 2" << std::endl;
	vec.push_back(std::move(s4)); 
	std::cerr << "daje" << std::endl;
	vec.push_back("b"); 
	
	//vec2.push_back(std::move(s2));
	/*s.print();
	s2 += "ciao";
	std::cout << std::endl << s2 << std::endl;*/
	
	
	std::initializer_list<std::string> il{ssss, aaa}; //?!?!?
	StrVec v2({ssss, aaa});

	return 0;
}
