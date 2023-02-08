#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void readFile( std::string &fileName, std::vector<std::string> &res) {
	std::string tmp;
	std::ifstream in(fileName);
	if(in)
		while(getline(in, tmp)) // Ex_8_5: in >> tmp 
			res.push_back(tmp);
	else std::cerr << "Invalid opening" << std::endl;
	in.close();
}

int main() {
	std::string fileName{"test.txt"};
	std::vector<std::string> res;
	readFile(fileName, res);
	for(auto s : res) std::cout << s << std::endl;
	return 0;
}
	

