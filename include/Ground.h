/* 
 * File:   Ground.h
 * Author: tomko
 *
 * Created on 24 lipiec 2012, 16:17
 */

#ifndef GROUND_H
#define	GROUND_H


#include <vector>
#include <list>

#include "Field.h"
#include "Ant.h"
#include "Nest.h"

/**
 * @brief Class representing place ehere ants can walk.
 *
 * 
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

  /**
   * Set size of ground.
   * @param l Length of ground.
   * @param w Width of ground.
   */
  void setSize(int l, int w);
private:

  /**
   * Creates map with size from length and width.
   */
  void createBlankMap();
  /**
   * Deletes map.
   */
  void deleteMap();

  int length, width;

protected:
  /** Container for field as a row of map
   */
  typedef std::vector<Field*> row_type;
  /** Container for rows as a map
   */
  typedef std::vector<row_type*> map_type;
  /** Container for ants.
   */

  /** Map of fields.
   */
  map_type map;

  //size
  typedef std::list<Ant*> ants_type;
  /** Container for nests
   */
  typedef std::list<Nest*> nests_type;

  /** Ants, which are visible on ground
   */
  ants_type ants;

  /** Nests, which remains on gorund
   */
  nests_type nests;
};

#endif	/* GROUND_H */

