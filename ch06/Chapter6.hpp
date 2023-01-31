#ifndef CHAPTER_6_HPP
#define CHAPTER_6_HPP

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
int max (int a, const int *const b);

// Exercise 6.27
int my_sum(const std::initializer_list<int>& ls);

// Exercise 6.36 - 6.37
std::string (&func(std::string(&)[10])) [10];

using stringT = std::string[10]; 

auto func(stringT&) -> std::string (&)[10]; // Trailing return

stringT& func(stringT&); // Type alias

std::string str[10];
decltype(str)& func(stringT&); // Decltype


#endif
