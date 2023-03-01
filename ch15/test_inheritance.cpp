#include <iostream>

class abstract_Base {
	public:
	virtual void pure_vir_met() = 0;
	void not_vir_method() {
		std::cout << "Not virtual method in abstract_Base" << std::endl;
	}
	~abstract_Base() = default;
};

class base : public abstract_Base {
	public:
	void pure_vir_met() override {
		std::cout << "Override of pure virtual in Base" << std::endl;
	}
};

class derived : public base {
	public:
	void pure_vir_met() override {
		std::cout << "Override of pure virtual in Derived" << std::endl;
	}
	void not_vir_method() {
		std::cout << "Not virtual method in Derived" << std::endl;
	}
	void other_method() {
		std::cout << "other method in derived" << std::endl;
	}
};

int main() {
	base b;
	derived d;
	
	abstract_Base *p;
	p = &b;
	p->pure_vir_met();
	p->not_vir_method();
	p = &d;
	p->pure_vir_met();
	p->not_vir_method();
	
	std::cout << "From the objects" << std::endl;
	b.not_vir_method();
	d.not_vir_method();
	//p->other_method(); // Not visible from an abstract_Base pointer!!
	
	return 0;
}
