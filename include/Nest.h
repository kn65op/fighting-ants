/* 
 * File:   Nest.h
 * Author: tomko
 *
 * Created on 24 lipiec 2012, 16:23
 */

#ifndef NEST_H
#define	NEST_H

#include <list>

#include "Ant.h"

/**
 * @brief Class reprezents nest.
 * 
 * 
 */
class Nest
{
public:
  /**
   * Default contructor.
   */
  Nest();
  /**
   * Default destructor.
   */
  virtual ~Nest();

  /**
   * Proced job in simulation which nest do (check if some Ants going out form nest).
   * @return List with pointers to Ant which went out in std::list<Ant*>.
   */
  std::list<Ant*> nextStep();
private:
  //number of ants in nest
  int ants_in;
  //nest id (id differ ants from different nests).
  int id;
  //food to eat
  int food;


};

#endif	/* NEST_H */

