/**********************************************************************************************
Filename:				VideoFrame.cpp
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

Purpose: Management of a single Video frame.
**********************************************************************************************/
using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include <iomanip>

#include "Frame.h"
#include "AudioFrame.h"
#include "VideoFrame.h"
#include "Animation.h"
#include "AnimationManager.h"

void VideoFrame::CalculateFrameResource() {
	double calcSize = 0.0;
	cout << "Video Frame: " << *(Frame*)this;
	cout << *this;
	for (int i = 0; i < BITS; i++) {
		calcSize = size / (COMPRESSION_RATIO * BITDEPTH_FACTOR[i]);
		cout << "| " << setprecision(4) << calcSize << setw(4);
	}
	cout << "\n--------------------------------------------------------------------------------------------" << endl;
}


ostream& operator<<(ostream& output, VideoFrame& video_frame) {
	int num = 2;

	output << "\nLempel-Ziv-Welch Lossless Compression " << endl;
	output << "--------------------------------------------------------------------------------------------" << endl;
	output << "colours:        ";
	for (int i = 0; i < 8; i++) {
		output << "| " << num;
		if (num < 10)
			output << setw(8);
		else if (num < 100)
			output << setw(7);
		else
			output << setw(6);
		num *= 2;
	}
	output << "\n--------------------------------------------------------------------------------------------" << endl;
	output << "file size (MB): ";

	return output;
}
