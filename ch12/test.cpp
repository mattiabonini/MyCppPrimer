#include <iostream>
#include <memory>

double* fun(double a) {
	double* b = new double(2*a);
	std::cout << "b = " << b << ", *b = " << *b << std::endl;
	return b;
}

int main() {
	double a = 3;
	//double c = 2;
	
	double *b = fun(a);
	std::cout << "b = " << b << ", *b = " << *b << std::endl;
	
	delete b;
	
	//b = &c;
	*b = 10;
	std::cout << "b = " << b << ", *b = " << *b << std::endl;
	return 0;
}
