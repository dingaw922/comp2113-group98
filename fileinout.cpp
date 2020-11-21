// Description: Functions to read or save the users' previous and new score

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

#include "fileinout.h"
#include "user.h"

using namespace std;

/* Function to read in the users' previous score and avatar*/
void extractUserListFromFile(vector<User> & userlist)
{
  ifstream fin("user_record.txt");
  if (fin.fail()){
    cout << "error in file opening!" << endl;
    exit(1);
  }

  string line;
  while (getline(fin, line)){
    istringstream line_in(line);
    User user;
    line_in >> user.name >> user.score >> user.u_avatar;
    userlist.push_back(user);
  }

  fin.close();
}

/* Function to save the users' new score and avatar*/
void saveUserListToFile(vector<User> & userlist)
{
  ofstream fout("user_record.txt");
  if (fout.fail()){
    cout << "Error in file opening!" << endl;
    exit(1);
  }

  for (int i = 0; i < userlist.size(); i++){
    fout << userlist[i].name << " " << userlist[i].score << " " << userlist[i].u_avatar << endl;
  }

  fout.close();
}
