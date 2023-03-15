#include <iostream>

namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}

int ivar = 100;

// Position 1
/*
//using Exercise::ivar; // Prediction: Compilation error!
using Exercise::dvar;
using Exercise::limit;
*/
//using namespace Exercise; // Prediction: compilation error on ++ivar

void manip() {
	// Position 2
	/*
	using Exercise::ivar; // Prediction: Shadowing
	// using Exercise::dvar; // Prediction: compilation error!
	using Exercise::limit;
	*/
	//using namespace Exercise; // Prediction: compilation error on ++ivar
	double dvar = 3.1416;
	int iObj = limit + 1;
	++ivar;
	++::ivar;
	std::cout << "dvar: " << dvar << ", iObj: " << iObj << ", ivar: " << Exercise::ivar << ", ::ivar: " << ::ivar << std::endl;
}

int main() {
	manip();
	return 0;
}
