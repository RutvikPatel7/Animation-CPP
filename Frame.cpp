/*****************************************************************************************
Filename : Frame.cpp
Version : 1.0
Author : Rutvik Patel
Assignment Number : Assignment 2 - Animation in C++
Course name-number : C++ Programming - CST8219
Source file : Animation.h, AnimationManager.h, Frame.h, Animation.cpp, AnimationManager.cpp,ass2.cpp, Frame.cpp
Purpose : File contains constructors, destructors and operator overloadinng methods to create, delete and display
	Frame data.
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

/*****************************************************************************************
Function Name  : <Parameterized Constructor of Frame class>
Purpose		   : Assigns value to name and duration
Function In Parameters : char * name and double duration
Function Out Parameters : None
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
Frame::Frame(char* name, double dur) {
	frameName = name;
	duration = dur;
}

/*****************************************************************************************
Function Name  : <Copy Constructor of Frame class>
Purpose		   : Assigns value to name and duration
Function In Parameters : const Frame object
Function Out Parameters : None
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
Frame::Frame(const Frame& frame) {
	frameName = frame.frameName;
	duration = frame.duration;
}

/*****************************************************************************************
Function Name  : <Copy Constructor of Frame class>
Purpose		   : Assigns value to name and duration
Function In Parameters : None
Function Out Parameters : None
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
Frame::~Frame() {
	//Statement to prevent memory leak
	//But it's causing unwanted behaviour 
//	delete this->frameName;
}

/*****************************************************************************************
Function Name  : <Operator overloading = >
Purpose		   : Assigns value to name and duration
Function In Parameters : const Frame object
Function Out Parameters : Frame object
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
Frame& Frame::operator=(const Frame& frame) {
	frameName = frame.frameName;
	duration = frame.duration;
	return *this;
}

/*****************************************************************************************
Function Name  : <Operator overloading << >
Purpose		   : Prints framename and duration
Function In Parameters : ostream object and Frame object
Function Out Parameters : returns ostream object
Version :		 1.0
Author :		 Rutvik Patel
*****************************************************************************************/
std::ostream& operator<< (std::ostream& output, Frame& frame) {
	output << "frameName = " << frame.frameName<< "; duration = " << frame.duration;
	return output;
}