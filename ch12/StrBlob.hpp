#ifndef STRBLOB_HPP
#define STRBLOB_HPP

#include <memory>
#include <vector>
#include <string>
#include <exception>
#include <initializer_list>
#include "StrBlobPtr.hpp"

class StrBlobPtr;

class StrBlob {
	public:
	friend class StrBlobPtr;
	typedef std::vector<std::string>::size_type size_type;
	
	// Constructors
	StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
	StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}
	
	size_type size() const {return data->size(); }
	bool empty() const {return data->empty(); }
	
	std::string& front();
	std::string& back();
	const std::string& front() const;
	const std::string& back() const;
	
	void push_back(std::string &);
	void pop_back();
	
	StrBlobPtr begin();
	StrBlobPtr end();
	
	private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(const size_type i, const std::string &msg) const;
	
};

#endif
