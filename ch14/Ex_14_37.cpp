#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std::placeholders;

class IsEqual {
	public:
	bool operator()(int a, int b) const {
		return (a == b) ? true : false;
	}
};

int main() {
	std::cout << "Insert two values: " << std::endl;
	int a, b;
	std::cin >> a >> b;
	std::cout << "Are those values equal? " << IsEqual()(a,b) << std::endl;
	
	std::vector<int> v{1, 3, 4, 3, 5, 6, 2, 3, 5, 7};
	
	std::cout << "Original vector: ";
	auto printer = [](int a) {std::cout << a; };
	std::for_each(v.begin(), v.end(), printer);
	std::replace_if(v.begin(), v.end(), std::bind(IsEqual(), _1, 3), 8);
	
	std::cout << std::endl << "Modified vector: ";
	std::for_each(v.begin(), v.end(), printer);
	std::cout << std::endl;	
	
	return 0;
}
