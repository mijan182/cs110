// Write a C++ program that asks the user to enter the days (e.g., 1000) and
// converts the given days into the number of years, weeks and remaining days.
// For simplicity, assume a year has 365 days.  

// ****************

#include <iostream>
using namespace std;

int main() {
    int totalDays;
    int years, weeks, days;

    // Prompt the user to enter the total number of days
    cout << "Enter the total number of days: ";
    cin >> totalDays;

    // Calculate years
    years = totalDays / 365;

    // Calculate remaining days after accounting for years
    int remainingDaysAfterYears = totalDays % 365;

    // Calculate weeks from the remaining days
    weeks = remainingDaysAfterYears / 7;

    // Calculate the final remaining days
    days = remainingDaysAfterYears % 7;

    // Display the result
    cout << totalDays << " days is equivalent to: " << endl;
    cout << "Years: " << years << endl;
    cout << "Weeks: " << weeks << endl;
    cout << "Days: " << days << endl;

    return 0;
}