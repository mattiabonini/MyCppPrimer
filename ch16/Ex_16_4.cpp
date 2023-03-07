#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <array>

// 16.4
template<typename T, typename I>
I find(I begin, I end, T value) {
	I it = begin;
	while(it != end)
		if(*it++ == value) return --it;
	return it;
}

// 16.7
template<typename T, long unsigned N>
constexpr long unsigned size(std::array<T,N> arr) {
	return N;
}

int main() {
	std::vector<int> v{1,3,5,7,9,2,4,6,8};
	std::list<std::string> ls{"hello", "world", "!", "how", "are", "you?"};
	
	std::cout << *find(v.cbegin(), v.cend(), 6) << std::endl;
	std::cout << *find(ls.begin(), ls.end(), "hello") << std::endl;
	
	std::array<int, 5> arr{1,2,3,4,5};
	std::cout << size(arr) << std::endl;
	
	return 0;
}
	

