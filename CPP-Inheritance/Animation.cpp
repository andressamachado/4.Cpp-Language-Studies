/**********************************************************************************************
Filename:				Animation.cpp
Version:				1.0
Author:					Andressa Pessoa de Araujo Machado [040923007]
Assignment Number:		3
Assignment Name:		Animation in C++ with Inheritance
Course Name:			C++ Programming Course
Code:					CST8219
Lab Section Number:		302
Professor's Name:		Abdullah Kadri & Surbhi Bahri
Due Date:				2020/04/06
Submission Date:		2020/04/06
List of source files:	AnimationManager.cpp, Animation.cpp, Frame.cpp, AudioFrame.cpp and VideoFrame.cpp

Purpose: Management of Frames in the Animation foward_list. Adds a frame,
outputs the members of the list, edits a specific frame, and deletes the
frame in the front.
**********************************************************************************************/
using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <forward_list>

#include "Frame.h"
#include "VideoFrame.h"
#include "AudioFrame.h"
#include "Animation.h"

/**********************************************************************************************
Function name:	operator>>
Purpose:		Overloaded function to add a Frame instance to the Animation
foward_list

In parameters:	istream&, Animation&
Out Parameters: istream&

Version:		1.0
Author:			Andressa Machado
**********************************************************************************************/
istream& operator>>(istream& user_input, Animation& animation) {
	// holds the user input for the frame name
	char frame_name[16] = "";

	std::cout << "Insert a Frame in the Animation \nPlease enter the Frame frameName: " << std::flush;
	user_input >> frame_name;

	// Get the frame_name as a string so we can calculate its size
	std::string string_frame_name(frame_name);

	// Checks if the user actually entered a name and continues loop until he
	// enter a valid name.
	if (string_frame_name.empty()) {

		std::cout << "Please, enter a valid name" << std::endl;

		do {
			std::cout << "Insert a Frame in the Animation \nPlease enter the Frame frameName: " << std::flush;
			user_input >> frame_name;

			// Get the frame_name as a string so we can calculate its size
			std::string string_frame_name(frame_name);

		} while (string_frame_name.empty());
	}

	// calculate frame_name size. Allowing to allocate exact block of memory
	int string_size = string_frame_name.length() + 1;

	// Allocates exact block of memory for frameName
	char* resized_frame_name = new char[string_size];

	// Copies the string to the resized variable that holds the frame name
	strcpy_s(resized_frame_name, string_size, frame_name);

	// Holds the user input for the duration of a frame. Reading as a char so we
	// can check if the user entered a number
	char char_size[8];
	// Holds the actual duration to be stored
	int frame_size = 0;

	// Validating the data entered by the user. Loops until it get a valid input
	do {
		std::cout << "Please enter the Frame size(MB): " << std::flush;
		user_input >> char_size;

		// Checking if the user entered a number
		if (!isdigit(char_size[0])) {
			std::cout << "Please, Enter a valid size(MB) " << std::endl;
		}
		else {

			// Saving the duration as an integer
			frame_size = atoi(char_size);

			// If duration is negative, asks the user to enter a valid value
			if (frame_size <= 0) {
				std::cout << "Please, Enter a valid size(MB) " << std::endl;
			}
		}
	} while (frame_size <= 0);

	//Reading as string to be able to validade user input
	std::string frame_type = " ";
	int invalid = 0;

	// Validating the data entered by the user. Loops until it get a valid input
	do {
		std::cout << "Please enter the Frame type (AudioFrame = A, VideoFrame = V): " << std::flush;
		user_input >> frame_type;
		invalid = 0;

		// Checking if the user entered a valid type
		if (frame_type.size() > 1) {
			std::cout << "Please, Enter a valid type " << std::endl;
			invalid = 1;
		}
		
		if (isdigit(frame_type[0])) {
			std::cout << "Please, Enter a valid type " << std::endl;
			invalid = 1;
		}

		if ((frame_type.compare("a") != 0 && frame_type.compare("A") != 0) && (frame_type.compare("v") != 0 && frame_type.compare("V") != 0)) {
			std::cout << "Please, Enter a valid type " << std::endl;
			invalid = 1;
		}
	} while (invalid || frame_type.empty());

	//Creating the frame to be added in the list
	if (frame_type == "V" || frame_type == "v") {
		VideoFrame* tempFrame = new VideoFrame(frame_name, frame_size);
		animation.frames.push_front(tempFrame);
	}
	else {
		AudioFrame* tempFrame = new AudioFrame(frame_name, frame_size);
		animation.frames.push_front(tempFrame);
	}


	std::cout << "Frame " << resized_frame_name << " Frame* added at the front of frames" << std::endl;

	return user_input;
}

