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
    
    //get user input for number of stars on first line
    cout << "How many stars on the first line? ";
    cin >> numStars;
    cout << endl;

    //for loop: controls the number of rows counting down from 1
    for (int row = numStars; row >= 1; row--) {
        
        //2nd for loop: prints stars for current row
        for (int starCount = 1; starCount <= row; starCount++) {
            cout << "*";
        }
        //goes to next line
        cout << endl;
    }
    
    return 0;
}