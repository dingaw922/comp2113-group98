// Filename: map.cpp
// Description: Functions to implement and update map

#include <iostream>
#include <unistd.h>
#include <iomanip>
#include "map.h"
#include "rocket.h"
#include "debris.h"
//#include "macros.h"

using namespace std;

//WIDTH = 51;
//HEIGHT = 21;
char map[height][width];
char map_char = ' ';
char map_divider = '|';

void displayMap(char map[height][width]){
  for (int i = 0; i < height; i++){
    for (int j = 0; j < width; j++){
      cout << map[i][j] ;
    }
    cout << endl;
  }
}

void cleanMap(char map[height][width]){
  for (int i = 0; i < height; i++){
    for (int j = 0; j < width; j++){
      if (j == 25) map[i][j] = map_divider;
      else map[i][j] = map_char;
    }
  }
}

void updateRocket(char map[height][width], Rocket rocket){
  char rocket_icon = rocket.avatar;
  map[rocket.y][rocket.x] = rocket_icon;
}

void updateDebris(char map[height][width], Debris debrisList[], int numdebris){
  char debris_icon = '-';
  for (int i = 0; i < numdebris; i++){
    if (debrisList[i].y > height || debrisList[i].x > width) continue;
    map[debrisList[i].y][debrisList[i].x] = debris_icon;
  }
}

void updateScore(char map[height][width], Rocket rocket1, Rocket rocket2){
    map[height - 1][rocket1.x] = '0' + (rocket1.score % 10);
    map[height - 1][rocket1.x - 1] = '0' + (rocket1.score / 10);
    map[height - 1][rocket2.x] = '0' + (rocket2.score%10);
    map[height - 1][rocket2.x - 1] = '0' +  (rocket2.score/10);
}

void updateMap(char map[height][width], Rocket rocket1, Rocket rocket2, int numdebris, Debris debrisList[]){
  cleanMap(map);
  updateRocket(map, rocket1);
  updateRocket(map, rocket2);
  updateDebris(map, debrisList, numdebris);
  updateScore(map, rocket1, rocket2);
  displayMap(map);
}
