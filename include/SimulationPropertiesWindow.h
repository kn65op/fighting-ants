/* 
 * File:   SimulationPropertiesWindow.h
 * Author: tomko
 *
 * Created on 29 sierpień 2012, 15:23
 */

#ifndef SIMULATIONPROPERTIESWINDOW_H
#define	SIMULATIONPROPERTIESWINDOW_H

#include <gtkmm-3.0/gtkmm.h>

class SimulationPropertiesWindow : public Gtk::Window
{
public:
  /**
   * Default constructor.
   */
  SimulationPropertiesWindow();
  
  /**
   * Copying is not allowed.
   * @param orig nothing.
   */
  SimulationPropertiesWindow(const SimulationPropertiesWindow& orig) = delete;
  
  /**
   * Default destructor.
   */
  virtual ~SimulationPropertiesWindow();
private:

  /** number of starting ants */
  int starting_ants;
  /** number of nest */
  int nests;
  /** frequency of placing food */
  int placing_food;
  /** number of starting food */
  int starting_food;
  /** number of fields ant can walk */
  int ant_can_walk;
  /** amount of food */
  int amount_of_food;

  //fields
  Gtk::SpinButton starting_ants_button;
  Gtk::SpinButton nests_button;
  Gtk::SpinButton placing_food_button;
  Gtk::SpinButton starting_food_button;
  Gtk::SpinButton ant_can_walk_button;
  Gtk::SpinButton amount_of_food_button;
  
};

#endif	/* SIMULATIONPROPERTIESWINDOW_H */

