// Description: Member functions for struct Debris and functions related to debris

#include <iostream>
#include <cstdlib>        // calling srand(), rand()
#include <ctime>          // calling time()


#include "debris.h"
#include "source.h"       // to use the global variable width and height

using namespace std;

/*Function to create a list of debris
Random generator making use of the computer's internal clock to control the choice of the seed.
1. Randomly pick a number less than the total number of debris to be debris moving to the left.
2. The remaining deris will be moving to the right.
3. Randomly generate the x and y coordinates of the debris within the height and width of the map.
4. Store the coordinates and direction of the debris into the debrisList.
*/
void createDebris(Debris debrisList[], int numdebris)
{
  srand(time(NULL));
  int numLeftDebris = rand() %numdebris;
  // debris moving to the left
  for (int i = 0; i < numLeftDebris; i++){
    int x = rand() %width;
    int y = rand() %(height - 2);
    Debris debris = {x, y, 'L'};
    debrisList[i] = debris;
  }

  // debris moving to the right
  for (int j = numLeftDebris; j < numdebris; j++){
    int x = rand() %width;
    int y = rand() %(height - 2);
    Debris debris = {x, y,'R'};
    debrisList[j] = debris;
  }
}

/*Function to move the debris in the debris list*/
void movingDebris(Debris debrisList[],int numdebris){
  for (int i = 0; i < numdebris; i++){
    debrisList[i].updateDebrisPosition();
  }
}

/*Function to move debris during the game
For every update:
Debris with direction L (i.e. moving to the left) -> x-coordinate - 1
Debris with direction R (i.e. moving to the right) -> x-coordinate + 1
When debris reached the border of the map (i.e. x-coordinate equals width or 0)
debris x-coordinate will be reset to the other end of the map
*/
void Debris::updateDebrisPosition()
{
    if (direction == 'L' && x > 0) x--;
    else if (direction == 'L' && x <= 0) x = (width - 1);
    else if (direction == 'R' && x < (width - 1) ) x++;
    else if (direction == 'R' && x >= (width - 1) ) x = 0;
}
