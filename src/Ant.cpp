/* 
 * File:   Ant.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 16:23
 */

#include "../include/Ant.h"

Ant::Ant()
{
  dis = new std::uniform_int_distribution<>(1,8);
}

Ant::~Ant()
{
  delete dis;
}

