#include "Chapter6.hpp"

int main() {
	int a = 3, b = 7;
	std::cout << "Before swap:\t a = " << a << ", b = " << b << std::endl;
	swap(&a, &b);
	std::cout << "After swap:\t a = " << a << ", b = " << b << std::endl;
	return 0;
}
