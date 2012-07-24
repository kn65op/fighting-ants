/* 
 * File:   MainWindow.h
 * Author: tomko
 *
 * Created on 24 lipiec 2012, 13:03
 */

#ifndef MAINWINDOWS_H
#define	MAINWINDOWS_H

#include <gtkmm-3.0/gtkmm.h>

#include "ApplicationController.h"
#include "Field.h"

/**
 * Class reprezenting main window.
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
  Field field;
  //start/stop button
  Gtk::Button ss_button;

  //for view
  //box for buttons
  Gtk::VBox buttons_box;
  //box for separating field from buttons
  Gtk::HBox main_box;


  //application controller
  ApplicationController ap;
};

#endif	/* MAINWINDOWS_H */

