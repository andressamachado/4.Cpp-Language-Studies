/******************************************************************
Filename:AnimationManager.cpp
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

Purpose: Management of the instances of Animation in the animations vector.
Adds an animation, outputs the animations in the vector, edits a specific
animation, Deletes a specific Animation in the vector.
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
Purpose: Overloaded function to add a Animation instance
to the AnimationManager vector.

In parameters: istream&, AnimationManager&
Out Parameters: istream&

Version: 1.0
Author: Andressa Machado
************************************************/
istream& operator>>(istream& user_input, AnimationManager& animation_manager) {

	// As we receive the istream object cin, we use it to read the user input
	// directly to the string
	string animation_name;

	// Loops until the user enter a valid string to the animation name
	do {
		std::cout << "Add an Animation to the Animation Manager\nPlease enter the Animation Name: " << std::flush;
		user_input >> animation_name;

		// If the user entered an empty string, starts the loop again
		if (animation_name.empty()) {
			std::cout << "Enter a valid name: " << std::endl;
		}
	} while (animation_name.empty());

	// Creating an Animation object
	Animation new_animation(animation_name);

	// Inserts the new Animation in the list
	animation_manager.animations.push_back(new_animation);

	std::cout << "Animation " << animation_name << " added at the back of the animations" << std::endl;

	return user_input;
}

/***********************************************
Function name: operator<<
Purpose: Overloaded function to output the Animation instances
in the AnimationManager vector.

In parameters: ostream&, AnimationManager&
Out Parameters: ostream&

Version: 1.0
Author: Andressa Machado
************************************************/
ostream& operator<<(ostream& print_output, AnimationManager& animation_manager) {

	if (animation_manager.animations.empty()) {
		print_output << "The Animation List is empty. No Animation to be shown." << std::endl;
		return print_output;
	}

	print_output << "Animation Manager: " << animation_manager.managerName << std::endl;

	// Counter to be used to display the animation number
	int animation_number = 0;

	// Loops to print the list of animation and their frames
	for (auto current_animation : animation_manager.animations) {
		print_output << "Animation: " << animation_number++ << std::endl;
		print_output << current_animation << std::endl;
	}

	return print_output;
}

/***********************************************
Function name: EditAnimation
Purpose: Gives the ability to select a specific Animation instance
and insert a frame, edit a frame or output a frame.

In parameters: none
Out Parameters: void

Version: 1.0
Author: Andressa Machado
************************************************/
void AnimationManager::EditAnimation() {

	if (animations.empty()) {
		std::cout << "The Animation List is empty. No Animation to be edited." << std::endl;
		return;
	}

	int animation_list_size = animations.size() - 1;
	// Holds the user input for the index as a char for validation purpose
	char user_input[20];
	// holds the actual index as an int
	int index = -1;

	// Loops until the user enter a valid animation index
	do {
		std::cout << "Which Animation do you wish to edit? Please give the index (from 0 to" << animation_list_size << "): " << std::flush;
		std::cin >> user_input;

		// Checks if the user entered a digit
		if (!isdigit(user_input[0])) {
			std::cout << "Please, enter a valid value for the range" << std::endl;
		}
		else {
			// If it is a digit, save it as a integer
			index = atoi(user_input);
			// Checks if the number is within the range
			if (index < 0 || index > animation_list_size) {
				std::cout << "Please enter a number within the said range" << std::endl;
			}
		}
	} while (index < 0 || index > animation_list_size);

	std::cout << "Editing Animation #" << index << std::endl;

	bool RUNNING = true;
	char user_option;

	// Menu for the Frame options
	while (RUNNING) {
		std::cout << "MENU\n 1. Insert a Frame\n 2. Delete a Frame\n 3. Edit a Frame\n 4. Quit" << std::endl;
		std::cin >> user_option;

		switch (user_option) {

		case '1':
			// As the range of the animation list was already checked, it is not
			// necessary to use the vector function at()
			cin >> animations[index];
			break;
		case '2':
			animations[index].DeleteFrame();
			break;
		case '3':
			animations[index].EditFrame();
			break;
		case '4':
			RUNNING = false;
			break;
		default:
			std::cout << "Please, Enter a valid option" << std::endl;
		}
	}

	std::cout << "Animation #" << index << " edit complete" << std::endl;
}

/***********************************************
Function name: DeleteAnimation
Purpose: Gives the ability to select a specific Animation instance
and delete it.

In parameters: none
Out Parameters: void

Version: 1.0
Author: Andressa Machado
************************************************/
void AnimationManager::DeleteAnimation() {

	if (animations.empty()) {
		std::cout << "The Animation List is empty. No Animation to be deleted." << std::endl;
		return;
	}

	std::cout << "Delete an Animation from the Animation Manager" << std::endl;

	int animation_list_size = animations.size() - 1;
	// Holds the user input for the index as a char for validation purpose
	char user_input[20];
	int index = -1;

	// Loops until the user enters a valid data
	do {
		std::cout << "Which Animation do you wish to delete? Please give the index in the range 0 to " << animation_list_size << ": " << std::flush;
		std::cin >> user_input;

		// Checks if the user entered a digit
		if (!isdigit(user_input[0])) {
			std::cout << "Please, enter a valid value for the range" << std::endl;
		}
		else {
			// If the user entered a digit, save it as an integer
			index = atoi(user_input);

			// Checks for the index range
			if (index < 0 || index > animation_list_size) {
				std::cout << "Please enter a number within the said range" << std::endl;
			}
		}
	} while (index < 0 || index > animation_list_size);

	// Iterator to holds the the animation to be deleted
	vector<Animation>::iterator animation_to_be_deleted = animations.begin() + index;

	// Deletes the desired animation list element
	animations.erase(animation_to_be_deleted);

	std::cout << "Animation #" << index << " deleted" << std::endl;
}
