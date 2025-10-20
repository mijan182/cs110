#include <iostream>
#include <ctime> // for time function
#include <cstdlib> // for rand and srand functions
using namespace std;

int main()
{
  cout << "Enter a three-digit integer: ";
  int number;
  cin >> number;

  if (number / 100 == number % 10)
    cout << number << " is a palindrome" << endl;
  else
    cout << number << " is not a palindrome" << endl;

  return 0;
}
