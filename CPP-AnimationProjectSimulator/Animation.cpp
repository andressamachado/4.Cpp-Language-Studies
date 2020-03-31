/******************************************************************
Filename:Animation.cpp
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
Purpose: Animation class to handle the functions of creating a list of
frames, editing a frame, displaying all frames or deleting a frame.
******************************************************************/

using namespace std;

#include <iostream>

#include "Frame.h"
#include "Animation.h"


/***********************************************
Function name: Animation
Purpose: constructor of the class to
		 initialize the Linked List of frames

In parameters: none
Out Parameters: 0 for Success

Version: 1.0
Author: Andressa Machado
************************************************/
Animation::Animation() {
	// String to hold the users input
	string user_input;

	// Integer used to count the size of the next reallocation.
	int string_size = 0;

	cout << "Please enter the Animation name: ";

	// Usage of cin as requested. cin does not read inputs with spaces.
	cin >> user_input;

	// get the size of user input
	string_size = user_input.length() + 1;

	// references the object animationName
	animationName = new char[string_size];
	strcpy_s(animationName, string_size, user_input.c_str());

	frames = NULL;
}

/***********************************************
Function name: ~Animation
Purpose: desconstructor of the class to
		 cleanup the memory allocated for the Linked List

In parameters: none
Out Parameters: 0 for Success

Version: 1.0
Author: Andressa Machado
************************************************/
Animation::~Animation() {
	// 'delete' frees memory but also calls the desconstructor of the class
	// Frame::~Frames() will be called
	delete frames;
	delete animationName;
}

/***********************************************
Function name: InsertFrame
Purpose: Inserts node to beginning the Linked List

In parameters: none
Out Parameters: 0 for Success

Version: 1.0
Author: Andressa Machado
************************************************/
void Animation::InsertFrame() {
	// Ignoring extra inputs comming from the menu to prevent wrong frames in the animation
	cin.ignore();

	// Explicity test if frame equals null, create and return.
	if (frames == NULL) {
		frames = new Frame(); 
		return;
	}

	// Creates a frame using constructor of Frame
	Frame* frame_to_add;
	frame_to_add = new Frame();

	// Adding at the beggining by making the new frame next point to frames
	frame_to_add->GetpNext() = frames;

	// Sets Animation to point at address frame_to_add
	frames = frame_to_add;
}

/***********************************************
Function name: DeleteFrame
Purpose: Delete the last node in the Linked List

In parameters: none
Out Parameters: 0 for Success

Version: 1.0
Author: Andressa Machado
************************************************/
void Animation::DeleteFrame() {
	// Ignoring extra inputs comming from the menu to prevent wrong frames in the animation
	cin.ignore();

	// Getting the first Frame
	Frame* current_frame = frames;

	// Linked List just have the head. No frames.
	if (frames == NULL) {
		cout << "Your animation has no frame. Returning...\n";
		return;
	}

	// Linked List has just one frame
	if (current_frame->GetpNext() == NULL) {
		frames = NULL;
		delete current_frame;
		return;
	}

	// While not in the last but second to last, move one node forward
	while (current_frame->GetpNext()->GetpNext() != NULL) {
		current_frame = current_frame->GetpNext();
	}

	// deleting the last frame and freeing its memory
	delete current_frame->GetpNext();

	// set new last frame to be null
	current_frame->GetpNext() = NULL;
}

/***********************************************
Function name: EditFrame
Purpose: Updates one of the attributes - the frameName - of the struct.

In parameters: none
Out Parameters: 0 for Success

Version: 1.0
Author: Andressa Machado
************************************************/
void Animation::EditFrame() {
	// Ignoring extra inputs comming from the menu to prevent wrong frames in the animation
	cin.ignore();

	cout << "Edit a Frame in the Animation";

	// Holds the Linked List size
	int llsize = 0;

	// The Linked List just have the head. No frames.
	if (frames == NULL) {
		cout << "\nThere is no frame to be edit.\n";
		return;
	}

	// Temporary Frame object to hold the one it is being used
	Frame* temp_frame = frames;

	// While it is not the last node, increase the size and move one node forward.
	while (temp_frame != NULL) {
		llsize++;
		temp_frame = temp_frame->GetpNext();
	}

	// Holds the desired index chosen by the user
	int index_frame = 0;
	cout << "\nThere are " << llsize
		<< " Frame(s) in the list. Please specify the index (<=" << llsize - 1
		<< ") to edit at: ";


	// Usage of cin as requested. cin does not read inputs with spaces.
	// cin.fail checks if input was valid (an int)
	// cin.clear will reset the cin.fail
	// cin.ignore will ignore subsequent erroes (when more than 1 input char is wrong)
	cin >> index_frame;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid value. Please enter number within range\n";
		return;
	}

	// Warning if the index entered by the user is bigger than the list size
	if (index_frame >= llsize) {
		cout << "Not a valid index\n";
		return;
	}

	// reset values to be used again in the loop. Allowing to find the correct
	// node.
	temp_frame = frames;
	llsize = 0;

	// while not the last node, look for the one chosen by the user.
	while (temp_frame != NULL) {

		if (llsize == index_frame) {

			cout << "The name of this Frame is " << temp_frame->GetFrameName()
				<< ". What do you wish to replace it with?\n";

			// user string input variable
			std::string user_input;
			// char* to be set as the new framename
			char* new_frame_name;

			// Integer used to count the size of the next reallocation.
			int string_size = 0;


			// Usage of cin as requested. cin does not read inputs with spaces.
			cin >> user_input;

			string_size = user_input.length() + 1;

			// Allocs new frame name with input size
			new_frame_name = new char[string_size];
			strcpy_s(new_frame_name, string_size, user_input.c_str());

			char* old_name = temp_frame->GetFrameName();
			temp_frame->GetFrameName() = new_frame_name;

			// free the old name memory allocation
			delete[] old_name;

			return;
		}
		// increase the value if not the correct node
		llsize++;
		// move one node forward
		temp_frame = temp_frame->GetpNext();
	}
}

/***********************************************
Function name: ReportAnimation
Purpose: Prints the Linked List.

In parameters: none
Out Parameters: 0 for Success

Version: 1.0
Author: Andressa Machado
************************************************/
void Animation::ReportAnimation() {
	// Ignoring extra inputs comming from the menu to prevent wrong frames in the animation
	cin.ignore();

	cout << "Animation name is " << animationName;
	cout << "\nReport the Animation";

	Frame* current_frame = frames;
	int i = 0;

	// while not the last node, continue printing the frame's names
	while (current_frame != NULL) {
		cout << "\nFrame #" << i
			<< " file name = " << current_frame->GetFrameName();
		current_frame = current_frame->GetpNext();
		i++;
	}
	cout << "\n";
}
