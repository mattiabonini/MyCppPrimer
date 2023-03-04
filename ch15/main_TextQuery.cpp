#include <fstream>
#include <iostream>

#include "TextQuery.hpp"
#include "Query.hpp"

void runQueries(std::ifstream &f) {
	TextQuery tq(f);
	while(true) {
		std::cout << "Insert the word to look for, or q for quit" << std::endl;
		std::string s;
		if(!(std::cin >> s) || s == "q") break;
		print(std::cout, tq.query(s)) << std::endl;
	}
}

int main() {
	std::ifstream file("TextForTextQuery.txt");
	if(!file) {
		std::cerr << "Not able to open the file" << std::endl;
		return -1;
	}
	
	TextQuery tq(file);
	Query q1 = Query("pattern") | Query("design");
	Query q2 = Query("pattern") & Query("design");
	Query q3 = ~Query("pattern") & Query("design");
	
	print(std::cout, q1.eval(tq));
	print(std::cout, q2.eval(tq));
	print(std::cout, q3.eval(tq));
	
	file.close();
	return 0;
}
