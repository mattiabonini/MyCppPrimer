#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <vector>

class Families {
	private:
	std::map<std::string, std::vector<std::pair<std::string, std::string>>> families;
	
	public:
	std::istream& readFamilies(std::istream &is) {
		std::string surname, name, birthday;
		while(is >> surname >> name >> birthday)
			families[surname].push_back({name, birthday});
		return is;
	}
	
	std::ostream& printFamilies(std::ostream &os = std::cout) {
		for(const auto &f : families) {
			os << "Surname: " << f.first << std::endl;
			for(const auto &c : f.second)
				os << "\t" << c.first << ", " << c.second << std::endl;
		}
		return os;
	}
};

int main() {
	Families fam;
	fam.readFamilies(std::cin);
	fam.printFamilies();

	return 0;
}
