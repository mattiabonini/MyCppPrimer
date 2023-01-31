#include "Chapter6.hpp"

// Exercise 6.3
int fact(int n) {
	if(n == 1 || n == 0) return 1;
	return n*fact(n-1);
}

// Exercise 6.7
int counter() {
	static int ctr = 0;
	return ctr++;
}

// Exercise 6.10
void swap(int *p, int *q) {
	int tmp = *p;
	*p = *q;
	*q = tmp;
} 

//Exercise 6.17
bool hasUpperLetters (const std::string &s) {
	for(auto &c : s)
		if(isupper(c)) return true;
	return false;
}

void toLowerCase (std::string &s) {
	for(auto &c : s)
		c = tolower(c);
}

// Test
void print(const int *beg, const int *end) {
	while(beg != end)
		std::cout << *beg++ << std::endl;
}

// Exercise 6.21
int max (int a, const int *b) {
	return (a < *b) ? *b : a;
}

// Exercise 6.22
void swap (const int *&a, const int *&b) {
	const int *tmp = a;
	a = b;
	b = tmp;
}

		
