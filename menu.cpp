/*****************************************************************************************
 * Program Name: menu.cpp
 * Author: Corbin stripling
 * Date: 01/21/2018
 * Description: menu.cpp is the source file for the menu function used in project one. It
 * is designed to be modular by allowing you to change the string in the array to generate
 * new menu options.
*****************************************************************************************/

#include "menu.hpp"
#include "inputValidate.hpp" 
#include<iostream>
#include<string>

int runMenu(){
	std::string menuDesc[] = {"Start Langton's Ant simulation","Quit"};

	int menuSize = 2;
	
 
	std::cout<<"*****************************************************"<<std::endl;
	std::cout<<"|                     MAIN MENU                     |"<<std::endl;
	std::cout<<"*****************************************************"<<std::endl;
	      
	for(int i = 0;i < menuSize;++i){
		int x = i + 1;
		std::cout<<"  "<<x<<" - "<<menuDesc[i]<<std::endl;
	}

  	std::cout<<"*****************************************************"<<std::endl;

	int userSelect = validateInt( 1, menuSize); 
	return userSelect;

}

int orientationMenu(){
	std::string menuDesc[] = {"Up","Right","Down","Left"};

	int menuSize = 4;
	
 
	std::cout<<"*****************************************************"<<std::endl;
	std::cout<<"|       Choose the ant's starting orientation.      |"<<std::endl;
	std::cout<<"*****************************************************"<<std::endl;
	      
	for(int i = 0;i < menuSize;++i){
		int x = i + 1;
		std::cout<<"  "<<x<<" - "<<menuDesc[i]<<std::endl;
	}

  	std::cout<<"*****************************************************"<<std::endl;

	int userSelect = validateInt( 1, menuSize); 
	return userSelect;
}

int resetMenu(){
	std::string menuDesc[] = {"Yes","No"};

	int menuSize = 2;
	
 
	std::cout<<"*****************************************************"<<std::endl;
	std::cout<<"|           Would you like to play again?           |"<<std::endl;
	std::cout<<"*****************************************************"<<std::endl;
	      
	for(int i = 0;i < menuSize;++i){
		int x = i + 1;
		std::cout<<"  "<<x<<" - "<<menuDesc[i]<<std::endl;
	}

  	std::cout<<"*****************************************************"<<std::endl;

	int userSelect = validateInt( 1, menuSize); 
	return userSelect;
}
