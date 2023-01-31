#include <iostream>
#include <string>
#include <vector>
#include <array>

// Exercise 6.3
int fact(int n);

// Exercise 6.5
template<typename T>
T abs(T x) {
	return std::abs(x);
}

// Exercise 6.7
int counter(); 

// Exercise 6.10
void swap(int *p, int *q);

// Exercise 6.17
bool hasUpperLetters (const std::string &s);

void toLowerCase (std::string &s);

// Exercise 6.18
struct matrix {};
bool compare(const matrix&, const matrix&);

std::vector<int>::iterator change_val(int, std::vector<int>::iterator);

// Test
void print(const int *beg, const int *end);

// Exercise 6.21
int max (int a, const int *b);

