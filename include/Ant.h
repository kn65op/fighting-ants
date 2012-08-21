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
#include <string>

class Ground;


/**
 * @brief Class represents ant.
 * 
 * Ant move around ground and search for food, after that it returns to nest to bring food to other ants.
 */
class Ant : private THelper::UsesRandom
{
public:
  class UnexpectedException
  {
  public:
    UnexpectedException(std::string mes)
    {
      message = mes;
    }

    operator std::string()
    {
      return message;
    }
  private:
    std::string message;
  };
  /**
   * Contructor to create Ant from nest.
   * @param id Nest id.
   * @param nx Nest X position.
   * @param ny Nest Y position.
   */
  Ant(int id, int nx, int ny);
  /**
   * Default destructor.
   */
  virtual ~Ant();

  /**
   * Move ant.
   * @param ground Ground on which ant moves.
   * @return true if ant still on ground, false if it go into nest.
   */
  bool move(Ground & ground);
  
  /**
   * Returs X coordinate.
   * @return X coordinate.
   */
  int getX() const
  {
    return x;
  }

  /**
   * Returns Y coordinate.
   * @return Y coordinate.
   */
  int getY() const
  {
    return y;
  }

  /**
   * Sets ant position to home nest position.
   */
  void setPositionToNestPosition();

private:
  //distrubution for movement
  std::uniform_int_distribution<> *dis;

  //nest id from which ant come from
  int id;
  //time (in steps) which ants spent on ground (means that it don't eat)
  int time;

  //maksimum time which ant can spent on ground without eating
  static int max_time;

  //ant position
  int x, y;
  
  //nest position
  int nest_x, nest_y;


  // funtions to moving in different ways.
  void freeMove(Ground & ground);

};

#endif	/* ANT_H */

