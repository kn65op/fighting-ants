/* 
 * File:   SimulationPropertiesDialog.h
 * Author: tomko
 *
 * Created on 29 sierpień 2012, 15:23
 */

#ifndef SIMULATIONPROPERTIESDIALOG_H
#define SIMULATIONPROPERTIESDIALOG_H

#include <gtkmm-3.0/gtkmm.h>

#include "Properties.h"

#include <list>

class SimulationPropertiesDialog : public Gtk::Dialog
{
public:

  enum Response
  {
    OK,
    CANCEL
  };

  /**
   * Constructor with properties.
   * @param properties Actual properties.
   */
  SimulationPropertiesDialog(Properties & properties);

  /**
   * Copying is not allowed.
   * @param orig nothing.
   */
  SimulationPropertiesDialog(const SimulationPropertiesDialog& orig) = delete;

  /**
   * Default destructor.
   */
  virtual ~SimulationPropertiesDialog();

  void saveProperties(Properties & properties);

private:
  //fields
  Gtk::SpinButton starting_ants_button;
  Gtk::SpinButton nests_button;
  Gtk::SpinButton placing_food_button;
  Gtk::SpinButton starting_food_button;
  Gtk::SpinButton ant_can_walk_button;
  Gtk::SpinButton amount_of_food_button;
  Gtk::SpinButton length_button;
  Gtk::SpinButton height_button;
  Gtk::SpinButton smell_time_button;

  //labels
  Gtk::Label starting_ants_label;
  Gtk::Label nests_label;
  Gtk::Label placing_food_label;
  Gtk::Label starting_food_label;
  Gtk::Label ant_can_walk_label;
  Gtk::Label amount_of_food_label;
  Gtk::Label length_label;
  Gtk::Label height_label;
  Gtk::Label smell_time_label;

  //boxes
  Gtk::HBox main_box;
  Gtk::VBox labels_box;
  Gtk::VBox buttons_box;

  //boxes for nests
  //Gtk::VBox labels_nests_box;
//  Gtk::Vbox buttons_nests_bos;

  //for nests
  std::list<Gtk::SpinButton*> nests_buttons_xs;
  std::list<Gtk::SpinButton*> nests_buttons_ys;
  std::list<Gtk::Label*> nests_labels_xs;
  std::list<Gtk::Label*> nests_labels_ys;

  std::list<int> old_x;
  std::list<int> old_y;
  
  void change_nests_positions();
  void change_nests_positions(Properties & properties);
  void fillNestPositions(int number);

  bool focus_out_nests_button(GdkEventFocus* f);
  void clearNestsList();
};

#endif	/* SIMULATIONPROPERTIESDIALOG_H */

