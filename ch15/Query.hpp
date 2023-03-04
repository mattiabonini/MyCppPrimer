#ifndef QUERY_HPP
#define QUERY_HPP

#include <iostream>
#include <memory>
#include <string>
#include <algorithm>

#include "TextQuery.hpp"

class Query_base;

class Query {
	friend Query operator& (const Query &lhs, const Query &rhs);
	friend Query operator| (const Query &lhs, const Query &rhs);
	friend Query operator~ (const Query &op);
	friend std::ostream& operator<< (std::ostream &os, const Query &q);
	
	public:
	Query(std::string s);
	QueryResult eval(const TextQuery &t) const; //{ return query->eval(t); }
	std::string rep() const; // { return query->rep(); }
	
	private:
	Query(std::shared_ptr<Query_base> q) : query(q) {}
	std::shared_ptr<Query_base> query;

};

class Query_base {
	friend class Query;
	
	protected:
	using line_no = TextQuery::line_type;
	virtual ~Query_base() = default;
	
	private:
	virtual QueryResult eval(const TextQuery& t) const = 0;
	virtual std::string rep() const = 0;

};

class WordQuery : public Query_base {
	friend class Query;

	WordQuery(std::string s) : word(s) {}
	
	QueryResult eval(const TextQuery& t) const { return t.query(word); }
	std::string rep() const { return word; }
	
	std::string word;
	
};

class NotQuery : public Query_base {
	friend Query operator~ (const Query &op);
	
	NotQuery(const Query &q) : query(q) {}
	
	QueryResult eval(const TextQuery& t) const;
	std::string rep() const { return "~(" + query.rep() + ")"; }
	
	Query query;
};

class BinaryQuery : public Query_base {
	protected:
	BinaryQuery(const Query &lhs_, const Query &rhs_, const std::string& op_):
		lhs(lhs_), rhs(rhs_), op(op_) {}
	
	std::string rep() const { 
		return "(" + lhs.rep() + " " + op + " " + rhs.rep() + ")";
	}
	
	Query lhs, rhs;
	std::string op;
	
};

class OrQuery : public BinaryQuery {
	friend Query operator| (const Query &lhs, const Query &rhs);
	
	OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {}
	QueryResult eval(const TextQuery& t) const;
};

class AndQuery : public BinaryQuery {
	friend Query operator& (const Query &lhs, const Query &rhs);
	
	AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "&") {}
	QueryResult eval(const TextQuery& t) const;
	
};

inline std::ostream& operator<< (std::ostream &os, const Query &q) {
	os << q.rep();
	return os;
}

inline Query::Query(std::string s) : query(new WordQuery(s)) {}
	
inline Query operator& (const Query &lhs, const Query &rhs) {
	return Query(std::shared_ptr<Query_base>(new AndQuery(lhs, rhs)));
}
	
inline Query operator| (const Query &lhs, const Query &rhs) {
	return Query(std::shared_ptr<Query_base>(new OrQuery(lhs, rhs)));
}

inline Query operator~ (const Query &op) {
	return Query(std::shared_ptr<Query_base>(new NotQuery(op)));
}

#endif
