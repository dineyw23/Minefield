#include "Field.h"
#include <iostream>
#include <vector>

/**
 * Constructor creates a 10x10 grid with no mines
**/
 Field::Field()
 {
 	_map.resize(FIELD_DIMENSION);
 	for(unsigned int i=0; i < _map.size(); i++)
 	{
 		_map[i].resize(FIELD_DIMENSION);
 		for(unsigned int j=0; j < _map[i].size(); j++)
 		{
 			_map[i][j] = EMPTY_HIDDEN;
 		}
 	}
 }

 bool Field::inBounds(int x, int y)
 {
 	if(x < 0 || x >= FIELD_DIMENSION || y < 0 || y >= FIELD_DIMENSION)
 	{
 		return false;
 	}
 	else
 		return true;
 }

 /**
  * Places a mine at the x,y coordinate in the field
 **/
 void Field::placeMine(int x, int y)
 {
 	if( inBounds(x,y) )
 		_map[x][y] = MINE_HIDDEN;
 }

/**
 * Retrieves the state of the field at location (x,y)
**/
FieldType Field::get(int x, int y)
{
	if( inBounds(x,y) )
 		return _map[x][y];
 	else
 		throw "Out of bounds";
}

/**
 * Returns whether or not _map at (x,y) has a mine and throws an
 * exception if the location is illegal
**/
 bool Field::isSafe(int x, int y)
 { 
   return inBounds(x,y) && (_map[x][y] != MINE_HIDDEN && _map[x][y] != MINE_SHOWN);
 }

/**
 * Changes the location from EMPTY_HIDDEN to EMPTY_SHOWN for the 
 * location and any valid locations adjacent (immediately above,
 * below, left, or right as printed) to the provided (x,y) location
**/
void Field::revealAdjacent(int x, int y)
{
	bool inside;
	inside = inBounds(x,y);
	if( !inside || _map[x][y] == MINE_HIDDEN || _map[x][y] == MINE_SHOWN )
	{
		return;
	}
	else if( _map[x][y] == EMPTY_HIDDEN )
	{
		_map[x][y] = EMPTY_SHOWN;
		revealAdjacent(x-1,y);
		revealAdjacent(x,y-1);
		revealAdjacent(x+1,y);
		revealAdjacent(x,y+1);
	}
}
/**
 *  Sets the valid location to MINE_SHOWN
**/
void Field::set(int x,int y)
{
  if(inBounds(x,y))
    _map[x][y] = MINE_SHOWN;
}
