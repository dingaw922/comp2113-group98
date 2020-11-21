// Fimename: user.h
// Description: Header file for user.cpp

#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

#include "user.h"

using namespace std;

/* Define a stuct User with 3 members and 4 member functions:
name, score and avatar
*/
struct User{
  string name;
  int score;
  char u_avatar;

  void updateScore(int points_awarded, vector<User> & userlist);
  void displayProfile(vector<User> &userlist);
  bool operator <(const User&a);
  void changeAvatar(char newAvatar, vector<User> & userlist);
};

/* Functions related to User */
bool user_exist(User a, vector<User> userlist);
void displayLeaderBoard(vector<User> & userlist);

#endif
