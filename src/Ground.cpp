/* 
 * File:   Ground.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 16:17
 */

#include "../include/Ground.h"

#include <algorithm>

Ground::Ground()
{
}

Ground::~Ground()
{
}

void Ground::setSize(int l, int w)
{
  if (!map.empty()) //erase old map
  {
    std::for_each(map.begin(), map.end(), [](Row* row)
    {
      std::for_each(row->begin(), row->end(), [](Field* field)
      {
	delete field;
      });
      delete row;
    });
  }

  //save values
  length = l;
  width = w;


  //create new map
  map.insert(map.begin(), width, new Row(length, new Field()));
}