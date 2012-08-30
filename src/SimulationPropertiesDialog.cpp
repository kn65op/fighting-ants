/* 
 * File:   SimulationPropertiesDialog.cpp
 * Author: tomko
 * 
 * Created on 29 sierpień 2012, 15:23
 */

#include <gtkmm-3.0/gtkmm/adjustment.h>

#include "../include/SimulationPropertiesDialog.h"

SimulationPropertiesDialog::SimulationPropertiesDialog(Properties properties) :
starting_ants_button(Gtk::Adjustment::create(properties.GetStarting_ants(), 1, 100, 1, 10, 0.0)),
nests_button(Gtk::Adjustment::create(properties.GetNests(), 1, 10, 1, 2, 0.0)),
placing_food_button(Gtk::Adjustment::create(properties.GetPlacing_food(), 0, 1, 0.0001, 0.1, 0.0)),
starting_food_button(Gtk::Adjustment::create(properties.GetStarting_food(), 0, 1, 0.0001, 0.1, 0.0)),
ant_can_walk_button(Gtk::Adjustment::create(properties.GetAnt_can_walk(), 0, 100000, 1, 100, 0.0)),
amount_of_food_button(Gtk::Adjustment::create(properties.GetAmount_of_food(), 1, 1000, 1, 10, 0.0))
{
}

SimulationPropertiesDialog::~SimulationPropertiesDialog()
{
}

