#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

int main() {

	// Ex 10.27
	std::vector<int> v{1,4,2,6,3,5,4,5,5,6,9,6,4,2,6,4,7,4,8,8};
	std::list<int> lst;
	
	std::sort(v.begin(), v.end());
	std::unique_copy(v.begin(), v.end(), std::back_inserter(lst));
	std::for_each(lst.begin(), lst.end(), [](int i) {std::cout << i << " ";});
	std::cout << std::endl;
	
	// Ex 10.28
	std::vector<int> v2(lst.begin(), lst.end());
	std::deque<int> test;
	std::copy(v2.begin(), v2.end(), std::inserter(test, test.end()));
	std::for_each(test.begin(), test.end(), [](int a){ std::cout << a << " ";});
	std::cout << std::endl;
	
	// Back inserter: 1 2 3 4 5 6 7 8 9 
	// Front inserter: 9 8 7 6 5 4 3 2 1
	// Inserter with begin(): 1 2 3 4 5 6 7 8 9
	// Inserter with end(): 1 2 3 4 5 6 7 8 9 (!!!)
	return 0;
}
