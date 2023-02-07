#ifndef SALES_DATA_HPP
#define SALES_DATA_HPP

#include <iostream>
#include <string>

class Sales_data {
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream& print(std::ostream&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);
	
	private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
	
	public:
	// Constructors
	Sales_data(std::string bookNo_, unsigned n, double p) :
				bookNo(bookNo_), units_sold(n), revenue(p*n) {}
	Sales_data() : Sales_data("", 0, 0) {}
	/* equivalent to Sales_data() : bookNo(""), units_sold(0), revenue(0) {} */
	Sales_data(std::string bookNo_) : Sales_data(bookNo_, 0, 0) {}
	Sales_data(std::istream& is) : Sales_data() { read(is, *this); }
	
	// Methods
	std::string isbn() const {return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
};

// Should I repeat the declaration?!
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);

#endif
