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
  /**
   * @brief Class for really unexpected errors, almost impossible.
   * 
   * This excepction should never be thrown.
   */
  class UnexpectedException
  {
  public:
    /**
     * Constructor with setting message .
     * @param mes Message to be setted.
     */
    UnexpectedException(std::string mes)
    {
      message = mes;
    }

    /**
     * Returns message.
     * @return Message as std::string.
     */
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
   * Returns ant's nest id.
   * @return Ant's nest id.
   */
  int getId() const
  {
    return id;
  }
  

  /**
   * Sets ant position to home nest position.
   */
  void setPositionToNestPosition();

  /**
   * Set max time which ant can spend outside nest.
   * @param max_time Time to set.
   */
  static void setMaxTime(int max_time)
  {
    max_time = max_time;
  }

  /**
   * Get blue element of color.
   * @return Blue element of color.
   */
  double getBColor() const;
  /**
   * Get Green element of color.
   * @return Green element of color.
   */
  double getGColor() const;
  /**
   * Get Red element of color.
   * @return Red element of color.
   */
  double getRColor() const;

  /**
   * Get food from ant (and removes it from ant).
   * @return Amount of food which ant carried.
   */
  int getFood() 
  {
    int tmp = food;
    food = 0;
    return tmp;
  }
  

private:
  //distrubution for movement
  std::uniform_int_distribution<> *dis;

  //nest id from which ant come from
  int id;
  //time (in steps) which ants spent on ground (means that ant don't eat)
  int time;

  //maksimum time which ant can spent on ground without eating
  static int max_time;

  //ant position
  int x, y;
  
  //nest position
  int nest_x, nest_y;

  //carried food
  int food;
  static int can_carry_food;

  // funtions to moving in different ways.
  void freeMove(Ground & ground);
  void getFood(Ground & ground);
  void goToNest(Ground & ground);

  //pointer to move function
  void (Ant::*move_function)(Ground & ground);
};

#endif	/* ANT_H */

