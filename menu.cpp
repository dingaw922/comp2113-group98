// menu.cpp

#include <iostream>
#include "menu.h"
using namespace std;

void new_main_menu(){ // menu for new user
  cout << "Please Choose From The Following:" << endl;
  cout << "1. Rules" << endl;
  cout << "2. Start A New Game" << endl;
  cout << "3. Leadership Board" << endl;
  cout << "4. Update Profile" << endl;
  cout << "5. Quit" << endl;
}

void existing_main_menu(){ //menu for existing user
  cout << "Please Choose From The Following:" << endl;
  cout << "1. Resume Game" << endl;
  cout << "2. Start A New Game" << endl;
  cout << "3. Leadership Board" << endl;
  cout << "4. Update Profile" << endl;
  cout << "5. Quit" << endl;
}

void display_rules(){
  cout << "Each game is 30-seconds long and a countdown of time left for\n" ;
  cout << "the game will be shown. Players are allowed to control the\n" ;
  cout << "rocketsâ movements vertically only. One point will be awarded\n" ;
  cout << "for completing each lap. The player with the most points at\n" ;
  cout << "the end of a session wins.Leaderboard showing the highest\n" ;
  cout << "score for each player at the level will be displayed after\n" ;
  cout << "each session. There are multiple levels which represent the\n" ;
  cout << "difficulty of the game, each level varies in speed, frequency\n" ;
  cout << "and size of horizontal spaceships." << endl;
}
