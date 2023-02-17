#include <iostream>
#include <string>

using std::string;

// Value-like behavior
class HasPtr_val {
	private:
	int i;
	std::string *ps;
	
	public:
	HasPtr_val() : i(0), ps(new string) {}
	HasPtr_val(string s) : i(0), ps(new string(s)) {}
	HasPtr_val(HasPtr_val &p) : i(p.i), ps(new string(*p.ps)) {}
	
	HasPtr_val& operator=(const HasPtr_val& p) {
		auto pnew = new string(*p.ps);
		delete ps;
		ps = pnew;
		i = p.i;
		return *this;
	}
	
	std::string get_ps() const {return *ps;};
	
	~HasPtr_val() { 
		std::cout << "Deleting object: " << *ps << std::endl; 
		delete ps; 
	}
};

int main() {
	HasPtr_val p1("ciao"), p2("hello"), p3(p1);
	std::cout << p1.get_ps() << " " << p2.get_ps() << " " << p3.get_ps() << std::endl;
	p3 = p2;
	std::cout << p1.get_ps() << " " << p2.get_ps() << " " << p3.get_ps() << std::endl;
	return 0;
}
