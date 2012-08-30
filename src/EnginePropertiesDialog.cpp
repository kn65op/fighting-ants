/* 
 * File:   EnginePropertiesDialog.cpp
 * Author: tomko
 * 
 * Created on 30 sierpień 2012, 14:05
 */

#include "../include/EnginePropertiesDialog.h"

EnginePropertiesDialog::EnginePropertiesDialog(Properties properties) :
interval_label("Okres pomiędzy kolejnymi krokami symulacji (w ms):"),
interval_button(Gtk::Adjustment::create(properties.GetSimulation_interval(), 0, 1000, 1, 10, 0.0))
{
  
  //boxes
  get_content_area()->pack_start(main_box);

  main_box.pack_start(labels_box);
  main_box.pack_end(buttons_box);

  labels_box.pack_end(interval_label);

  buttons_box.pack_end(interval_button);

  add_button("Anuluj", Response::CANCEL);
  add_button("OK", Response::OK);
  
  main_box.show();
  main_box.show_all_children(true);
}

EnginePropertiesDialog::~EnginePropertiesDialog()
{
  
}

void EnginePropertiesDialog::saveProperties(Properties& properties)
{
  properties.SetSimulation_interval(interval_button.get_value_as_int());
}

