/* 
 * File:   Ground.h
 * Author: tomko
 *
 * Created on 24 lipiec 2012, 16:17
 */

#ifndef GROUND_H
#define	GROUND_H

#include "Nest.h"
#include "Ant.h"

#include <list>

/**
 * Class representing place ehere ants can walk.
 */
class Ground
{
public:
  /**
   * Default constructor.
   */
  Ground();
  /**
   * Default destructor.
   */
  virtual ~Ground();

  /**
   * Function proceedes next step of simulation .
   */
  void proceedNextStep();
private:
  //size
  int length, width;
};

#endif	/* GROUND_H */

