#include <iostream>
#include <vector>

std::vector<int>* fun() {
	return new std::vector<int>();
}

void readInput(std::vector<int>* v) {
	for(int a; std::cin >> a; )
		v->push_back(a);
}

void printVec(std::vector<int>* v) {
	for(auto it = v->begin(); it != v->end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main() {
	std::vector<int> *v = fun();
	readInput(v);
	printVec(v);
	delete v;
	return 0;
}
	
