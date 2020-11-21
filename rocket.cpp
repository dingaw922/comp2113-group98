// Filename: rocket.cpp
// Description: Functions to update rocket position

#include "rocket.h"
#include "debris.h"

/* Function to reset the rocket's position when it collides with debris */
void Rocket::resetRocketPosition()
{
  y = height - 2;
}

/* Function to add score to the runtime score when the rocket finishes a lap */
void Rocket::addScore()
{
  score++;
}

/* Function to update the position of Rocket of User 2.
Player 2 will control the rocket using key 'w' as up key and 's' as down key.
Rocket position will be reset if it reach the top of the map (i.e. y- coordinate is 0)
and one point will be added.
*/ 
void Rocket::updateRocket1Position(char direction)
{
  if (direction == 'w' && y > 0) y--;
  else if (direction == 's' && y < (height -2)) y++;
  else if (y == 0) {
    resetRocketPosition();
    addScore();
  }
}

/* Function to update the position of Rocket of User 2.
User 2 will control the rocket using key 'u' as up key and 'j' as down key.
Rocket position will be reset if it reach the top of the map (i.e. y- coordinate is 0)
and one point will be added.
*/ 
void Rocket::updateRocket2Position(char direction)
{
  if (direction =='u' && y > 0) y--;
  else if (direction =='j' && y < (height -2)) y++;
  else if (y == 0) {
    resetRocketPosition();
    addScore();
  }
}
