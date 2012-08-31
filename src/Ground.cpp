/* 
 * File:   Ground.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 16:17
 */

#include "../include/Ground.h"

#include <algorithm>
#include <random>

#include "../include/Food.h"

//tmp
#include <iostream>
#include <stdexcept>

Ground::Ground()
{
  is_map = false;
  column_distribution = nullptr;  
  row_distribution = nullptr;
  new_food_distribution = nullptr;
  start_food_distribution = nullptr;
}

Ground::~Ground()
{
  deleteMap();
}

void Ground::createMap(int l, int w, double starting_food_probability, double placing_food_probability)
{
  deleteMap();
  deleteDistributions();
  if (start_food_distribution != nullptr)
  {
    delete start_food_distribution;
  }
  int tmp = static_cast<int> (1 / starting_food_probability);
  start_food_distribution = new std::uniform_int_distribution<>(1, tmp);

  if (new_food_distribution != nullptr)
  {
    delete new_food_distribution;
  }
  tmp = static_cast<int> (1 / placing_food_probability);
  new_food_distribution = new std::uniform_int_distribution<>(1, tmp);

  //save values
  length = l;
  width = w;
  
  makeDistributions();
  createBlankMap();
}

void Ground::createBlankMap()
{
  row_type *tmp;
  map.reserve(width);
  for (int i=0; i<width; ++i)
  {
    tmp = new row_type();
    tmp->reserve(length);
    map.push_back(tmp);
    for (int j=0; j<length; ++j)
    {
 //temporary making blank and food fields (aprox 99:1)
      if ((*start_food_distribution)(*gen) == 1)
      {
	tmp->push_back(new Food());
      }
      else
      {
	tmp->push_back(new Field());
      }
    }
  }
  is_map = true;
  /*map.insert(map.begin(), width, (row_type*)0);
  std::for_each(map.begin(), map.end(), [this](row_type * row)
  {
    row =  new row_type(length, (Field*)0);
    std::for_each(row->begin(), row->end(), [](Field * field)
    {
      field = new Field();
    });
  });*/
}

void Ground::deleteMap()
{
  is_map = false;
  if (!map.empty()) //erase old map
  {
    std::for_each(map.begin(), map.end(), [](row_type * row)
    {
      std::for_each(row->begin(), row->end(), [](Field * field)
      {
	delete field;
      });
      row->clear();
      delete row;
    });
  }
  map.clear();
}

bool Ground::checkifInGround(int x, int y)
{
  return !(x < 0 || y < 0 || x > width - 1 || y > length - 1);
}

void Ground::checkFood()
{
  if (!map.empty()) //erase old map
  {
    std::for_each(map.begin(), map.end(), [](row_type * row)
    {
      std::for_each(row->begin(), row->end(), [](Field * & field)
      {
	Food * food = dynamic_cast<Food*> (field);
  	if (food && food->isEmpty())
  	{
	  delete food;
    	  field = new Field();
    	}
      });
    });
  }
}


void Ground::generateFood()
{
  if ((*new_food_distribution)(*gen) == 1)
  {
    Field *tmp;
    int x, y;
    int i = 0;
    do //searching for field where food can be placed
    {
      x = (*row_distribution)(*gen);
      y = (*column_distribution)(*gen);
      tmp = map[x]->at(y);

      if (++i == 100) //after 100 tries, not looking for more
      {
	return;
      }
    }
    while (!tmp->canBeChangedIntoFood());
    delete tmp;
    tmp = new Food();
    map[x]->at(y) = tmp;
  }
}

void Ground::makeDistributions()
{
  row_distribution = new std::uniform_int_distribution<>(0, length - 1);
  column_distribution = new std::uniform_int_distribution<>(0, width - 1);
}

void Ground::deleteDistributions()
{
  if (row_distribution != nullptr) 
  {
    delete row_distribution;
    row_distribution = nullptr;
  }
  if (column_distribution != nullptr)
  {
    delete column_distribution;
    column_distribution = nullptr;
  }
}

bool Ground::isFood(int x, int y) const
{
  Food* food = dynamic_cast<Food*>(map[x]->at(y));
  return food != nullptr && !food->isEmpty();
}

int Ground::getFoodFromField(int x, int y, int requested_food) const
{
  Food *tmp = dynamic_cast<Food*>(map[x]->at(y));
  if (tmp)
  {
    return tmp->getFood(requested_food);
  }
  else
  {
    return 0;
  }
}

int Ground::getLeftDistanceFromNestToBorder(int i) const
{
  return nests->at(i)->getX() - 1;
}

int Ground::getUpDistanceFromNestToBorder(int i) const
{
  return nests->at(i)->getY() - 1;
}

int Ground::getRightDistanceFromNestToBorder(int i) const
{
  return length - nests->at(i)->getX();
}

int Ground::getDownDistanceFromNestToBorder(int i) const
{
  return width - nests->at(i)->getY();
}

void Ground::proceedNextStep()
{

  std::for_each(map.begin(), map.end(), [](row_type * row)
  {
    std::for_each(row->begin(), row->end(), [](Field * & field)
    {
      field->flowAwaySmell();
    });
  });
}

