#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <list>

template <typename C>
void print(const C &c) {
/*
	// Using size_type
	for(typename C::size_type i = 0; i != c.size(); ++i)
		std::cout << c[i] << " ";
*/	
	// Using iterators
	for(typename C::const_iterator it = c.begin(); it != c.end(); ++it)
		std::cout << *it << " ";
		
	std::cout << std::endl;
	
}

int main() {
	std::vector<int> v{1,2,3,4,5};
	std::array<std::string, 3> ar{"ehi", "we", "hello"};
	std::list<double> l{1., 1.5, 2, 2.5};
	
	print(v);
	print(ar);
	print(l);
	
	return 0;
}
