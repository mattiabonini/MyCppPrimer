#ifndef STRBLOBPTR_HPP
#define STRBLOBPTR_HPP

#include <memory>
#include <exception>
#include <stdexcept>
#include "StrBlob.hpp"

class StrBlob;

class StrBlobPtr {
	friend StrBlobPtr operator+(const StrBlobPtr&, size_t i);
	friend StrBlobPtr operator-(const StrBlobPtr&, size_t i);
	
	public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &b, std::size_t sz = 0);
	
	// Operators
	std::string& operator[](size_t i) {return (*wptr)[i]; }
	const std::string& operator[](size_t i) const {return (*wptr)[i]; }
	StrBlobPtr& operator++(); //prefix
	StrBlobPtr& operator--(); //prefix
	StrBlobPtr operator++(int); //postfix
	StrBlobPtr operator--(int); //postfix
	std::string& operator*() const;
	std::string* operator->() const;
	
	StrBlobPtr& incr();
	std::string& deref() const;
	
	bool operator!= (const StrBlobPtr& p) const {return p.curr != curr;}
	
	private:
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
	
	std::shared_ptr<std::vector<std::string>>
	check(std::size_t i, const std::string &msg) const;

};

StrBlobPtr operator+(const StrBlobPtr&, size_t i);
StrBlobPtr operator-(const StrBlobPtr&, size_t i);

#endif
