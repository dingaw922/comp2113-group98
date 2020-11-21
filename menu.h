// Filename: menu.h
// Description: Header file for menu.cpp

#ifndef MENU_H
#define MENU_H

#include "menu.h"
#include "user.h"
#include "game.h"
#include "debris.h"

int displayHelpMenu();
int level();
void displayMenu(User user1, User user2, vector<User> &userlist, Debris debrisList[], int numdebris);
void displayRules();
bool checkChoiceValidity(int menuChoice);

#endif
