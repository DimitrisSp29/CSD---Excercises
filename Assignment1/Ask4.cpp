#include "std_lib_facilities.h"

/* ----------------------Available Items-----------------------------*/

string item1= "Cigarettes";                     
int item1_price = 5;
int item1_code = 1;

string item2= "Water Bottle";
double item2_price = 0.5;
int item2_code = 2;

string item3= "Magazine";
int item3_price = 3;
int item3_code = 3;

string item4= "Lighter";
int item4_price = 1;
int item4_code = 4;

string item5= "Wine";
double item5_price = 10;
int item5_code = 5;

/* ------------------------------------------------------------------*/

void print_available_items()        // Prints available items.
{
    cout << "Item: " << item1 << " Price: " << item1_price << " Code: " << item1_code << endl;
    cout << "Item: " << item2 << " Price: " << item2_price << " Code: " << item2_code << endl;
    cout << "Item: " << item3 << " Price: " << item3_price << " Code: " << item3_code << endl;
    cout << "Item: " << item4 << " Price: " << item4_price << " Code: " << item4_code << endl;
    cout << "Item: " << item5 << " Price: " << item5_price << " Code: " << item5_code << endl;
    cout << "Exit_Code: 99\n";
}


int main()                               // Start of the main function 
{
    double funds=0;                      // Variable containing the available funds.
    int item=0;                          // Variable containing the user chosen item code.
    cout << "Enter available funds: ";
    cin >> funds;
    print_available_items();             // Calls the function that prints the available items.
    while(cin >> item)                   // Runs the while loop as long as the user inputs data.
    {
        switch (item)                    // Selects a case for every different item code selected and
        {                                // if the user inputs an invalid entry or has insufficient funds outputs an according message.
            case 1:
            if(funds >= item1_price)
            {
                funds = funds - item1_price;
            }
            else
            {
                cout << "Insufficient funds!\n";
            }
            break;

            case 2:
            if(funds >= item2_price)
            {
                funds = funds - item2_price;
            }
            else
            {
                cout << "Insufficient funds!\n";
            }
            break;
            
            case 3:
            if(funds >= item3_price)
            {
                funds = funds - item3_price;
            }
            else
            {
                cout << "Insufficient funds!\n";
            }
            break;
            
            case 4:
            if(funds >= item4_price)
            {
                funds = funds - item4_price;
            }
            else
            {
                cout << "Insufficient funds!\n";
            }
            break;
            
            case 5:
            if(funds >= item5_price)
            {
                funds = funds - item5_price;
            }
            else
            {
                cout << "Insufficient funds!\n";
            }
            break;
            
            case 99: return 0; 
            
            default: "Invalid Entry!\n";
        }
    }
}