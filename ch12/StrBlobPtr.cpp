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
