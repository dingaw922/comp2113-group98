// Filename: map.cpp
// Description: Functions to implement, update and display map

#include <iostream>
#include <unistd.h>
#include <iomanip>

#include "map.h"
#include "rocket.h"
#include "debris.h"

using namespace std;

/* Define a 2-dimensional array to store the map */
char map[height][width];
char map_char = ' ';          
char map_divider = '|';     // divider between two playspaces 

/* function to print map*/
void displayMap(char map[height][width])
{
  for (int i = 0; i < height; i++){
    for (int j = 0; j < width; j++){
      cout << map[i][j] ;
    }
    cout << endl;
  }
}

/* function to reset the map*/
void cleanMap(char map[height][width])
{
  for (int i = 0; i < height; i++){
    for (int j = 0; j < width; j++){
      if (j == 25) map[i][j] = map_divider;
      else map[i][j] = map_char;
    }
  }
}

/* function to update the rocket position in the map */
void updateRocket(char map[height][width], Rocket rocket)
{
  char rocket_icon = rocket.avatar;
  map[rocket.y][rocket.x] = rocket_icon;
}

/* function to update the debris position in the map */
void updateDebris(char map[height][width], Debris debrisList[], int numdebris)
{
  char debris_icon = '-';
  for (int i = 0; i < numdebris; i++){
    if (debrisList[i].y > height || debrisList[i].x > width) continue;
    map[debrisList[i].y][debrisList[i].x] = debris_icon;
  }
}

/* function to update the scores in the map */
void updateScore(char map[height][width], Rocket rocket1, Rocket rocket2)
{
    map[height - 1][rocket1.x] = '0' + (rocket1.score % 10);
    map[height - 1][rocket1.x - 1] = '0' + (rocket1.score / 10);
    map[height - 1][rocket2.x] = '0' + (rocket2.score%10);
    map[height - 1][rocket2.x - 1] = '0' +  (rocket2.score/10);
}

/* function to update the map every PAUSELENGTH (1000 * 10 milliseconds) 
1. clean map
2. update rocket 1 and 2 position 
3. update debris position 
4. update scores
5. print map
*/
void updateMap(char map[height][width], Rocket rocket1, Rocket rocket2, int numdebris, Debris debrisList[])
{
  cleanMap(map);
  updateRocket(map, rocket1);
  updateRocket(map, rocket2);
  updateDebris(map, debrisList, numdebris);
  updateScore(map, rocket1, rocket2);
  displayMap(map);
}
