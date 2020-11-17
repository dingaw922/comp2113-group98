// user_profile.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "user.h"
using namespace std;

struct User{
    string name;
    int score;
    int difficulty_level;
    string theme;

    // Function to add 1 point to the user's score;
    // !!! Problem cannot update the leadership board accordingly
    void updateScore(int points_awarded){
      score += points_awarded;
      cout << name << "\'s new score: " << score << endl;
    };

    // Function to display profile of user
    void displayProfile(){
      cout << "Profile" << endl;
      cout << left;
      cout << setw(18) << "Name: " << name << endl;
      cout << setw(18) << "Score: " << score << endl;
      cout << setw(18) << "Difficulty Level: " << difficulty_level << endl;
      cout << setw(18) << "Theme: " << theme << endl;
    };

    bool operator <(const User& a){
      if (this->score > a.score) return false;
      if (this->score < a.score) return true;
      return this->name < a.name;
    };

    //void updateScore(int points_awarded);
};
/*
// Function to add 1 point to the user's score;
void User::updateScore(int points_awarded){
  score = score + points_awarded;
  cout << name << "\'s new score: " << score << endl;
}*/


bool user_exist(User a, vector<User> userlist){
  for (int i = 0; i < userlist.size() ; i++){
    if (a.name == userlist[i].name){
      return true;
    }
  }
  return false;
}

void addUser(User &a, vector<User> &userlist){
  a = {a.name, 0, 1, "Default"};
  userlist.push_back(a);
//  cout << "New User Registered" << endl;
}

void displayLeadershipBoard(vector<User> &userlist){
  sort(userlist.begin(), userlist.end());
  cout << left;
  cout << setw(3) << "No" << setw(6) << "Name" << setw(6) << "Score" << endl;
  for (int i = 0; i < userlist.size(); i++)
    cout << setw(3) << i + 1 << setw(10) << userlist[i].name << setw(6) << userlist[i].score << endl;
}

vector<User> userlist;

int main(){

  User trial1, trial2;
  trial1.name = "Ivy";
  trial2.name = "Ashley";
  addUser(trial1, userlist);
  addUser(trial2, userlist);
  User userA;
  cout << "Please enter your username: ";
  cin >> userA.name;
  if (user_exist(userA, userlist)){
    cout << "Welcome Back" << endl;
  }
  else {
    cout << "Welcome " << userA.name << endl;
    addUser(userA, userlist);
  }

// commands to test functions updateScore
  trial1.updateScore(10);

// command to test displayLeadershipBoard
  displayLeadershipBoard(userlist);

/* commands to test functions displayProfile
  trial1.displayProfile();
  trial2.displayProfile();
*/
}
