#include <iostream>
#include <string>
#include <sstream>

using std::string;

template <typename T> string debug_rep(const T&);
template <typename T> string debug_rep(T*);
//string debug_rep(const string&); // With and without comment
string debug_rep(char *c) { return debug_rep(string(c)); }
string debug_rep(const char *c) { return debug_rep(string(c)); }

template <typename T> string debug_rep(const T &t) {
	std::cout << "string debug_rep(const T &t)" << std::endl;
	std::ostringstream os;
	os << t;
	return os.str();
}

template <typename T> string debug_rep(T *p) {
	std::cout << "string debug_rep(T *p)" << std::endl;
	std::ostringstream os;
	os << "Pointer p: " << p;
	if(p) os << ", " << debug_rep(*p);
	else os << ", nullptr";
	return os.str();
}

string debug_rep(const string &s) {
	std::cout << "string debug_rep(const string &s)" << std::endl;
	return "'" + s + "'";
}

int main() {
	string s{"hello"};
	string *p = &s;
	const string *cp = &s;
	std::cout << debug_rep(s) << std::endl;
	std::cout << debug_rep(p) << std::endl;
	std::cout << debug_rep(cp) << std::endl;
	std::cout << debug_rep("world") << std::endl;
	return 0;
}
