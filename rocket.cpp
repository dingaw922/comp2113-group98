// Filename: rocket.cpp
// Description: Functions to update rocket position

#include "rocket.h"
#include "debris.h"
//#include "macros.h"

void Rocket::resetRocketPosition(){
  y = height - 2;
}

void Rocket::addScore(){
  score++;
}
  //user 1 : w,s ; user 2: u, j;
void Rocket::updateRocket1Position(char direction){
  if (direction == 'w' && y > 0) y--;
  else if (direction == 's' && y < (height -2)) y++;
  else if (y == 0) {
    resetRocketPosition();
    addScore();
  }
}

void Rocket::updateRocket2Position(char direction){
  if (direction =='u' && y > 0) y--;
  else if (direction =='j' && y < (height -2)) y++;
  else if (y == 0) {
    resetRocketPosition();
    addScore();
  }
}
