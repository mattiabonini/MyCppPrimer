#include <iostream>
#include <vector>
#include <memory>

using vector = std::vector<int>;

std::shared_ptr<vector> fun() {
	return std::make_shared<vector>();
}

void readInput(std::shared_ptr<vector> v) {
	for(int a; std::cin >> a; )
		v->push_back(a);
}

void printVec(std::shared_ptr<vector> v) {
	for(auto it = v->begin(); it != v->end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main() {
	std::shared_ptr<vector> v = fun();
	readInput(v);
	printVec(v);
	return 0;
}
