// Filename: map.h
// Description: Header file for map.cpp

#ifndef MAP_H
#define MAP_H

#include "map.h"
#include "debris.h"
#include "rocket.h"
//#include "macros.h"



void displayMap(char map[height][width]);
void cleanMap(char map[height][width]);
void updateRocket(char map[height][width], Rocket rocket);
void updateDebris(char map[height][width], Debris debrisList[], int numdebris);
void updateScore(char map[height][width], Rocket rocket1, Rocket rocket2);
void updateMap(char map[height][width], Rocket rocket1, Rocket rocket2, int numdebris, Debris debrisList[]);

#endif
