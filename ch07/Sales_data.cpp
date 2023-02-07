#include "Sales_data.hpp"

Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
	
double Sales_data::avg_price() const {
	if(units_sold)
		return revenue/units_sold;
	else return 0;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

std::ostream& print(std::ostream& os, const Sales_data& sd) {
	os << sd.isbn() << " " << sd.units_sold << " " << sd.revenue << " " << sd.avg_price();
	return os;
}

std::istream& read(std::istream& is, Sales_data& sd) {
	double price;
	is >> sd.bookNo >> sd.units_sold >> price;
	sd.revenue = sd.units_sold * price;
	return is;
}

