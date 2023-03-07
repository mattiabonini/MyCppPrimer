#ifndef DEBUG_DELETE_HPP
#define DEBUG_DELETE_HPP

class DebugDelete {
	public:
	DebugDelete(std::ostream &s = std::cerr) : os(s) {}
	
	template <typename T>
	void operator()(T *p) {
		os << "Deleting the pointer with the debug class" << std::endl;
		delete p;
	}
	
	private:
	std::ostream &os;
};

#endif
