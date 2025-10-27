#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double balance = 10.00;     // Starting balance
    double cost;                // Cost of each song
    const double CHEAPEST = 0.99;  // Minimum song cost

    cout << fixed << setprecision(2); // Format money output to 2 decimals

    while (balance >= CHEAPEST) {
        cout << "\nEnter the cost of a song: ";
        cin >> cost;

        if (cost <= 0) {
            cout << "Invalid cost. Please enter a positive value.\n";
            continue;
        }

        if (cost <= balance) {
            balance -= cost;
            cout << "Song purchased for $" << cost << "! Enjoy!!!\n";
            cout << "Your remaining balance is: " << balance << endl;
        } else {
            cout << "Your choice is too expensive!!!  Choose another one please!\n";
            cout << "Your remaining balance is: " << balance << endl;
        }
    }

    cout << "\nYour balance is $" << balance 
         << ". You cannot buy more songs.\n";
    cout << "Come again!" << endl;

    return 0;
}