/* 
 * File:   Properties.h
 * Author: tomko
 *
 * Created on 30 sierpień 2012, 14:05
 */

#ifndef PROPERTIES_H
#define	PROPERTIES_H

#include <string>
#include <list>

/**
 * @brief This class holds and manage all parameters for simulation and engine.
 * 
 * 
 */
class Properties
{
public:
  /** Default constructor. */
  Properties();
/** Default destructor. */
  virtual ~Properties();

  int GetAmount_of_food() const
  {
    return amount_of_food;
  }

  void SetAmount_of_food(int amount_of_food)
  {
    this->amount_of_food = amount_of_food;
  }

  int GetAnt_can_walk() const
  {
    return ant_can_walk;
  }

  void SetAnt_can_walk(int ant_can_walk)
  {
    this->ant_can_walk = ant_can_walk;
  }

  int GetNests() const
  {
    return nests;
  }

  void SetNests(int nests)
  {
    this->nests = nests;
  }
  
  double GetPlacing_food() const
  {
    return placing_food;
  }

  void SetPlacing_food(double placing_food)
  {
    this->placing_food = placing_food;
  }

  double GetStarting_food() const
  {
    return starting_food;
  }

  void SetStarting_food(double starting_food)
  {
    this->starting_food = starting_food;
  }

  int GetStarting_ants() const
  {
    return starting_ants;
  }

  void SetStarting_ants(int starting_ants)
  {
    this->starting_ants = starting_ants;
  }

  int GetSimulation_interval() const
  {
    return simulation_interval;
  }

  void SetSimulation_interval(int simulation_interval)
  {
    this->simulation_interval = simulation_interval;
  }

  int GetHeight() const
  {
    return height;
  }

  void SetHeight(int height)
  {
    this->height = height;
  }

  int GetLength() const
  {
    return length;
  }

  void SetLength(int length)
  {
    this->length = length;
  }


  /**
   * Save properties to file.
   * @param file Filename.
   */
  void saveToFile(std::string file);

  /**
   * Read properties from file.
   * @param file Filename.
   */
  void loadFromFile(std::string file);

private:
  /** number of starting ants */
  int starting_ants;
  /** number of nest */
  int nests;
  /** frequency of placing food */
  double placing_food;
  /** number of starting food */
  double starting_food;
  /** number of fields ant can walk */
  int ant_can_walk;
  /** amount of food */
  int amount_of_food;
  /** ground length */
  int length;
  /** ground height */
  int height;

  /** simulation interval */
  int simulation_interval;

  std::list<int> nests_x;
  std::list<int> nests_y;

};

#endif	/* PROPERTIES_H */

