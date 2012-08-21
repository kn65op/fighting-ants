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
#include <map>

#include "Field.h"
#include "Ant.h"
#include "Nest.h"

#include <UsesRandom.h>

/**
 * @brief Class representing place ehere ants can walk.
 *
 * 
 */

class Ground : private THelper::UsesRandom
{
public:
  /** Container for Ants
   */
  typedef std::list<Ant*>* ants_type;
  /** Container for nests
   */
  typedef std::map<int, Nest*>* nests_type;

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
   * Set size of ground. It also creates ground.
   * @param l Length of ground.
   * @param w Width of ground.
   */
  void setSize(int l, int w);
  /**
   * Checks if coordinates are laying in ground.
   * @param x X coordinate.
   * @param y Y coordinate.
   * @return true if coordinates lay in groud, else otherwise.
   */
  bool checkifInGround(int x, int y);

  /**
   * Sets ants to paint.
   * @param ants Ants to paint.
   */
  void setAnts(ants_type ants)
  {
    this->ants = ants;
  }

  /**
   * Sets nests to paint.
   * @param nests Nests to paint.
   */
  void setNests(nests_type nests)
  {
    this->nests = nests;
  }

  /**
   * Checks if some food are empty and generate randomly new food.
   */
  void checkFood();

  /**
   * Generates new food on ground corresponding to parameters (i.e. probability of generation new food).
   */
  void generateFood();

  /**
   * Checks if on field on this coordinates is food.
   * @param x X coordinate.
   * @param y Y coordinate.
   * @return true if on this field is food, else otherwise.
   */
  bool isFood(int x, int y) const;

  /**
   * Get food from field and return food which was gotten.
   * @param x X coordinate.
   * @param y Y coordinate.
   * @param requested_food Food which are requested to get.
   * @return Amount of food which was gotten.
   */
  int getFoodFromField(int x, int y, int requested_food) const;
private:
  /**
   * Creates map with size from length and width.
   */
  void createBlankMap();
  /**
   * Deletes map.
   */
  void deleteMap();

  /**
   * Deletes row and column distributions.
   */
  void deleteDistributions();
  /**
   * Creates row and column distributions.
   */
  void makeDistributions();

  //distribution for different purposes
  std::uniform_int_distribution<> start_food_distribution;
  std::uniform_int_distribution<> new_food_distribution;
  std::uniform_int_distribution<> *row_distribution;
  std::uniform_int_distribution<> *column_distribution;


protected:
  /** true if map is ready, false otherwise
   */
  bool is_map;
  /** length of map
   */
  int length;
  /** width of map
   */
  int width;

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


  /** Ants, which are visible on ground
   */
  ants_type ants;

  /** Nests, which remains on gorund
   */
  nests_type nests;
};

#endif	/* GROUND_H */

