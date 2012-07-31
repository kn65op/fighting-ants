/* 
 * File:   Ground.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 16:17
 */

#include "../include/Ground.h"

#include <algorithm>

//tmp
#include <iostream>

Ground::Ground()
{
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

  createMap();
}

void Ground::createMap()
{
  Row *tmp;
  map.reserve(width);
  for (int i=0; i<width; ++i)
  {
    tmp = new Row();
    tmp->reserve(length);
    map.push_back(tmp);
    for (int j=0; j<length; ++j)
    {
      tmp->push_back(new Field());
    }
  }
  /*map.insert(map.begin(), width, (Row*)0);
  std::for_each(map.begin(), map.end(), [this](Row * row)
  {
    row =  new Row(length, (Field*)0);
    std::for_each(row->begin(), row->end(), [](Field * field)
    {
      field = new Field();
    });
  });*/
}

void Ground::deleteMap()
{
  if (!map.empty()) //erase old map
  {
    std::for_each(map.begin(), map.end(), [](Row * row)
    {
      std::for_each(row->begin(), row->end(), [](Field * field)
      {
	delete field;
      });
      delete row;
    });
  }
}
