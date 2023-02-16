#include "TextQuery.hpp"

TextQuery::TextQuery(std::ifstream &f) {
	std::string line, word;
	size_t line_num = 1;
	while(getline(f, line)) {
		lines.push_back(line);
		std::istringstream is(line);
		while(is >> word) words[word].insert(line_num);
		++line_num;
	}
}
	
QueryResult TextQuery::query(std::string search) {
	return QueryResult(search, lines, words);
}

QueryResult::QueryResult(std::string &search_,  TextQuery::line_type &lines, std::map<std::string, std::set<size_t>> &words) :
	search(search_), lines_ptr(&lines, my_delete_Vec), words_ptr(&words, my_delete_Map) {}
	
std::ostream& print(std::ostream &os, QueryResult &&q) {
	auto p = (q.words_ptr)->find(q.search);
	size_t n = (p == (q.words_ptr)->end()) ? 0 : (p->second).size();
	os << q.search << " occurs " << n << " times" << std::endl;
	if(!n) return os;
	for(auto it = p->second.begin(); it != p->second.end(); ++it)
		os << "(line " << *it << ") " << (*q.lines_ptr)[*it - 1] << std::endl;
	return os;
}

void my_delete_Vec(TextQuery::line_type *a) {}
void my_delete_Map(std::map<std::string, std::set<size_t>> *a) {}

