#include <iostream>
#include <vector>

using vecIterator = std::vector<int>::iterator;

bool findValue(vecIterator&& beg, vecIterator&& end, int value) {
	while(beg != end) {
		if(*beg == value) return true;
		++beg;
	}
	return false;
}

vecIterator& findPos(vecIterator& beg, vecIterator& end, int value) {
	while(beg != end) {
		if(*beg == value) break;
		++beg;
	}
	return beg;
}

int main() {
	std::vector<int> test{1, 2, 3, 4, 5, 6, 7, 8, 9};
	int value = 7;
	
	// Ex 9.4
	std::cout << "Is " << value << " in vector? " << std::boolalpha << findValue(test.begin(), test.end(), value) << std::endl;
	
	// Ex 9.5
	vecIterator begin = test.begin();
	vecIterator end = test.end();
	begin = findPos(begin, end, value);
	std::cout << "Did we find value? " << std::boolalpha << ((begin == end) ? false : true) << std::endl;
	
	return 0;
}
