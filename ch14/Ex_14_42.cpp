#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std::placeholders;

int main() {
	std::vector<int> v{1, 4, 5, 323, 2412, 3452, 523, 325325, 2353, 
						223, 233, 24, 4, 42, 35, 3, 3543, 34321, 35};
	
	// a
	auto counter = std::count_if(v.begin(), v.end(), std::bind(std::greater_equal<int>(), _1, 1024));
	std::cout << "# el. greater or equal than 1024: " << counter << std::endl;
	
	// b
	std::vector<std::string> v2{"pooh", "pooh", "aaa", "pooh", "ciao"};
	std::cout << "First not equal to pooh is: " << *std::find_if(v2.begin(), v2.end(), std::bind(std::not_equal_to<std::string>(), _1, "pooh")) << std::endl;
	
	// c
	auto printer = [](int a) {std::cout << a << " "; };
	std::for_each(v.begin(), v.end(), printer);
	std::cout << std::endl;
	std::transform(v.cbegin(), v.cend(), v.begin(), std::bind(std::multiplies<int>(), _1, 2));
	std::for_each(v.begin(), v.end(), printer);
	std::cout << std::endl;
	
	// Ex 14_43
	std::vector<int> v3{2,3,4,5,6,7};
	std::modulus<int> IntMod;
	std::cout << "Is 420 divisible for every element? " << (v3.end() == std::find_if(v3.begin(), v3.end(), [&](int a) -> bool { return IntMod(420, a) != 0; })) << std::endl;
	std::cout << "Is 60 divisible for every element? " << (v3.end() == std::find_if(v3.begin(), v3.end(), [&](int a) -> bool { return IntMod(60, a) != 0; })) << std::endl;
	
	return 0;
}
