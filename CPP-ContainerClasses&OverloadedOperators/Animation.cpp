/******************************************************************
Filename:Animation.cpp
Version: 1.0
Author: Andressa Pessoa de Araujo Machado [040923007]
Assignment Number:2
Assignment Name:Animation in C++ using Container Classes and Overloaded
Operators
Course Name: C++ Programming Course
Code:CST8219
Lab Section Number: 302
Professor's Name: Abdullah Kadri & Surbhi Bahri
Due Date: 2020/03/14
Submission Date:2020/03/14
List of source files: AnimationManager.cpp, Animation.cpp and Frame.cpp

Purpose: Management of Frames in the Animation foward_list. Adds a frame,
outputs the members of the list, edits a specific frame, and deletes the
frame in the front.
******************************************************************/
using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <forward_list>

#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"

/***********************************************
Function name: operator>>
Purpose: Overloaded function to add a Frame instance to the Animation
foward_list

In parameters: istream&, Animation&
Out Parameters: istream&

Version: 1.0
Author: Andressa Machado
************************************************/
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
	char char_duration[8];
	// Holds the actual duration to be stored
	int frame_duration = 0;

	// Validating the data entered by the user. Loops until it get a valid input
	do {
		std::cout << "Please enter the Frame duration: " << std::flush;
		user_input >> char_duration;

		// Checking if the user entered a number
		if (!isdigit(char_duration[0])) {
			std::cout << "Please, Enter a valid duration " << std::endl;
		}
		else {

			// Saving the duration as an integer
			frame_duration = atoi(char_duration);

			// If duration is negative, asks the user to enter a valid value
			if (frame_duration <= 0) {
				std::cout << "Please, Enter a valid duration " << std::endl;
			}
		}
	} while (frame_duration <= 0);

	// Copies the argument into the Frame field frameName
	Frame f = Frame(resized_frame_name, frame_duration);

	// Adds the frame at the front of the animation foward_list
	animation.frames.emplace_front(f);

	std::cout << "Frame " << resized_frame_name << " added at the front of frames" << std::endl;

	return user_input;
}

/***********************************************
Function name: operator<<
Purpose: Overloaded function to output the frames in the Animation foward_list

In parameters: ostream&, Animation&
Out Parameters: ostream&

Version: 1.0
Author: Andressa Machado
************************************************/
ostream& operator<<(ostream& print_output, Animation& animation) {

	print_output << "\tAnimation name is " << animation.animationName << endl;
	print_output << "\tReport the Animation";

	if (animation.frames.empty()) {
		std::cout << "\n\tNo frames in the Animation" << std::endl;
		return print_output;
	}

	// Counter to control the number of the frame
	int frame_position = 0;

	// loop to display the frames in the animation list
	for (auto current_frame = animation.frames.begin();
		current_frame != animation.frames.end(); ++current_frame) {
		print_output << "\n\tFrame " << frame_position << ": " << *current_frame;
		frame_position++;
	}

	return print_output;
}

/***********************************************
Function name: EditFrame
Purpose: Function to update a Frame instance in the Animation foward_list.
It asks the user for a new Frame name and a new duration, instantiate a new
Frame and put it on the place where the old frame was.

In parameters: none
Out Parameters: void

Version: 1.0
Author: Andressa Machado
************************************************/
void Animation::EditFrame() {

	std::cout << "Edit a frame in the Animation" << std::endl;

	if (frames.empty()) {
		std::cout << "This are no Frames in the Animation" << std::endl;
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

	// Loops until find the desired frame to be edited
	for (auto current_frame = frames.begin(); current_frame != frames.end(); ++current_frame) {

		// If frame is found, perform the edition
		if (frame_list_size == location) {
			std::cout << "The name and duration of this Frame are " << *current_frame << ". What do you wish to replace them with?" << std::endl;
			char new_frame_name[64];
			cin >> new_frame_name;
			double new_duration;
			cin >> new_duration;

			// Creates a new instance of Frame and assign to the place the old one was
			// sitting
			*current_frame = Frame(new_frame_name, new_duration);

			std::cout << "Frame #" << location << " edit complete" << endl;
		}

		// If not found, increase the counter and starts the loop again
		++frame_list_size;
	}
}

/***********************************************
Function name: DeleteFrame
Purpose: Function to delete the first frame in the Animation foward_list

In parameters: none
Out Parameters: void

Version: 1.0
Author: Andressa Machado
************************************************/
void Animation::DeleteFrame() {

	if (frames.empty()) {
		std::cout << "This are no Frames in the Animation`s list to be deleted" << std::endl;
		return;
	}

	// delete the frame at the front of the list
	frames.pop_front();

	std::cout << "First Frame deleted" << std::endl;

}
