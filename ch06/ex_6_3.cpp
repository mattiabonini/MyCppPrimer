#include "Chapter6.hpp"

using std::cout;
using std::cin;
using std::endl;

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
	
