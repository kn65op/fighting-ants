/* 
 * File:   Ant.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 16:23
 */

#include <exception>

#include "../include/Ant.h"

#include "../include/Ground.h"

Ant::Ant(int id, int nx, int ny)
{
  //First ant will wolk completly randomly
  dis = new std::uniform_int_distribution<>(1,8);

  this->id = id;
  nest_x = nx;
  nest_y = ny;

  move_function = nullptr;
}

Ant::~Ant()
{
  delete dis;
}

void Ant::freeMove(Ground& ground)
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
    throw new UnexpectedException("Random number is outside range!");
  }
}

void Ant::setPositionToNestPosition()
{
  x = nest_x;
  y = nest_y;
}

bool Ant::move(Ground& ground)
{
  if (move_function == nullptr)
  {
    move_function = &Ant::freeMove;
  }
  freeMove(ground);
  return true;
}