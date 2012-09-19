/* 
 * File:   ApplicationControllerGtkmm.cpp
 * Author: tomko
 * 
 * Created on 19 wrzesień 2012, 20:49
 */

#include "../include/ApplicationControllerGtkmm.h"

#include <string>

ApplicationControllerGtkmm::ApplicationControllerGtkmm() : ApplicationController()
{
}

ApplicationControllerGtkmm::~ApplicationControllerGtkmm()
{
}

void ApplicationControllerGtkmm::showMessage()
{
  Glib::ustring message;
  std::map<int, Nest*>::iterator it, end;
  end = nests.end();
  for (it = nests.begin(); it != end; it++)
  {
    message += "Gniazdo " + std::to_string(it->first) + " ma " + std::to_string(it->second->getNumberOfAnts()) + " mrówek. ";
  }
  statusbar->remove_all_messages();
  statusbar->push(message);
}

