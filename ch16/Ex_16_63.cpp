#include <iostream>
#include <vector>
#include <cstring>
#include <string>

template <typename T>
size_t count(const std::vector<T> &vec, const T &val) {
	std::cout << "template <typename T> size_t count(const std::vector<T> &vec, const T &val)" << std::endl;
	size_t ctr = 0;
	for(const auto &v : vec)
		if(v == val) ++ctr;
	return ctr;
}

template<>
size_t count(const std::vector<const char*> &vec, const char* const &val) {
	std::cout << "template<> size_t count(const std::vector<const char*> &vec, const char* const &val)" << std::endl;
	size_t ctr = 0;
	for(const auto &v : vec)
		if(strcmp(v, val) == 0) ++ctr;
	return ctr;
}

int main() {
	std::vector<const char*> v1{"hello", "Hello", "hello"};
	std::vector<std::string> v2{std::string("hello"), std::string("Hello"), std::string("hello")};
	std::vector<int> v3{1, 2, 3, 4, 4, 5};
	
	const char *s = "hello";
	std::cout << count(v1, s) << std::endl;
	std::cout << count(v2, std::string(s)) << std::endl;
	std::cout << count(v3, 4) << std::endl;
	
	return 0;
}
