/* 
 * File:   Field.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 15:24
 */

#include "../include/Field.h"

Field::Field()
{
}

Field::~Field()
{
}

bool Field::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  return true;
}

