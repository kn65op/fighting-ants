/* 
 * File:   MainWindow.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 13:03
 */


#include "../include/MainWindow.h"
#include "../include/GroundArea.h"
#include "../include/EnginePropertiesDialog.h"
#include "../include/SimulationPropertiesDialog.h"

#include <fstream>
#include <string>

#include <iostream>

MainWindow::MainWindow()
{
  //set title
  set_title("Fighting ants");
  
  //make menu
  makeMenu();

  //setting widow view
  //title
  set_title("Fighting ants");
  set_size_request(800, 600);

  //setting view
  add(main_box);

  //setting main box 
  main_box.pack_start(*(m_refUIManager->get_widget("/MenuBar")), Gtk::PACK_SHRINK);
  main_box.pack_end(main_part_box);

  //setting main part box
  field = new GroundArea();
  main_part_box.pack_start(*field, Gtk::PACK_EXPAND_WIDGET);
  main_part_box.pack_end(buttons_box, Gtk::PACK_SHRINK);

  //setting buttons_box
  buttons_box.pack_start(init_button);
  buttons_box.pack_end(ss_button);
  buttons_box.pack_end(step_button);
  is_started = false;

  //setting buttons
  ss_button.set_label("Start");
  ss_button.set_sensitive(false);
  init_button.set_label("Utwórz mapę");
  step_button.set_label("Krok");
  step_button.set_sensitive(false);
  ss_button.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_start_stop_button_clicked));
  init_button.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_init_button_clicked));
  step_button.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_step_button_clicked));

  //showing widgets
  main_box.show();
  main_box.show_all_children(true);

  //setting application controller
  ap.setProperties(properties);
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
    step_button.set_sensitive(false);
    ap.startSimulation();
  }
  else //stopping
  {
    ss_button.set_label("Start");
    init_button.set_sensitive(true);
    step_button.set_sensitive(true);
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

void MainWindow::makeMenu()
{
  std::string tmp;
  std::ifstream ui_file("ui_file");
  while (!ui_file.eof() && ui_file.good())
  {
    std::getline(ui_file, tmp);
    ui_info += tmp;
  }

  //actions
  m_refActionGroup = Gtk::ActionGroup::create();

  m_refActionGroup->add(Gtk::Action::create("MenuFile", "_Plik"));
  m_refActionGroup->add(Gtk::Action::create("Quit", "_Wyjdź"), sigc::mem_fun(*this, &MainWindow::on_quit_menu_item_clicked));

  m_refActionGroup->add(Gtk::Action::create("MenuSettings", "_Ustawienia"));
  m_refActionGroup->add(Gtk::Action::create("SimulationSettings", "Ustawienia symluacji"), sigc::mem_fun(*this, &MainWindow::on_simulation_settings_menu_item_clicked));
  m_refActionGroup->add(Gtk::Action::create("EngineSettings", "Ustawienia silnika"), sigc::mem_fun(*this, &MainWindow::on_engine_settings_menu_item_clicked));

  //ui manager
  m_refUIManager = Gtk::UIManager::create();
  m_refUIManager->insert_action_group(m_refActionGroup);
  add_accel_group(m_refUIManager->get_accel_group());
  std::cout << ui_info << "\n";
  m_refUIManager->add_ui_from_string(ui_info);

}

void MainWindow::on_quit_menu_item_clicked()
{
  if (!on_delete_event(nullptr))
  {
    hide();
  }
}

void MainWindow::on_simulation_settings_menu_item_clicked()
{
  SimulationPropertiesDialog spd(properties);
  if (spd.run() == SimulationPropertiesDialog::Response::OK)
  {
    spd.saveProperties(properties);
    ap.setProperties(properties);
  }
}

void MainWindow::on_engine_settings_menu_item_clicked()
{
  EnginePropertiesDialog epd(properties);
  if (epd.run() == EnginePropertiesDialog::Response::OK)
  {
    epd.saveProperties(properties);
  }
}

bool MainWindow::on_delete_event(GdkEventAny* event)
{
  //TODO: Dialog
  return ap.isSimulationOn();
}