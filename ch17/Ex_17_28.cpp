#include <iostream>
#include <random>

unsigned get_rand(const unsigned &min, const unsigned &max, const int &seed = 1) {
	static std::default_random_engine e(seed);
	static std::uniform_int_distribution<unsigned> dist(min, max);
	return dist(e);
}

int main() {
	for(size_t i = 0; i < 20; ++i)
		std::cout << get_rand(0, 10) << std::endl;
	
	return 0;
}
