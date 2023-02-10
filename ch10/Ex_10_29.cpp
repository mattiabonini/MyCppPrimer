#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {

	// Ex 10.29 - Reading from std input instead of files
	std::istream_iterator<int> in(std::cin), eof;
	std::vector<int> v(in, eof);
	std::cout << std::endl << "OUTPUT" << std::endl;
	std::for_each(v.begin(), v.end(), [](int a) {std::cout << a << " ";});
	std::cout << std::endl;
	
	// Ex 10.30
	std::ostream_iterator<int> out(std::cout, " ");
	std::sort(v.begin(), v.end());
	std::copy(v.begin(), v.end(), out);
	std::cout << std::endl;
	
	// Ex 10.31
	std::unique_copy(v.begin(), v.end(), out);
	std::cout << std::endl;
	return 0;
}
	