/**********************************************************************************************
Function name:	operator<<
Purpose:		Overloaded function to output the frames in the Animation foward_list

In parameters:	ostream&, Animation&
Out Parameters: ostream&

Version:		1.0
Author:			Andressa Machado
**********************************************************************************************/
ostream& operator<<(ostream& print_output, Animation& animation) {

	print_output << "\tAnimation name is " << animation.animationName << endl;
	print_output << "\tReport the Animation";

	if (animation.frames.empty()) {
		std::cout << "\n\tNo frames in the Animation" << std::endl;
		return print_output;
	}

	// Counter to control the number of the frame
	int frame_position = 0;
	forward_list<Frame*>::iterator current_frame;

	// loop to display the frames in the animation list
	for (current_frame = animation.frames.begin(); current_frame != animation.frames.end(); ++current_frame) {
		print_output << "\nFrame #" << frame_position << std::endl;
		(*current_frame)->CalculateFrameResource();
		frame_position++;
	}

	return print_output;
}

/**********************************************************************************************
Function name:			 ~Animation
Purpose:				 Animation Destructor
Function In parameters:  none
Function Out parameters: none
Version:				 1.0
Author:					 Andressa Machado
***********************************************************************************************/
Animation::~Animation(){
}

/***********************************************************************************************
Function name:	EditFrame
Purpose:		Function to update a Frame instance in the Animation foward_list.
				It asks the user for a new Frame name and a new duration, instantiate a new
				Frame and put it on the place where the old frame was.

In parameters:	none
Out Parameters: void

Version:		1.0
Author:			Andressa Machado
***********************************************************************************************/
void Animation::EditFrame() {

	std::cout << "Edit a frame in the Animation" << std::endl;

	if (frames.empty()) {
		std::cout << "These are no Frames in the Animation" << std::endl;
		return;
	}

	// Size of animation list
	int frame_list_size = 0;
	// holds the user input for the desired index as a char so we can validate
	// data
	char char_location[8];
	// holds the actual location as an integer
	int location = -1;

	// Counts the size of the animation list
	for (auto current_frame : frames) {
		frame_list_size++;
	}

	// Loops until the user enter a valid data
	do {
		std::cout << "There are " << frame_list_size << " Frame(s) in the list. Please specify the index (<=0) to edit at : " << std::flush;
		std::cin >> char_location;

		// Checks if the user enterd a digit
		if (!isdigit(char_location[0])) {
			std::cout << "Please enter a valid number for the Frame index " << std::endl;
		}
		else {
			// If the user entered a digit, save it as an integer
			location = atoi(char_location);

			// Checks if the value is within range
			if (location < 0 || location > frame_list_size - 1) {
				std::cout << "Please enter a number within the said range " << std::endl;
			}
		}
	} while (location < 0 || location > frame_list_size - 1);

	// resets the size of the animation list
	frame_list_size = 0;
	Frame* old_frame; 
	forward_list<Frame*>::iterator current_frame;

	// Loops until find the desired frame to be edited
	for ( current_frame = frames.begin(); current_frame != frames.end(); ++current_frame) {
		// If frame is found, perform the edition
		if (frame_list_size == location) {

			old_frame = *current_frame; 

			std::cout << "The name of this Frame is " << *(Frame*)old_frame << ". What do you wish to replace them with?" << std::endl;
			cout << "Please enter the Frame frameName: ";
			char new_frame_name[64];
			cin >> new_frame_name;
			cout << "Please enter the Frame size(MB): ";
			double new_size;
			cin >> new_size;

			cout << "Please enter the Frame type (AudioFrame = A, VideoFrame = V): ";
			char frame_type;
			cin >> frame_type;

			delete old_frame;

			// Creates a new instance of Frame and assign to the place the old one was sitting
			if (frame_type == 'v' || frame_type == 'V') {
				VideoFrame* tempFrame = new VideoFrame(new_frame_name, new_size);
				*current_frame = tempFrame;
			}
			else {
				AudioFrame* tempFrame = new AudioFrame(new_frame_name, new_size);
				*current_frame = tempFrame;
			}

			std::cout << "Frame #" << location << " edit complete" << endl;
		}

		// If not found, increase the counter and starts the loop again
		++frame_list_size;
	}
}

/***********************************************************************************************
Function name:	DeleteFrame
Purpose:		Function to delete the first frame in the Animation foward_list

In parameters:	none
Out Parameters: void

Version:		1.0
Author:			Andressa Machado
***********************************************************************************************/
void Animation::DeleteFrame() {

	if (frames.empty()) {
		std::cout << "This are no Frames in the Animation`s list to be deleted" << std::endl;
		return;
	}

	Frame* frame_to_be_deleted = frames.front();
	// delete the frame at the front of the list
	frames.pop_front();
	delete[] frame_to_be_deleted;


	std::cout << "First Frame deleted" << std::endl;
}