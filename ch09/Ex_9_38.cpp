#include <iostream>
#include <vector>

int main() {
	std::vector<int> a;
	std::cout << "Size: " << a.size() << ", Capacity: " << a.capacity() << std::endl;
	for(int i = 0; i < 100; ++i) {
		a.push_back(i);
		std::cout << "Size: " << a.size() << ", Capacity: " << a.capacity() << std::endl;
		if(i == 58) a.reserve(91);
	}
	a.shrink_to_fit();
	std::cout << "Size: " << a.size() << ", Capacity: " << a.capacity() << std::endl;
	return 0;
}
