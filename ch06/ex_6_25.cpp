#include <iostream>
#include <cstring>

int main(int argc, char **argv) {
	//if(argc != 3) return 2;
	std::string res;
	for(int i = 1; i < argc; ++i)
		res += argv[i];
	std::cout << res << std::endl;
	return 0;
}
