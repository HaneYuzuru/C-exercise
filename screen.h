#include <iostream>
#include <stdlib.h>
#include <string.h>

#ifndef SCREEN
#define SCREEN
class screen{
public:
	typedef std::string::size_type pos;
	screen() = default;
	screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht * wd, c){}
	screen &set(char);
	screen &set(pos,pos,char);
	char get() const
		{return contents[cursor];}
	inline char get(pos ht,pos wd) const;
	screen &move(pos r, pos c);
	screen &display(std::ostream &os){
		do_display(os);
		return *this;
	}
	const screen &display(std::ostream &os) const{
		do_display(os);
		return *this;
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display(std::ostream &os) const{
		os << contents;
	}
};

inline screen &screen::set(char c){
	contents[cursor] = c;
	return *this;
}

inline screen &screen::set(pos r, pos col, char ch){
	contents[r*width + col] = ch;
	return *this;
}

inline screen &screen::move(pos r, pos c){
	pos row = r * width;
	cursor = row + c;
	return *this;
}

char screen::get(pos r, pos c) const{
	pos row = r * width;
	return contents[row + c];
}
#endif