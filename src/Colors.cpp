/* 
 * File:   Colors.cpp
 * Author: tomko
 * 
 * Created on 19 wrzesień 2012, 19:37
 */

#include "../include/Colors.h"

std::vector<double> Colors::r = {106.0/255.0, 0.0/255.0, 238.0/255.0, 205.0/255.0, 139.0/255.0, 139.0/255.0, 0.0/255.0, 0.0/255.0, 148.0/255.0, 1.0, 255.0/255.0};
std::vector<double> Colors::g = {90.0/255.0, 100.0/255.0, 238.0/255.0, 198.0/255.0, 101.0/255.0, 35.0/255.0, 255.0/255.0, 0.0/255.0, 0.0/255.0, 52.0/255.0, 182.0/255.0};
std::vector<double> Colors::b = {205.0/255.0, 0.0/255.0, 0.0/255.0, 115.0/255.0, 8.0/255.0, 35.0/255.0, 127.0/255.0, 139.0/255.0, 211.0/255.0, 179.0/255.0, 192.0/255.0};

Colors::~Colors()
{
  //nothing to do.
}

double Colors::getBColor(int id)
{
  return b.at(id);
}

double Colors::getGColor(int id)
{
  return g.at(id);
}

double Colors::getRColor(int id)
{
  return r.at(id);
}

