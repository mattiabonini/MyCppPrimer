#ifndef MY_STRING_HPP
#define MY_STRING_HPP

#include <memory>
#include <utility>
#include <cstring>
#include <algorithm>
#include <iostream>

class String {
	public:
	String() : elem(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const char*);
	String(const String &);
	String& operator=(const String &rhs);
	~String() {free(); }
	
	size_t size() const { return first_free - elem; }
	size_t capacity() const { return cap - elem; }
	
	char* begin() { return elem;}
	char* end() { return first_free; }
	const char* begin() const { return elem;}
	const char* end() const { return first_free; }
	
	void print() const;
	
	private:
	static std::allocator<char> alloc;
	char *elem, *first_free, *cap;
	
	void free();
	std::pair<char*, char*> alloc_n_copy(const char *b, const char *e);
};

#endif

