#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int choice;
    cout << "===== BASIC PROGRAM MENU =====" << endl;
    cout << "1. Even/Odd Checker" << endl;
    cout << "2. Temperature Converter" << endl;
    cout << "3. Multiplication Table" << endl;
    cout << "4. Input Validation" << endl;
    cout << "5. Calculator" << endl;
    cout << "6. Day of Week" << endl;
    cout << "7. String Reverser" << endl;
    cout << "8. Vowel Counter" << endl;
    cout << "9. File Writer & Reader" << endl;
    cout << "10. Grade Calculator" << endl;
    cout << "11. Leap Year Checker" << endl;
    cout << "Enter your choice (1-11): ";
    cin >> choice;
    cin.ignore(); // clear leftover newline

    switch (choice) {
        case 1: {
            int num;
            cout << "Enter a number: ";
            cin >> num;
            if (num % 2 == 0) cout << "Even" << endl;
            else cout << "Odd" << endl;
            break;
        }
        case 2: {
            double f, c;
            cout << "Enter Fahrenheit: ";
            cin >> f;
            c = (5.0 / 9) * (f - 32);
            cout << "Celsius: " << c << endl;
            break;
        }
        case 3: {
            int num;
            cout << "Enter number: ";
            cin >> num;
            for (int i = 1; i <= 10; i++)
                cout << num << " x " << i << " = " << num * i << endl;
            break;
        }
        case 4: {
            int num;
            do {
                cout << "Enter a positive number: ";
                cin >> num;
            } while (num <= 0);
            cout << "You entered: " << num << endl;
            break;
        }
        case 5: {
            double a, b;
            char op;
            cout << "Enter expression (ex: 3 + 2): ";
            cin >> a >> op >> b;
            switch (op) {
                case '+': cout << a + b; break;
                case '-': cout << a - b; break;
                case '*': cout << a * b; break;
                case '/': cout << a / b; break;
                default: cout << "Invalid operator";
            }
            cout << endl;
            break;
        }
        case 6: {
            int day;
            cout << "Enter number (1-7): ";
            cin >> day;
            switch (day) {
                case 1: cout << "Monday"; break;
                case 2: cout << "Tuesday"; break;
                case 3: cout << "Wednesday"; break;
                case 4: cout << "Thursday"; break;
                case 5: cout << "Friday"; break;
                case 6: cout << "Saturday"; break;
                case 7: cout << "Sunday"; break;
                default: cout << "Invalid";
            }
            cout << endl;
            break;
        }
        case 7: {
            string s;
            cout << "Enter string: ";
            getline(cin, s);
            for (int i = s.size() - 1; i >= 0; i--)
                cout << s[i];
            cout << endl;
            break;
        }
        case 8: {
            string s;
            cout << "Enter string: ";
            getline(cin, s);
            int count = 0;
            for (int i = 0; i < s.size(); i++) {
                char c = tolower(s[i]);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    count++;
            }
            cout << "Vowel count: " << count << endl;
            break;
        }
        case 9: {
            ofstream out("names.txt");
            cout << "Enter 5 names:" << endl;
            for (int i = 0; i < 5; i++) {
                string name;
                getline(cin, name);
                out << name << endl;
            }
            out.close();

            ifstream in("names.txt");
            string line;
            cout << "\nNames from file:" << endl;
            while (getline(in, line))
                cout << line << endl;
            in.close();
            break;
        }
        case 10: {
            int score;
            cout << "Enter score (0-100): ";
            cin >> score;
            if (score >= 90) cout << "A";
            else if (score >= 80) cout << "B";
            else if (score >= 70) cout << "C";
            else if (score >= 60) cout << "D";
            else cout << "F";
            cout << endl;
            break;
        }
        case 11: {
            int year;
            cout << "Enter year: ";
            cin >> year;
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                cout << "Leap year";
            else
                cout << "Not a leap year";
            cout << endl;
            break;
        }
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
