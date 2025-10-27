// Program LineCt counts the number of characters per line
// and the number of lines in a file.
// Assumption: There is a '\n' before the EOF. Exercise extension fixes this.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int lineNo;
    char character;
    int number;
    ifstream inData;

    inData.open("LineData.txt");
    lineNo = 0;
    inData.get(character);

    while (!inData.eof())   // loop until the end of file
    {
        lineNo++;
        number = 0;

        while (character != '\n' && !inData.eof())   // loop until end of line or EOF
        {
            number++;               // count this character
            inData.get(character);  // read next character
        }

        cout << "Line " << lineNo << " contains "
             << number << " characters." << endl;

        inData.get(character); // get the next character, clear out the '\n'
    }

    return 0;
}
