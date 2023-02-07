#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <iostream>
#include <string>
#include <vector>
//#include "Window_mgr.hpp"

class Screen;

class Window_mgr {
	public:
	using ScreenIndex = std::vector<Screen>::size_type;
	
	void clear(ScreenIndex i);
	
	private:
	std::vector<Screen> screens; //{Screen(24, 80, ' ')};
	
};

class Screen {
	public:
	typedef std::string::size_type pos;
	
	friend void Window_mgr::clear(ScreenIndex i);
	
	mutable unsigned access_ctr = 0;
	
	Screen() = default;
	Screen(pos w, pos h) : width(w), height(h), contents(w*h, ' ') {}
	Screen(pos w, pos h, char c) : width(w), height(h), contents(w*h, c) {}
	
	char get() const{return contents[cursor]; }
	char get(pos r, pos c) const{return contents[r*width + c]; }
	
	Screen& move(pos r, pos c);
	
	Screen& set(char s);
	Screen& set(pos r, pos c, char s);
	
	const Screen& display(std::ostream& os) const;
	Screen& display (std::ostream& os);
	
	private:
	pos width = 0, height = 0, cursor = 0;
	std::string contents;
	void do_display(std::ostream& os) const{ os << contents; }
};

inline Screen& Screen::move(pos r, pos c) {
	cursor = r*width + c;
	return *this;
}

inline Screen& Screen::set(char s) {
	contents[cursor] = s;
	return *this;
}

inline Screen& Screen::set(pos r, pos c, char s) {
	contents[r*width + c] = s;
	return *this;
}

inline const Screen& Screen::display(std::ostream& os) const {
	do_display(os);
	return *this;
}

inline Screen& Screen::display (std::ostream& os){
	do_display(os);
	return *this;
}

void Window_mgr::clear(ScreenIndex i) {
		Screen &s = screens[i];
		s.contents = std::string(s.width*s.height, ' ');
}

#endif
