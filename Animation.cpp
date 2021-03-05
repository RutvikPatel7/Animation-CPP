/*****************************************************************************************
Filename : Animation.cpp
Version : 1.0
Author : Rutvik Patel
Assignment Number : Assignment 2 - Animation in C++
Course name-number : C++ Programming - CST8219
Professor's Name : Surbhi Bahri
Source file : Animation.h, AnimationManager.h, Frame.h, Animation.cpp, AnimationManager.cpp,ass2.cpp, Frame.cpp
Purpose : File contains constructors, destructors and required methods to create, delete and edit
	Frame.
*****************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <forward_list>
#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"
using namespace std;

/*****************************************************************************************
Function Name  : <EditFrame>
Purpose		   : Prompts user to enter frame number and updates selected frame.
Function In Parameters : None
Function Out Parameters : None
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
void Animation::EditFrame() {
	printf("Edit a frame in the Animation\n");
	if (this->frames.empty()) {
		printf("There is no frame to edit.\n");
	}
	else {
		int length = 0;
		for (auto frame = this->frames.begin(); frame != this->frames.end(); ++frame) {
			length++;
		}
		printf("There are %d Frame(s) in the list. Please specify the index (<=%d) to edit at :", length, length - 1);
		int userInput = 0;
		cin >> userInput;
		if (userInput < 0 || userInput >= length) {
			cout << "Invalid user input..!" << endl;
			return;
		}

		forward_list<Frame>::iterator it = this->frames.begin();
		it = next(it, userInput);
		char* name = (char*)malloc(100 * sizeof(char));
		if (name == NULL) return;
		double duration;
		cout << "The name and duration of this Frame are " << *it << ". What do you wish to replace them with?" << endl;
		cin >> name >> duration;
		it = next(this->frames.begin(), userInput - 1);
		this->frames.erase_after(it);
		Frame frame(name, duration);
		name = strcat(name, "\0");
		this->frames.insert_after(it, frame);
	}
}

/*****************************************************************************************
Function Name  : <DeleteFrame>
Purpose		   : Prompts user to enter frame number and delete selected frame.
Function In Parameters : None
Function Out Parameters : None
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
void Animation::DeleteFrame() {
	
	if (this->frames.empty()) {
		printf("There is no frame to delete.\n");
	}
	else {
		printf("Delete a Frame in the Animation\n");
		int length = 0;
		for (auto frame = this->frames.begin(); frame != this->frames.end(); ++frame) {
			length++;
		}
		printf("Which Animation do you wish to delete? Please give the index in the range 0 to %d :"
			, length - 1);
		int userInput = 0;
		cin >> userInput;
		if (userInput < 0 || userInput >= length) {
			cout << "Invalid user input..!" << endl;
			return;
		}
		if (userInput == 0) this->frames.pop_front();
		else {
			int index = 1;
			for (auto frame = this->frames.begin(); frame != this->frames.end(); ++frame) {
				if (index == userInput) {
					this->frames.erase_after(frame); break;
				}
				index++;
			}
		}
		printf("Frame #%d deleted\n", userInput);
	}
}

/*****************************************************************************************
Function Name  : <Overloaded operator >>  >
Purpose		   : Prompts user to enter frame name and duration and inserts frame in the animation.
Function In Parameters : istream object and Animation object.
Function Out Parameters : istream object
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
istream& operator>>(std::istream& input, Animation& animation) {
	char* name = (char*)malloc(100 * sizeof(char));
	if (name == NULL) return input;
	double duration;
	cout << "Insert a frame in the Animation" << endl;
	cout << "Please enter the Frame frameName :";
	input >> name;
	cout << "Please enter the Frame duration :";
	input >> duration;
	//Frame frame(name, duration);
	name = strcat(name, "\0");
	animation.frames.emplace_front(Frame(name, duration));
	return input;
}

/*****************************************************************************************
Function Name  : <Overloaded operator <<  >
Purpose		   : Prints Frame detail for the current animation.
Function In Parameters : ostream object and Animation object.
Function Out Parameters : ostream object
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
ostream& operator<<(std::ostream& output, Animation& animation) {
	output << "\tAnimation name is " << animation.animationName << "\n"
		<< "\tReport the Animation\n";
	if (animation.frames.empty()) {
		output << "\tNo frames in the Animation.\n";
	}
	else {
		int index = 0;
		for (auto frame = animation.frames.begin(); frame != animation.frames.end(); ++frame) {
			output << "\tFrame " << index << ": " << *frame << "\n";
			index++;
		}
	}
	return output;
}
