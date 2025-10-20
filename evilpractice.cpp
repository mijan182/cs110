#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (){

    int choice;
    double num1, num2, result;

    while(true){
        cout << "\n===== CALCULATOR MENU =====\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";
        cout << "============================\n";
        cout << "Enter choice: ";
        cin >> choice;
    }

    switch(choice){
        case 1:
            cout<< "enter first number: ";
            cin >> num1;
            cout<< "enter second number: ";
            cin >> num2;
            result = num1 + num2;
            cout << "result: "<<result<<endl;
            break;

        case 2:
            cout<< "enter first number: ";
            cin >> num1;
            cout<< "enter second number: ";
            cin >> num2;
            result = num1 - num2;
            cout << "result: "<< result<<endl;
            break;
        case 3:
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;

        case 4:
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
            while (num2 == 0) {
                cout << "Cannot divide by zero! Enter a non-zero number: ";
                cin >> num2;
        }

        result = num1/num2;
        cout<<"result: "<< result<<endl;
        break;

        case 5:
            cout<<"Exiting program...\n";
            return 0;

        default:
            cout<<"Invalid choice! Try again. \n";
    }

}