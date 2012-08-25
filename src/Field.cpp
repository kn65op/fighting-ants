/* 
 * File:   Field.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 18:55
 */

#include "../include/Field.h"

Field::Field() : can_be_changed_into_food(true)
{
  bcolor = 0.1647;
  gcolor = 0.1647;
//  rcolor = 0.6471;
  rcolor = 1;

  smell = 0;
}

/**Field::Field(const Field& orig)
{
}*/

Field::~Field()
{
}

double Field::getBColor() const 
{
  return bcolor;
}

double Field::getGColor() const
{
  return gcolor;
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
    smell -= 0.01;
  }
}