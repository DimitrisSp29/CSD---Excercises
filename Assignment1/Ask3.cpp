/* This is a program in which a point moves in a user-defined direction inside a 10x10 matrix starting from position [0, 0]
Dimitris S. Spythouris A.M: 4040 */
#include "std_lib_facilities.h"


int x = 0;  // Position on the x-axis;
int y = 0;  // Position on the y-axis;


int move_up()   //Function that moves the point up by 1 if it hasn't surpassed the bounds.
{
    if(y==10)
    {
        cout << "Error! Can't move out of bounds!\n";
    }
    else
    {
        y++;
    }
}

int move_down()   //Function that moves the point down by 1 if it hasn't surpassed the bounds.
{
    if(y==0)
    {
        cout << "Error! Can't move out of bounds!\n";
    }
    else
    {
        y--;
    }
}

int move_left()   //Function that moves the point left by 1 if it hasn't surpassed the bounds.
{
    if(x==0)
    {
        cout << "Error! Can't move out of bounds!\n";
    }
    else
    {
        x--;
    }
}

int move_right()   //Function that moves the point right by 1 if it hasn't surpassed the bounds.
{
    if(x==10)
    {
        cout << "Error! Can't move out of bounds!\n";
    }
    else
    {
        x++;
    }
}

int main()      // Start of the main function.
{
    char command;   // Character referring to the user inputted command.
    while(cin >> command)       // Prompts the user to input a direction for the point to move or exit the program.
    {
        switch (command)
        {
            case 'w': move_up(); break;
            case 'a': move_left(); break;
            case 's': move_down(); break;
            case 'd': move_right(); break;
            case 'q': cout << "Your position was: [" << x << ", " << y << "]\n"; return 0;
            default: cout << "Invalid command, try again.";
        }
    }
}