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

Purpose: Management of a single Audio frame.
**********************************************************************************************/
using namespace std;

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


void AudioFrame::CalculateFrameResource() {
	double frame_size = 0.0;
	int bitrate_amount = 3;

	cout << "Audio Frame: " << *(Frame*)this;
	cout << *this;

	for (int i = 0; i < bitrate_amount; i++) {
		frame_size = size / COMPRESSION_RATIO[i];
		cout << "| " << setprecision(3) << frame_size << setw(3);
	}
	cout << "\n----------------------------------------------" << endl;
		
}

ostream& operator<<(ostream& output, AudioFrame& audio_frame) {
	int bitrate_value = 128;

	output << "\nMP3 Lossy Compression " << endl;
	output << "----------------------------------------------" << endl;
	output << "bitrate (kbits/s):      ";

	for (int i = 0; i < 3; i++) {
		output << "| " << bitrate_value << setw(4);
		bitrate_value += 32;
	}

	output << "\n----------------------------------------------" << endl;
	output << "file size (MB):         ";

	return output;
}