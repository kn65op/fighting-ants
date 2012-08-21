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
  //check if map is ready
  if (!is_map)
  {
    return true;
  }

  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  //scale of squares
  int xsquare = width / this->width;
  int ysquare = height / length;

  int i, j;
  i = 0;
  //draw all fields
  for (row_type* row : Ground::map)
  {
    j = 0;
    for (Field* field : *row)
    {
      cr->set_source_rgb(field->getRColor(), field->getGColor(), field->getBColor());
      cr->rectangle(i * xsquare, j*ysquare, xsquare, ysquare);
      cr->fill();
      ++j;
    }
    ++i;
  }

  //draw nests
  if (nests)
  {
    for (auto nest : *nests) //std::pair<id, Nest*>
    {
      cr->set_source_rgb(1, 1, 1);
      cr->rectangle(nest.second->getX() * xsquare, nest.second->getY() * ysquare, xsquare, ysquare);
      cr->fill();
    }
  }

  //draw ants with are on the ground
  if (ants)
  {
    for (auto ant : *ants)
    {
      cr->set_source_rgb(ant->getRColor(), ant->getGColor(), ant->getBColor());
      cr->rectangle(ant->getX() * xsquare, ant->getY() * ysquare, xsquare, ysquare);
      cr->fill();
    }
  }

  //cr->set_source_rgb(0.8,0.8,0.0);
  //cr->rectangle(0, 0, 100, 5);
  //cr->fill();

  return true;
}

