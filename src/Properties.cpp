/* 
 * File:   Properties.cpp
 * Author: tomko
 * 
 * Created on 30 sierpień 2012, 14:05
 */

#include "../include/Properties.h"

Properties::Properties()
{
  amount_of_food = 50;
  ant_can_walk = 500;
  nests = 2;
  placing_food = 0.0005;
  simulation_interval = 100;
  starting_ants = 10;
  starting_food = 0.0001;
}

Properties::~Properties()
{
}

