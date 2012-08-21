/* 
 * File:   Nest.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 16:23
 */

#include "../include/Nest.h"

Nest::Nest(int id, int n)
{
  this->id = id;
  //TMP
  x = 0;
  y = 0;
  //TMP
  //creating starting number of ants
  for (int i=0; i<n; ++i)
  {
    //create ants
    ants.push_back(new Ant(id, x, y));
  }

  food = 0;
}

Nest::~Nest()
{
}

std::list<Ant*> Nest::nextStep()
{
  produceAnts();

  //TODO: zmienić
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

void Nest::addFood(int amount)
{
  food += amount;
}

void Nest::produceAnts()
{
  if (food > 4 *ants.size())
  {
    int number = food - 4 * ants.size();
    number /= 4;
    number = number > 10 ? 10 : number;
    for (int i = 0; i < number; i++)
    {
      ants.push_back(new Ant(id, x, y));
    }
  }
}

void Nest::addAnt(Ant* ant)
{
  ants.push_back(ant);
}