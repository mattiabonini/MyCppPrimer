#include <iostream>
#include <utility>


void f(int a, int &b) {
	std::cout << ++a << ", " << --b << std::endl;
}
void g(int &&a, int &b) {
	std::cout << ++a << ", " << --b << std::endl;
}

template <typename F, typename T1, typename T2>
void flip1(F fun, T1 t1, T2 t2) {
	fun(t2,t1);
}

template <typename F, typename T1, typename T2>
void flip2(F fun, T1 &&t1, T2 &&t2) {
	fun(t2,t1);
}

template <typename F, typename T1, typename T2>
void flip3(F fun, T1 &&t1, T2 &&t2) {
	fun(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main() {
	int a = 5;
	
	// flip 1
	std::cout << "Flip 1" << std::endl;
	flip1(f, a, 42); 
	std::cout << a << std::endl; // 5
	//flip1(g, a, 42); //error
	
	// flip 2
	std::cout << "Flip 2" << std::endl;
	flip2(f, a, 42); 
	std::cout << a << std::endl; // 4
	//flip2(g, a, 42); //error

	
	// flip 3
	std::cout << "Flip 3" << std::endl;
	flip3(f, a, 42); 
	std::cout << a << std::endl; // 3
	flip3(g, a, 42);
	std::cout << a << std::endl; // 2
	
	return 0;
}
	
	
