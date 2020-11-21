// Filename: game.cpp
// Description: Functions for implementation of Space Race game

#include <iostream>
#include <stdio.h>          // call getchar()
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>
#include <unistd.h>         // to use the usleep()
#include <chrono>           // to track time interval

#include "game.h"
#include "map.h"
#include "rocket.h"
#include "debris.h"
#include "input.h"
#include "user.h"

using namespace std;

#define PAUSELENGTH 1000 * 10   // the suspension duration during the game runtime

/*Function to get user's input for moving the rockets*/
char getRocketDirection()
{
  char a = getchar();
  return a;
}

/*Function to check if the rocket collides with the debris
Check the coordinates of the rocket against all debris in the debrislist
If collision occurs, the rocket's position will be reset to the startling line.
*/
void checkCollision(Debris debrisList[], Rocket &rocket, int numdebris)
{
  for (int i = 0; i < numdebris; i++){
    if ((rocket.x == debrisList[i].x) && (rocket.y == debrisList[i].y)){
      rocket.resetRocketPosition();
      break;
    }
  }
}

/* Function to prompt the selection of diffficulty level and
return the difficulty level selected by the players.
The number of debris in the game will be updated in this function
*/
int level(int &numdebris){
  int difficultylevel;
  cout << "Please select the difficulty level (1/2/3): ";
  cin >> difficultylevel;
  cout << "\n";
  if (difficultylevel == 1) numdebris = 50;
  else if (difficultylevel == 2) numdebris = 70;
  else if (difficultylevel == 3) numdebris = 90;
  return difficultylevel;
}

void game(Debris debrisList[], User & user1, User & user2, vector<User> &userlist, int numdebris){
  int difficultylevel = level(numdebris);
  char map[height][width];
  for (int i = 0; i < userlist.size() ; i++){
    if (user1.name == userlist[i].name){
      user1 = userlist[i];
    }
  }
  for (int j = 0; j < userlist.size() ; j++){
    if (user2.name == userlist[j].name){
      user2 = userlist[j];
    }
  }
  Rocket rocket1 = {12, height - 2, 0, user1.u_avatar};
  Rocket rocket2 = {38, height - 2, 0, user2.u_avatar};
  createDebris(debrisList, numdebris);
  for (int i = 0; i < numdebris; i++) cout << debrisList[i].x << "|" << debrisList[i].y << endl;
  //initialize();
  bool gameStatus = true;
  auto startTime = chrono::system_clock::now();
  while (gameStatus){
      auto endTime = chrono::system_clock::now();
      cout << "\n\n";
      updateMap(map, rocket1, rocket2, numdebris, debrisList);
      cout << setw(20) << "Time : ";
      cout << chrono::duration_cast<chrono::seconds> (endTime - startTime).count() << " / 60 seconds" << endl;
      char a = getRocketDirection();
      cout << "a " << a;
      if (a == 'w' || a == 's') rocket1.updateRocket1Position(a);
      else if( a == 'u' || a =='j') rocket2.updateRocket2Position(a);
      movingDebris(debrisList, numdebris);
      checkCollision(debrisList, rocket1, numdebris);
      checkCollision(debrisList, rocket2, numdebris);
      usleep(PAUSELENGTH);
      endTime = chrono::system_clock::now();
      if (endTime - startTime > chrono::minutes(1)){
        cout << "\n\n";
        updateMap(map,rocket1, rocket2, numdebris, debrisList);
        cout << setw(20) << "Time : ";
        cout << chrono::duration_cast<chrono::seconds> (endTime - startTime).count() << " / 60 seconds" << endl;
        gameStatus = false;
        usleep(5);
        break;
      }
  }
  user1.updateScore(rocket1.score * difficultylevel, userlist);
  user2.updateScore(rocket2.score * difficultylevel, userlist);
  cout << "\n" ;
  displayLeaderBoard(userlist);

}
