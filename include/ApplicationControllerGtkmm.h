/* 
 * File:   ApplicationControllerGtkmm.h
 * Author: tomko
 *
 * Created on 19 wrzesień 2012, 20:49
 */

#ifndef APPLICATIONCONTROLLERGTKMM_H
#define	APPLICATIONCONTROLLERGTKMM_H

#include "ApplicationController.h"

#include "gtkmm-3.0/gtkmm/statusbar.h"

class ApplicationControllerGtkmm : public ApplicationController
{
public:
  ApplicationControllerGtkmm();
  virtual ~ApplicationControllerGtkmm();

  /**
   * Setting status bar.
   * @param statusb Statusbar to set.
   */
  void setStatusBar(Gtk::Statusbar * statusb)
  {
    statusbar = statusb;
  }
private:
  Gtk::Statusbar * statusbar;
protected:
  void showMessage() override;
};

#endif	/* APPLICATIONCONTROLLERGTKMM_H */

