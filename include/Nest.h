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
 * @brief Class represents nest.
 * 
 * 
 */
class Nest
{
public:
  /**
   * Contructor which creates ants in nest.
   * @param n Number of ants which will be created in nest.
   */
  Nest(int n);
  /**
   * Default destructor.
   */
  virtual ~Nest();

  /**
   * Proced job in simulation which nest do (check if some Ants going out form nest).
   * @return List with pointers to Ant which went out in std::list<Ant*>.
   */
  std::list<Ant*> nextStep();

  /**
   * Returns X coordinate of nest.
   * @return X coordinate.
   */
  int getX() const
  {
    return x;
  }

  /**
   * Returns Y cooridinate of nest.
   * @return Y coordinate.
   */
  int getY() const
  {
    return y;
  }

  /**
   * Add food to nest storage.
   * @param amount Amount of food to add to nest.
   */
  void addFood(int amount);

  
private:
  //nest id (id differ ants from different nests).
  int id;
  //food to eat
  int food;
  //coordinates
  int x, y;
  //ants in nest
  std::list<Ant*> ants;


};

#endif	/* NEST_H */

