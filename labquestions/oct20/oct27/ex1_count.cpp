// Program Count prompts for the number of integers to sum.
// It then reads the integers in a loop, summing them.
// Finally, it prints the sum.

#include <iostream>
using namespace std;

int main ()
{
    int sum = 0;          // summing variable
    int dataValue;        // input value

    int loopCounter;      // loop counter
    int loopTotal;        // total number of integers

    loopCounter = 0;      // initialize loop counter

    cout << "Please input the number of integers that you would like to add: ";
    cin >> loopTotal;

    while (loopCounter < loopTotal)
    {
        cout << "Enter an integer value: ";
        cin >> dataValue;
        sum = sum + dataValue;
        loopCounter++;
    }

    cout << "The sum of the " << loopTotal << " integers is " << sum << endl;

    return 0;
}
