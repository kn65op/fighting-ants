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
  //antmax time
  simulate = false;
}

ApplicationController::~ApplicationController()
{
  deleteAll();
}

void ApplicationController::startSimulation()
{
  /**
  for (int i=0; i<100; ++i)
  {
    ants.push_back(new Ant());
  }*/
  //for test one nest created

  simulate = true;
  simulation_thread = new std::thread(&ApplicationController::processSimulation, this);
}

void ApplicationController::deleteAll()
{
  //remove ants
  std::for_each(ants.begin(), ants.end(), [](Ant * ant)
  {
    delete ant;
  });
  ants.clear();


  //destroy nests.
  for (auto & pair : nests)
  {
    delete pair.second;
  };
  nests.clear();
}

void ApplicationController::initSimulation()
{
  deleteAll();
  for (int i=0; i < nests_number; ++i)
  {
    nests[i] = new Nest(i);
    nests[i]->setPosition((i + 1) * 5, (i + 1) * 5);
    nests[i]->setStartingAnts(starting_ants_number);
  }
 /* 
  //create field 
  nests[10] = new Nest(10); //TODO: losowa pozycja lub coś
  nests[10]->setPosition(40,55);
  nests[10]->setStartingAnts(15);

  nests[20] = new Nest(20);
  nests[20]->setPosition(55,40);
  nests[20]->setStartingAnts(15);

  nests[30] = new Nest(30);
  nests[30]->setPosition(40,40);
  nests[30]->setStartingAnts(15);
  
  nests[40] = new Nest(40);
  nests[40]->setPosition(55,55);
  nests[40]->setStartingAnts(15);
  */

  ground->createMap(length, height, start_food_proability, place_food_proability);

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
  std::this_thread::sleep_for(std::chrono::milliseconds(interval));
  }
}

void ApplicationController::stepSimulation()
{
  ground->lock();
  //simulate ants
  for (auto & ant : ants) //pinter to Ant
  {
    if (ant->isDead())
    {
      nests[ant->getId()]->removeAnt();
      delete ant; //TODO: leave food on ground
      ant = nullptr;
    }
    else if (!ant->move(*ground)) //ant moves, if false it go to nest
    {
      Nest *tmp = nests[ant->getId()];
      if (ant->isDead()) //after fighting
      {
        tmp->removeAnt();
        delete ant;
      }
      else
      {
	tmp->addAnt(ant);
        tmp->addFood(ant->getFood());
      }
      ant = nullptr; //remove ant from list
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

  //make smell to flow away
  ground->proceedNextStep();

  //check food
  ground->checkFood();

  //generate new food
  ground->generateFood();

  ground->unlock();
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

void ApplicationController::setProperties(Properties& properties)
{
  starting_ants_number = properties.GetStarting_ants();
  nests_number = properties.GetNests();
  start_food_proability = properties.GetStarting_food();
  place_food_proability = properties.GetPlacing_food();
  Ant::setMaxTime(properties.GetAnt_can_walk());
  ground->setAmountOfFood(properties.GetAmount_of_food());
  interval = properties.GetSimulation_interval();
  length = properties.GetLength();
  height = properties.GetHeight();
}