/* 
 * File:   Field.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 18:55
 */

#include "../include/Field.h"

double Field::smell_time;

Field::Field() : can_be_changed_into_food(true)
{
  bcolor = 1;
  gcolor = 1;
//  rcolor = 0.6471;
  rcolor = 1;

  smell = -1;
}

/**Field::Field(const Field& orig)
{
}*/

Field::~Field()
{
}

double Field::getBColor() const 
{
  return bcolor * smell;
}

double Field::getGColor() const
{
  return gcolor * smell;
}

double Field::getRColor() const
{
  return rcolor * smell;
}

bool Field::canBeChangedIntoFood() const
{
  return can_be_changed_into_food;
}

void Field::makeSmell(int id)
{
  smell_id = id;
  smell = 1.0;
}

void Field::flowAwaySmell()
{
  if (smell > 0)
  {
    smell -= smell_time;
  }
}

bool Field::isSmell(int id)
{
  return smell > 0 && id == smell_id;
}

double Field::getSmell(int id)
{
  if (smell_id == id)
  {
    return smell;
  }
}

void Field::makeSmell(int id, Direction dir)
{
  smell = 1.0;
  smell_id = id;
  direction = dir;
}