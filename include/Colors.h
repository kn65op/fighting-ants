/* 
 * File:   Colors.h
 * Author: tomko
 *
 * Created on 19 wrzesień 2012, 19:37
 */

#ifndef COLORS_H
#define	COLORS_H

#include <vector>

/**
 * @brief Class to get different color for different ids.
 * 
 * Now is supported id from 0 to 9.
 */

class Colors
{
public:
  Colors() = delete;
  Colors(const Colors& orig) = delete;
  virtual ~Colors();

  static double getRColor(int id);
  static double getGColor(int id);
  static double getBColor(int id);
private:
  static std::vector<double> r;
  static std::vector<double> g;
  static std::vector<double> b;
};

#endif	/* COLORS_H */

