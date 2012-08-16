/* 
 * File:   Field.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 15:24
 */

#include <cairomm-1.0/cairomm/context.h>

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
  for (row_type* row : Ground::map)
  {
    for (Field* field : *row)
    {
      cr->set_source_rgb(field->getRColor(), field->getGColor(), field->getBColor());
      //TODO: draw fields
    }
  }

  //draw nests
  for (auto nest: nests)
  {
    //TODO: draw nests
  }

  //draw ants with are on the ground
  for (auto ant : ants)
  {
    //TODO: draw ants
  }

  cr->set_source_rgb(0.8,0.0,0.0);
  cr->rectangle(0, 0, 10, 5);
  cr->fill();

  return true;
}

