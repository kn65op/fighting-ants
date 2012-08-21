/* 
 * File:   MainWindow.h
 * Author: tomko
 *
 * Created on 24 lipiec 2012, 13:03
 */

#ifndef MAINWINDOWS_H
#define	MAINWINDOWS_H

#include "ApplicationController.h"

#include <gtkmm-3.0/gtkmm.h>

class GroundArea;

/**
 * @brief Class reprezenting main window.
 */
class MainWindow : public Gtk::Window
{
public:
  /**
   * Default constructor.
   */
  MainWindow();
  /**
   * Copying is not allowed.
   */
  MainWindow(const MainWindow& orig) = delete;
  /**
   * Default destructor.
   */
  ~MainWindow();
private:
  //for paint field with ants
  GroundArea* field;
  //start/stop button
  Gtk::Button ss_button;
  //state of this button
  bool is_started;

  //for view
  //box for buttons
  Gtk::VBox buttons_box;
  //box for separating field from buttons
  Gtk::HBox main_box;


  //application controller
  ApplicationController ap;

  //signal handlers
  void on_start_stop_button_clicked();
};

#endif	/* MAINWINDOWS_H */

