/*
Name: Jana Marie Reyes
Student ID: 200548478
Date: 11/24/25
File name: ex1_area.cpp
*/

#include <iostream>
using namespace std;

// Function prototypes:
void getValues(double &, double &);
double computeArea(double, double);
void printArea(double);

int main()
{
   double length, width, area;  // Changed from float to double

   cout << "This program computes the area of a rectangle." << endl;
   cout << "You will be prompted to enter both the length and width.";
   cout << endl << "Enter a real number (such as 7.88 or 6.3) for each.";
   cout << endl << "The program will then compute and print the area.";
   cout << endl;

   // call function getValues(length, width) here
   // call function computeArea(length, width) here
   // call function printArea(area) here

   getValues(length, width);
   area = computeArea(length, width);  // Store the returned value
   printArea(area);

   return 0;
}

/*
   Purpose:  To ask the user for the length and width of a rectangle and
             to return these values via the two parameters.
   Return:   Length   The length entered by the user.
             Width    The width entered by the user.
*/

void getValues(double & l, double & w)
{
    cout << "Please enter the length of your rectangle: ";
    cin >> l;
    cout << "Please enter the width of your rectangle: ";
    cin >> w;
}

/* Given:  Length   The length of the rectangle.
           Width    The width of the rectangle.
   Purpose:   To compute the area of this rectangle.
   Return: The area in the function name.
*/

double computeArea(double l, double w)
{
    // add code to compute area
    double ans = l * w;
    return ans;
}

/* Given:  Area    The area of a rectangle.
   Purpose:   To print Area.
   Return: Nothing.
*/
void printArea(double a)
{
    // add code to print area of the rectangle
    cout << "The area of the rectangle is: " << a << endl;  // Fixed "triangle" to "rectangle"
}