/* 
 * File:   Food.cpp
 * Author: tomko
 * 
 * Created on 20 sierpień 2012, 14:24
 */

#include "../include/Food.h"

Food::Food()
{
  bcolor = rcolor = 0;
  gcolor = 1;
  amount = 100;
}

Food::~Food()
{
}

int Food::getFood(int n)
{
  int tmp = n > amount ? n : amount;
  amount -= tmp;
  return tmp;
}

bool Food::isEmpty()
{
  return !amount;
}