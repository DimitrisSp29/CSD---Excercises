#include "std_lib_facilities.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

int min(int x, int y, int z)              // Function that calculates the minimum of 3 numbers.
{
   return min(min(x, y), z);
}


int levenshtein_distance(string s1, string s2)              // Function that calculates the Levenshtein distance between 2 strings.
{
    int str1l = s1.length();        // Variable that holds the size of the first string.
    int str2l = s2.length();        // Variable that holds the size of the second string.
    int sub_cost = 0;               // The substitution cost of each operation.
    int edits[str1l+1][str2l+1];    // The array that holds the total edits needed for each case.
    size_t i,j;                     // The iterators needed for looping the array.
    for(i=0; i<=str1l; i++)         // For loop that sets every cell of the array to 0
    {
        for(j=0; j<=str2l; j++)
        {
            edits[i][j] = 0;
        }
    }
    for (i = 0; i <=str1l; i++)     // For loop that sets the values of the first column equal to the according row number.
    {
        edits[i][0] = i;
    }
    for (j = 0; j <=str2l; j++)     // For loop that sets the values of the first row equal to the according column number.
    {
        edits[0][j] = j;
    }


    //-----|Main loop that compares each letter of the strings and calculates the number of edits|-----//
    for(i=1; i<=str1l; i++)
    {
          for(j=1; j<=str2l; j++)
          {
                if(s1[i] == s2[j])              // If the according characters of the string are equal,
                {                               // the sub. cost is 0 and the edits are equal to the upper left diagonal value.
                      sub_cost = 0;
                      edits[i][j]=edits[i-1][j-1];
                }
                else                            // If they are unequal then the edits are equal to
                {                               // the minimum value of the left + 1, upper + 1, and upper left + sub. cost values.
                        sub_cost = 1;
                        edits[i][j] = min(edits[i-1][j] + 1,
                                          edits[i][j-1] + 1,
                                          edits[i-1][j-1]+sub_cost);
                }
          }
    }
    //-------------------------------------------------------------------------------------------------//


    return edits[str1l][str2l];                 // Returns the lower right value of the array which is the total edits needed. 
}

string delete_linebreaks(string str)	//Function that removes the linebreaks of the inserted string.
{
	string::size_type pos = 0;
	while ( ( pos = str.find ("\r\n",pos) ) != string::npos )		// Searches for the "\r\n" characters until the end of file and removes them.
	{
		str.erase ( pos, 2 );
	} 
	return str;
}

double difference_percentage(string string1, string string2)        // Function that calculates the percentage difference of the two strings.
{
      double lev_dis = levenshtein_distance(string1, string2);         // Calculates the levenshtein distance.
      int max_length = max(string1.length()-1, string2.length()-1);     // Defines the max length of the two strings.
      double percentage = (lev_dis / double(max_length))*100;       // Divides the levenshtein distance by the max string length to calculate the percentage.
      cout << "The file A and file B are " << setprecision(3) << percentage << "% " << "different.\n";
}

int main()              // Start of the main function.
{
    ifstream file1("Read_a.txt");         // Opens the two files for reading.
    ifstream file2("Read_b.txt");         
    if(!file1 || !file2)                  // If the program is unable to open a file print an error message and terminate.
    {
        cout << "Error opening files!\n";
        return -1;
    }

    string word1((std::istreambuf_iterator<char>(file1)), (std::istreambuf_iterator<char>()));      // Use of the istreambuf_iterator to place the contents of the files
    string word2((std::istreambuf_iterator<char>(file2)), (std::istreambuf_iterator<char>()));      // inside the according strings.
    
    word1 = delete_linebreaks(word1);		//Remove the linebreaks of each word.
    word2 = delete_linebreaks(word2);

    difference_percentage(word1, word2);    // Calculate the percentage difference of the two files.
    file1.close();          //Close the files.
    file2.close();
    keep_window_open();
}