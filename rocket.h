// Filename: rocket.h
// Description: Headerfile for rocket.cpp

#ifndef ROCKET_H
#define ROCKET_H

#include "rocket.h"
#include "debris.h"
#include "source.h"

/* Define struct Rocket with 3 members and 4 member functions */
struct Rocket
{
  int x;        // x-coordinate
  int y;        // y-coordinate
  int score;    // runtime score
  char avatar;

  void resetRocketPosition();
  void addScore();
  void updateRocket1Position(char direction);
  void updateRocket2Position(char direction);
};

#endif
