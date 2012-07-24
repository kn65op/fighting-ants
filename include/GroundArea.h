/* 
 * File:   Field.h
 * Author: tomko
 *
 * Created on 24 lipiec 2012, 15:24
 */

#ifndef FIELD_H
#define	FIELD_H

#include <gtkmm-3.0/gtkmm.h>

/**
 * Class representing Gtk::DrawingArea where simalation will be presented.
 */
class GroundArea : public Gtk::DrawingArea
{
public:
  /**
   * Default constructor.
   */
  GroundArea();
  /**
   * Default destructor.
   */
  virtual ~GroundArea();
protected:
  /**
   * Function draws simulation state.
   * @param cr Cario::Context where painting it's made.
   * @return true.
   */
  virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
};

#endif	/* FIELD_H */

