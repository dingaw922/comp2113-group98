// Filename: user_profile.cpp
// Description: Member functions for struct User and functions related to User

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "user.h"

using namespace std;

/* Function to add awarded points to the user's score and update the userlist */
void User::updateScore(int points_awarded, vector<User> &userlist)
{
  score += points_awarded;
  cout << name << "\'s new score: " << score << "\n" << endl;
  for (int i = 0; i < userlist.size(); i++){
    if (name == userlist[i].name){
      userlist[i].score = score;
    }
  }
}

/* Function to display profile of user */
void User::displayProfile(vector<User> & userlist)
{
  for (int i = 0; i < userlist.size(); i++){
    if (name == userlist[i].name){
      cout << left;
      cout << setw(18) << "Name" << ": " << userlist[i].name << endl;
      cout << setw(18) << "Score" << ": " << userlist[i].score << endl;
      cout << setw(18) << "Rocket Avatar" << ": " << userlist[i].u_avatar << endl;
      cout << "\n" ;
    }
  }
}

/* Function to change user's avatar and update the userlist */
void User::changeAvatar(char newAvatar, vector<User> & userlist)
{
  u_avatar = newAvatar;
  cout << "\nRocket Has Been Updated Successfully !!!\n" << endl;
  for (int i = 0; i < userlist.size(); i++){
    if (name == userlist[i].name){
      userlist[i].u_avatar = newAvatar;
    }
  }
}

/* Declare the boolean operator < for struct User */
bool User::operator <(const User& a)
{
  if (this->score < a.score) return false;
  if (this->score > a.score) return true;
  return (this->name) < a.name;
}

/* To check is a user exit in the userlist */
bool user_exist(User a, vector<User> userlist)
{
  for (int i = 0; i < userlist.size(); i++){
    if (a.name == userlist[i].name){
      return true;
    }
  }
  return false;
}

/* To display the Leader Board in a table format */
void displayLeaderBoard(vector<User> &userlist)
{
  sort(userlist.begin(), userlist.end());
  cout << "*** Leader Board ***" << endl;
  cout << left;
  cout << setw(3) << "No" << setw(15) << "Name" << setw(8) << "Score" << setw(10) << "Avatar" << endl;
  for (int i = 0; i < userlist.size(); i++){
    cout << setw(3) << i + 1 << setw(15) << userlist[i].name << setw(8) << userlist[i].score << setw(10) << userlist[i].u_avatar << endl;
  }
  cout << "\n" ;
}
