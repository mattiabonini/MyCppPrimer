#include <iostream>

class numbered {
	private:
	static int count;
	int id;
	
	public:	
	numbered() {id = count++;}
	numbered(const numbered &n) {id = count++;}
	
	int get_id() {return id;}
};

int numbered::count = 0;

void f(numbered& x) {
	std::cout << "In f: " << x.get_id() << std::endl;
}

int main() {
	numbered a, b = a, c = b;
	std::cout << "a_id = " << a.get_id() << ", b_id = " << b.get_id() << ", c_id = " << c.get_id() << std::endl;
	f(a); 
	f(b); 
	f(c);
	return 0;
}
