/*
Name: Jana Marie Reyes
Student ID: 200548478
Date: 11/17/25
File name: ex1_is_even.cpp
*/

#include <iostream>
using namespace std;

double avg(int, int, int, int, int); //prototype

int main(){
    int first, second, third, fourth, fifth; //declare vars
    cout << "Please enter 5 integer marks: "; //asks user for input
    cin >> first >> second >> third >> fourth >> fifth; //initializes input into vars

    // Call the function directly in the cout statement
    cout << "The average of those marks is: " << avg(first, second, third, fourth, fifth) << endl;

    return 0;
}

//define function avg
double avg(int num1, int num2, int num3, int num4, int num5){
    //finds the average between 5 numbers
    double average = (num1 + num2 + num3 + num4 + num5) / 5.0;
    return average;
}