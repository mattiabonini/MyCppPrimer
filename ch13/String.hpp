#ifndef MY_STRING_HPP
#define MY_STRING_HPP

#include <memory>
#include <utility>
#include <cstring>
#include <algorithm>
#include <iostream>

class String {
	friend std::ostream& operator<<(std::ostream &os, const String &s);
	friend bool operator==(String &lhs, String &rhs);
	friend bool operator!=(String &lhs, String &rhs);
	friend bool operator<(String &lhs, String &rhs);
	
	public:
	String() : elem(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const char*);
	String(const String &);
	String(String &&) noexcept;
	String& operator=(const String &rhs);
	String& operator=(String &&rhs) noexcept;
	~String() {free(); }
	
	char& operator[](size_t i) { return *(elem + i); }
	const char& operator[](size_t i) const { return *(elem + i); }
	
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

std::ostream& operator<<(std::ostream &os, const String &s);
bool operator==(String &lhs, String &rhs);
bool operator!=(String &lhs, String &rhs);
bool operator<(String &lhs, String &rhs);

#endif

