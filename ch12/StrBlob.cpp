#include "StrBlob.hpp"

std::string& StrBlob::front() {
	check(0, "front on empty vector");
	return data->front();
}
	
std::string& StrBlob::back() {
	check(0, "back on empty vector");
	return data->back();
}

const std::string& StrBlob::front() const {
	check(0, "front on empty vector");
	return data->front();
}

const std::string& StrBlob::back() const {
	check(0, "back on empty vector");
	return data->back();
}
	

void StrBlob::push_back(std::string &s) {
	data->push_back(s);
}

void StrBlob::pop_back() {
	check(0, "pop on empty vector");
	return data->pop_back();
}
	
void StrBlob::check(const size_type i, const std::string &msg) const {
	if(i >= this->size())
		throw std::out_of_range(msg);
}

StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
	return StrBlobPtr(*this, this->size());
}
