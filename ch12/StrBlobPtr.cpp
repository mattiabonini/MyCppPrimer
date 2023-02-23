#include "StrBlobPtr.hpp"

StrBlobPtr::StrBlobPtr(StrBlob &b, std::size_t sz) : wptr(b.data), curr(sz) {}

StrBlobPtr& StrBlobPtr::incr() {
	auto sp = check(curr, "Out of bound increment");
	++curr;
	return (*this);
}

std::string& StrBlobPtr::deref() const {
	auto sp = check(curr, "Out of bound dereferencing");
	return (*sp)[curr];
}
	
std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
	auto sp = wptr.lock();
	if(!sp) throw(std::runtime_error("Unbounded weak pointer"));
	if(i >= sp->size()) throw std::out_of_range(msg);
	return sp;
}

StrBlobPtr& StrBlobPtr::operator++() {
	check(curr, "Out of bound increment");
	++curr;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator--() {
	--curr;
	check(curr, "Out of bound decrement");
	return *this;
}

StrBlobPtr operator++(int) {
	StrBlobPtr ret(*this);
	++*this;
	return ret;
}

StrBlobPtr operator--(int) {
	StrBlobPtr ret(*this);
	--*this;
	return ret;
}

std::string& operator*() const {
	auto p = check(curr, "Dereference past end");
	return (*p)[curr];
}
	
	
std::string* operator->() const {
	return & this->operator*();
}

StrBlobPtr operator+(const StrBlobPtr& op, size_t i) {
	StrBlobPtr ret(op);
	ret.curr += i;
	check(ret.curr, "Out of bound index addition");
	return ret;
}

StrBlobPtr operator-(const StrBlobPtr& op, size_t i) {
	StrBlobPtr ret(op);
	ret.curr -= i;
	check(ret.curr, "Out of bound index subtraction");
	return ret;
}
