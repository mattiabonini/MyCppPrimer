#include <iostream>
#include <memory>
#include <string>

int main() {
	std::allocator<std::string> alloc;
	auto p = alloc.allocate(10);
	auto q = p;
	
	std::string s;
	for(unsigned i = 0; i != 10 && std::cin >> s; ++i)
		alloc.construct(q++,s);
	
	for(auto it = p; it != q; ++it) std::cout << *it << std::endl;
	
	while(q != p)
		alloc.destroy(q--);
	
	alloc.deallocate(p,10);
	return 0;
}
