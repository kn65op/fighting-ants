/* 
 * File:   Nest.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 16:23
 */

#include "../include/Nest.h"

Nest::Nest(int n)
{
  //TMP
  x = y = 25;
  //TMP
  ants_in = n;
  //creating starting number of ants
  for (int i=0; i<n; ++i)
  {
    //create ants
    ants.push_back(new Ant(id, x, y));
  }
}

Nest::~Nest()
{
}

std::list<Ant*> Nest::nextStep()
{
  std::list<Ant*> tmp;
  if (ants.empty())
  {
    return tmp;
  }
  tmp.push_back(ants.back());
  ants.pop_back();
  tmp.front()->setPositionToNestPosition();
  return tmp;
}
