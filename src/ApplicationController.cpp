/* 
 * File:   ApplicationController.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 18:22
 */

#include "../include/ApplicationController.h"

ApplicationController::ApplicationController()
{
  ground.setSize(400,300);
}

ApplicationController::~ApplicationController()
{
}

void ApplicationController::startSimulation()
{
  simulate = true;
  simulation_thread = new std::thread(&ApplicationController::processSimulation, this);
}

void ApplicationController::stopSimulation()
{
  simulate = false;
  simulation_thread->join();
  delete simulation_thread;
  simulation_thread = 0;
}

void ApplicationController::processSimulation()
{
  while(simulate)
  {
    //TODO: Do simulation
  }
}

