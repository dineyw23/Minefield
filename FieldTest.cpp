/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

TEST(FieldTest, isSafeEmpty)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_TRUE( minefield.isSafe(1,1) );
}

TEST(FieldTest, isSafeBoom)
{
	Field minefield;
  //Just for branch probablities
  minefield.placeMine(-2,5);	
	minefield.placeMine(4,5);
	ASSERT_FALSE( minefield.isSafe(4,5) );
}

TEST(FieldTest, isSafeOutOfBounds)
{
	Field minefield;
  //Just for branch probablities
  minefield.placeMine(-2,5);	
	bool safe;
	safe = minefield.isSafe(-1,11);
	ASSERT_FALSE(safe);
}

TEST(FieldTest, revealAdjacentEmptyAllShown)
{
	Field minefield;
	
	minefield.revealAdjacent(1,2);
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(0,0) );
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(9,9) );
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(0,9) );
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(9,0) );
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(1,2) );
}

TEST(FieldTest, revealAdjacentFirstRowEmpty)
{
	Field minefield;

	for(int y=0; y<10; y++)
		minefield.placeMine(1,y);
	
	minefield.revealAdjacent(2,0);
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(3,0) );
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(9,9) );
	ASSERT_EQ( EMPTY_HIDDEN, minefield.get(0,0) );
	ASSERT_EQ( MINE_HIDDEN, minefield.get(1,0) );
}


TEST(FieldTest, outOfBounds)
{
  Field minefield;
  bool check = false;
  try
  {
    minefield.get(-1,0);
  }
  catch(...)
  {
    check = true;
  }
  ASSERT_EQ(check,true);

  bool check2 = false;
  try
  {
    minefield.get(1,100);
  }
  catch(...)
  {
    check2 = true;
  }
  ASSERT_EQ(check2,true);

}

TEST(FieldTest, revealAdjacentMineHidden)
{
  Field minefield;
 //Just for branch probabilities gcov
  minefield.placeMine(-1,-2);

  minefield.placeMine(3,3);
  minefield.revealAdjacent(3,3); 
  minefield.placeMine(6,6);
  ASSERT_EQ(MINE_HIDDEN,minefield.get(3,3));
  minefield.revealAdjacent(6,6); 
  ASSERT_EQ(MINE_HIDDEN,minefield.get(6,6));
}

TEST(FieldTest, revealAdjacentMineShown)
{
  Field minefield;
  minefield.set(1,1);
  minefield.revealAdjacent(1,1);
  ASSERT_EQ(MINE_SHOWN,minefield.get(1,1));
}

TEST(FieldTest, setOutOfBounds)
{
  Field minefield;
  minefield.placeMine(1,1);
  minefield.set(1,-1);
  ASSERT_EQ(MINE_HIDDEN,minefield.get(1,1));
}

