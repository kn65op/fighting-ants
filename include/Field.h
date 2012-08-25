/* 
 * File:   Field.h
 * Author: tomko
 *
 * Created on 24 lipiec 2012, 18:55
 */

#ifndef FIELD_H
#define	FIELD_H

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
   * Make smell less perceptible. Finally the smell disappear.
   */
  void flowAwaySmell();

  /**
   * Checks if is smell on field.
   * @param id Nest id.
   * @return true if here it's smell, false otherwise.
   */
  bool isSmell(int id);
  
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
};

#endif	/* FIELD_H */

