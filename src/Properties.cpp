/* 
 * File:   Properties.cpp
 * Author: tomko
 * 
 * Created on 30 sierpień 2012, 14:05
 */

#include "../include/Properties.h"

#include <fstream>

Properties::Properties()
{
  amount_of_food = 50;
  ant_can_walk = 500;
  nests = 2;
  placing_food = 0.0005;
  simulation_interval = 100;
  starting_ants = 10;
  starting_food = 0.001;
  length = 100;
  height = 100;
  smell_time = 100;
}

Properties::~Properties()
{
}

void Properties::saveToFile(std::string file)
{
  std::ofstream f(file);
  f << amount_of_food << "\n";
  f << ant_can_walk << "\n";
  f << nests << "\n";
  f << placing_food << "\n";
  f << simulation_interval << "\n";
  f << starting_ants << "\n";
  f << starting_food << "\n";
  f << length << "\n";
  f << height << "\n";
  f << smell_time << "\n";
  for (auto i : nests_x)
  {
    f << i << "\n";
  }
  for (auto i : nests_y)
  {
    f << i << "\n";
  }
  f.close();
}

void Properties::loadFromFile(std::string file)
{
  std::ifstream f(file);
  if (!f.good())
  {
    return;
  }
  f >> amount_of_food;
  f >> ant_can_walk;
  f >> nests;
  f >> placing_food;
  f >> simulation_interval;
  f >> starting_ants;
  f >> starting_food;
  f >> length;
  f >> height;
  f >> smell_time;

  int tmp;
  while (nests_x.size() < nests)
  {
    f >> tmp;
    nests_x.push_back(tmp);
  }
  while (nests_y.size() < nests)
  {
    f >> tmp;
    nests_y.push_back(tmp);
  }
  f.close();
}
