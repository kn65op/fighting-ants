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
#include "../include/GroundArea.h"

MainWindow::MainWindow()
{
  //setting widow view
  //title
  set_title("Fighting ants");
  set_size_request(800, 600);

  //setting view
  add(main_box);

  //setting main box
  field = new GroundArea();
  main_box.pack_start(*field, Gtk::PACK_EXPAND_WIDGET);
  main_box.pack_end(buttons_box, Gtk::PACK_SHRINK);

  //setting buttons_box
  buttons_box.pack_start(init_button);
  buttons_box.pack_end(ss_button);
  buttons_box.pack_end(step_button);
  is_started = false;

  //setting buttons
  ss_button.set_label("Start");
  ss_button.set_sensitive(false);
  init_button.set_label("Init");
  step_button.set_label("Step");
  step_button.set_sensitive(false);
  ss_button.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_start_stop_button_clicked));
  init_button.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_init_button_clicked));
  step_button.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_step_button_clicked));

  //showing widgets
  main_box.show();
  main_box.show_all_children(true);

  //setting application controller
  ap.setGround(field);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_start_stop_button_clicked()
{
  if (is_started = !is_started) //starting
  {
    ss_button.set_label("Stop");
    init_button.set_sensitive(false);
    ap.startSimulation();
  }
  else //stopping
  {
    ss_button.set_label("Start");
    init_button.set_sensitive(true);
    ap.stopSimulation();
  }
}

void MainWindow::on_step_button_clicked()
{
  ap.stepSimulation();
}

void MainWindow::on_init_button_clicked()
{
  ap.initSimulation();
  step_button.set_sensitive(true);
  ss_button.set_sensitive(true);
}