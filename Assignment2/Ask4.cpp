#include "std_lib_facilities.h"
#include <vector>
#include <cmath>
#include <fstream>
#include <ctime>

// The user class.
class user
{
// The private variables, username and password.
private:
    string username;
    string password;
// The public variables and functions.
public:
    string name;
    string lname;
    double age;

    // Assigns a string to the class' username.
    void setUsername(string uname)
    {
        username = uname;
    }
    // Returns the class' username.
    string getUsername()
    {
        return username;
    }
    // Returns the class' pasword.
    string getPassword()
    {
        return password;
    }
    // Assigns a string to the class' password.
    void setPassword(string pwd)
    {
        password = pwd;
    }
};
// The announcement class.
class announcement
{
// Contains 3 public variables: userID, message, date.
public:
    string userID;
    string message;
    string date;
};

// Start of the main function.
int main()
{
    //------------User 1-------------//
    // Fill the credentials of user1.
    user user1;
    user1.setUsername("mgiannoulis");
    user1.setPassword("cppiscool");
    user1.name = "Mixalis";
    user1.lname = "Giannoulis";
    user1.age = 24;
    //-------------------------------//

    //--------------------User 1 Announcements----------------------//
    // Create 3 announcements.
    announcement Ann1;
    announcement Ann2;
    announcement Ann3;

    // Set the userID for each one.
    Ann1.userID = user1.getUsername();
    Ann2.userID = user1.getUsername();
    Ann3.userID = user1.getUsername();

    // Set the message for each one.
    Ann1.message = "New excercises announced for HY150!";
    Ann2.message = "NASA will launch a rocket to Mars on 2024.";
    Ann3.message = "Huge floods in Heraklion after today's storm!";

    // Variable that holds the current date.
    time_t ann_date = time(NULL);

    // Set the date of each announcement.
    Ann1.date = asctime(localtime(&ann_date));
    Ann2.date = asctime(localtime(&ann_date));
    Ann3.date = asctime(localtime(&ann_date));
    //---------------------------------------------------------------//

    // Create a file called "announcements.csv" and open it for writing.
    ofstream csv_file("announcements.csv");
    if(!csv_file)
    {
        cout << "Error writing to file!\n";
        return -1;
    }

    // Output UserID Announcements and Date on the first 3 columns.
    csv_file << "UserID,Announcements,Date\n";
    
    // Output each announcement on each row.
    csv_file << Ann1.userID << "," << Ann1.message << "," << Ann1.date;
    csv_file << Ann2.userID << "," << Ann2.message << "," << Ann2.date;
    csv_file << Ann3.userID << "," << Ann3.message << "," << Ann3.date;

    // Close the file.
    csv_file.close();
}