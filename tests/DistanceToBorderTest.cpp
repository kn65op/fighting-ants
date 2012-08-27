/* 
 * File:   DistanceToBorderTest.cpp
 * Author: tomko
 *
 * Created on 2012-08-24, 11:29:36
 */

#include "include/Ant.h"


#include <gtest.h>

#include "include/Ground.h"
#include "include/Nest.h"

#include <map>

class GroundTest : public ::testing::Test
{
  protected:
    void SetUp()
    {
      ground.setSize(100, 120);
      ul = new Nest(1);
      dr = new Nest(2);
      m = new Nest(3);

      ul->setPosition(1,1);
      dr->setPosition(100,120);
      m->setPosition(45, 60);

      map = new std::map<int, Nest*>();

      (*map)[1] = ul;
      (*map)[2] = dr;
      (*map)[3] = m;

      ground.setNests(map);
      
    };

    void TearDown()
    {
      delete ul;
      delete dr;
      delete m;

      delete map;
      
    }

    Ground ground;

    Nest *ul;
    Nest *dr;
    Nest *m;

    std::map<int, Nest*> *map;
      
};

TEST_F(GroundTest, Left)
{
  ASSERT_EQ(ground.getLeftDistanceFromNestToBorder(1), 0);
  ASSERT_EQ(ground.getLeftDistanceFromNestToBorder(2), 99);
  ASSERT_EQ(ground.getLeftDistanceFromNestToBorder(3), 44);
}

TEST_F(GroundTest, Right)
{
  ASSERT_EQ(ground.getRightDistanceFromNestToBorder(1), 99);
  ASSERT_EQ(ground.getRightDistanceFromNestToBorder(2), 0);
  ASSERT_EQ(ground.getRightDistanceFromNestToBorder(3), 55);
}

TEST_F(GroundTest, Up)
{
  ASSERT_EQ(ground.getUpDistanceFromNestToBorder(1), 0);
  ASSERT_EQ(ground.getUpDistanceFromNestToBorder(2), 119);
  ASSERT_EQ(ground.getUpDistanceFromNestToBorder(3), 59);
}

TEST_F(GroundTest, Down)
{
  ASSERT_EQ(ground.getDownDistanceFromNestToBorder(1), 119);
  ASSERT_EQ(ground.getDownDistanceFromNestToBorder(2), 0);
  ASSERT_EQ(ground.getDownDistanceFromNestToBorder(3), 60);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}