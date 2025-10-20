//*******************************************************************************************
//
// Student name: Sami Uddin
//
// Student number: 123-456-789
//
// Assignment number: 1
//
// Date written: date
//
// Problem statement: This C++ program inputs the number from a file, and outputs the sum of
// the digits of that number. Then it treats it as tons and outputs the equivalent in pounds,
// ounces, kilograms, and grams.
// The program also outputs the conversion factors used.
//
// Input: a whole number from an input file
//
// Output: the sum of the digits and the number of tons converted to pounds, ounces,
//         kilograms and grams, as well as the conversion factors used, all to an output file
//
// Main algorithm: input the number from the file
//		   separate the digits of the number
//	           calculate the sum of the digits and print it out
//		   treat the sub as the number of tons
//                 convert the number of tons into the required amounts as follows:
//                 the new unit equals tons multiplied by the appropriate conversion factor
//                 print out the converted amounts
//                 print out the conversion factors
//
// Major variables: number - the whole number from the file
//                  sumOfDigits - adding digits and store them
//                  numberOfTons - the number of tons 
//                  TONS_TO_POUNDS - the conversion factor to pounds
//                  TONS_TO_OUNCES - the conversion factor to ounces
//                  TONS_TO_KILOGRAMS - the conversion factor to kilograms
//                  TONS_TO_GRAMS - the conversion factor to grams
//                  pounds - the equivalent amount in pounds
//                  ounces - the equivalent amount in ounces
//                  kilograms - the equivalent amount in kilograms
//                  grams - the equivalent amount in grams
//
// Assumptions: - a ton means 2000 pounds, 32000 ounces, 907.185 kilograms and 907185 grams
//
// Program limitations: - hardcoded for these four conversions only
//                      - almost no formatting of output is performed
//
//*******************************************************************************************

#include <iostream> // needed for I/O
#include <fstream> // needed for file I/O

using namespace std;

int main()
{
     // declaring the variables
     int number;
     int lastDigit;
     int secondLastDigit;
     int thirdLastDigit;
     int sumOfDigits;
     int numberOfTons;     

     // declare the conversion factors as constants
     const int TONS_TO_POUNDS      = 2000;
     const int TONS_TO_OUNCES    =   32000;
     const float TONS_TO_KILOGRAMS =  907.185; 
     const int TONS_TO_GRAMS  = 907185;

     // variables for the other four units of measure
     int pounds;        
     int ounces;
     float kilograms;
     int grams;

     // declare the file buffers
     ifstream inFile; // call the input file buffer inFile
     ofstream outFile; // call the output file buffer outFile

     // try to open the input file
     inFile.open("input.txt");

     // error check file open
     if(!inFile) // if there was a problem
     {
          // print an error message
          cout << "Error opening the input file, input.txt. Exiting..." << endl;

          // stop the program
          return 1;
     }

     // try to open the input file
     outFile.open("output.txt");  

     // 1st part: read the number    
 
     inFile >> number;

     // separating the digits

     lastDigit = number % 10;
     number = number / 10;

     secondLastDigit = number % 10;
     number = number / 10;

     thirdLastDigit = number % 10;
     number = number / 10;

     // sum of the digits
     
     sumOfDigits = lastDigit + secondLastDigit + thirdLastDigit;

     // output the sum of digits
     
     outFile << sumOfDigits << " is the sum of digits" << endl;


     //2nd part: assign the sum as the number of tons to be converted

     numberOfTons = sumOfDigits;

     // convert the number of tons into the other units of measure

     pounds = numberOfTons * TONS_TO_POUNDS;	// convert to pounds by multiplying by the conversion factor 
     ounces = numberOfTons * TONS_TO_OUNCES; // convert to ounces by multiplying by the conversion factor

     kilograms = float(numberOfTons) * TONS_TO_KILOGRAMS; // convert to kilograms with type casting
     grams = numberOfTons * TONS_TO_GRAMS; // convert to grams by multiplying by the conversion factor

     // output the calculated amounts in the other units
     outFile <<  numberOfTons << " tons are equivalent to:" << endl;
     outFile <<  pounds << " pounds" << endl;
     outFile <<  ounces << " ounces" << endl;
     outFile <<  kilograms << " kilograms" << endl;
     outFile <<  grams << " grams" << endl << endl;

     // output the conversion factors
     outFile << "The conversion factors used were as follows. 1 ton equals:" << endl;
     outFile << TONS_TO_POUNDS << " pounds" << endl;
     outFile << TONS_TO_OUNCES << " ounces" << endl;
     outFile << TONS_TO_KILOGRAMS << " kilograms" << endl;
     outFile << TONS_TO_GRAMS << " grams" << endl;

     // close the input and output files
     inFile.close();
     outFile.close();

     return 0; // exiting from the program
}