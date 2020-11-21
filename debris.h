// Description: Headerfile for debris.cpp

#ifndef DEBRIS_H
#define DEBRIS_H

#include "debris.h"
#include "source.h"

/*Declare struct Debris with 3 members and a member function
x -> x-coordinate of debris
y -> y-coordinate of debris
direction -> direction of debris' movement i.e. left or right

updateDebrisPosition -> to move debris during the game
*/
struct Debris
{
  int x;
  int y;
  char direction;

  void updateDebrisPosition();
};


/*Functions related to debris*/
void createDebris(Debris debrisList[], int numdebris);
void movingDebris(Debris debrisList[], int numdebris);

#endif
