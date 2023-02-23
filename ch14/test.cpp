#include <iostream>

int f(double a, double b) {
	return a + b;
}
int f(int a, double b) {
	return a*b;
}

int main() {
	double a = 3.6, b = 3.6;
	std::cout << f(a,b) << std::endl;
	return 0;
}
