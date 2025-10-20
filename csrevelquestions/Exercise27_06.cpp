#include <iostream>
using namespace std;

int floatToIntBits(float value)
{
  int* t = reinterpret_cast<int*>(&value);
  return *t;
}

int main()
{
  float value = 4.5;
  
  cout << floatToIntBits(value) << endl;

  return 0;
}
