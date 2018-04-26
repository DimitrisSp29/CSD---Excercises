#include "std_lib_facilities.h"
#include <tgmath.h>         // Libraries required
#include <valarray>         // for the use of "sqrt".


double resulting_numinator = 0;         // Global variables that hold the numinator
double resulting_denominator = 0;       // and denominator of the resulting fraction.


int least_common_multiple(int a, int b)      // Function that calculates the Least Common Multiple of two numbers.
{
    int lcm=0;                               // Initialization of the variable containing the L.C.M.
    int max = (a > b) ? a : b;               // Assigns the biggest of the two numbers to a variable.
    while(true)                             
    {                                                
        if(max % a == 0 && max % b == 0)     // If max is divided perfectly by a and b assigns it to the L.C.M.
        {
            lcm = max;
            return lcm;
        }
        else                                 // If the division is imperfect increments max by 1.
        {
            ++max;
        }
    }
}


int subtract(int num1, int denom1, int num2, int denom2)            // Function that subtracts two fractions.
{
    int num3 = 0;                                                       //
    int denom3 = 0;                                                     // Variables reffering to the L.C.M and the resulting fraction's numinator/denominator.
    int lcm = 0;                                                        //
    if(denom1==denom2)                                                  // If the denominators are equal subtracts the numinators.
    {
        num3 = num1 - num2;
        denom3 = denom1;
        resulting_numinator = num3;
        resulting_denominator = denom3;
    }
    if(denom1!=denom2)                                                  // If the denominators are unequal uses the lcm to find the like fractions and subtract them.
    {
        lcm =least_common_multiple(denom1, denom2);
        num3 = (num1*(lcm/denom1))-(num2*(lcm/denom2));
        denom3 = lcm;
        resulting_numinator = num3;
        resulting_denominator = denom3;
    }
}


int main()                                                          // Start of the main function.
{
    int first_numinator=0, first_denominator=0;                     // Variables that will hold the user-inputted 
    int second_numinator=0, second_denominator=0;                   // numinators and denominators.
    cout << "Enter two fractions:\n";
    try
    {
        if(!(cin >> first_numinator >> first_denominator >> second_numinator >> second_denominator))    // Prompts the user to input two fractions. If it fails, throws an error.
        {
            throw "Invalid Input!";
            keep_window_open();
        }

        if (first_denominator==0 || second_denominator==0)                                              // If either of the denominators are 0 throws an error.
        {
            throw "Error!: Division by 0!";
            keep_window_open();
        }
        
        subtract(first_numinator, first_denominator, second_numinator, second_denominator);             // Subtracts the inputted fractions.

        if(resulting_numinator<0 || resulting_denominator<0)                                            // Checks if the resulting fraction contains negative numbers and throws an error.
        {
            throw "Error!: Can't calculate the square root of the resulting fraction (Negative values).";
            keep_window_open();
        }
    }
    catch(const char* msg)                                                                                // Catches any errors that occur in the try{} block.
    {
        keep_window_open();
        cerr << msg << endl;
        return -1;
    }
    resulting_numinator = sqrt (resulting_numinator);                                                        // Calculates the square root of the resulting fraction's numinator
    resulting_denominator = sqrt (resulting_denominator);                                                    // and denominator.
    cout << "The resulting fraction is:"<< resulting_numinator << "/" << resulting_denominator << endl;      // Prints the final fraction to the screen.
    keep_window_open();
}