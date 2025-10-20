#include <iostream>
#include <string>
using namespace std;

char toHexChar(int);
string binaryToHex(string);
int binaryToDecimal(string);
string decimalToHex(int);
char toHexChar(int);

int main()
{
  // Prompt the user to enter a string
  cout << "Enter a binary number: ";
  string binaryValue;
  cin >> binaryValue;
  cout << "The hex value is " << binaryToHex(binaryValue) << endl;

  return 0;
}

string binaryToHex(string binaryValue) {
	int decimalValue = binaryToDecimal(binaryValue);
	return decimalToHex(decimalValue);
}

int binaryToDecimal(string binarystring)
{
	int value = binarystring[0] - '0';
	for (int i = 1; i < binarystring.length(); i++)
	{
		value = value * 2 + binarystring[i] - '0';
	}

	return value;
}

/** Convert a decimal to a hex as a string */
string decimalToHex(int decimal)
{
	string hex;

	while (decimal != 0) {
		int hexValue = decimal % 16;
		hex = toHexChar(hexValue) + hex;
		decimal = decimal / 16;
	}

	return hex;
}

/** Convert an integer to a single hex digit in a character */
char toHexChar(int hexValue)
{
	if (hexValue <= 9 && hexValue >= 0)
		return (char)(hexValue + '0');
	else  // hexValue <= 15 && hexValue >= 10
		return (char)(hexValue - 10 + 'A');
}