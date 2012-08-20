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

Ground::Ground() : dis(1,100)
{
  is_map = false;
}

Ground::~Ground()
{
  deleteMap();
}

void Ground::setSize(int l, int w)
{
  deleteMap();

  //save values
  length = l;
  width = w;

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
      if (dis(*gen) == 1)
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
      delete row;
    });
  }
}

bool Ground::checkifInGround(int x, int y)
{
  return !(x < 0 || y < 0 || x > width - 1 || y > length - 1);
}