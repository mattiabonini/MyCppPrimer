#include <iostream>
#include <fstream>
#include <sstream>

class StringLength {
	public:
	StringLength() = default;
	
	void operator()(const std::string& s) {
		if(s.size() < 10) ++less9;
		else ++great10;
	}
	
	void print_count() {
		std::cout << "1-9 letters: " << less9 << std::endl;
		std::cout << "10+ letters: " << great10 << std::endl;
	}
	
	private:
	size_t less9 = 0, great10 = 0;
};

int main() {
	std::ifstream in("input.txt");
	StringLength comp;
	
	if(in) {
		std::string line, word;
		while(getline(in, line)) {
			std::istringstream str(line);
			while(str >> word) comp(word);
		}
	}
	comp.print_count();
	
	return 0;
}
			
	
