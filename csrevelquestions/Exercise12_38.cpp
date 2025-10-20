#ifndef IMPROVEDSTACK_H
#define IMPROVEDSTACK_H
#include <memory>
using namespace std;

template<typename T>
class Stack
{
public:
  Stack();
  Stack(const Stack&);
  ~Stack();
  bool empty() const;
  T peek() const;
  void push(T value);
  T pop();
  int getSize() const;

private:
  unique_ptr<T[]> elements;
  int size;
  int capacity;
  void ensureCapacity();
};

template<typename T>
Stack<T>::Stack(): size(0), capacity(16)
{
  elements = unique_ptr<T[]>(new T[capacity]);
}

template<typename T>
Stack<T>::Stack(const Stack& stack)
{
  elements = unique_ptr<T[]>(new T[stack.capacity]);
  size = stack.size;
  capacity = stack.capacity;
  for (int i = 0; i < size; i++)
  {
    elements[i] = stack.elements[i];
  }
}

template<typename T>
Stack<T>::~Stack()
{
}

template<typename T>
bool Stack<T>::empty() const
{
  return (size == 0);
}

template<typename T>
T Stack<T>::peek() const
{
  return elements[size - 1];
}

template<typename T>
void Stack<T>::push(T value)
{
  ensureCapacity();
  elements[size++] = value;
}

template<typename T>
void Stack<T>::ensureCapacity()
{
  if (size >= capacity)
  {
    unique_ptr<T[]> temp(new T[capacity]);
    // Copy elements to temp
    for (int i = 0; i < size; i++)
      temp[i] = elements[i];

    capacity = 2 * size;
    elements = unique_ptr<T[]>(new T[capacity]);
    // Copy temp to new elements
    for (int i = 0; i < size; i++)
      elements[i] = temp[i];
  }
}

template<typename T>
T Stack<T>::pop() 
{
  return elements[--size];
}

template<typename T>
int Stack<T>::getSize() const
{
  return size;
}

#endif

#include <iostream>
using namespace std;

int main()
{
  Stack<int> stack;

  for (unsigned i = 1; i <= 100; i++)
  {
    stack.push(i);
  }

  while (!stack.empty())
  {
    cout << stack.pop() << endl;
  }

  return 0;
}