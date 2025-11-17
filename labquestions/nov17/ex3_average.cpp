/*
Name: Jana Marie Reyes
Student ID: 200548478
Date: 11/17/25
File name: ex1_is_even.cpp
*/

#include <iostream>
using namespace std;

//define function first
void avg(int num1, int num2, int num3, int num4, int num5){
    //finds the average between 5 numbers
    double average = (num1 + num2 + num3 + num4 + num5) / 5.0;
    cout << "The average of those marks is: " << average << endl;
}

int main(){
    int first, second, third, fourth, fifth; //declare vars
    cout << "Please enter 5 integer marks: "; //asks user for input
    cin >> first >> second >> third >> fourth >> fifth; //initializes input into vars

    // Call the function
    avg(first, second, third, fourth, fifth); //calls function
    
    return 0;
}

