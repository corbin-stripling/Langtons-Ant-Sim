/***************************************************************************
 * Program Name: ant.hpp
 * Author: Corbin Stripling
 * Date: 01/21/2018
 * Description: Header file for the Ant class used in Langton's Ant sim.
****************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

class Ant{ 
	private:
		int rowCount;
		int colCount;
		int mvCounter;
		int locX;
		int locY;
		int orient;
		char temp;
		char **	newBoard;	
	public:
		char **board;
		Ant();
		Ant(int rowNum,int colNum);
		~Ant();
		char **buildBoard(int rowNum,int colNum);
		void setWhite();
		void placeAnt(int antStartX,int antStartY);
		void makeMove(int antStartX,int antStartY,int antOrientation,int stepCount); 
		void checkEdge();
		void printBoard();
};

#endif
