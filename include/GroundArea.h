/* 
 * File:   Field.h
 * Author: tomko
 *
 * Created on 24 lipiec 2012, 15:24
 */

#ifndef GROUND_AREA_H
#define	GROUND_AREA_H

#include <gtkmm-3.0/gtkmm.h>
#include <mutex>

#include "Ground.h"

/**
 * @brief Class representing Gtk::DrawingArea where simalation will be presented.
 */
class GroundArea : public Gtk::DrawingArea, public Ground
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

  void redraw(const Cairo::RefPtr<Cairo::Context>& cr);

  void lock()
  {
    mutex.lock();
  }
  void unlock()
  {
    mutex.unlock();
  }
protected:
  /**
   * Function draws simulation state.
   * @param cr Cario::Context where painting it's made.
   * @return true.
   */
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

private:
  std::mutex  mutex;
};

#endif	/* GROUND_AREA_H */

