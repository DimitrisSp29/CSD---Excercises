#include "std_lib_facilities.h"
#include <vector>
#include <math.h>
// Function that calculates the Euclidean distance between two n-dimensional points.
double Euclidean_Distance(vector<int> point1, vector<int> point2)
{
    // Dimensions are equal to the size of one of the points.
    int dims = point1.size();

    // Variable that holds the remainder of the division of each dimension in the power of 2.
    double rem = 0;

    // For each dimension calculate rem.
    for(int i=0; i<dims; ++i)   
    {
        rem += pow(point2.at(i) - point1.at(i),2);
    }
    // Return the square root of the result.
    return sqrt(rem);
}
int main()      // Start of the main function
{
    // Define the vectors that will be used as points.
    vector<int> point1;
    vector<int> point2;

    // Assign two values to each vector.
    point1.push_back(0);
    point1.push_back(0);
    point2.push_back(10);
    point2.push_back(10);

    // Print the according message displaying the distance between the points.
    cout << "The Euclidean distance for the given points p,q is d(p,q)= " << Euclidean_Distance(point1, point2) << endl;
    keep_window_open();
    return 0;
}