/*
Name: Jana Marie Reyes
Student ID: 200548478
Date: 11/3/25
File name: ex3_stars.cpp
*/

#include <iostream>
using namespace std;

int main() {
    int numStars;
    
    // Get user input for number of stars on first line
    cout << "How many stars on the first line? ";
    cin >> numStars;
    cout << endl;

    // Outer loop: controls the number of rows (counting down from numStars to 1)
    for (int row = numStars; row >= 1; row--) {
        
        // Inner loop: prints stars for current row
        for (int starCount = 1; starCount <= row; starCount++) {
            cout << "*";
        }
        
        // Move to next line after printing all stars for current row
        cout << endl;
    }
    
    return 0;
}