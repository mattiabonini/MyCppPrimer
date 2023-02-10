#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <list>

int main(int argc, char **argv) {
/*
	std::ifstream in_file(argv[1]);
	std::ofstream out1(argv[2], std::fstream::app);
	std::ofstream out2(argv[3], std::fstream::app);
	
	std::istream_iterator<int> in_iterator(in_file), eof;
	std::ostream_iterator<int> out1_iterator(out1, " ");
	std::ostream_iterator<int> out2_iterator(out2, "\n");
	
	while(in_iterator != eof) {
		if(*in_iterator % 2) out1_iterator = *in_iterator;
		else out2_iterator = *in_iterator;
		++in_iterator;
	}
	*/
	// Ex 10.37
	std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
	std::list<int> lst(v.rbegin()+2, v.rend()-4);
	for(auto &i : lst) std::cout << i << " ";
	
	return 0;
}
