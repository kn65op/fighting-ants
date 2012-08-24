/* 
 * File:   Ant.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 16:23
 */

#include <exception>
#include <stdlib.h>

#include "../include/Ant.h"

#include "../include/Ground.h"

int Ant::can_carry_food = 10;

#include <iostream>

int Ant::max_time;
int Ant::max_time_without_feeding;
int Ant::noa;

Ant::Ant(int id, int nx, int ny) : nest_time_distribution(-10, -5)
{
  live = true;
  std::cout << (++noa) << "\n";
  //First ant will wolk completly randomly
  move_distribution = nullptr;

  this->id = id;
  nest_x = nx;
  nest_y = ny;

  move_function = nullptr;
  food = 0;

  time = max_time;
  time_in_nest = nest_time_distribution(*gen);

  last_direction = Direction::NO_DIRECTION;
}

Ant::~Ant()
{
  std::cout << (--noa) << "\n";
  if (move_distribution != nullptr)
  {
    delete move_distribution;
  }
}

void Ant::freeMove(Ground& ground)
{
  createMoveDistribution(ground);
  switch ((*move_distribution)(*gen))
  {
  case 0:
    if (ground.checkifInGround(x - 1, y - 1))
    {
      --x;
      --y;
    }
    break;
  case 1:
    if (ground.checkifInGround(x, y - 1))
    {
      --y;
    }
    break;
  case 2:
    if (ground.checkifInGround(x + 1, y - 1))
    {
      --y;
      ++x;
    }
    break;
  case 3:
    if (ground.checkifInGround(x - 1, y))
    {
      --x;
    }
    break;
  case 4:
    if (ground.checkifInGround(x + 1, y))
    {
      ++x;
    }
    break;
  case 5:
    if (ground.checkifInGround(x - 1, y + 1))
    {
      --x;
      ++y;
    }
    break;
  case 6:
    if (ground.checkifInGround(x, y + 1))
    {
      ++y;
    }
    break;
  case 7:
    if (ground.checkifInGround(x + 1, y + 1))
    {
      ++x;
      ++y;
    }
    break;
  default:
    throw new UnexpectedException("Random number is outside range!");
  }

  if (food != can_carry_food && ground.isFood(x, y)) //on food field
  {
    move_function = &Ant::getFood;
  }
}

void Ant::setPositionToNestPosition()
{
  x = nest_x;
  y = nest_y;
}

bool Ant::move(Ground& ground)
{
  if (move_function == nullptr) //ant just go out nest
  {
    move_function = &Ant::freeMove;
  }
  if (distanceToNest() > (--time - 10))
  {
    move_function = &Ant::goToNest;
  }
  (this->*move_function)(ground);
  if (x == nest_x && y == nest_y) //going into nest
  {
    move_function = nullptr;
    time_in_nest = nest_time_distribution(*gen);
    return false;
  }
  return true;
}

void Ant::getFood(Ground& ground)
{
  food += ground.getFoodFromField(x, y, can_carry_food - food);
  move_function = &Ant::goToNest;
}

void Ant::goToNest(Ground& ground)
{
  //for now it's closest way
  if (x > nest_x && ground.checkifInGround(x - 1, y))
  {
    --x;
  }
  if (x < nest_x && ground.checkifInGround(x + 1, y))
  {
    ++x;
  }

  if (y > nest_y && ground.checkifInGround(x, y - 1))
  {
    --y;
  }
  if (y < nest_y && ground.checkifInGround(x, y + 1))
  {
    ++y;
  }

}

double Ant::getBColor() const
{
  return 0.1 * food;
}

double Ant::getRColor() const
{
  return 0;
}

double Ant::getGColor() const
{
  return 0;
}

int Ant::distanceToNest() const
{
  return std::max(abs(x - nest_x), abs(y - nest_y)); //TODO check
}

bool Ant::canGoOut()
{
  if ((++time_in_nest) > 0)
  {
    if (--time < max_time_without_feeding)
    {
      die();
      return false;
    }
    else
    {
      return true;
    }
  }
  return !time_in_nest;
}

void Ant::feed()
{
  time = max_time;
}

void Ant::die()
{
  live = false;
}

void Ant::createMoveDistribution(Ground & ground)
{
  int range = 10;
  int dirrl = abs(x - nest_x) > range ? x - nest_x : 0;
  int dirud = abs(y - nest_y) > range ? y - nest_y : 0;
  
  Direction act_direction = getDirectionFromDifferenceSigns(dirrl, dirud);
//  if (act_direction == last_direction && move_distribution != nullptr)
//  {
//    return;
//  }
  if (move_distribution != nullptr)
  {
    delete move_distribution;
  }
  last_direction = act_direction;
  int zones = 4;
  int left_max = ground.getLeftDistanceFromNestToBorder(id);
  int up_max = ground.getUpDistanceFromNestToBorder(id);
  int right_max = ground.getRightDistanceFromNestToBorder(id);
  int down_max = ground.getDownDistanceFromNestToBorder(id);
  int lr = abs(nest_x - x);
  int ud = abs(nest_y - y);

  int iprobl = lr ? zones - lr / (left_max / zones) : 1;
  int iprobr = lr ? zones - lr / (right_max / zones) : 1;
  int iprobu = ud ? zones - ud / (up_max / zones) : 1;
  int iprobd = ud ? zones - ud / (down_max / zones) : 1;

  double a = 0.25;
  double b = 0.75;
  
  double probl = iprobl ? iprobl * a + b : 1;
  double probr = iprobr ? iprobr * a + b : 1;
  double probu = iprobu ? iprobu * a + b : 1;
  double probd = iprobd ? iprobd * a + b : 1;

  switch (act_direction)
  {
  case Direction::UL:
    move_distribution = new std::discrete_distribution<> ({std::min(probl, probu), probu, probu, probl, 1, probl, 1, 1});
    break;
  case Direction::UR:
    move_distribution = new std::discrete_distribution<> ({probu, probu, std::min(probr, probu), 1, probr, 1, 1, probr});
    break;
  case Direction::U:
    move_distribution = new std::discrete_distribution<> ({probu, probu, probu, 1, 1, 1, 1, 1});
    break;
  case Direction::DL:
    move_distribution = new std::discrete_distribution<> ({probl, 1, 1, probl, 1, std::min(probd, probl), probd, probd});
    break;
  case Direction::DR:
    move_distribution = new std::discrete_distribution<> ({1, 1, probr, 1, probr, probd, probd, std::min(probd, probr)});
    break;
  case Direction::D:
    move_distribution = new std::discrete_distribution<> ({1, 1, 1, 1, 1, probd, probd, probd});
    break;
  case Direction::L:
    move_distribution = new std::discrete_distribution<> ({probl, 1, 1, probl, 1, probl, 1, 1});
    break;
  case Direction::R:
    move_distribution = new std::discrete_distribution<> ({1, 1, probr, 1, probr, 1, 1, probr});
    break;
  case Direction::NO_DIRECTION:
    move_distribution = new std::discrete_distribution<> ({1, 1, 1, 1, 1, 1, 1, 1});
    break;
  }
}