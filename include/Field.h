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
private:
  //colors of field
  double bcolor;
  double gcolor;
  double rcolor;
};

#endif	/* FIELD_H */

