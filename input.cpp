// Filename: input.cpp
// Description : Function to initialize the game 
// Referece: Goga Koreli, Snake, (2016), GitHub repository, https://github.com/gogakoreli/snake

#include <termios.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include <string>
#include <stdio.h>

#include "input.h"

using namespace std;

struct termios t;

void input_enter_off()
{
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void input_enter_on()
{
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void input_init()
{

}
