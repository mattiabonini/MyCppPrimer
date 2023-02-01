#include <iostream>
#include <vector>
#include <climits>

using F = int (int, int);
using PF = int (*)(int, int);

int m_add(int a, int b) { return a+b;};
int m_sub(int a, int b) { return a-b;};
int m_mul(int a, int b) { return a*b;};
int m_div(int a, int b) { return ((b == 0) ? INT_MAX : a/b);};

int main() {
	int a = 72, b = 9;
	
	std::vector<PF> op_vec{m_add, m_sub, m_mul, m_div};
	
	for(auto f : op_vec)
		std::cout << a << " op " << b << " = " << f(a,b) << std::endl;
	
	return 0;
}
	
