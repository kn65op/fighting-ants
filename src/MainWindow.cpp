/* 
 * File:   MainWindow.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 13:03
 */

#include <cairomm-1.0/cairomm/refptr.h>
#include <cairomm-1.0/cairomm/enums.h>
#include <cairomm-1.0/cairomm/context.h>

#include "../include/MainWindow.h"

MainWindow::MainWindow()
{
  //setting widow view
  //title
  set_title("Fighting ants");
  set_size_request(800, 600);
  
  //setting view
  add(main_box);

  //setting main box
  main_box.pack_start(field);
  main_box.pack_end(buttons_box, Gtk::PACK_SHRINK);

  //setting buttons_box
  buttons_box.pack_end(ss_button);

  //setting buttons
  ss_button.set_label("Start");

  //setting drawingArea
  Glib::RefPtr<Gdk::Window> www = field.get_window();
  
  //showing widgets
  main_box.show();
  main_box.show_all_children(true);

//  Cairo::RefPtr<Cairo::Context> cont = field.get_window()->create_cairo_context();
}

MainWindow::~MainWindow()
{
}

