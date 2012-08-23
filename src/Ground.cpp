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

Ground::Ground() : start_food_distribution(1,100), new_food_distribution(1,100)
{
  is_map = false;
  column_distribution = nullptr;  
  row_distribution = nullptr;
}

Ground::~Ground()
{
  deleteMap();
}

void Ground::setSize(int l, int w)
{
  deleteMap();
  deleteDistributions();

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
      if (start_food_distribution(*gen) == 1)
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
  if (new_food_distribution(*gen) == 1)
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
  return dynamic_cast<Food*>(map[x]->at(y)) != nullptr;
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
