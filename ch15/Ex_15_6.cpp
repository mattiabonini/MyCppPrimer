#include <iostream>
#include <string>

class Quote {
	public:
	Quote() = default;
	Quote(const std::string &id, double sales_price) : bookNo(id), price(sales_price) {}
	
	std::string isbn() const {return bookNo; }
	
	virtual double net_price(size_t n) const {
		return n*price;
	}
	
	virtual std::ostream& debug(std::ostream& os = std::cout) {
		os << "ID: " << bookNo << ", price: " << price ;
		return os;
	}
	
	virtual ~Quote() = default;
	
	protected:
	double price = 0.0;
	
	private:
	std::string bookNo;
};

class Bulk_quote : public Quote {
	public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &id, double sales_price, size_t qty, double dis) :
		Quote(id, sales_price), min_qty(qty), discount(dis) {}
	
	double net_price(size_t n) const override { // If I don't declare this virtual, is the polymorphism handled dynamically? YES! -> Once it is declared virtual it is always virtual
		if(n >= min_qty)
			return n * price * (1 - discount);
		else return n*price;
	}
	
	std::ostream& debug(std::ostream& os = std::cout) override {
		Quote::debug() << ", min_quantity: " << min_qty << ", discount: " << discount*100 << "%";
		return os;
	}
	
	protected:
	size_t min_qty = 0;
	double discount = 0.0;

};

class Limited_bulk_quote : public Bulk_quote {
	public:
	Limited_bulk_quote(const std::string &id, double sales_price, size_t min_qty_, size_t max_qty_, double dis) :
		Bulk_quote(id, sales_price, min_qty_, dis), max_qty(max_qty_) {}
	
	double net_price(size_t n) const override {
		if(n >= max_qty)
			return Bulk_quote::net_price(max_qty) + Quote::net_price(n - max_qty); //(n - max_qty) * price;
		else return Bulk_quote::net_price(n);
	}
	
	std::ostream& debug(std::ostream& os = std::cout) override final{
		Bulk_quote::debug() << ", max_quantity: " << max_qty;
		return os;
	}
	
	private:
	size_t max_qty;
	
};

void print(std::ostream& os, const Quote &q, size_t n) {
	os << "You purchased " << n << " copies of \"" << q.isbn() << 
		"\" and the total price is " << q.net_price(n) << std::endl;
}

int main() {
	Quote q1("Harry Potter", 12);
	Bulk_quote b1("Lord of the rings", 16, 5, .5);
	Limited_bulk_quote lb1("Sapiens", 10, 5, 8, .5);
	
	print(std::cout, q1, 10);
	print(std::cout, b1, 4);
	print(std::cout, b1, 10);
	print(std::cout, lb1, 7);
	print(std::cout, lb1, 10);
	
	q1.debug() << std::endl;
	b1.debug() << std::endl;
	lb1.debug() << std::endl;
	
	return 0;
}
