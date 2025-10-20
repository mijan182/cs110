//*****************************************************************************************
//
// Student name: Sami Uddin
//
// Student number: 123-456-789
//
// Assignment number: X
//
// Program name: assignment2.cpp
//
// Date written: date
//
// Problem statement: This C++ program displays the day of the week from a given date.
//
// Input: an input file, called dates.txt. Each line is of the form
//                  YYYY MMM D/DD
//
// Output: an input file, called daynames.txt. Each line displays the day of the week
//          for a date, also indicates if that date is invalid.
//
//
// Algorithm used: Use Zeller's formula and check the leap year.
//
// Program limitations: hardcoded for specific input and output files
//
//*****************************************************************************************

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    // declaring variables
    int month, day, year;
    string getMonth;

    // declare the file buffers
    ifstream inData;
    ofstream outData;

     // try to open the input file
    inData.open("dates.txt");

    // error check file open
    if (!inData)    // there was a problem opening the file
    {
        cout << "Unable to open the input file dates.txt. Exiting...\n";    // print error message
        return 1;       // and stop program
    }
    
    // try to open the input file
    outData.open("daynames.txt");

    // reading the first line from the file
    inData >> year >> getMonth >> day;

    // declaring and initializing variables
    int numberOfDaysInMonth = 0;
    string monthName, dayName;
    int tempYear;
    int numberOfEntry = 0;

    // creating a while loop that will read numbers until the end of the file
    while (inData)
    {
        // counting the number of entries
        numberOfEntry++;

        // assigning month name from month code and assigning days of months
        if (getMonth == "JAN")
        {
            monthName = "January";
            month = 1;
            numberOfDaysInMonth = 31;
        }
        else if (getMonth == "FEB")
        {
            monthName = "February";
            month = 2;
            //cheking leap year
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                numberOfDaysInMonth = 29;
            else
                numberOfDaysInMonth = 28;
        }
        else if (getMonth == "MAR")
        {
            monthName = "March";
            month = 3;
            numberOfDaysInMonth = 31;
        }
        else if (getMonth == "APR")
        {
            monthName = "April";
            month = 4;
            numberOfDaysInMonth = 30;
        } 
        else if (getMonth == "MAY")
        {
            monthName = "May";
            month = 5;
            numberOfDaysInMonth = 31;
        }
        else if (getMonth == "JUN")
        {
            monthName = "June";
            month = 6;
            numberOfDaysInMonth = 30;
        }
        else if (getMonth == "JUL")
        {
            monthName = "July";
            month = 7;
            numberOfDaysInMonth = 31;
        }
        else if (getMonth == "AUG")
        {
            monthName = "August";
            month = 8;
            numberOfDaysInMonth = 31;
        }
        else if (getMonth == "SEP")
        {
            monthName = "September";
            month = 9;
            numberOfDaysInMonth = 30;
        }
        else if (getMonth == "OCT")
        {
            monthName = "October";
            month = 10;
            numberOfDaysInMonth = 31;
        }
        else if (getMonth == "NOV")
        {
            monthName = "November";
            month = 11;
            numberOfDaysInMonth = 30;
        }
        else if (getMonth == "DEC")
        {
            monthName = "December";
            month = 12;
            numberOfDaysInMonth = 31;
        }

        // checking validity of the date and adjusting month value for the algorithm
        if (day > 0 && day <= numberOfDaysInMonth)
        {
            tempYear = year;
            if (month == 1)
            {
                month = 13;
                tempYear = --year;
            }
            else if (month == 2)
            {
                month = 14;
                tempYear = --year;
            }

            int k = tempYear % 100;
            int j = (int)(tempYear / 100);

            // calculating days of a week using Zeller's formula
            int dayOfWeek = (int)(day + (int)((month + 1) * 26.0 / 10) + k + (int)(k / 4.0) + (int)(j / 4.0) + 5 * j) % 7;

            // assigning day names
            switch (dayOfWeek)
            {
            case 0:
                dayName = "Saturday"; break;
            case 1:
                dayName = "Sunday"; break;
            case 2:
                dayName = "Monday"; break;
            case 3:
                dayName = "Tuesday"; break;
            case 4:
                dayName = "Wednesday"; break;
            case 5:
                dayName = "Thursday"; break;
            case 6:
                dayName = "Friday"; break;
            }
            //output the day name in the file
            outData << day << " " << monthName << " " << year << " is " << dayName << "." << endl;
        }
        else outData << day << " " << monthName << " " << year << " is an invalid date." << endl;

        // reading next line of information
        inData >> year >> getMonth >> day;
    }
    // output total entries 
    outData << "Total Dates: " << numberOfEntry << endl;

    // closing files
    inData.close();
    outData.close();

    return 0;
}