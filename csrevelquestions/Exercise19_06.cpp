#include <iostream>
using namespace std;

// T is a generic type
template<typename T>
bool ordered(const T list[], int size, bool ascending = true)
{
  bool ordered = true;
  if (ascending)
  {
    for (int i = 0; i < size - 1; i++)
      if (list[i] > list[i + 1]) 
      {
        ordered = false;
        break;
      }

    return ordered;
  }
  else
  {
    for (int i = 0; i < size - 1; i++)
      if (list[i] < list[i + 1])
      {
        ordered = false;
        break;
      }
  }

  return ordered;
}

template<typename T>
void printArray(const T list[], int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    cout << list[i] << " ";
  }
  cout << endl;
}

int main()
{
  int list1[] = { 3, 5, 1, 0, 2, 8, 7 };
  cout << (ordered(list1, 7) ? "true" : "false") << endl;
  cout << (ordered(list1, 7, false) ? "true" : "false") << endl;

  int list2[] = { 1, 2, 3, 5, 7, 8 };
  cout << (ordered(list2, 6) ? "true" : "false") << endl;
  cout << (ordered(list2, 6, true) ? "true" : "false") << endl;
  cout << (ordered(list2, 6, false) ? "true" : "false") << endl;

  return 0;
}
