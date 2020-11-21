// Filename: Menu.cpp 
// Description: Functions to display menu and to execute the menu 

#include <iostream>

#include "menu.h"
#include "user.h"
#include "game.h"
#include "debris.h"

using namespace std;

/* Function to check if the user's input is valid */
bool checkChoiceValidity(int menuChoice)
{
  while (menuChoice > 4 || menuChoice < 1){
    cout << "\nInvalid Choice\nPlease Enter Again: " << endl;
    return true;
  }
  return false;
}

/* Function to display the basic rules of the game */
void displayRules()
{
  cout << "*** Basic Rules ***" << endl;
  cout << "- Players will select th difficulty level before the game starts. \n";
  cout << "- There will be 3 difficulty levels such as 1, 2 and 3.\n";
  cout << "- Each game is 1-minute long.\n";
  cout << "- A countdown of time left will be shown on top of the screen.\n" ;
  cout << "- Players are allowed to control the rockets' movement vertically only.\n" ;
  cout << "- Player 1 : 'w' as up key; 's' as down key. \n";
  cout << "- Player 2 : 'u' as up key; 'j' as down key. \n";
  cout << "- Runtime score for each player will be displayed at the bottom of the screen. \n";
  cout << "- One point will be awarded for completing each lap\n" ;
  cout << "- The player with the most points at the end of a session wins.\n" ;
  cout << "- Score of each player in the sessions will be multiplied by the difficulty level and accumulated. \n";
  cout << "- Leaderboard with the accumulated score for all players will be displayed after each session.\n" ;
  cout << "\n";
}

/* Function to display the sub menu "Help Menu" 
and prompt user's input and return user's input
*/
int displayHelpMenu()
{
  cout << "*** Help Menu ***" << endl;
  cout << "1. User Profile" << endl;
  cout << "2. Change Rocket Avatar" << endl;
  cout << "3. Basic Rules" << endl;
  cout << "4. Back To Main Menu" << endl;
  cout << "Please Enter Your Choice: " ;
  int helpChoice;
  cin >> helpChoice;
  cout << "\n";
  return helpChoice;
}

/* Function to display the main menu and execute accordingly */
void displayMenu(User user1, User user2,vector<User> &userlist, Debris debrisList[], int numdebris)
{  
  // Main Menu Content and prompt user input
  cout << "*** Main Menu ***" << endl;
  cout << "1. Start Game" << endl;
  cout << "2. Leader Board" << endl;
  cout << "3. Help" << endl;
  cout << "4. Quit" << endl;
  cout << "Please Enter Your Choice: ";
  int menuChoice;
  cin >> menuChoice;
  cout << "\n";
  
  /*Execution of user input 
  Choices: 
  1. Enter the space race game
  2. Leader Board of all the users will be displayed
  3. Sub menu will be displayed
  4. Exit the whole game
  After the execution of completes, main menu will be displayed, unless 4. Quit
  */
  switch (menuChoice){
    case 1:
      game(debrisList, user1, user2, userlist, numdebris);
      displayMenu(user1, user2,userlist, debrisList, numdebris);
      break;
    case 2:
      displayLeaderBoard(userlist);
      displayMenu(user1, user2,userlist, debrisList, numdebris);
      break;
    case 4:
      cout << "*** Bye Bye! ***" << endl;
      break;
    case 3:
      int helpChoice = displayHelpMenu();             // display sub menu
      
      /* Execution of user input  
      1. Users' profiles will be displayed one after another 
      2. Facilitate the change of rocket's avatar 
      - user wil be prompted to input 1 / 2 to identify which user's avatar will be changed
      - Option 0 is provided to allow user to return to main menu 
      3. Basic rules of the game will be displayed 
      4. Back to main menu option 
      After the execution of completes, main menu will be displayed, unless option 4 or any other keys.
      */
      switch (helpChoice){
        case 1:
          cout << "*** Users' Profile ***" << endl;
          cout << "Player 1 -> " << endl;
          user1.displayProfile(userlist);
          cout << "Player 2 -> " << endl;
          user2.displayProfile(userlist);
          displayMenu(user1, user2,userlist, debrisList, numdebris);
          break;
          
        case 2: 
          cout << "*** Change Rocket Avatar ***" << endl;
          cout << "Player 1 Or Player 2 Wants To Change Rocket ? (1/2)" << endl;
          cout << "Press 0 To Return To Main Menu" << endl;
          int choice;
          cin >> choice;
          while (choice != 1 && choice != 2 && choice != 0 ){
            cout << "Invalid Input Try Again" << endl;
            cin >> choice;
          }
          if (choice != 0){
            cout << "Please Enter Your New Rocket: ";
            char newAvatar;
            cin >> newAvatar;
            if (choice == 1) user1.changeAvatar(newAvatar, userlist);
            else if (choice == 2) user2.changeAvatar(newAvatar, userlist);
          }
          cout << "\n" ;
          displayMenu(user1, user2,userlist, debrisList, numdebris);
          break;
        
        case 3:
          displayRules();
          displayMenu(user1, user2,userlist, debrisList, numdebris);
          break;
        
        default:
          displayMenu(user1, user2,userlist, debrisList, numdebris);
          break;
      }
  }
}
