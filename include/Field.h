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
private:

};

#endif	/* FIELD_H */

