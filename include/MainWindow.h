/* 
 * File:   MainWindow.h
 * Author: tomko
 *
 * Created on 24 lipiec 2012, 13:03
 */

#ifndef MAINWINDOWS_H
#define	MAINWINDOWS_H

#include "ApplicationControllerGtkmm.h"
#include "Properties.h"


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
  //step simulation button;
  Gtk::Button step_button;
  //init simulation button
  Gtk::Button init_button;
  //state of this button
  bool is_started;

  //for view
  //box for buttons
  Gtk::HBox buttons_box;
  //box for separating field from buttons
  Gtk::VBox main_part_box;
  // main box for menubar, main part of screen and status bar
  Gtk::VBox main_box;

  Gtk::Statusbar statusbar;
  


  //application controller
  ApplicationControllerGtkmm * ap;
  //properties
  Properties properties;

  //signal handlers
  void on_start_stop_button_clicked();
  void on_init_button_clicked();
  void on_step_button_clicked();
  void on_quit_menu_item_clicked();
  void on_simulation_settings_menu_item_clicked();
  void on_engine_settings_menu_item_clicked();

  void makeMenu();

  bool canQuit();
  Glib::ustring ui_info;

  //for menu
  Glib::RefPtr<Gtk::UIManager> m_refUIManager;
  Glib::RefPtr<Gtk::ActionGroup> m_refActionGroup;
  
  bool on_delete_event(GdkEventAny * event) override;
  
};

#endif	/* MAINWINDOWS_H */

