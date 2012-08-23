/* 
 * File:   Direction.cpp
 * Author: tomko
 * 
 * Created on 23 sierpień 2012, 14:25
 */

#include "../include/Direction.h"

Direction getDirectionFromDifferenceSigns(int horiz, int vert)
{
  if (horiz < 0)
  {
    if (vert < 0)
    {
      return Direction::UL;
    }
    else if (vert)
    {
      return Direction::DL;
    }
    else
    {
      return Direction::L;
    }
  }
  else if (horiz)
  {
    if (vert < 0)
    {
      return Direction::UR;
    }
    else if (vert)
    {
      return Direction::DR;
    }
    else
    {
      return Direction::R;
    }
  }
  else
  {
    if (vert < 0)
    {
      return Direction::U;
    }
    else if (vert)
    {
      return Direction::D;
    }
    else
    {
      return Direction::NO_DIRECTION;
    }
  }
}