void Ground::makeSmell(int x, int y, int id)
{
  map[x]->at(y)->makeSmell(id);
}

bool Ground::isSmell(int x, int y, int id)
{
  return map[x]->at(y)->isSmell(id);
}

Direction Ground::followSmell(int x, int y, int id)
{
  return map[x]->at(y)->getDirection(id);
//  Direction dir = Direction::NO_DIRECTION;
//  if (map[x]->at(y)->isSmell(id))
//  { //search for decreasing smell
//    double act = map[x]->at(y)->getSmell(id);
//    double min = act;
//    double tmp;
//
//    try
//    {
//      if ((tmp = map.at(x - 1)->at(y - 1)) //smaller
//      {
//        min = tmp;
//        dir = Direction::UL;
//      }
//    }
//    catch (std::out_of_range e)
//    {
//    }
//
//    try
//    {
//      if ((tmp = map.at(x)->at(y - 1)) //smaller
//      {
//        min = tmp;
//        dir = Direction::U;
//      }
//    }
//    catch (std::out_of_range e)
//    {
//    }
//
//    try
//    {
//      if ((tmp = map.at(x + 1)->at(y - 1)) //smaller
//      {
//        min = tmp;
//        dir = Direction::UR;
//      }
//    }
//    catch (std::out_of_range e)
//    {
//    }
//
//    try
//    {
//      if ((tmp = map.at(x - 1)->at(y)) //smaller
//      {
//        min = tmp;
//        dir = Direction::L;
//      }
//    }
//    catch (std::out_of_range e)
//    {
//    }
//
//    try
//    {
//      if ((tmp = map.at(x + 1)->at(y)) //smaller
//      {
//        min = tmp;
//        dir = Direction::R;
//      }
//    }
//    catch (std::out_of_range e)
//    {
//    }
//
//    try
//    {
//      if ((tmp = map.at(x - 1)->at(y + 1)) //smaller
//      {
//        min = tmp;
//        dir = Direction::DL;
//      }
//    }
//    catch (std::out_of_range e)
//    {
//    }
//
//    try
//    {
//      if ((tmp = map.at(x)->at(y + 1)) //smaller
//      {
//        min = tmp;
//        dir = Direction::D;
//      }
//    }
//    catch (std::out_of_range e)
//    {
//    }
//
//    try
//    {
//      if ((tmp = map.at(x + 1)->at(y + 1)) //smaller
//      {
//        min = tmp;
//        dir = Direction::DR;
//      }
//    }
//    catch (std::out_of_range e)
//    {
//    }
//
//  }
//
//  return dir;
}

void Ground::makeSmell(int x, int y, int id, Direction dir)
{
  map[x]->at(y)->makeSmell(id, dir);
}

Direction Ground::findFoodNextTo(int x, int y)
{
  Direction dir = Direction::NO_DIRECTION;
  try
  {
    if (dynamic_cast<Food*> (map.at(x - 1)->at(y - 1)))
    {
      dir = Direction::UL;
    }
  }
  catch (std::out_of_range e)
  {
  }

  try
  {

    if (dynamic_cast<Food*> (map.at(x)->at(y - 1)))
    {
      dir = Direction::U;
    }
  }
  catch (std::out_of_range e)
  {
  }

  try
  {

    if (dynamic_cast<Food*> (map.at(x + 1)->at(y - 1)))
      {
        dir = Direction::UR;
      }
  }
  catch (std::out_of_range e)
  {
  }

  try
  {

    if (dynamic_cast<Food*> (map.at(x - 1)->at(y)))
      {
        dir = Direction::L;
      }
  }
  catch (std::out_of_range e)
  {
  }

  try
  {

    if (dynamic_cast<Food*> (map.at(x + 1)->at(y)))
      {
        dir = Direction::R;
      }
  }
  catch (std::out_of_range e)
  {
  }

  try
  {

    if (dynamic_cast<Food*> (map.at(x - 1)->at(y + 1)))
      {
        dir = Direction::DL;
      }
  }
  catch (std::out_of_range e)
  {
  }

  try
  {

    if (dynamic_cast<Food*> (map.at(x)->at(y + 1)))
      {
        dir = Direction::D;
      }
  }
  catch (std::out_of_range e)
  {
  }

  try
  {

    if (dynamic_cast<Food*> (map.at(x + 1)->at(y + 1)))
      {
        dir = Direction::DR;
      }
  }
  catch (std::out_of_range e)
  {
  }

  return dir;
}

std::list<Ant*> Ground::findAntsNextTo(int x, int y, int id)
{
  std::list<Ant*> ret;

  std::for_each(ants->begin(), ants->end(), [x, y, id, & ret](Ant * ant)
  {
    if (ant && abs(x - ant->getX()) <= 1 && abs(y - ant->getY()) <= 1 && ant->getId() != id) //  distance is 1 or less
    {
      ret.push_back(ant);
    }
  });
  
  return ret;
}

void Ground::setAmountOfFood(int amount)
{
  Food::setAmountOfFood(amount);
}