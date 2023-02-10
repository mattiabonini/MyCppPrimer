#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

// Ex 10.11
template <class T>
void elimDups(std::vector<T> &v) {
	std::sort(v.begin(), v.end());
	auto it = std::unique(v.begin(), v.end());
	v.erase(it, v.end());
}

bool isShorter(const std::string& s1, const std::string& s2) {
	return s1.size() < s2.size();
}

// Ex 10.13
bool min5(const std::string& s) {
	return s.size() < 5;
}

int main() {
	std::vector<std::string> vec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	
	// Ex 10.11
	/*
	elimDups(vec);
	for(auto &s : vec) std::cout << s << " ";
	std::cout << std::endl;
	std::stable_sort(vec.begin(), vec.end(), isShorter);
	for(auto &s : vec) std::cout << s << " ";
	std::cout << std::endl;
	*/
	// Ex 10.13
	auto it2 = std::partition(vec.begin(), vec.end(), min5);
	for(auto &s : vec) std::cout << s << " ";
	std::cout << std::endl;
	vec.erase(it2, vec.end());
	for(auto &s : vec) std::cout << s << " ";
	std::cout << std::endl;
	
	return 0;
}
