#include "TextQuery.hpp"

TextQuery::TextQuery(std::ifstream &f) : lines(std::make_shared<line_type>()), words(std::map<std::string, std::shared_ptr<std::set<size_t>>>()) {
	std::string line, word;
	size_t line_num = 1;
	while(getline(f, line)) {
		lines->push_back(line);
		std::istringstream is(line);
		while(is >> word) {
			std::shared_ptr<std::set<size_t>> &sp_lines = words[word];
			if(!sp_lines) sp_lines.reset(new std::set<size_t>());
			sp_lines->insert(line_num);
		}
		++line_num;
	}
}
	
QueryResult TextQuery::query(std::string search) const {
	auto res = words.find(search);
	auto ret = (res == words.end()) ? std::make_shared<std::set<size_t>>() : res->second;
	return QueryResult(search, lines, ret);
}


QueryResult::QueryResult(std::string search_, const std::shared_ptr<TextQuery::line_type> &lines, const std::shared_ptr<std::set<size_t>> &lines_no) :
	search(search_), lines_ptr(lines), words_ptr(lines_no) {}
	
std::ostream& print(std::ostream &os, QueryResult &&q) {
	size_t n = (q.words_ptr->empty()) ? 0 : q.words_ptr->size();
	os << q.search << " occurs " << n << " times" << std::endl;
	if(!n) return os;
	for(auto it = q.words_ptr->begin(); it != q.words_ptr->end(); ++it)
		os << "(line " << *it << ") " << (*q.lines_ptr)[*it - 1] << std::endl;
	return os;
}

