#include <iostream>
#include <string>

using namespace std;

//ADD CODE: Add prototypes for the unmix and decipher functions here

string unmix(string);
void decipher(string &);


int main()
{
	string code = "K*@*R*S*\037*D*W*D*Q*B*H*R*D* ";
	cout << "Step 0: " << code << endl;

	string unmixed;
	unmixed = unmix(code);
	cout << "Step 1: " << unmixed << endl;

	decipher(unmixed);
	cout << "Step 2: " << unmixed << endl;

	return 0;
}

//Function unmix:
//  Returns a new string containing
//  only the even characters of string s
string unmix(string s)
{
	string ret;
	for (int i = 0; i < s.length(); i++)
	{
		//ADD CODE: if i is even

        if(i % 2== 0)
		{
			//COMPLETE LINE: add the character at i onto ret
			ret += s[i];
		}
	}
	return ret;
}

//Function decipher:
//  Implements a Caesar Cipher decoder
//  every character in s will have 1 added on to its value
void decipher(string &s)
{
	//ADD CODE: Write a for loop to that counts i from 0 to the length of string s
    for(int i = 0; i < s.length(); i++)
	{
		s[i] = s[i]+1;
	}
}