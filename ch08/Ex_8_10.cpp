#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;

// Ex 8.9
std::istream& read(std::istream& is) {
	std::string s;
	while(is >> s)
		std::cout << s << std::endl;
	std::cout << "STATUS - Inside the function: " << is.rdstate() << std::endl;
	is.clear();
	return is;
}

// Ex 8.10
void readToVec(std::istream& in, std::vector<std::string> &res) {
	std::string s;
	/*
	// One line in one element
	while(getline(in, s)) 
		res.push_back(s); 
	*/
	
	// One word at a time
	std::string word;
	std::istringstream sstr;
	while(getline(in, s)) {
		sstr.str(s);
		while(sstr >> word)
			res.push_back(word);
		sstr.clear(); // Important!
	}
	
	in.clear();
}

int main() {

	std::ifstream in("sales_in.txt");
	
	/*
	// Ex 8.9
	std::cout << "STATUS - At the begin: " << in.rdstate() << std::endl;
	std::istringstream sin("wee");
	read(sin);
	std::cout << "STATUS - Outside the function: "<< std::cin.rdstate() << std::endl;
	*/
	
	// Ex 8.10
	std::vector<std::string> res;
	readToVec(in, res);
	for(const auto& s : res) std::cout << s << std::endl;
	
	in.close();
	return 0;
}
