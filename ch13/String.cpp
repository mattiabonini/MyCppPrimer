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

String::String(String &&str) noexcept : elem(str.elem), first_free(str.first_free), cap(str.cap) {
	std::cout << "Executing String(String &&)" << std::endl;
	str.elem = str.first_free = str.cap = nullptr;
}

String& String::operator=(String &&rhs) noexcept {
	std::cout << "Executing String& operator=(String &&)" << std::endl;
	if(this != &rhs) {
		free();
		elem = rhs.elem;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elem = rhs.first_free = rhs.cap = nullptr;
	}
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

std::ostream& operator<<(std::ostream &os, const String &s) {
	for(auto p = s.elem; p != s.first_free; ++p) os << *p;
	return os;
}

bool operator==(String &lhs, String &rhs) {
	if(lhs.size() != rhs.size()) return false;
	for(auto p = lhs.begin(), q = rhs.begin(); p != lhs.end(); ++p, ++q)
		if(*p != *q) return false;
	return true;
}

bool operator!=(String &lhs, String &rhs) {
	return !(lhs == rhs);
}

bool operator<(String &lhs, String &rhs) {
	auto n = (lhs.size() < rhs.size()) ? lhs.size() : rhs.size();
	for(auto i = 0; i < n; ++i)
		if(*(lhs.elem + i) < *(rhs.elem + i)) return true;	
		else if(*(lhs.elem + i) > *(rhs.elem + i)) return false;
	return (lhs.size() < rhs.size()) ? true : false;
}

	
	
	
	
	
