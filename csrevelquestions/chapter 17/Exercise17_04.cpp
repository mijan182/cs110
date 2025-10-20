#include <iostream>
#include <iomanip>
using namespace std;

double m(int i)
{
  if (i == 1)
    return 1;
  else
    return m(i - 1) + 1.0 / i;
}

int main()
{
  cout << setw(4) << left << "i" << setw(20) << "m(i)" << endl;
  for (int i = 1; i <= 10; i++)
    cout << setw(4) << i << setw(20) << showpoint 
      << setprecision(5) << m(i) << endl;

  return 0;
}
