/* 
 * File:   SimulationPropertiesDialog.h
 * Author: tomko
 *
 * Created on 29 sierpień 2012, 15:23
 */

#ifndef SIMULATIONPROPERTIESDIALOG_H
#define SIMULATIONPROPERTIESDIALOG_H

#include <gtkmm-3.0/gtkmm.h>

class SimulationPropertiesDialog : public Gtk::Dialog
{
public:
  /**
   * Default constructor.
   */
  SimulationPropertiesDialog();
  
  /**
   * Copying is not allowed.
   * @param orig nothing.
   */
  SimulationPropertiesDialog(const SimulationPropertiesDialog& orig) = delete;
  
  /**
   * Default destructor.
   */
  virtual ~SimulationPropertiesDialog();
private:
  //fields
  Gtk::SpinButton starting_ants_button;
  Gtk::SpinButton nests_button;
  Gtk::SpinButton placing_food_button;
  Gtk::SpinButton starting_food_button;
  Gtk::SpinButton ant_can_walk_button;
  Gtk::SpinButton amount_of_food_button;
  
};

#endif	/* SIMULATIONPROPERTIESDIALOG_H */

