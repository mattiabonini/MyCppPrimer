#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>

class Person {
	friend std::ostream& print(std::ostream&, const Person&);
	friend std::istream& read(std::istream&, Person&);

	private:
	std::string name;
	std::string address;
	
	public:
	Person() = default;
	Person(std::string name_) : name(name_) {}
	Person(std::string name_, std::string address_) : name(name_), address(address_) {}
	Person(std::istream& is) { read(is, *this); }
	
	const std::string get_name() const {return name; }
	const std::string get_address() const {return address; }
	
};

std::ostream& print(std::ostream&, const Person&);
std::istream& read(std::istream&, Person&);

#endif
