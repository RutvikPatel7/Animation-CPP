/*****************************************************************************************
Filename : AnimationManager.cpp
Version : 1.0
Author : Rutvik Patel
Student's name : Rutvik Patel
Assignment Number : Assignment 2 - Animation in C++
Course name-number : C++ Programming - CST8219
Source file : Animation.h, AnimationManager.h, Frame.h, Animation.cpp, AnimationManager.cpp,ass2.cpp, Frame.cpp
Purpose : File contains constructors, destructors and required methods to create, delete and edit
	animation.
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
Function Name  : <EditAnimation>
Purpose		   : Prompts user to enter animation number and updates selected animation.
Function In Parameters : None
Function Out Parameters : None
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
void AnimationManager::EditAnimation() {
	cout << "Which Animation do you wish to edit? Please give the index (from 0 to "
		<<  (this->animations.size() - 1) << "): " << std::endl;
	int frameNumb = 0;
	cin >> frameNumb;
	if (frameNumb < 0 || frameNumb >= this->animations.size()) {
		cout << "Invalid user input..!" << endl;
		return;
	}
	cout << "Editing Animation #" << frameNumb << endl;

	bool RUNNING = true;
	while (RUNNING)
	{
		int userInput = 0;
		printf(" 1. Insert a frame\n");
		printf(" 2. Delete a frame\n");
		printf(" 3. Edit a frame\n");
		printf(" 4. Quit\n");
		cin >> userInput;
		switch (userInput)
		{
		case 1: cin >> this->animations.at(frameNumb); break;
		case 2: this->animations.at(frameNumb).DeleteFrame(); break;
		case 3: this->animations.at(frameNumb).EditFrame(); break;
		case 4: RUNNING = false; break;
		default: cout << "Invalid input..!\n"; break;
		}
	}
	cout << "Animation #" << frameNumb << " edit complete"<< endl;
}

/*****************************************************************************************
Function Name  : <EditAnimation>
Purpose		   : Prompts user to enter animation number and delete selected animation.
Function In Parameters : None
Function Out Parameters : None
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
void AnimationManager::DeleteAnimation() {
	if (this->animations.size() == 0) {
		printf("There is no animation to delete.\n");
	}
	else {
		printf("Delete an Animation from the Animation Manager\n");
		printf("Which Animation do you wish to delete? Please give the index in the range 0 to %d :"
			, this->animations.size() - 1);
		int userInput = 0;
		cin >> userInput;
		if (userInput < 0 || userInput >= this->animations.size()) {
			cout << "Invalid user input..!" << endl;
			return;
		}
		this->animations.erase(this->animations.begin() + userInput);
		printf("Animation #%d deleted\n", userInput);
	}

}

/*****************************************************************************************
Function Name  : <Overloaded operator >>  >
Purpose		   : Prompts user to enter animation name and inderts animation in the list.
Function In Parameters : None
Function Out Parameters : None
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
istream& operator>>(std::istream& inputStr, AnimationManager& am) {
	std::string animName = "";
	std::cout << "Add an animation to the Animation Manager\n";
	std::cout << "Please enter the Animation Name: ";
	inputStr >> animName;
	std::cout << "Animation " << animName << " added at the back of animations " << std::endl;
	Animation animation(animName);
	am.animations.push_back(animation);
	return inputStr;
}

/*****************************************************************************************
Function Name  : <Overloaded operator <<  >
Purpose		   : Prints details about animation.
Function In Parameters : None
Function Out Parameters : None
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
ostream& operator<<(std::ostream& outputStr, AnimationManager& am) {
	outputStr << "AnimationManager: " << am.managerName << std::endl;
	int index = 0;
	vector<Animation>::iterator i;
	for (i = am.animations.begin(); i != am.animations.end(); i++) {
		outputStr << "Animation: " << index << "\n"<< *i;
		index++;
	}
	return outputStr;
}
