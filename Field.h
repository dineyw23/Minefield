#ifndef FIELD_H
#define FIELD_H

#include <vector>

/**
 * For keeping track of whether a location has a mine
 * or empty space as well as whether it is shown or hidden
**/
enum FieldType
{
	MINE_SHOWN,
	MINE_HIDDEN,
	EMPTY_SHOWN,
	EMPTY_HIDDEN
};

class Field
{
	public:
		Field();
		bool isSafe(int, int);
		FieldType get(int,int);
		void revealAdjacent(int, int);
		void placeMine(int, int);
		void set(int x,int y);

	private:
		bool inBounds(int,int);
		static const int FIELD_DIMENSION = 10;
		std::vector< std::vector<FieldType> > _map;	
};

#endif //FIELD_H
