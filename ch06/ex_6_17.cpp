#include "Chapter6.hpp"

int main() {
	std::string s = {"Hello worLD!"};
	std::cout << "Has upper letters? " << hasUpperLetters(s) << std::endl;
	std::cout << s << " -- ";
	toLowerCase(s); 
	std::cout << s << std::endl;
	int arr[] = {1, 2, 3, 4, 5};
	print(std::begin(arr), std::end(arr));
	return 0;
}
