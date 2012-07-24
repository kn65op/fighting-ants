/* 
 * File:   ApplicationController.h
 * Author: tomko
 *
 * Created on 24 lipiec 2012, 18:22
 */

#ifndef APPLICATIONCONTROLLER_H
#define	APPLICATIONCONTROLLER_H

/**
 * Class
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
};

#endif	/* APPLICATIONCONTROLLER_H */

