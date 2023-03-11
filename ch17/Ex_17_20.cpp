#include <string>
#include <iostream>
#include<fstream>
#include <regex>

bool valid(const std::smatch &m) {
	if(m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else 
		return !m[3].matched && m[4].str() == m[6].str();
}

int main() {
	std::string phone{"(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})"};
	std::regex r(phone);
	std::string s;
	std::ifstream fin{"phone_numbers.txt"};
	
	std::string fmt{"$2.$5.$7"};
	
	if(fin) {
	while(getline(fin, s)) {
		// Ex 17.20
		for(std::sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) 
			if(valid(*it))
				std::cout << "valid: " << it->str() << std::endl;
			else
				std::cout << "not valid: " << it->str() << std::endl;
				
		// Ex 17.24
		auto res = std::regex_replace(s, r, fmt);
		std::cout << res << std::endl;
		
		// Ex 17.25
		std::smatch m;
		std::regex_search(res, m, r);
		std::cout << "First phone num: " << m.str() << std::endl; 
		
	}
	}
	fin.close();
	return 0;
}
