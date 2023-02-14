#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using my_map = std::map<std::string, std::string>;

my_map assemble_map(std::string &file) {
	my_map m;
	std::ifstream f(file);
	if(f) {
		std::string key;
		std::string line;
		while(f >> key && getline(f, line)) {
			if(line.size()); // Skipping the first space
				m[key] = line.substr(1);
		}
	}
	else
		std::cerr << "Couldn't open the transform file!" << std::endl;
	
	return m;
}
	
const std::string& transform(const my_map &m, const std::string &s) {
	if(m.find(s) != m.end())
		return m.find(s)->second;
	else return s;
}

void wordTransform(std::string &&readFile, std::string &&transformFile) {
	my_map m = assemble_map(transformFile);
	std::string s, text;
	std::ifstream f(readFile);
	if(f) {
		while(getline(f, text)) {
			bool firstWord = true;
			std::istringstream line(text);
			while(line >> s) {
				if(firstWord) firstWord = false;
				else std::cout << " ";
				
				std::cout << transform(m, s);
			}
			std::cout << std::endl;
		}
	}
	else std::cerr << "Couldn't open the read file!" << std::endl;
	/*
	// Debug
	for(const auto &s : m)
		std::cout << "Transforming " << s.first << " into " << s.second << std::endl; */
}



int main(int argc, char **argv) {
	if(argc != 3) {
		std::cerr << "Two inputs expected!" << std::endl;
		return -1;
	}
	wordTransform(std::string(argv[1]), std::string(argv[2]));
	return 0;
}
