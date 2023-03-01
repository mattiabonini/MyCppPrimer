#include <iostream>
#include <string>
#include <set>
#include <memory>

class Quote {
	public:
	Quote() = default;
	Quote(const std::string &id, double sales_price) : bookNo(id), price(sales_price) {}
	
	virtual Quote* clone() const & {return new Quote(*this);}
	virtual Quote* clone() && {return new Quote(std::move(*this));}
	
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

class Disc_quote : public Quote {
	public:
	Disc_quote() = default;
	Disc_quote(const std::string &id, double sales_price, size_t qty, double dis) :
		Quote(id, sales_price), min_qty(qty), discount(dis) {}
	
	double net_price(size_t n) const = 0;
	
	std::ostream& debug(std::ostream& os = std::cout) override {
		Quote::debug() << ", min_quantity: " << min_qty << ", discount: " << discount*100 << "%";
		return os;
	}
	
	protected:
	size_t min_qty = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
	public:
	using Disc_quote::Disc_quote;
	
	Bulk_quote* clone() const & override {return new Bulk_quote(*this);}
	Bulk_quote* clone() && override {return new Bulk_quote(std::move(*this));}
	
	double net_price(size_t n) const override { 
		if(n >= min_qty)
			return n * price * (1 - discount);
		else return n*price;
	}
};

class Limited_bulk_quote : public Disc_quote {
	public:
	Limited_bulk_quote() = default;
	Limited_bulk_quote(const std::string &id, double sales_price, size_t min_qty_, size_t max_qty_, double dis) :
		Disc_quote(id, sales_price, min_qty_, dis), max_qty(max_qty_) {}
		
	Limited_bulk_quote* clone() const & override {return new Limited_bulk_quote(*this);}
	Limited_bulk_quote* clone() && override {return new Limited_bulk_quote(std::move(*this));}
	
	double net_price(size_t n) const override {
		if(n >= max_qty)
			return max_qty * (1 - discount) * price + (n - max_qty) * price;
		else if(n >= min_qty) 
			return n * (1 - discount) * price;
		else 
			return n*price;
	}
	
	std::ostream& debug(std::ostream& os = std::cout) override final{
		Disc_quote::debug() << ", max_quantity: " << max_qty;
		return os;
	}
	
	private:
	size_t max_qty = 0;
	
};

class Basket {
	public:
	void add_item(const Quote &q) { items.insert(std::shared_ptr<Quote>(q.clone())); }
	void add_item(Quote &&q) {items.insert(std::shared_ptr<Quote>(std::move(q).clone())); }
	
	double total_receipt(std::ostream& os = std::cout) const;
	
	private:
	static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double print(std::ostream& os, const Quote &q, size_t n) {
	double ret = q.net_price(n);
	os << "You purchased " << n << " copies of \"" << q.isbn() << 
		"\" and the total price is " << ret << std::endl;
	return ret;
	
}

double Basket::total_receipt(std::ostream& os) const {
	double sum = 0.0;
	for(auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
		sum += print(os, **iter, items.count(*iter));
	os << "Total: " << sum << std::endl;
	return sum;
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
	
	Basket bsk;
	bsk.add_item(q1);
	bsk.add_item(b1);
	bsk.add_item(b1);
	bsk.add_item(b1);
	bsk.add_item(lb1);
	bsk.add_item(lb1);
	bsk.add_item(lb1);
	bsk.add_item(b1);
	bsk.add_item(b1);
	
	bsk.total_receipt();
	
	return 0;
}
