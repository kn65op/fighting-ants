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
  //TODO: new thread
  simulate = true;
}

void ApplicationController::stopSimulation()
{
  simulate = false;
}

