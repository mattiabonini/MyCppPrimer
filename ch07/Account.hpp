#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

class Account {
	public:
	void calculate() { amount += amount * interestRate; }
	
	static double rate() {return interestRate;}
	static void rate(double newRate);
	
	private:
	std::string owner;
	double amount;
	
	static double interestRate;
	static double initRate();	
};

#endif
