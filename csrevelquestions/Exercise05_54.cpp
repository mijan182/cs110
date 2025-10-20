#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

int main()
{
  // Open a file
  ifstream input("input.txt");

  int next;
  int previous = -2147483648;
  bool isInOrder = true;
  while (!input.eof()) // Read data to the end of file
  {
    input >> next; // Read data
    if (next < previous) 
    {
      isInOrder = false;
      break;
    }

    previous = next;
  }

  if (isInOrder) 
    cout << "The numbers are in an increasing order";
  else
    cout << "The numbers are not in an increasing order";

  input.close();

  return 0;
}