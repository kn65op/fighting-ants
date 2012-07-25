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
#include "Ground.h"

#include <thread>

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
   * Function stops simulation.
   */
  void stopSimulation();

  /**
   * Function resets simulation to initial state.
   */
  void resetSimulation();
  
private:
  //ants
  std::list<Ant*> ants;
  //nests
  std::list<Nest*> nests;
  //ground
  Ground ground;

  //threads
  std::thread *simulation_thread;
  //if simulation should continue
  bool simulate;

  /**
   * Processing simulation.
   */
  void processSimulation();
};

#endif	/* APPLICATIONCONTROLLER_H */
