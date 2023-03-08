#include <iostream>

template<typename T> // It fails with big numbers, we should define a promotion scheme
auto sum(const T &a, const T &b) -> decltype(a + b) {
	return a + b;
}

int main() {
	long a = 9000000000000000000;
	long b = 9000000000000000000;
	std::cout << a << std::endl;
	std::cout << sum(a,b) << std::endl;
	return 0;
}
