#ifndef TEXTQUERY_HPP
#define TEXTQUERY_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

class QueryResult;

class TextQuery {
	public:
	friend class QueryResult;
	typedef std::vector<std::string> line_type;
	
	TextQuery(std::ifstream &f);
	
	QueryResult query(std::string);
	
	private:
	line_type lines;
	std::map<std::string, std::set<size_t>> words;

};

class QueryResult {
	public:
	
	friend std::ostream& print(std::ostream &, QueryResult &&);
	
	QueryResult(std::string &, TextQuery::line_type &, std::map<std::string, std::set<size_t>> &);
	
	std::string search;
	std::shared_ptr<TextQuery::line_type> lines_ptr;
	std::shared_ptr<std::map<std::string, std::set<size_t>>> words_ptr;
};

std::ostream& print(std::ostream &, QueryResult &&);
void my_delete_Vec(TextQuery::line_type *a); // {;};
void my_delete_Map(std::map<std::string, std::set<size_t>> *a); // {;};

#endif
