#ifndef BLOB_HPP
#define BLOB_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>

template<typename T> class BlobPtr;
template<typename T> class Blob;
template<typename T> bool operator==(const Blob<T> &lhs, const Blob<T> &rhs);

template<typename T> class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T> &lhs, const Blob<T> &rhs);
	
	public:
	typedef typename std::vector<T>::size_type size_type;
	typedef T value_type;
	
	Blob() : data(std::make_shared<T>()) {}
	Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}
	Blob(const Blob &b) : data(b.data) {}
	~Blob() = default;
	
	size_type size() const { return data->size(); }
	bool empty() const {return data->empty(); }
	
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	
	void pop_back();
	
	T& back();
	const T& back() const;
	
	T& operator[](size_type i);
	const T& operator[](size_type i) const;
	
	BlobPtr<T> begin();
	BlobPtr<T> end();
	
	private:
	std::shared_ptr<std::vector<T>> data;
	bool check(size_type i, const std::string &msg);
};

template<typename T> class BlobPtr {
	friend class Blob<T>;
	typedef typename Blob<T>::size_type size_type;
	
	public:
	BlobPtr() : curr(0) {}
	BlobPtr(Blob<T> &b, size_type sz = 0) : wptr(b.data), curr(sz) {}
	
	// Prefix
	BlobPtr& operator++() {
		check(curr, "out of bounds increment");
		++curr;
		return *this;
	}
	
	BlobPtr& operator--() {
		check(curr, "out of bounds increment");
		--curr;
		return *this;
	}
	
	// Postfix
	BlobPtr operator++(int);
	BlobPtr operator--(int);
	
	T& operator*() { 
		auto p = check(curr, "dereferencing out of bounds");
		return (*p)[curr];
	}
	
	private:
	std::shared_ptr<std::vector<T>> check(size_type i, const std::string &msg);
	
	std::weak_ptr<std::vector<T>> wptr;
	size_type curr;
	
};

template<typename T> 
bool Blob<T>::check(size_type i, const std::string &msg) {
	if(i >= size())
		throw std::out_of_range(msg);
}

template<typename T>
inline void Blob<T>::pop_back() {
	check(0, "pop on empty vector");
	data->pop_back();
}

template<typename T>
inline T& Blob<T>::back() {
	check(0, "back on empty vector");
	return data->back();
}

template<typename T>
inline T& Blob<T>::operator[](size_type i) {
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
inline const T& Blob<T>::back() const {
	check(0, "back on empty vector");
	return data->back();
}

template<typename T>
inline const T& Blob<T>::operator[](size_type i) const {
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T> 
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
	return lhs.data == rhs.data;
}

template<typename T> 
inline BlobPtr<T> Blob<T>::begin() {
	return BlobPtr<T>(*this, 0);
}

template<typename T> 
inline BlobPtr<T> Blob<T>::end() {
	return BlobPtr<T>(*this, size());
}

template<typename T>
inline BlobPtr<T> BlobPtr<T>::operator++(int) {
	auto ret = *this;
	++*this;
	return ret;
}

template<typename T>
inline BlobPtr<T> BlobPtr<T>::operator--(int) {
	auto ret = *this;
	--*this;
	return ret;
}

template<typename T>
inline std::shared_ptr<std::vector<T>> BlobPtr<T>::check(size_type i, const std::string &msg) {
	auto p = wptr.lock();
	if(i >= p->size())
		throw std::out_of_range(msg);
	return p;
}

#endif
