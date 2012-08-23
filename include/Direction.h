/* 
 * File:   Direction.h
 * Author: tomko
 *
 * Created on 23 sierpień 2012, 14:25
 */

#ifndef DIRECTION_H
#define	DIRECTION_H

/**
 * @brief Class which represents direction.
 * 
 * 
 */
enum class Direction
{
  L,
  R,
  U,
  D,
  UL,
  UR,
  DL,
  DR,
  NO_DIRECTION
};

Direction getDirectionFromDifferenceSigns(int horiz, int vert);

#endif	/* DIRECTION_H */

