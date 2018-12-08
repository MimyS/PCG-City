#pragma once

#include"ViewClass.hpp"
#include"Utils.hpp"

using namespace std;

class ControlClass {
	bool ProgramStart = false;
public:
	void keyboard(unsigned char, int, int, ViewClass &);
	void keyboard_special(int, int, int, ViewClass &);
	ControlClass();
	~ControlClass();
};
