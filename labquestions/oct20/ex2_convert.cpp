// Program Convert converts a temperature in Fahrenheit to
// Celsius or a temperature in Celsius to Fahrenheit
// depending on whether the user enters an F or a C.

#include <iostream>
using namespace std;

int main() {
    char letter;     // User's conversion choice (C/c or F/f)
    int tempIn;      // Input temperature
    int tempOut;     // Output temperature

    cout << "Input Menu" << endl << endl;
    cout << "F: Convert from Fahrenheit to Celsius" << endl;
    cout << "C: Convert from Celsius to Fahrenheit" << endl;
    cout << "Type a C or an F, then press return." << endl << endl;

    cout << "Enter your option: ";
    cin >> letter;

    // --- First IF structure: validate the letter ---
    // We check if the user typed C, c, F, or f.
    // If not, we show "wrong letter" and skip conversion.
    if (letter != 'C' && letter != 'c' && letter != 'F' && letter != 'f') {
        cout << "Wrong letter." << endl;
    } 
    else {
        // Only ask for temperature if letter is valid
        cout << "Type an integer number: ";
        cin >> tempIn;

        // --- Second IF structure: perform the right conversion ---
        // If the user chose C or c, convert Celsius → Fahrenheit.
        // Otherwise, convert Fahrenheit → Celsius.
        if (letter == 'C' || letter == 'c')
            tempOut = (9 * tempIn / 5) + 32;
        else
            tempOut = 5 * (tempIn - 32) / 9;

        cout << endl;
        cout << "Temperature to convert: " << tempIn << endl;
        cout << "Converted temperature: " << tempOut << endl;
    }

    return 0;
}
