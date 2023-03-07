#include "Blob.hpp"

int main() {
	Blob<int> b{1,2,3,4,5};
	BlobPtr<int> p(b);
	++p;
	std::cout << *p++ << std::endl;
	std::cout << *p << std::endl;
	
	return 0;
}
