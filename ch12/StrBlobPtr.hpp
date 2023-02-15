#ifndef STRBLOBPTR_HPP
#define STRBLOBPTR_HPP

#include <memory>
#include <exception>
#include <stdexcept>
#include "StrBlob.hpp"

class StrBlob;

class StrBlobPtr {
	public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &b, std::size_t sz = 0);
	
	StrBlobPtr& incr();
	std::string& deref() const;
	
	bool operator!= (const StrBlobPtr& p) const {return p.curr != curr;}
	
	private:
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
	
	std::shared_ptr<std::vector<std::string>>
	check(std::size_t i, const std::string &msg) const;

};

#endif
