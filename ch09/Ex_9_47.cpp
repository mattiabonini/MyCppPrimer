#include <iostream>
#include <string>

int main() {
	std::string numbers{"1234567890"};
	std::string alphabet{"abcdefghijklmnopqrstuvxywzABCDEFGHIJKLMNOPQRSTUVXYZ"};
	
	std::string s{"ab2c3d7R4E6"};
	
	std::string::size_type pos = 0;
	
	std::cout << "Numbers: ";
	while((pos = s.find_first_of(numbers, pos)) != std::string::npos) {
		std::cout << s[pos] << " ";
		++pos;
	}
	
	pos = 0;
	std::cout << std::endl << "Letters: ";
	while((pos = s.find_first_of(alphabet, pos)) != std::string::npos) {
		std::cout << s[pos] << " ";
		++pos;
	}
	std::cout << std::endl;
	
	return 0;
}
