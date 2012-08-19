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
  j = 0;
  //draw all fields
  for (row_type* row : Ground::map)
  {
    i = 0;
    for (Field* field : *row)
    {
      cr->set_source_rgb(field->getRColor(), field->getGColor(), field->getBColor());
      int tmp1 = i * xsquare;
      int tmp2 = j * ysquare;
      cr->rectangle(tmp1, tmp2, tmp1 + xsquare, tmp2 + ysquare);
      cr->fill();
      ++i;
      //TODO: draw fields
    }
    ++j;
  }

  //draw nests
  for (auto nest: nests)
  {
    //TODO: draw nests
  }

  //draw ants with are on the ground
  for (auto ant : ants)
  {
    cr->set_source_rgb(0,0,0);
    int x = ant->getX();
    int y = ant->getY();
    int tmp1 = x * xsquare;
    int tmp2 = y * ysquare;
    cr->rectangle(tmp1, tmp2, tmp1 + x, tmp2 + y);
    cr->fill();
    //TODO: draw ants
  }

//  cr->set_source_rgb(0.8,0.0,0.0);
  //cr->rectangle(0, 0, 10, 5);
  //cr->fill();

  return true;
}

