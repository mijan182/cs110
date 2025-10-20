#include <iostream>
#include <string>
using namespace std;

int b = 31;

int hashCodeForString(string& s)
{
  int code = 0;

  for (int i = 0; i < s.size(); i++)
    code = code * b + s[i];

  return code;
}

int main()
{
  string s = "4.5";
  
  cout << hashCodeForString(s) << endl;

  return 0;
}
