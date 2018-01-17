/****************************************************************************************
 * Program Name: inputValidate.cpp
 * Author: Corbin Stripling
 * Date:01/21/2018
 * Description: Source file for my input validation function. It is designed to be 
 * modular for future projects in this course.
****************************************************************************************/

#include "inputValidate.hpp"
#include<iostream>

int validateInt(int min, int max){ //designed to serve different int request on this project and future projects. 
	int minNum = min;
	int maxNum = max;
	int userChoice = 0;
	
	while(!(std::cin>>userChoice)||userChoice < minNum||userChoice > maxNum){
		std::cout<<"INPUT NOT VALID! RE-ENTER RESPONSE"<<std::endl;
		std::cin.clear();
		std::cin.ignore(50,'\n');
	}
	
	return userChoice;				
	 
} 
