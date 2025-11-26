/*
Name: Jana Marie Reyes
Student ID: 200548478
Date: 11/24/25
File name: ex2_calcPay.cpp
*/
#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes 
void getData(double &, double &);
double calcPay(double, double);
void printPay(double, double, double);

int main() {
    double payRate, hoursWorked, totalPay;
    
    cout << "This program calculates total pay for an employee." << endl;
    
    getData(payRate, hoursWorked);
    totalPay = calcPay(payRate, hoursWorked);
    printPay(payRate, hoursWorked, totalPay);
    
    return 0;
}

//se reference parameters to get user input
void getData(double &payRate, double &hoursWorked) {
    cout << "Please enter pay rate per hour: ";
    cin >> payRate;
    cout << "Please enter hours worked: ";
    cin >> hoursWorked;
}

//implement the calculation
double calcPay(double payRate, double hoursWorked) {
    return payRate * hoursWorked;
}

//add all required parameters and implement output
void printPay(double payRate, double hoursWorked, double totalPay) {
    cout << fixed << setprecision(2);
    cout << "For an employee who worked " << hoursWorked 
         << " hours with a pay rate $ " << payRate << " per hour," << endl;
    cout << "The total pay is $ " << totalPay << "." << endl;
}