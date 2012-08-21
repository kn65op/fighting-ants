/* 
 * File:   ApplicationController.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 18:22
 */

#include "../include/ApplicationController.h"
#include "../include/GroundArea.h"

#include <chrono>

ApplicationController::ApplicationController()
{
}

ApplicationController::~ApplicationController()
{
}

void ApplicationController::startSimulation()
{
  /**
  for (int i=0; i<100; ++i)
  {
    ants.push_back(new Ant());
  }*/
  //for test one nest created
  initSimulation();

  simulate = true;
  simulation_thread = new std::thread(&ApplicationController::processSimulation, this);
}

void ApplicationController::initSimulation()
{
  nests[1] = new Nest(1, 5);
  ground->setSize(100, 100);

  //antmax time
  Ant::setMaxTime(1000);

  paintArea();
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
  while (simulate)
  {
    stepSimulation();
  }
}

void ApplicationController::stepSimulation()
{
  //simulate ants
  for (auto ant : ants) //pinter to Ant
  {
    if (!ant->move(*ground)) //ant moves, if false it go to nest
    {
      nests[ant->getId()]->addAnt(ant);
      ant = 0; //remove ant from list
    }
  }
  //remove ant which come into nest

  ants.remove_if([](Ant * ant)
  {
    return !ant;
  });

  //simulate nests
  std::list<Ant*> tmp;
  for (auto & pair : nests) //std::pair<int, Nest*>
  {
    tmp = pair.second->nextStep();
    ants.insert(ants.begin(), tmp.begin(), tmp.end());
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  //check food
  ground->checkFood();

  //generate new food
  ground->generateFood();

  paintArea();
}

void ApplicationController::paintArea()
{
  //painting area
  ground->setAnts(&ants);
  ground->setNests(&nests);
  Glib::RefPtr<Gdk::Window> win = ground->get_window();
  if (win)
  {
    Gdk::Rectangle r(0, 0, ground->get_allocation().get_width(), ground->get_allocation().get_height());
    win->invalidate_rect(r, false);
  }
}