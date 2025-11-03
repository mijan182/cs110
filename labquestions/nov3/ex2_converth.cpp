// Program Convert converts a temperature in Fahrenheit to
// Celsius or a temperature in Celsius to Fahrenheit
// depending on whether the user enters an F or a C.

/*
Name: Jana Marie Reyes
Student ID: 200548478
Date: 11/3/25
File name: ex2_converth1.cpp
*/

#include <iostream>
using namespace std;

int main()
{
    char letter;    // Place to store input letter
    int tempIn;     // Temperature to be converted
    int tempOut;    // Converted temperature
    char repeat;    // Variable to store repeat choice

    cout << "Input Menu" << endl << endl;
    cout << "F: Convert from Fahrenheit to Celsius" << endl;
    cout << "C: Convert from Celsius to Fahrenheit" << endl;

    //ADD CODE: Begin do-while loop here
    do { 
        cout << "Type a C or an F, then press return." << endl;
        cin >> letter;

        //REPLACE CODE: use a while loop instead of an if/else to detect
        //              and correct wrong letters
        while (letter != 'C' && letter != 'c' && letter != 'F' && letter != 'f') { /*while the letter is not either C or c of f or F*/
            cout << "Wrong letter." << endl;  
            cout << "Type a C or an F, then press return." << endl;
            cin >> letter;
        }

        cout << "Type an integer number, then press return." << endl;
        cin >> tempIn;

        if (letter == 'C' || letter == 'c') {
            tempOut = (9 * tempIn / 5) + 32;
        } else {
            tempOut = 5 * (tempIn - 32) / 9;
        }
        cout << "Temperature to convert: " << tempIn << endl;
        cout << "Converted temperature: " << tempOut << endl;

        //ADD CODE: ask user "Do you want to convert another temperature (y/n).
        cout << "Do you want to convert another temperature? (y/n): ";
        cin >> repeat;

    //ADD CODE: end do-while loop here - repeat loop if user typed a 'y'
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}