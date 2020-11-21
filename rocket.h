// Filename: rocket.h
// Description: Headerfile for rocket.cpp

#ifndef ROCKET_H
#define ROCKET_H

//#include "macros.h"
#include "rocket.h"
#include "debris.h"
#include "source.h"

struct Rocket{
  int x;  // x-axis position
  int y;
  int score;
  char avatar;

  void resetRocketPosition();
  void addScore();
  void updateRocket1Position(char direction);
  void updateRocket2Position(char direction);
};

#endif
