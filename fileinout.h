// Filename: fileinout.h
// Description: Headerfile for fileinout.cpp

#ifndef FILEINOUT_H
#define FILEINOUT_H

#include "user.h"
#include "fileinout.h"

/*Functions to read or save the players' previous and new score*/
void extractUserListFromFile(vector<User> & userlist);
void saveUserListToFile(vector<User> & userlist);

#endif
