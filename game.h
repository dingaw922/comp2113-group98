// Filename: game.h
// Description: Header file for game.cpp

#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "rocket.h"
#include "debris.h"
#include "input.h"
#include "game.h"
#include <iostream>
#include <stdio.h> // call getchar()
#include <stdlib.h>
#include <unistd.h>
#include "user.h"


char getRocketDirection();
void checkCollision(Debris debrisList[], Rocket & rocket, int numdebris);
void initialize();
void game(Debris debrisList[], User & user1, User &user2, vector<User> &userlist, int numdebris);

#endif
