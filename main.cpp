// Filename: main.cpp
// Description: Implementation of set up of Space Race game

#include <iostream>
#include <string>

#include "user.h"
#include "menu.h"
#include "debris.h"
#include "fileinout.h"

using namespace std;

/*declare 2 User since this will be a 2-player game
declare a vector of Users to store the information of the users
*/
struct User user1;
struct User user2;
vector<User> userlist;

/* Function to add new users into the userlist
User's score will be initialized to 0
User's avatar will be default '@''
*/
void addUser(User &a, vector<User> &userlist)
{
  a.score = 0;
  a.u_avatar = '@';
  userlist.push_back(a);
}

/*Function for implementing the game*/
int main()
{
  // Extract the previous list of users
  extractUserListFromFile(userlist);

  /* Preset the number of debris to 0 and
  declare a dynamic array to store the debris' information later.
  Dynamic array is required as different difficulty levels will have different number of debris
  */
  int numdebris = 0;
  Debris *debrisList = new Debris[numdebris];

  /* Welcome text and prompt users to input thier usernames
  New users will be added into the userlist
  */
  cout.width(30);
  cout << "*** Welcome To Space Race! ***"<< endl;
  cout << "\nPlayer 1 -> Enter Your Username: " ;
  cin >> user1.name;
  if (! user_exist(user1, userlist)) {
    addUser(user1, userlist);}
  cout << "\nPlayer 2 -> Enter Your Username: " ;
  cin >> user2.name;
  if (! user_exist(user2, userlist)){
    addUser(user2, userlist);  }
  cout << "\n";

  /* Display the menu*/
  displayMenu(user1, user2, userlist, debrisList, numdebris);

  /* save all users' information on the userlist
  and clear memory on the dynamic array
  */
  saveUserListToFile(userlist);
  delete [] debrisList;
}
