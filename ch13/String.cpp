#include "String.hpp"

std::allocator<char> String::alloc;

String::String(const char *c) {
	std::cout << "Executing String(const char*)" << std::endl;
	elem = alloc.allocate(strlen(c));
	first_free = elem;
	for(size_t i = 0; i < strlen(c); ++i)
		alloc.construct(first_free++, c[i]);
	cap = elem + strlen(c);
}

String::String(const String &str) {
	std::cout << "Executing String(String&)" << std::endl;
	auto newdata = alloc_n_copy(str.begin(), str.end());
	elem = newdata.first;
	first_free = cap = newdata.second;
}
	
String& String::operator=(const String &rhs) {
	std::cout << "Executing String& operator=(const String&)" << std::endl;
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elem = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

void String::free() {
	while(first_free != elem)
		alloc.destroy(first_free--);
	alloc.deallocate(elem, cap - elem);
}

std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e) {
	auto data = alloc.allocate(e - b);
	return {data, std::uninitialized_copy(b, e, data)};
}

void String::print() const {
	for(auto p = elem; p != first_free; ++p)
		std::cout << *p;
}
