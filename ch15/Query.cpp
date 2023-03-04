#include "Query.hpp"

QueryResult Query::eval(const TextQuery &t) const{ return query->eval(t); }
std::string Query::rep() const { return query->rep(); }

QueryResult AndQuery::eval(const TextQuery& t) const {
	auto right = rhs.eval(t), left = lhs.eval(t);
	auto ret_lines = std::make_shared<std::set<size_t>>();
	std::set_intersection(right.words_ptr->begin(), right.words_ptr->end(), left.words_ptr->begin(), left.words_ptr->end(), inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), left.lines_ptr, ret_lines);
}	
	
QueryResult OrQuery::eval(const TextQuery& t) const {
	auto right = rhs.eval(t), left = lhs.eval(t);
	auto ret_lines = std::make_shared<std::set<size_t>>(left.words_ptr->begin(), left.words_ptr->end());
	ret_lines->insert(right.words_ptr->begin(), right.words_ptr->end());
	return QueryResult(rep(), left.lines_ptr, ret_lines);
}

QueryResult NotQuery::eval(const TextQuery& t) const {
	auto result = query.eval(t);
	auto ret_lines = std::make_shared<std::set<size_t>>();
	
	auto beg = result.words_ptr->begin(), end = result.words_ptr->end();
	auto sz = result.lines_ptr->size();
	for(size_t n = 0; n != sz; ++n) {
		if(beg == end || *beg != n)
			ret_lines->insert(n);
		else if(beg != end)
			++beg;
	}
	return QueryResult(rep(), result.lines_ptr, ret_lines);
}
