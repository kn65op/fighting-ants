/* 
 * File:   SimulationPropertiesDialog.cpp
 * Author: tomko
 * 
 * Created on 29 sierpień 2012, 15:23
 */

#include <gtkmm-3.0/gtkmm/adjustment.h>

#include "../include/SimulationPropertiesDialog.h"

#include <algorithm>
#include <string>

SimulationPropertiesDialog::SimulationPropertiesDialog(Properties & properties) :
starting_ants_label("Początkowa liczba mrówek:"),
starting_ants_button(Gtk::Adjustment::create(properties.GetStarting_ants(), 1, 100, 1, 10, 0.0)),
nests_label("Liczba gniazd:"),
nests_button(Gtk::Adjustment::create(properties.GetNests(), 1, 10, 1, 2, 0.0)),
placing_food_label("Prawdopodobieństwo pojawienia się jedzenia w czasie symulacji:"),
placing_food_button(Gtk::Adjustment::create(properties.GetPlacing_food(), 0, 1, 0.0001, 0.1, 0.0)),
starting_food_label("Prawdopodobieństwo pojawienia się jedzenia na początku na danym polu:"),
starting_food_button(Gtk::Adjustment::create(properties.GetStarting_food(), 0, 1, 0.0001, 0.1, 0.0)),
ant_can_walk_label("Ile pól może przejść mrówka szukając jedzenia:"),
ant_can_walk_button(Gtk::Adjustment::create(properties.GetAnt_can_walk(), 0, 100000, 1, 100, 0.0)),
amount_of_food_label("Ile jedzenia ma być na polu z jedzeniem:"),
amount_of_food_button(Gtk::Adjustment::create(properties.GetAmount_of_food(), 1, 1000, 1, 10, 0.0)),
length_label("Długość planszy: "),
length_button(Gtk::Adjustment::create(properties.GetLength(), 10, 500, 1, 10, 0.0)),
height_label("Szerokość planszy: "),
height_button(Gtk::Adjustment::create(properties.GetHeight(), 10, 500, 1, 10, 0.0))
{
  //setting floats
  placing_food_button.set_digits(4);
  starting_food_button.set_digits(4);

  //showing it

  //boxes
  get_content_area()->pack_start(main_box);

  main_box.pack_start(labels_box);
  main_box.pack_end(buttons_box);

  labels_box.pack_end(height_label);
  labels_box.pack_end(length_label);
  labels_box.pack_end(starting_ants_label);
  labels_box.pack_end(nests_label);
  labels_box.pack_end(placing_food_label);
  labels_box.pack_end(starting_food_label);
  labels_box.pack_end(ant_can_walk_label);
  labels_box.pack_end(amount_of_food_label);

  buttons_box.pack_end(height_button);
  buttons_box.pack_end(length_button);
  buttons_box.pack_end(starting_ants_button);
  buttons_box.pack_end(nests_button);
  buttons_box.pack_end(placing_food_button);
  buttons_box.pack_end(starting_food_button);
  buttons_box.pack_end(ant_can_walk_button);
  buttons_box.pack_end(amount_of_food_button);

  add_button("Anuluj", Response::CANCEL);
  add_button("OK", Response::OK);

  //for nests positions
  nests_button.signal_focus_out_event().connect(sigc::mem_fun(*this, &SimulationPropertiesDialog::focus_out_nests_button));
  
  //showing acutal number of buttons
  change_nests_positions();
  
  main_box.show();
  main_box.show_all_children(true);
}

SimulationPropertiesDialog::~SimulationPropertiesDialog()
{
}

void SimulationPropertiesDialog::saveProperties(Properties& properties)
{
  properties.SetAmount_of_food(amount_of_food_button.get_value_as_int());
  properties.SetAnt_can_walk(ant_can_walk_button.get_value_as_int());
  properties.SetNests(nests_button.get_value_as_int());
  properties.SetPlacing_food(placing_food_button.get_value());
  properties.SetStarting_ants(starting_ants_button.get_value_as_int());
  properties.SetStarting_food(starting_food_button.get_value());
  properties.SetLength(length_button.get_value_as_int());
  properties.SetHeight(height_button.get_value_as_int());
}

void SimulationPropertiesDialog::change_nests_positions()
{
  //showing buttons to select nests positions
  int nests_number = nests_button.get_value_as_int();

  nest_adjustment_x = Gtk::Adjustment::create(1, 1, length_button.get_value(), 1, 10, 0.0);
  nest_adjustment_y = Gtk::Adjustment::create(1, 1, height_button.get_value(), 1, 10, 0.0);

  clearNestsList();
  Gtk::Label* label_tmp;
  Gtk::SpinButton* button_tmp;

  for (int i=0; i < nests_number; ++i)
  {
    label_tmp = new Gtk::Label("Pozycja x gniazda " + std::to_string(i) + ":");
    nests_labels_xs.push_back(label_tmp);
    labels_box.pack_end(*label_tmp);

    label_tmp = new Gtk::Label("Pozycja y gniazda " + std::to_string(i) + ":");
    nests_labels_ys.push_back(label_tmp);
    labels_box.pack_end(*label_tmp);

    button_tmp = new Gtk::SpinButton(nest_adjustment_x);
    nests_buttons_xs.push_back(button_tmp);
    buttons_box.pack_end(*button_tmp);

    button_tmp = new Gtk::SpinButton(nest_adjustment_y);
    nests_buttons_xs.push_back(button_tmp);
    buttons_box.pack_end(*button_tmp);
  }

  labels_box.show_all_children(true);
  buttons_box.show_all_children(true);
  
}

bool SimulationPropertiesDialog::focus_out_nests_button(GdkEventFocus* f)
{
  change_nests_positions();
  return true;
}

void SimulationPropertiesDialog::clearNestsList()
{
  std::for_each(nests_buttons_xs.begin(), nests_buttons_xs.end(), [this](Gtk::SpinButton* button)
  {
    buttons_box.remove(*button);
    delete button;
    button = 0;
  });
  std::for_each(nests_buttons_ys.begin(), nests_buttons_ys.end(), [this](Gtk::SpinButton* button)
  {
    buttons_box.remove(*button);
    delete button;
    button = 0;
  });
  std::for_each(nests_labels_xs.begin(), nests_labels_xs.end(), [this](Gtk::Label* label)
  {
    labels_box.remove(*label);
    delete label;
    label = 0;
  });
  std::for_each(nests_labels_ys.begin(), nests_labels_ys.end(), [this](Gtk::Label* label)
  {
    labels_box.remove(*label);
    delete label;
    label = 0;
  });
}

