/* 
 * File:   FindingAntsTest.cpp
 * Author: tomko
 *
 * Created on 2012-08-27, 12:32:05
 */

#include <gtest.h>

#include "include/Ant.h"
#include "include/Ground.h"

#include <map>

class GroundTest : public ::testing::Test
{
protected:

  void SetUp()
  {
    ants = new std::list<Ant*>();
    
    ground.setSize(100, 120);

    Ant *tmp;

    tmp = new Ant(1, 10, 10);
    tmp->setPositionToNestPosition();
    ants->push_back(tmp);

    tmp = new Ant(1, 11, 11);
    tmp->setPositionToNestPosition();
    ants->push_back(tmp);

    tmp = new Ant(2, 12, 11);
    tmp->setPositionToNestPosition();
    ants->push_back(tmp);

    ground.setAnts(ants);
  };

  void TearDown()
  {

    delete ants;
  }

  Ground ground;

  std::list<Ant*> *ants;

};

TEST_F(GroundTest, None)
{
  ASSERT_TRUE(ground.findAntsNextTo(10, 20, 2).empty());
  ASSERT_TRUE(ground.findAntsNextTo(10, 11, 1).empty());
}

TEST_F(GroundTest, Found)
{
  ASSERT_EQ(ground.findAntsNextTo(11,10,3).size(), 3);
  ASSERT_EQ(ground.findAntsNextTo(12,11,3).size(), 2);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}