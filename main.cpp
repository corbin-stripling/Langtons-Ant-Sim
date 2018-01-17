/******************************************************************************
 * Program Name: main.cpp
 * Author: Corbin Stripling
 * Date:01/21/2018
 * Description: Main function for project 1(Langton's Ant).
******************************************************************************/
#include"ant.hpp"
#include"menu.hpp"
#include"inputValidate.hpp"
#include<iostream>
#include<cstdlib>
#include<ctime>
 
int main(){
	int menuChoice,rowNum,colNum,stepCount,randChoice,antStartX,antStartY,antOrientation;
	int reset = 1;
	
	while(reset == 1){//runs entire program inside reset parameter.
		menuChoice = runMenu();//displays menu
	
		if (menuChoice == 1){//user input section if they want to play.
			std::cout<<"Very well! Let's begin the sim!\n"<<std::endl;
		
			std::cout<<"Please select the board width (min 5/max 250):"<<std::endl;//set to 250 max. Personally, I don't go over 80 because my screen isn't big enough. 
			colNum = validateInt(5,250);
 
			std::cout<<"Please select the board height (min5/max 250):"<<std::endl;
			rowNum = validateInt(5,250);

			std::cout<<"Please select the number of moves you wish to simulate(1 min/max 1000000:"<<std::endl;//That's right 1,000,000, and it takes forever.  
			stepCount = validateInt(1,1000000);
			std::cout<<"To satisfy EXTRA CREDIT requirements: Would you like to randomly place the ant?"<<std::endl;
			std::cout<<"1 = Yes\n0 = No"<<std::endl;
			randChoice = validateInt(0,1);
			if(randChoice == 0){ 
				std::cout<<"Please select the starting location of the ant\n X = ?"<<std::endl;//the board is not numbered with a 0 to not confuse the everyday user.
				antStartX = validateInt(1,colNum) - 1;

				std::cout<<"Please select the starting location of the ant\n Y = ?"<<std::endl;
				antStartY = validateInt(1,rowNum) - 1;
			}
			else if(randChoice == 1){
				srand(time(NULL));
				antStartX = rand() % colNum;
				antStartY = rand() % rowNum;		
				std::cout<<"Random Ant placement activated.\nX AXIS = "<<antStartX<<"\nY AXIS = "<<antStartY<<std::endl;
			} 
			antOrientation = orientationMenu();		//calls menu to set orientation

			Ant ant(rowNum,colNum);//builds ant
			ant.setWhite();//sets board up
			ant.placeAnt(antStartX,antStartY);//places ant
			ant.printBoard();//shows starting position and board
		
			ant.makeMove(antStartX,antStartY,antOrientation,stepCount); //runs move algorithm	
		}
		
		else {//ends program if user chooses no to play.
			std::cout<<"GOODBYE!"<<std::endl;
			break;
		}
		
		
		reset = resetMenu();  //offers replay

	}
	return 0;	
}
