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

TEST(FieldTest, safePosition)
{
  Field minefield;
  minefield.placeMine(4,2);
  ASSERT_TRUE(minefield.isSafe(4,3));  
}

TEST(FieldTest, notSafePosition)
{
  Field minefield;
  minefield.placeMine(4,2);
  ASSERT_FALSE(minefield.isSafe(4,2));  
}
TEST(FieldTest, illegalPosition)
{
  Field minefield;
  bool check = false;
  //minefield.placeMine(10,2);
  try
  {
    minefield.isSafe(14,3);  
  }
  catch(...)
  {
    check = true;
  }
  ASSERT_EQ(true,check);
}


TEST(FieldTest, boudaryReveal)
{
  Field minefield;
  bool check = false;
  minefield.placeMine(9,2);
  try
  {
    minefield.revealAdjacent(14,3);  
  }
  catch(...)
  {
    check = true;
  }
  ASSERT_EQ(true,check);

}

TEST(FieldTest, RnotSafePosition)
{
  Field minefield;
  minefield.placeMine(4,2);
  minefield.revealAdjacent(4,2);  
  ASSERT_EQ(MINE_SHOWN,minefield.get(4,2));  
}
