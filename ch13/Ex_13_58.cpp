#include <iostream>
#include <vector>
#include <algorithm>

class Foo;
class Foo {
	public:
	Foo(std::vector<int> vec_) : vec(vec_) {}
	
	/*
	Foo sorted() const & { 
		std::cout << "Calling Foo sorted() const &" << std::endl;
		Foo ret(*this);
		std::sort(ret.vec.begin(), ret.vec.end());
		return ret;
	}
	
	*/
	Foo sorted() const & {
		std::cout << "Calling Foo sorted() const &" << std::endl;
		return Foo(*this).sorted();
	}
	
	Foo sorted() && {
		std::cout << "Calling Foo sorted() &&" << std::endl;
		std::sort(this->vec.begin(), this->vec.end());
		return *this;
	}
		
	private:
	std::vector<int> vec;
};

int main() {
	std::vector<int> v{1,2,3};
	Foo f1(v);
	f1.sorted();
	Foo(v).sorted();
	return 0;
}
