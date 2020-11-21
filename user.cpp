// user_profile.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "user.h"
using namespace std;

// Function to add 1 point to the user's score;
// !!! Problem cannot update the leadership board accordingly
void User::updateScore(int points_awarded, vector<User> &userlist){
  score += points_awarded;
  cout << name << "\'s new score: " << score << "\n" << endl;
  for (int i = 0; i < userlist.size() ; i++){
    if (name == userlist[i].name){
      userlist[i].score = score;
    }
  }
}

    // Function to display profile of user
void User::displayProfile(vector<User> & userlist){
  //cout << name << " " << score << " " << u_avatar << endl;
  for (int i = 0; i < userlist.size() ; i++){
    if (name == userlist[i].name){
      cout << left;
      cout << setw(18) << "Name" << ": " << userlist[i].name << endl;
      cout << setw(18) << "Score" << ": " << userlist[i].score << endl;
      cout << setw(18) << "Rocket Avatar" << ": " << userlist[i].u_avatar << endl;
      cout << "\n" ;
    }
  }
}

void User::changeAvatar(char newAvatar, vector<User> & userlist){
  u_avatar = newAvatar;
  cout << "\nRocket Has Been Updated Successfully !!!\n" << endl;
  for (int i = 0; i < userlist.size() ; i++){
    if (name == userlist[i].name){
      userlist[i].u_avatar = newAvatar;
    }
  }
}

bool User::operator <(const User& a){
  if (this->score < a.score) return false;
  if (this->score > a.score) return true;
  return (this->name) < a.name;
}

bool user_exist(User a, vector<User> userlist){
  for (int i = 0; i < userlist.size() ; i++){
    if (a.name == userlist[i].name){
      return true;
    }
  }
  return false;
}

void displayLeaderBoard(vector<User> &userlist){
  sort(userlist.begin(), userlist.end());
  cout << "*** Leader Board ***" << endl;
  cout << left;
  cout << setw(3) << "No" << setw(15) << "Name" << setw(8) << "Score" << setw(10) << "Avatar" << endl;
  for (int i = 0; i < userlist.size(); i++){
    cout << setw(3) << i + 1 << setw(15) << userlist[i].name << setw(8) << userlist[i].score << setw(10) << userlist[i].u_avatar << endl;
  }
  cout << "\n" ;
}
