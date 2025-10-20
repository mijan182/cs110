#include <iostream>
using namespace std;

int main()
{
  cout << "Enter a temperature: ";
  double temperature;
  cin >> temperature;
  
  if (temperature < 30)
    cout << "too cold";
  else if (temperature >= 100)
    cout << "toll hot";
  else 
    cout << "just right";

  return 0;
}
