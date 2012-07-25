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
 * @brief Class representing place ehere ants can walk.
 *
 * 
 * /
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

  /**
   * Set size of ground.
   * @param l Length of ground.
   * @param w Width of ground.
   */
  void setSize(int l, int w);
private:
  //size
  int length, width;
};

#endif	/* GROUND_H */

