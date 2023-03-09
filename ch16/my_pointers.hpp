#ifndef MY_POINTERS_HPP
#define MY_POINTERS_HPP

#include <iostream>
#include <functional>

// Forward declarations
template <typename T> class my_shared_ptr;
template <typename T, typename... Args> my_shared_ptr<T> make_shared(Args&&... args);

template <typename T>
class my_shared_ptr {
	using DeleterType = void(*)(T*);
	template <typename... Args> friend my_shared_ptr<T> make_shared(Args&&... args);
	public:
	my_shared_ptr(T *p = nullptr, DeleterType del = nullptr) : data(p), counter(new size_t(data != nullptr)), d(del) { 
		std::cout << "Constructor - Counter is: " << *counter << std::endl;
	}
	my_shared_ptr(const my_shared_ptr &m);
	my_shared_ptr& operator=(const my_shared_ptr &rhs);
	~my_shared_ptr();
	
	T& operator*() const { return *data; }
	T* operator->() const { return data; }
	
	private:
	T *data = nullptr;
	size_t *counter = nullptr;
	DeleterType d = nullptr;
};


struct defaultDeleter {
	template <typename T> void operator()(T *p) { delete p; }
};

template <typename T, typename D = defaultDeleter>
class my_unique_ptr {
	public:
	my_unique_ptr(T *p = nullptr, const D &del = defaultDeleter()) : data(p), d(del) {}
	my_unique_ptr(const my_unique_ptr&) = delete;
	my_unique_ptr& operator=(const my_unique_ptr &rhs) = delete;
	~my_unique_ptr() { 
		std::cout << "Destructor unique ptr" << std::endl;
		d(data); 
	}
	
	T& operator*() const { return *data; }
	T* operator->() const { return data; }
	
	private:
	T *data;
	D d;

};

template <typename T> 
inline my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr &m) : data(m.data), counter(m.counter), d(m.d) {
	++*counter;
	std::cout << "Copy constructor - Counter is: " << *counter << std::endl;
}

template <typename T> 
inline my_shared_ptr<T>& my_shared_ptr<T>::operator=(const my_shared_ptr &rhs) {
	std::cout << "Assignment (copying rhs)" << std::endl;
	auto tmp(rhs); // Auto-assignment
	--*counter;
	std::cout << "Assignment to do - Counter is: " << *counter << std::endl;
	data = tmp.data;
	counter = tmp.counter;
	d = tmp.d;
	++*counter;
	std::cout << "Assignment performed - Counter is: " << *counter << std::endl;
	return *this;
}

template <typename T>
inline my_shared_ptr<T>::~my_shared_ptr() {
	if(!data) return;
	--*counter;
	std::cout << "Destructor - Counter is: " << *counter << std::endl;
	if(*counter == 0) {
		d ? d(data) : delete data;
		delete counter;
	}
	data = nullptr;
	d = nullptr;
}

template<typename T, typename... Args>
my_shared_ptr<T> make_shared(Args&&... args) {
	return my_shared_ptr<T>(new T(std::forward<Args>(args)...));
}

#endif
