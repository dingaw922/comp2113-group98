# COMP2113 Group 98 - Space Race
## Team Members
1. Ashley Ng Zhen Zhen 
   - UID: 3035721500
2. Ding Ai Wei
   - UID: 3035719741
## Game Description 
Space race is a two-player game where each player controls a rocket and moves it vertically up and down to get to the top of the map without knocking into space debris to gain points. The rocket will return back to the starting position each time it hits a horizontally moving spaceship.

Players are able to choose its rocket design for the game. Players are able to choose difficulty of game via numbered levels. A higher level will represent a higher weightage per score, the final score is calculated by the score in each session multiplied by the difficulty level and accumulated. A leaderboard is created to rank players in the game by final score. At the end of the game, the final score of each player will be displayed accordingly, followed by the leaderboard. Players profile such as name, rocket choice, latest score will be stored when player leaves the game and resume from where it last left off.

## Basic Game Rules 
 1. Each game is one minute long and a countdown of time left for the game will be shown.
 2. Players are allowed to control the rockets’ movements vertically but not horizontally.
 3. One point will be awarded for completing each lap, the player with the most points at the end of a session wins.
 4. Leaderboard ranking players from highest score to lowest score will be created. 
 5. There are multiple levels which represent the difficulty of the game, each level varies in frequency of horizontal space debris. 

## Features to be Implemented
**1. Generation of game sets or events**  
The space debris movement will be generated according to difficulty level. 

**2. Data structures for storing game status**  
Array will be used to store the user’s rocket design, score and name. 

**3. Dynamic memory management**  
Search tree data structure will be used to store and update the leaderboard for each level.   
Each node is an array storing the user’s information such as username and highest score at that level.   
This is useful for insertion of new nodes when there is a new player and for displaying the ranking of the players after each session.   

**4. File input/ output (e.g. for loading / saving game status)**  
Input: User’s rocket design, selection of theme and game status including level from last game 
Output: User’s game status after each session 

**5. Program codes in multiple files**  
Different elements and functions of the game will be coded in different files.   
A makefile will be created to specify the dependency of the files.   
Below is a brief list of files to be created:
   - Rocket’s movement 
   - Space debris movement 
   - Difficulty level function to modify the speed, frequency and size of space debris movement
   - Run time scoring 
   - Countdown timer 
   - User’s rocket design and current status
   - Main game function with menu for difficulty level selection.
