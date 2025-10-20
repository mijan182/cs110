#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Please enter three integer numbers: ";
    cin >> a >> b >> c;

    int smallest = a;

    if (b < smallest)
        smallest = b;
    if (c < smallest)
        smallest = c;

    cout << "The smallest number is: " << smallest << endl;
    return 0;
}
