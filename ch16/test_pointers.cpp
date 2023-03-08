#include "my_pointers.hpp"

template <typename T>
void my_deleter(T *p) {
	std::cout << "Defining my deleter" << std::endl;
	delete p;
}

int main() {
	my_shared_ptr<int> p;
	my_shared_ptr<double> d(new double(2.0));
	my_shared_ptr<double> e(new double(10.0));
	my_shared_ptr<long> f(new long(7), my_deleter<long>);
	
	{
		my_shared_ptr<double> d2(d);
		my_shared_ptr<double> d3(e);
		d3 = d2;
		auto f2(f);
		*f2 = 1;
		std::cout << "Back in the scope" << std::endl;
	}
	std::cout << "Back in the main" << std::endl;
	std::cout << *f << std::endl;
	
	my_unique_ptr<int> un(new int(5));
	*un = 7;
	std::cout << *un << std::endl;
	return 0;
}
