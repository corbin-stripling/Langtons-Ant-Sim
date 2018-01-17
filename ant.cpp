/*******************************************************************
 * Program Name: ant.cpp
 * Author: Corbin Stripling
 * Date:1/21/2018
 * Description: Source File for Ant class of Langton's Ant sim.This
 * Class contains all of the functions needed to run the sim. With 
 * the exception of the menu and input validation files.  
*******************************************************************/

#include"ant.hpp"
#include<iostream>
Ant::Ant(){ //default constructor
	board = buildBoard(0,0);
	
}

Ant::Ant(int rowNum,int colNum){ //constructor with initializer
	board = buildBoard(rowNum,colNum);
}

Ant::~Ant(){ //destructor
	for(int row = 0; row < rowCount; row++){
	 	delete[] board[row];
	}
	delete [] board;
}

char ** Ant::buildBoard(int rowNum,int colNum){ //initializes a 2D array based on user selected sizes.
	rowCount = rowNum;
	colCount = colNum;

	char ** newBoard = new char *[rowCount];
	for(int row = 0;row < rowCount;row++){
		newBoard[row] = new char[colCount];
	}
	return newBoard; 
}

void Ant::setWhite(){ //sets the entire board to white or ' '
	 for(int i = 0; i < rowCount;i++){
		for(int j = 0;j < colCount;j++){
			board[i][j] = ' ';
		}
	}
}

void Ant::placeAnt(int antStartX,int antStartY){ //uses user input to place the ant at user desired starting location.
	locX = antStartX; 
	locY = antStartY;

	board[locY][locX] = '*';
}

void Ant::makeMove(int antStartX,int antStartY,int antOrientation,int stepCount){ //The actual function that doe the heavy lifting.
	locX = antStartX;
	locY = antStartY;
	orient = antOrientation;
	mvCounter = stepCount;
	board[locY][locX] = '#';

	switch(orient){			//program uses integers to orient 1 = north, 2 = east, etc. This switch takes that into account and adjust the move accordingly. 
		case 1: locY = locY - 1;
			break;
		case 2: locX = locX + 1;
			break;
		case 3: locY = locY + 1;
			break;
		case 4: locX = locX - 1;
			break;		 	   
	}
	
	checkEdge(); //accounts for edge cases see below 

	for(int i = 0;i < mvCounter;i++){  	
		if(board[locY][locX] == ' '){ //reads if space is white or black, turns the ant, and stores the opposite color for later use.   
			orient = orient + 1;
			temp = '#';
		}
		else if(board[locY][locX] == '#'){
			orient = orient - 1;
			temp = ' '; 
		}
		
		board[locY][locX] = '*';//moves ant to new location based on orientation rules.
		
		printBoard();//prints board see below

		board[locY][locX] = temp;//flips color of previous held space.

		if(orient == 5){	//if else function keeps oreintation between 1 and 4.
			orient = 1;
		}
		else if(orient == 0){
			orient = 4;
		}
  
		switch(orient){ //repeat of switch case in while loop.
			case 1: locY = locY - 1;
				break;
			case 2: locX = locX + 1;
				break;
			case 3: locY = locY + 1;
				break;
			case 4: locX = locX - 1;
				break;		 	   
		}
		checkEdge();	//prevents crashing for edge cases see below.
	}
}

void Ant::checkEdge(){ //this is how I handled the ant moving off the board. I made the board into a theoretical sphere. 
	if(locY == rowCount){//Think of a 2D view of earth. If the ant steps off the edge it has stepped to the other side of the board.
		locY = 0;
	}
	else if(locY < 0){
		locY = rowCount - 1;
	}
	else if(locX == colCount){
		locX = 0;
	}
	else if(locX < 0){
		locX = colCount - 1;
	}
}
void Ant::printBoard(){ //prints the board runs every move.
	for(int i = -2;i < colCount;i++){
		std::cout<<"-";
	}
	std::cout<<std::endl;
	
	for(int i = 0; i < rowCount;i++){
		std::cout<<"|";
		for(int j = 0;j < colCount;j++){
			std::cout<<board[i][j];
		}
		std::cout<<"|"<<std::endl;
 	}
	for(int i = -2;i < colCount;i++){
		std::cout<<"-";
	}
	std::cout<<std::endl;
}
