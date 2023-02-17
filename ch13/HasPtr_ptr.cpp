#include <iostream>
#include <string>

using std::string;

// Pointer-like behavior
class HasPtr_ptr {
	private:
	int i;
	std::string *ps;
	size_t *use;
	
	public:
	HasPtr_ptr() : i(0), ps(new string), use(new size_t(1)) {}
	HasPtr_ptr(string s) : i(0), ps(new string(s)), use(new size_t(1)) {}
	HasPtr_ptr(HasPtr_ptr &p) : i(p.i), ps(p.ps), use(p.use) { ++*use; }
	
	HasPtr_ptr& operator=(const HasPtr_ptr& p) {
		++(*p.use);
		if(--*use == 0) {
			delete ps;
			delete use;
		}
		ps = p.ps;
		i = p.i;
		use = p.use;
		return *this;
	}
	
	string get_ps() const {return *ps;};
	size_t get_count() const {return *use; }
	void set_ps(string s) const { *ps = s; }
	
	~HasPtr_ptr() { 
		if(--*use == 0) {
			std::cout << "Deleting object: " << *ps << std::endl;
			delete use;
			delete ps;
		} 
	}
};

int main() {
	HasPtr_ptr p1("ciao"), p2("hello");
	std::cout << "Count p1: " << p1.get_count() << ", p2: " << p2.get_count() << std::endl;
	HasPtr_ptr p3(p1);
	std::cout << "Count p1: " << p1.get_count() << ", p2: " << p2.get_count() << ", p3: " << p3.get_count() << std::endl;
	std::cout << p1.get_ps() << " " << p2.get_ps() << " " << p3.get_ps() << std::endl;
	p3 = p2;
	std::cout << "Count p1: " << p1.get_count() << ", p2: " << p2.get_count() << ", p3: " << p3.get_count() << std::endl;
	std::cout << p1.get_ps() << " " << p2.get_ps() << " " << p3.get_ps() << std::endl;
	return 0;
}
