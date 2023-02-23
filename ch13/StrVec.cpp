#include "StrVec.hpp"
std::allocator<string> StrVec::alloc;

StrVec::StrVec(std::initializer_list<std::string> il) {
	elements_ = alloc.allocate(il.size());
	first_free_ = std::uninitialized_copy(il.begin(), il.end(), elements_);
	capacity_ = first_free_;
}
	
StrVec::StrVec(const StrVec &svec) {
	auto newdata = alloc_n_copy(svec.begin(), svec.end());
	elements_ = newdata.first;
	first_free_ = capacity_ = newdata.second;
}

StrVec& StrVec::operator=(const StrVec &rhs) {
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements_ = newdata.first;
	first_free_ = newdata.second;
	capacity_ = newdata.second;
	return *this;
}

StrVec::StrVec(StrVec &&svec) noexcept : elements_(svec.elements_), first_free_(svec.first_free_), capacity_(svec.capacity_) {
	svec.elements_ = svec.first_free_ = svec.capacity_ = nullptr;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept{
	if(this != &rhs) {
		free();
		elements_ = rhs.elements_;
		first_free_ = rhs.first_free_;
		capacity_ = rhs.capacity_;
		rhs.elements_ = rhs.first_free_ = rhs.capacity_ = nullptr;
	}
	return *this;
}

StrVec& StrVec::operator=(std::initializer_list<std::string> il) {
	free();
	elements_ = alloc.allocate(il.size());
	first_free_ = elements_;
	for(auto i = 0; i != il.size(); ++i)
		alloc.construct(first_free_++, il[i]);
	capacity_ = first_free_;
	return *this;
} 
	
void StrVec::reserve(size_t n) {
	if(capacity() < n) {
		auto newdata = alloc.allocate(n);
		auto last = std::uninitialized_copy(begin(), end(), newdata);
		free();
		elements_ = newdata;
		first_free_ = last;
		capacity_ = elements_ + n;
	}
}

void StrVec::resize(size_t n) {
	if(capacity() < n) {
		auto new_data = alloc.allocate(n);
		auto last = std::uninitialized_fill_n(new_data, n, "");
		free();
		elements_ = new_data;
		first_free_ = capacity_ = last;
	} else {
		// Destroy and fill or change?!
		while(first_free_ != elements_)
			alloc.destroy(--first_free_);
		for(size_t i = 0; i < n; ++i)
			alloc.construct(first_free_++, "");
	}
}
	
void StrVec::push_back(string &s) {
	chk_n_alloc();
	alloc.construct(first_free_++, s);
}

void StrVec::pop_back() {
	alloc.destroy(--first_free_);
}

string& StrVec::front() {
	if(!elements_) throw std::runtime_error("Front on an empty vector");
	return *elements_;
}

string& StrVec::back() {
	if(first_free_ == elements_) throw std::runtime_error("Back on an empty vector");
	return *(first_free_ - 1);
}
	
void StrVec::reallocate() {
	auto newcap = size() ? 2*size() : 1; //New capacity
	
	// Allocation of new memory 
	auto newdata = alloc.allocate(newcap);
	auto dest = newdata;
	auto elem = elements_;
	for(size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
		
	// Deallocation of old memory 
	free();
	elements_ = newdata;
	first_free_ = dest;
	capacity_ = newdata + newcap;
}

void StrVec::free() {
	while(first_free_ != elements_)
		alloc.destroy(--first_free_);
	//std::for_each(elements, first_free, [this](string &s) {alloc.destroy(&s);}); // equivalent representation
	alloc.deallocate(elements_, capacity_ - elements_);
}
	
std::pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
	auto data = alloc.allocate(e - b);
	return {data, std::uninitialized_copy(b, e, data)};
}
	
	
	
	
