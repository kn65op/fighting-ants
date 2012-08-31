/* 
 * File:   ApplicationController.h
 * Author: tomko
 *
 * Created on 24 lipiec 2012, 18:22
 */

#ifndef APPLICATIONCONTROLLER_H
#define	APPLICATIONCONTROLLER_H

#include "Ant.h"
#include "Nest.h"
#include "Properties.h"

#include <thread>
#include <atomic>
#include <map>


class GroundArea;

/**
 * @brief Class which control simulation.
 */
class ApplicationController
{
public:
  /**
   * Default constructor.
   */
  ApplicationController();
  /**
   * Default destructor.
   */
  virtual ~ApplicationController();

  /**
   * Function starts simulation.
   */
  void startSimulation();

  /**
   * Initializate simulation (so it can work).
   */
  void initSimulation();

  /**
   * Function stops simulation.
   */
  void stopSimulation();

  /**
   * Procced one step of simulation.
   */
  void stepSimulation();

  /**
   * Function resets simulation to initial state.
   */
  void resetSimulation();
  /**
   * Set ground to application controller.
   * @param ground Ground* to set.
   */
  void setGround(GroundArea* ground)
  {
    this->ground = ground;
  }

  bool isSimulationOn() const
  {
    return simulate;
  }

  /**
   * Set all setting to passed properties. Some of them affect only map creating.
   * @param properties Properties to set.
   */
  void setProperties(Properties & properties);
  
private:
  //ants
  std::list<Ant*> ants;
  //nests
  std::map<int, Nest*> nests;
  //ground
  GroundArea* ground;

  //threads
  std::thread *simulation_thread;
  //if simulation should continue
  std::atomic<bool> simulate;

  //properties
  int starting_ants_number;
  int nests_number;

  /**
   * Processing simulation.
   */
  void processSimulation();

  void paintArea();
};

#endif	/* APPLICATIONCONTROLLER_H */

