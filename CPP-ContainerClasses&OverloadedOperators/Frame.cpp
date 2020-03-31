/******************************************************************
Filename:Frame.cpp
Version: 1.0
Author: Andressa Pessoa de Araujo Machado [040923007]
Assignment Number:2
Assignment Name:Animation in C++ using Container Classes and Overloaded
Operators
Course Name: C++ Programming
Course Code:CST8219
Lab Section Number: 302
Professor's Name: Abdullah Kadri & Surbhi Bahri
Due Date: 2020/03/14
Submission Date:2020/03/14
List of source files: AnimationManager.cpp, Animation.cpp and Frame.cpp

Purpose: Management of a single frame. It gives you the ability to create
a frame, to copy a frame, to assign one frame to another, and to output
that frame.
******************************************************************/
using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>

#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"

/***********************************************
Function name: Frame
Purpose: Frame constructor. Initializes a new Frame instance

In parameters: char*, double
Out Parameters: none

Version: 1.0
Author: Andressa Machado
************************************************/
Frame::Frame(char* frame_name, double frame_duration) {

	// Get the frame_name as a string so we can calculate its size
	std::string string_frame_name(frame_name);
	// calculate frame_name size. Allowing to allocate exact block of memory
	int string_size = string_frame_name.length() + 1;
	// Allocates memory for frameName
	this->frameName = new char[string_size];

	// Copies the argument into the Frame field frameName
	strcpy_s(this->frameName, string_size, frame_name);
	// Sets the Frame field duration
	this->duration = frame_duration;
}

/***********************************************
Function name: Frame
Purpose: Frame copy constructor. Initializes a new Frame instance
copying the Frame that was passed as a parameter.

In parameters: const Frame&
Out Parameters: none

Version: 1.0
Author: Andressa Machado
************************************************/
Frame::Frame(const Frame& original_frame) {
	
	// Get the frame_name as a string so we can calculate its size
	std::string string_frame_name(original_frame.frameName);
	// calculate frame_name size. Allowing to allocate exact block of memory
	int string_size = string_frame_name.length() + 1;
	// Allocates memory for frameName
	this->frameName = new char[string_size];

	// Assigns the copy frame fields to the same ones in the passed frame
	strcpy_s(this->frameName, string_size, original_frame.frameName);
	this->duration = original_frame.duration;
}

/***********************************************
Function name: ~Frame
Purpose: Free the dynamically allocated memory for the frameName field.

In parameters: none
Out Parameters: none

Version: 1.0
Author: Andressa Machado
************************************************/
Frame::~Frame() { delete[] this->frameName; }

/***********************************************
Function name: operator=
Purpose: Overloaded function to assign one frame to another.
It will copy the passed frame fields value to the desired frame
and return this frame.

In parameters: const Frame&
Out Parameters: Frame&

Version: 1.0
Author: Andressa Machado
************************************************/
Frame& Frame::operator=(const Frame& original_frame) {
	
	// Get the frame_name as a string so we can calculate its size
	std::string string_frame_name(original_frame.frameName);
	// calculate frame_name size. Allowing to allocate exact block of memory
	int string_size = string_frame_name.length() + 1;
	// Allocates memory for frameName
	this->frameName = new char[string_size];

	// Assigns the copy frame fields to the same ones in the passed frame
	strcpy_s(this->frameName, string_size, original_frame.frameName);

	return *this;
}

/***********************************************
Function name: operator<<
Purpose: Overloaded function to output the Frame instances fields

In parameters: std::ostream& output_message, Frame& frame
Out Parameters: std::ostream&

Version: 1.0
Author: Andressa Machado
************************************************/
std::ostream& operator<<(std::ostream& output_message, Frame& frame) {

	output_message << "frameName = " << frame.frameName << "; duration = " << frame.duration;

	return output_message;
}
