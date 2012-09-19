/* 
 * File:   Food.cpp
 * Author: tomko
 * 
 * Created on 20 sierpień 2012, 14:24
 */

#include "../include/Food.h"

int Food::started_amount_of_food = 10;

Food::Food()
{
  bcolor = rcolor = 0;
  gcolor = 1;
  amount = started_amount_of_food; //TODO losowe
  can_be_changed_into_food = false;
  color_factor = 1;
  smell = 0;
}

Food::~Food()
{
}

int Food::getFood(int n)
{
  int tmp = n < amount ? n : amount;
  amount -= tmp;
  return tmp;
}

bool Food::isEmpty()
{
  return !amount;
}

void Food::setAmountOfFood(int amount)
{
  started_amount_of_food = amount;
}

void Food::makeSmell(int id, Direction dir)
{
  //do nothing
}
