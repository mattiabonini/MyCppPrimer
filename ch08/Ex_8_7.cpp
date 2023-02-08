#include "../ch07/Sales_data.hpp"
#include <fstream>

int main(int argc, char **argv) {
	std::ifstream in(argv[1]);
	std::ofstream out(argv[2], std::ofstream::app);
	if(in) {
		Sales_data total(in);
		Sales_data trans;
		while(read(in, trans)) {
			if(total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(out, total) << std::endl;
				total = trans;
			}
		}
		print(out, total) << std::endl;
		}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	in.close();
	out.close();
	
	return 0;
}
	
