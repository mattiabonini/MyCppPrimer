#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int fact(int n) {
	if(n == 1 || n == 0) return 1;
	return n*fact(n-1);
}

template<typename T>
T abs(T x) {
	return std::abs(x);
}

int main() {
	int n;
	double x;
	
	cout << "Insert a number n > 0 to compute factorial." << endl;
	cin >> n;
	cout << n << "! is " << fact(n) << endl;
	
	cout << "Insert a number x to compute absolute value." << endl;
	cin >> x;
	cout << "|" << x << "| is " << abs(x) << endl;
	
	return 0;
}
	
