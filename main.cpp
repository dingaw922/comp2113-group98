// main.cpp

#include <iostream>
#include <string>
#include <map>
#include "menu.h"
#include "user.h"
using namespace std;

/*
struct User{
    string name;
    int score;
    int difficulty_level;
    string theme;
};
*/

vector<User> userlist;

int main() {
  User trial1, trial2;
  trial1.name = "Ivy";
  trial2.name = "Ashley";
  addUser(trial1, userlist);
  addUser(trial2, userlist);
  User userA;
  int decision;

  cout <<"Welcome To The Game!!!" << endl;
  cout << "Please Enter Your Name: " ;
  cin >> userA.name;
  if (user_exist(userA, userlist)){
    cout << "Welcome Back" << endl;
  }
  else {
    cout << "Welcome " << userA.name << endl;
    addUser(userA, userlist);
  }
  existing_main_menu();
  cin >> decision;
  while (decision > 5 || decision < 1){   // implement invalid choice within the while loop
    cout << "Invalid Choice ! Please try again !" << endl;
    cin >> decision;
  }
  while (decision != 5){
    switch (decision){
      case 1:
        cout << "Starting Game" << endl;
        break;
      case 2:
        cout << "Basic Rules" << endl;
        display_rules();
        break;
      case 3:
        cout << "User Profile" << endl;
        userA.displayProfile();
        break;
      case 4:
        cout << "Leadership Board" << endl;
        displayLeadershipBoard(userlist);
        break;
    }
    cout << "Decision" << endl;
    cin >> decision;
  }




  cout << "Bye Bye" << endl; //decision == 5, quit game
}
  /*
  map<User, int> userlist;
  User user1;
  cin >> user1.name;
  if (userlist.count(user1) > 0) {
    cout << userlist[user1];
    menu();
  }
  else{
    cout << "Name not found" << endl;
    userlist[user1] = 0;
  }
}

/*
int main(){

  string username;
  map<User, int> userlist;
  User user1;
  // final todo : to display everyting nicely
  cout << "Welcome to Space Race !!!" << endl;
  cout << "Please enter your username: " << endl;
  cin >> user1.name;
  if (userlist.count[user1] > 0){
    menu();
  }
  else {
    cout <<"Welcome New User!" << endl;
    userlist[user1] = user1.name;
  }



  // if user does not exist create a new user profile
  //
  menu();


}
*/
