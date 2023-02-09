#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <list>
#include <forward_list>

// Ex 9.28
void insertInForward(std::forward_list<std::string> &fwd, std::string s1, std::string s2) {
	auto prev = fwd.before_begin(), curr = fwd.begin();
	bool hasInsert = false;
	
	while(curr != fwd.end()) {
		if(*curr == s1) {
			fwd.insert_after(curr, s2);
			hasInsert = true;
		}
		++prev, ++curr;
	}
	if(!hasInsert) fwd.insert_after(prev, s2);
}

int main() {

	// Ex 9.18
	//std::deque<std::string> con;
	/*
	std::list<std::string> con; // Ex 9.19
	std::string s;
	while(std::cin >> s)
		con.push_back(s);
	std::cout << std::endl << "OUTPUT" << std::endl;
	for(auto iter = con.begin(); iter != con.end(); ++iter)
		std::cout << *iter << std::endl;
	*/
	/*
	// Ex 9.20
	std::list<int> num{1,2,3,4,5,6,7,8,9};
	std::deque<int> even, odd;
	for(auto it = num.begin(); it != num.end(); ++it)
		if(*it % 2 == 0) even.push_back(*it);
		else odd.push_back(*it);
	
	std::cout << std::endl << "EVEN DEQUE" << std::endl;
	for(auto it = even.begin(); it != even.end(); ++it)
		std::cout << *it << std::endl;
	
	std::cout << std::endl << "ODD DEQUE" << std::endl;
	for(auto it = odd.begin(); it != odd.end(); ++it)
		std::cout << *it << std::endl;
	*/
	/*
	// Ex 9.24
	std::vector<int> v;
	//std::cout << v.at(0);
	//std::cout << v[0];
	//std::cout << *v.begin();
	std::cout << v.front();
	*/
	/*
	// Ex 9.26
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	std::vector<int> vec(std::begin(ia), std::end(ia));
	std::list<int> lst(std::begin(ia), std::end(ia));
	
	auto it = vec.begin();
	while(it != vec.end())
		if(*it % 2 == 0) it = vec.erase(it);
		else ++it;
	
	auto it2 = lst.begin();
	while(it2 != lst.end())
		if(*it2 % 2) it2 = lst.erase(it2);
		else ++it2;
	
	for(auto& a : vec) std::cout << a << " ";
	std::cout << std::endl;
	
	for(auto& a : lst) std::cout << a << " ";
	std::cout << std::endl;
	*/
	/*
	// Ex 9.27
	std::forward_list<int> fwd{1,2,3,4,5,6,7,8,9};
	
	for(auto prev = fwd.before_begin(), curr = fwd.begin(); curr != fwd.end();) {
		if(*curr % 2) {
			curr = fwd.erase_after(prev);
		} else {
			prev = curr;
			++curr;
		}
	}
	
	for(auto& a : fwd) std::cout << a << " ";
	std::cout << std::endl;
	*/
	
	// Ex 9.28	
	std::forward_list<std::string> fwd{"ciao", "come", "stai", "?", "cappello", "come", "mouse"};
	std::string s1{"come"};
	std::string s2{"banana"};
	std::string s3{"mela"};
	std::string s4{"telefono"};
	
	insertInForward(fwd, s1, s2);
	for(auto &a : fwd) std::cout << a << " ";
	std::cout << std::endl;
	
	insertInForward(fwd, s3, s4);
	for(auto &a : fwd) std::cout << a << " ";
	std::cout << std::endl;
	
	return 0;
}
