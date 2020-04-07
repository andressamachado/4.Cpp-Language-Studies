/**********************************************************************************************
Filename:				Frame.cpp
Version:				1.0
Author:					Andressa Pessoa de Araujo Machado [040923007]
Assignment Number:		3
Assignment Name:		Animation in C++ with inheritance
Course Name:			C++ Programming
Course Code:			CST8219
Lab Section Number:		302
Professor's Name:		Abdullah Kadri & Surbhi Bahri
Due Date:				2020/04/06
Submission Date:		2020/04/06
List of source files:	AnimationManager.cpp, Animation.cpp, Frame.cpp, AudioFrame.cpp and VideoFrame.cpp

Purpose: Abstract class that acts as a base class for the AudioFrame class and VideoFrame class.
**********************************************************************************************/
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>

#include "Frame.h"
#include "AudioFrame.h"
#include "VideoFrame.h"
#include "Animation.h"
#include "AnimationManager.h"

ostream& operator<< (ostream& output, Frame& frame) {
	output << "frameName = " << frame.frameName << std::flush;
	return output;
}

