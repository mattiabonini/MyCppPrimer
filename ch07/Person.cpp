#include "Person.hpp"

std::ostream& print(std::ostream& os, const Person& p) {
	os << p.get_name() << " " << p.get_address();
	return os;
}
	
std::istream& read(std::istream& is, Person& p) {
	is >> p.name >> p.address;
	return is;
}
