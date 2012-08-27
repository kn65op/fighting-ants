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
 * Nest task is storaging food for ants and making new ants. During this task it's important to keep some amount of food all time.
 */
class Nest
{
public:
  /**
   * Contructor which creates ants in nest.
   * @param id Nest id.
   */
  Nest(int id);
  /**
   * Default destructor.
   */
  virtual ~Nest();

  /**
   * Proced job in simulation which nest do (check if some Ants going out form nest). Also produce new ants if it's possible.
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

  /**
   * Add ant to nest.
   * @param ant Ant to add to nest.
   */
  void addAnt(Ant* ant);

  /**
   * Set nest position.
   * @param x X coordinate.
   * @param y Y coordinate.
   */
  void setPosition(int x, int y);

  /**
   * Set starting number of ants.
   * @param n Number of ants, which nest will have on beginning.
   */
  void setStartingAnts(int n);

  /**
   * Remove ants from counting.
   */
  void removeAnt();
  
private:
  //nest id (id differ ants from different nests).
  int id;
  //food to eat
  double food;
  //coordinates
  int x, y;
  //ants in nest
  std::list<Ant*> ants;
  //number of all ants from this nest
  int number_of_ants;

  void produceAnts();
};

#endif	/* NEST_H */

