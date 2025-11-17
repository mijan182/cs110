//
// Program to test "is_even" function.
//

/*
Name: Jana Marie Reyes
Student ID: 200548478
Date: 11/17/25
File name: ex1_is_even.cpp
*/

#include <iostream>
using namespace std;


void is_even(int); // Function Prototype


int main()
{
    int num;

    cout << "Enter an integer:\n";
    cin >> num;
    cout << "Is " << num << " even?  ";

    is_even(num);

    cout << endl;

    return 0;
}


// *is_even* Function Definition.
// Prints "yes" if a is even, "no" otherwise.
void is_even(int a)
{
    if(a % 2 == 0){ //checks if even
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
}