#include <iostream>
#include <functional>
#include <string>
#include <map>

int add(int a, int b) {
	return a + b;
}

class minus {
	public:
	int operator()(int a, int b) {
		return a - b;
	}
};

int main() {
	auto multiply = [](int a, int b) -> int { return a*b;};
	std::divides<int> divide;
	
	std::map<std::string, std::function<int(int,int)>> binops;
	binops.insert({"+", add});
	binops.insert({"-", minus()});
	binops.insert({"*", multiply});
	binops.insert({"/", divide});
	binops.insert({"%", [](int a, int b) {return a%b; }});
	
	std::cout << "10 + 5 = " << binops["+"](10,5) << std::endl;
	std::cout << "10 - 5 = " << binops["-"](10,5) << std::endl;
	std::cout << "10 * 5 = " << binops["*"](10,5) << std::endl;
	std::cout << "10 / 5 = " << binops["/"](10,5) << std::endl;
	std::cout << "10 % 5 = " << binops["%"](10,5) << std::endl;
	
	return 0;
}
