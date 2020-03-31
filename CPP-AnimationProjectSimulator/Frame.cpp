/******************************************************************
Filename:Frame.cpp
Version: 1.0
Author: Andressa Pessoa de Araujo Machado [040923007]
Assignment Number:1
Assignment Name:Animation Project in C++
Course Name: C++ Programming
Course Code:CST8219
Lab Section Number: 302
Professor's Name: Abdullah Kadri & Surbhi Bahri
Due Date: 2020/02/11
Submission Date:2020/02/11
List of source files: Animation.cpp, Frame.cpp
Purpose: Node of the list used by Animation.cpp.
******************************************************************/

using namespace std;

#include <iostream>

#include "Frame.h"

/***********************************************
Function name: Frame
Purpose: constructor of the class to
		 initialize its attributes

In parameters: none
Out Parameters: 0 for Success

Version: 1.0
Author: Andressa Machado
************************************************/
Frame::Frame() {
	// Frame's Name string. c works as a individual char of the String.
	string user_input;

	// Integer used to count the size of the next reallocation.
	int string_size = 0;
	cout << "Insert a Frame in the Animation\n";
	cout << "Please enter the Frame frameName: ";

	// Usage of cin as requested. cin does not read inputs with spaces.
	cin >> user_input;

	string_size = user_input.length() + 1;

	frameName = new char[string_size];
	strcpy_s(frameName, string_size, user_input.c_str());

	pNext = NULL;
}

/***********************************************
Function name: Frame
Purpose: deconstructor of the class to
		 cleanup allocated memory for its attributes

In parameters: none
Out Parameters: 0 for Success

Version: 1.0
Author: Andressa Machado

************************************************/
Frame::~Frame() {
	delete[] frameName;
	delete pNext;
}
