// user_profile.h

#ifndef USER_H
#define USER_H

#include "user.h"
#include <string>
#include <vector>
using namespace std;

struct User{
  string name;
  int score;
  char u_avatar;

  void updateScore(int points_awarded, vector<User> & userlist);
  void displayProfile(vector<User> &userlist);
  bool operator <(const User&a);
  void changeAvatar(char newAvatar, vector<User> & userlist);
  //void addUser(vector<User> &userlist);
};

bool user_exist(User a, vector<User> userlist);
//void addUser(User, vector<User> userlist);
void displayLeaderBoard(vector<User> & userlist);



#endif
