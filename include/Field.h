/* 
 * File:   Field.h
 * Author: tomko
 *
 * Created on 24 lipiec 2012, 15:24
 */

#ifndef FIELD_H
#define	FIELD_H

#include <gtkmm-3.0/gtkmm.h>

class Field : public Gtk::DrawingArea
{
public:
  Field();
  virtual ~Field();
protected:
  
  virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
};

#endif	/* FIELD_H */

