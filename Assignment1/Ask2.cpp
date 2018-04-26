/* This is a program that checks if the syntax of a string follows the Spanish exclamation and question mark rule
which states that each has to appear both at the beginning and the end of a word without the other one in between.
Dimitris S. Spythouris. A.M:4040 */
#include "std_lib_facilities.h"

void check_syntax(string Str) // Function that checks if the syntax of the inserted string is correct.
{
    int ExclamationNum=0;   // Number of exclamation marks found.
    int QuestionNum=0;      // Number of question marks found.
    int i=0;                // String iterator.
    while(Str[i]!='\0')         // While loop that asserts the validity of the inserted string
    {                           // by checking for the correct placement of the '!' or "?" characters.
        if(Str[i]=='!')
        {
            ExclamationNum++;
            i++;
            while(ExclamationNum!=2 && Str[i]!='\0')
            {
                if(Str[i]=='!')
                {
                    ExclamationNum++; 
                    break;
                }
                if(Str[i]=='?')
                {
                    cout << "The inserted text is invalid!\n";      // The string is invalid if an initial '!' character is followed by a '?'.
                    return;
                }
                i++;
            }
        }
        if (Str[i]=='?')
        {
            QuestionNum++;
            i++;
            while(QuestionNum!=2 && Str[i]!='\0')
            {
                if(Str[i]=='?')
                {
                    QuestionNum++;
                    break;
                }
                if(Str[i]=='!')
                {
                    cout << "The inserted text is invalid!\n";      // The string is invalid if an initial '?' character is followed by a '!'.
                    return;
                }
                i++;
            }
        }
        ++i;
    }
    if(ExclamationNum != 0 && ExclamationNum % 2 != 0)      // The string is invalid if there isn't an even number of exclamation marks.
    {
        cout << "The inserted text is invalid!\n";
        return;
    }
    if(QuestionNum !=0 && QuestionNum % 2 != 0)             // The string is invalid if there isn't an even number of question marks.
    {
        cout << "The inserted text is invalid!\n";
        return;
    }
    cout << "The inserted text is valid!\n";                // In all other cases the string is valid.
}


int main() // Start of the main function.
{
    string sentence;
    cout << "Please enter a sentence or a word: ";
    getline(cin,sentence);                             // Prompts the user to input a string
    check_syntax(sentence);                            // Checks the syntax.
    keep_window_open();     
    return 0;
}