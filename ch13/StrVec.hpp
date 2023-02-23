#ifndef STRVEC_HPP
#define STRVEC_HPP

#include <string>
#include <iostream>
#include <memory>
#include <utility>
#include <exception>
#include <stdexcept>
#include <initializer_list>

using std::string;

class StrVec{
	public:
	// Construction and copy control
	StrVec() : elements_(nullptr), first_free_(nullptr), capacity_(nullptr) {}
	StrVec(std::initializer_list<std::string> il);
	StrVec(const StrVec &svec);
	StrVec(StrVec &&) noexcept;
	StrVec& operator=(const StrVec &rhs);
	StrVec& operator=(StrVec &&rhs) noexcept;
	StrVec& operator=(std::initializer_list<std::string> il);
	~StrVec() { free(); }
	
	std::string& operator[](size_t i) {return *(elements_ + i); }
	const std::string& operator[](size_t i) const {return *(elements_ + i); }
	
	//
	size_t size() const { return first_free_ - elements_; }
	size_t capacity() const { return capacity_ - elements_; }
	void reserve(size_t n);
	void resize(size_t n);
	
	string* begin() { return elements_; }
	string* end() { return first_free_; }
	const string* begin() const { return elements_; }
	const string* end() const { return first_free_; }
	void push_back(string &s);
	void pop_back();
	string& front();
	string& back();
	
	private:
	static std::allocator<string> alloc;
	string *elements_, *first_free_, *capacity_;
	
	void chk_n_alloc() { if(size() == capacity()) reallocate(); }
	void reallocate();
	void free();
	std::pair<string*, string*> alloc_n_copy(const string *b, const string *e);
};

#endif
