/* 
 * File:   Food.h
 * Author: tomko
 *
 * Created on 20 sierpień 2012, 14:24
 */

#ifndef FOOD_H
#define	FOOD_H

#include "Field.h"

/**
 * @brief Class represents food laying on ground.
 * 
 */
class Food : public Field
{
public:
  /**
   * Default constructor.
   */
  Food();
  /**
   * Copying is forbidden.
   */
  Food(const Food& orig) = delete;
  /**
   * Default destructor.
   */
  virtual ~Food();

  /**
   * Get food from field.
   * @param n Requested food to take.
   * @return Real food taken.
   */
  int getFood(int n);

  /**
   * Checks if food is empty.
   * @return true if food is empty, false otherwise.
   */
  bool isEmpty();
private:
  int amount;
};

#endif	/* FOOD_H */

