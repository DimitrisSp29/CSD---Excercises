#include "std_lib_facilities.h"
#include <cmath>
#include <vector>

// Function that calculates the manhattan distance between two points.
double ManhattanDis(vector<double> u, vector<double> v)
{
    // Return 0 if the vectors are empty.
    if(u.size() == 0)
    {
    	return 0;
    }

    // Variable that holds the remainder of the division of each dimension in the power of 2.
    double rem = abs(v.at(v.size() - 1) - u.at(u.size() - 1));

    // Remove the last element of each vector.
    u.pop_back();
    v.pop_back();

    // Return the result.
    return rem + ManhattanDis(u, v);
}
int main()      // Start of the main function
{
    // Define the vectors that will be used as points.
    vector<double> u;
    vector<double> v;

    // Assign two values to each vector.
    u.push_back(1);
    u.push_back(2);
    u.push_back(3);
    u.push_back(4);

    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);

    // Print the according message displaying the  Manhattan distance between the points.
    cout << "The Manhattan distance for the given points u,v is ManhattanDis(p,q)= " << ManhattanDis(u, v) << endl;
    keep_window_open();
    return 0;
}