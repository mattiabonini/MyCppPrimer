#include <iostream>

class Base {
	public:
	int pub_mem;
	
	protected:
	int prot_mem;
	
	private:
	int priv_mem;
};

class Pub_derv : public Base {
	void memfcn(Base &b) { b = *this; }
};

class Prot_derv : protected Base {
	void memfcn(Base &b) { b = *this; }
};

class Priv_derv : private Base {
	void memfcn(Base &b) { b = *this; }
};

class Derived_from_Public : public Pub_derv {
	void memfcn(Base &b) { b = *this; }
};

class Derived_from_Protected : public Prot_derv {
	void memfcn(Base &b) { b = *this; }
};

class Derived_from_Private : public Priv_derv {
	//void memfcn(Base &b) { b = *this; } // Illegal!
};

int main() {
	Pub_derv d1;
	Priv_derv d2;
	Prot_derv d3;
	Derived_from_Public dd1;
	Derived_from_Private dd2;
	Derived_from_Protected dd3;
	
	Base *b = &d1; // Ok
	//b = &d2; // Illegal
	//b = &d3; // Illegal
	//b = &dd1; // Ok
	//b = &dd2; // Illegal
	//b = &dd3; // Illegal
	
	return 0;
}

