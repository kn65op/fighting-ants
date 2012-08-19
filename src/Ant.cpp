/* 
 * File:   Ant.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 16:23
 */

#include <exception>

#include "../include/Ant.h"

#include "../include/Ground.h"

Ant::Ant()
{
  //First ant will wolk completly randomly
  dis = new std::uniform_int_distribution<>(1,8);

  //tmp
  x = y = 50;
}

Ant::~Ant()
{
  delete dis;
}

bool Ant::move(Ground& ground)
{
  switch ((*dis)(*gen))
  {
  case 1:
    if (ground.checkifInGround(x - 1, y))
    {
      --x;
    }
    break;
  case 2:
    if (ground.checkifInGround(x + 1, y))
    {
      ++x;
    }
    break;
  case 3:
    if (ground.checkifInGround(x, y+1))
    {
      ++y;
    }
    break;
  case 4:
    if (ground.checkifInGround(x, y-1))
    {
      --y;
    }
    break;
  case 5:
    if (ground.checkifInGround(x+1, y+1))
    {
      ++y;
      ++x;
    }
    break;
  case 6:
    if (ground.checkifInGround(x+1, y-1))
    {
      ++x;
      --y;
    }
    break;
  case 7:
    if (ground.checkifInGround(x-1, y+1))
    {
      --x;
      ++y;
    }
    break;
  case 8:
    if (ground.checkifInGround(x-1, y-1))
    {
      --x;
      --y;
    }
    break;
  default:
    throw std::exception();
  }

  //TODO: dopisać
}