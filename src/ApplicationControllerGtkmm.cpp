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
  message = "Liczba mrówek w gniazdach: ";
  for (it = nests.begin(); it != end; ++it)
  {
    message += std::to_string(it->first) + ": " + std::to_string(it->second->getNumberOfAnts()) + " | ";
  }
  message = message.substr(0, message.length() - 3);
  statusbar->remove_all_messages();
  statusbar->push(message);
}

