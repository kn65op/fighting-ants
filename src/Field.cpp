/* 
 * File:   Field.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 18:55
 */

#include "../include/Field.h"

Field::Field()
{
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
  return rcolor;
}