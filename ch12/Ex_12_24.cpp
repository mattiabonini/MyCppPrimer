#include <iostream>
#include <string>

int main() {
	int size{0};
	std::cout << "Input the size: ";
	std::cin >> size;
	char* res = new char[size + 1];
	
	std::cin.ignore();
	std::cout << "Input the string: ";
	std::cin.get(res, size + 1);
	std::cout << res << std::endl;
	
	delete[] res;
	return 0;
}
