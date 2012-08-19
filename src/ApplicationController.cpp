/* 
 * File:   ApplicationController.cpp
 * Author: tomko
 * 
 * Created on 24 lipiec 2012, 18:22
 */

#include "../include/ApplicationController.h"

#include <chrono>

ApplicationController::ApplicationController()
{
}

ApplicationController::~ApplicationController()
{
}

void ApplicationController::startSimulation()
{
  for (int i=0; i<100; ++i)
  {
    ants.push_back(new Ant());
  }
  nests.push_back(new Nest());
  ground->setSize(100, 100);
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
  while (simulate)
  {
    //simulate ants
    for (auto ant : ants) //pinter to Ant
    {
      if (!ant->move(*ground)) //ant moves, if false it go to nest
      {
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
    for (auto nest : nests) //pointer to nest
    {
      tmp = nest->nextStep();
      ants.insert(ants.begin(), tmp.begin(), tmp.end());
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    //painting area
    ground->setAnts(&ants);
    ground->setNests(&nests);
    Glib::RefPtr<Gdk::Window> win = ground->get_window();
    if (win)
    {
      Gdk::Rectangle r(0,0, ground->get_allocation().get_width(), ground->get_allocation().get_height());
      win->invalidate_rect(r, false);
    }

  }
}

