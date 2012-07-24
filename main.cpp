/* 
 * File:   main.cpp
 * Author: tomko
 *
 * Created on 24 lipiec 2012, 12:41
 */

#include <gtkmm-3.0/gtkmm.h>
#include "include/MainWindow.h"

/*
 * Main funtion, entry point to application. 
 */
int main(int argc, char** argv)
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "pl.tomko.ants");

  MainWindow mw;
	  
  return app->run(mw);
}

