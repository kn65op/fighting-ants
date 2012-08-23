/* 
 * File:   Nest.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 16:23
 */

#include <algorithm>

#include "../include/Nest.h"

#include <iostream>
Nest::Nest(int id, int n)
{
  this->id = id;
  //TMP
  x = 5;
  y = 5;
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

  std::list<Ant*> tmp;
  std::for_each(ants.begin(), ants.end(), [&tmp, this](Ant * & ant)
  {
    if (ant->canGoOut())
    {
      if (food > 1) //can be feeded
      {
        food -= (double)(Ant::getMaxTime() - ant->getTime()) / (double)Ant::getMaxTime();
        ant->feed();
      }
      if (ant->getTime() > 0.1 * Ant::getMaxTime()) //going out it's not useless
      {
      	ant->setPositionToNestPosition();
      	tmp.push_back(ant);
      	ant = 0;
      }
    }
    else if (ant->isDead()) //check if is dead
    {
      delete ant;
      ant = 0;
    }
  });
  ants.remove_if([](Ant * ant)
  {
    return !ant;
  });

  return tmp;
}

void Nest::addFood(int amount)
{
  std::cout << "FOOD: " << (food += amount) << "\n";
}

void Nest::produceAnts()
{
  //TODO change this
  if (food > 4 * (ants.size() + 1))
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