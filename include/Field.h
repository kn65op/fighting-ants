/* 
 * File:   Field.h
 * Author: tomko
 *
 * Created on 24 lipiec 2012, 18:55
 */

#ifndef FIELD_H
#define	FIELD_H

#include "Direction.h"

/**
 * @brief Class reprezents one field from ground.
 */
class Field
{
public:
  /**
   * Default constructor.
   */
  Field();
  /**
   * Copy constructor, for now it's not done.
   * @param orig Original Field.
   */
  Field(const Field& orig) = delete;
  /**
   * Default destructor.
   */
  virtual ~Field();
  
  /**
   * Returns red element of field color.
   * @return Red color.
   */
  double getRColor() const;
  /**
   * Returns green element of field color.
   * @return Green color.
   */
  double getGColor() const;
  /**
   * Returns blue element of field color.
   * @return Blue color.
   */
  double getBColor() const;

  /**
   * Returns information if this type of field can be changed into food.
   * @return true if this type of field can be changed into food, false otherwise.
   */
  bool canBeChangedIntoFood() const;

  /**
   * Creates path on this field.
   * @param id This path nest id.
   */
  void makeSmell(int id);

  /**
   * Creates path with direction on field.
   * @param id Nest id.
   * @param dir Direction, where to go next.
   */
  void makeSmell(int id, Direction dir);

  /**
   * Make smell less perceptible. Finally the smell disappear.
   */
  void flowAwaySmell();

  /**
   * Checks if is smell on field.
   * @param id Nest id.
//   * @return true if here it's smell, false otherwise.
   */
  bool isSmell(int id);

  /**
   * Get value of smell.
   * @param id Nest id.
   * @return Value of smell.
   */
  double getSmell(int id);

  /**
   * Get direction.
   * @param id Nest id.
   * @return Direction.
   */
  Direction getDirection(int id) const
  {
    if (smell_id != id)
    {
      return Direction::NO_DIRECTION;
    }
    return direction;
  }

  static void setSmell_time(int smell_time)
  {
    smell_time = 1 / static_cast<double>(smell_time);
  }


  
protected:
  /** Blue element of field color.
   */
  double bcolor;
  /** Green element of field color.
   */
  double gcolor;
  /** Red element of field color.
   */
  double rcolor;

  /** Indicates if this field can be changed into food
   */
  bool can_be_changed_into_food;
  
  /** path to food.
   */
  double smell;
  /** nest id, which made path to food
   */
  int smell_id;

  /** direction 
   */
  Direction direction;

private:
  static double smell_time;
};

#endif	/* FIELD_H */

