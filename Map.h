/**
*	@file Map.h
*	@class Map
*	@author Craig van Heerden U15029779, Dedre Olwage U15015239
*
*	@brief //complete
*
*	@section Description
* 	//complete
*
*/

#ifndef MAP_H
#define MAP_H
#include "subject.h"



class Map : public Subject
{
private:

//complete
    char** MapContents;
    char* FileLocation;
    void SetMap();
    int mapSizeX;
    int mapSizeY;


//Observer and Mediator

		/**
		*	@brief The integers holding the x- and y-coordinates of where the trap can be located at.
		*/
	int trapX, trapY;


public: //complete
	Map ();
    ~Map();

		/**
		*	This constructor sets the attribute "File Location"'s value.
		*	@param A char which the attribute "File location" should be set to.
		*/
    Map(char*);

		/**
		*	This function prints the contents of the 2D dynamic array onto the screen.
		*	@return Nothing, the function is void.
		*/
    void printMap();

		/**
		*	This function determines whether a player/mob can move or not.
		*	@param Four integers, initial x- and y-coordinate, and the x- and y-coordinate the player/mob wants to move to.
		*	@return A bool indication whether the player/mob can move or not.
		*/
    bool Move(int,int,int,int);

		/**
		*	This function that sets the contents of given text file into the 2D dynamic array.
		*	@return Nothing, the function is void.
		*/
    void setMap();

		/**
		*	This function returns the lenght of the map (total rows of the 2D dynamic array).
		*	@return Nothing, the function is void.
		*/
	int getXLength();

		/**
		*	This function returns the width of the map (total columns of the 2D dynamic array).
		*	@return Nothing, the function is void.
		*/
	int getYLength();

		/**
		*	This function  sets a specific cell in the map
		*	@param Four integers, initial x- and y-coordinate, and the x- and y-coordinate the player/mob wants to move to, and a char to indicate what that cell should be set to.
		*	@return Nothing, the function is void.
		*/

	void setCell(int x, int y,int x2, int y2, char c);

		/**
		*	This function  returns a certian cell's contents.
		*	@param Two integers, the x- and y-coordinate of the cell which the contents of has to be returned.
		*	@return A char conteaining the contents of a specific cell.
		*/
	char getCell(int,int);

		/**
		*	This function creates calls another function in it to determine whether if there is a character above,below,left or right from the player/mob.
		*	@param Two integers, initial x- and y-coordinate used to calculate cells around it.
		*	@return A character indicating if there is something 'a'bove, 'b'elow, 'l'eft or 'r'ight from the player/mob.
		*/
	char testCell(int,int);

		/**
		* 	This function informs  the Subject  about a change it underwent, so the Subject can react accordingly.
		*	@return Nothing is returned (function is void).
		*/
	void notify(Subject *map);//O

    /**
    * 	This function 'clears' the cell at the coordinates by making it a space.
    * @param Two integers, the x and y coordinates of the cell to be cleared.
    *	@return Nothing is returned (function is void).
    */
  void clear(int, int);//O




};
#endif
