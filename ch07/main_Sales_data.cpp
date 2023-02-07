#include "Sales_data.hpp"

using std::cin;
using std::cout;

int main() {
/*
	Sales_data total;
	if(read(cin, total)) {
		Sales_data trans;
		while(read(cin, trans)) { 
			if(total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total) << std::endl;
				total = trans;
			}
		}
		print(cout, total) << std::endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
*/	
	// Equivalent to 
	Sales_data total(cin);
	if(!total.isbn().empty()) {
		while(cin) {
			Sales_data trans(cin);
			if(total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total) << std::endl;
				total = trans;
			}
		}
		print(cout, total) << std::endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
		
	return 0;
}
