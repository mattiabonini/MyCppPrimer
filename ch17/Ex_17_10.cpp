#include <iostream>
#include <bitset>

using std::bitset;

template <unsigned N>
class Quiz {
	template <unsigned M> friend std::ostream& operator<<(std::ostream &os, const Quiz<M> &q);
	public:
	Quiz(std::istream &is = std::cin) {
		unsigned n;
		bool ans;
		std::cout << "Setting answers" << std::endl;
		while(is >> n >> ans)
			res.set(n-1, ans);
	}
	
	void grade(bitset<N> &ans) {
		auto mask = ~(ans^res);
		std::cout << "The grade is: " << mask.count() << " / " << mask.size() << std::endl;
	}
		
	private:
	bitset<N> res;
};

template <unsigned N> 
std::ostream& operator<<(std::ostream &os, const Quiz<N> &q) {
	os << q.res << std::endl;
	return os;
}

int main() {
	// Ex 17.10
	bitset<32> b1{0x20212e}; // 1, 2, 3, 5, 8, 13, 21
	bitset<32> b2;
	b2.set(1).set(2).set(3).set(5).set(8).set(13).set(21);
	
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	
	/*
	// Ex 17.11
	bitset<10> quiz10;
	bitset<100> quiz100; // Not possible to convert to long formats
	
	unsigned n;
	bool ans;
	std::cout << "Setting answers" << std::endl;
	while(std::cin >> n >> ans)
		quiz10.set(n-1, ans);
	std::cout << quiz10 << std::endl;
	*/
	
	// Ex 17.13
	Quiz<10> q;
	bitset<10> stud;
	stud.set(1).set(2).set(3).set(5).set(8);
	std::cout << "Student: " << stud << std::endl;
	std::cout << "Answer:  " << q;
	q.grade(stud);
	
	return 0;
}
