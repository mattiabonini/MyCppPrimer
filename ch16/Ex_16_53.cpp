#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::ostream& print(std::ostream &os, const T &t) {
	os << t << std::endl;
	return os;
}

template <typename T, typename... Args>
std::ostream& print(std::ostream &os, const T &t, const Args&... args) {
	os << t << ", ";
	return print(os, args...);
}

class NoStreamOperator {
	std::vector<int> vec{1,2,3};
};

int main() {
	std::string s{"hello"};
	int i = 7;
	double pi = 3.14;
	NoStreamOperator obj;
	print(std::cout, i, 42, pi);
	
	return 0;
}
