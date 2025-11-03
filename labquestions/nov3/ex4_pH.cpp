/*
Name: Jana Marie Reyes
Student ID: 200548478
Date: 11/3/25
File name: ex4_pH.cpp
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double hydroxideIonConcentrate;

    cout << "This program calculates ph level." << endl;
    cout << "Enter 0 to quit the program" << endl;

    do {
        cout << "Please input the concentration of hydroxide: ";
        cin >> hydroxideIonConcentrate;

        if (hydroxideIonConcentrate == 0) {
            cout << "You entered 0, so quit the program." << endl;
            break;
        }

        // These calculations need to be INSIDE the do-while loop
        double hydroniumConcentrate = 1.0e-14 / hydroxideIonConcentrate;
        double phLvl = -log10(hydroniumConcentrate);

        cout << fixed << setprecision(10);
        cout << "The pH level of solution " << hydroxideIonConcentrate << " is " << phLvl << ". ";
        
        if (phLvl < 7.0) {
            cout << "The solution is acidic." << endl;
        } else {
            cout << "The solution is basic." << endl;
        }
        
        cout << endl;
        
    } while (hydroxideIonConcentrate != 0);  // Fixed variable name
    
    return 0;
}