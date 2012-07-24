/* 
 * File:   Field.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 15:24
 */

#include "../include/GroundArea.h"

GroundArea::GroundArea()
{
}

GroundArea::~GroundArea()
{
}

bool GroundArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  //draw all fields

  //draw nests

  //draw ants with are on the ground

  return true;
}

