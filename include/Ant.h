/* 
 * File:   Ant.h
 * Author: tomko
 *
 * Created on 24 lipiec 2012, 16:23
 */

#ifndef ANT_H
#define	ANT_H

#include <UsesRandom.h>

#include <random>

/**
 * @brief Class represents ant.
 * 
 * 
 */
class Ant : private UsesRandom
{
public:
  /**
   * Default constructor.
   */
  Ant();
  /**
   * Default destructor.
   */
  virtual ~Ant();
private:
  std::uniform_int_distribution<> *dis; 
};

#endif	/* ANT_H */

