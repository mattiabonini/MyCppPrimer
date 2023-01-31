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
