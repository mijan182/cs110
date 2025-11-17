/*
Name: Jana Marie Reyes
Student ID: 200548478
Date: 11/16/25
File name: A3-CRAB.cpp
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to generate random dice roll (1-6)
int getRoll(){
    int roll = (rand() % 6) + 1;
    return roll;
}

// Function to calculate sum of two dice
int calcSum(int die1, int die2){
    int total = die1 + die2;
    return total;
}

// Function to play one round of Craps and output results
int printRoll(int round, ofstream& output){
    int die1, die2, sum;

    // Roll two dice
    die1 = getRoll();
    die2 = getRoll();
    sum = calcSum(die1, die2);
    
    output << "You rolled " << die1 << " + " << die2 << " = " << sum << endl;

    // Check for immediate win (natural)
    if (sum == 7 || sum == 11)
    {
        output << "You win" << endl;
        return 1;
    }
    // Check for immediate loss (craps)
    else if (sum == 2 || sum == 3 || sum == 12)
    {
        output << "You lose" << endl;
        return 0;
    }
    // Point established - continue rolling
    else
    {
        int point = sum;
        output << "Point is " << point << endl;
        
        // Flag control loop for point rounds
        bool keepRolling = true;
        int result = 0;
        while (keepRolling)
        {
            die1 = getRoll();
            die2 = getRoll();
            sum = calcSum(die1, die2);
            
            output << "You rolled " << die1 << " + " << die2 << " = " << sum << endl;
            
            // Win if roll equals point
            if (sum == point)
            {
                output << "You win" << endl;
                result = 1;
                keepRolling = false;
            }
            // Lose if roll equals 7
            else if (sum == 7)
            {
                output << "You lose" << endl;
                result = 0;
                keepRolling = false;
            }
            // Continue rolling if neither point nor 7
        }
        return result;
    }            
}

// Function to calculate and output final results
void printResult(int rounds, int wins, int losses, ofstream& output){
    double winPerc = (static_cast<double>(wins)/rounds) * 100;
    double lossPerc = (static_cast<double>(losses)/rounds) * 100;

    output << "Results after " << rounds << " rounds: " << winPerc << "% win, " 
    << lossPerc << "% lose" << endl;
}

int main(){
    srand(time(0));  // Seed random number generator

    int numRounds;

    // Get number of rounds from user
    cout << "How many rounds? ";
    cin >> numRounds;

    // Validate minimum rounds requirement
    if (numRounds < 50){
        cout << "Error: Number of Rounds must be 50 or more."<< endl;
        return 1;
    }

    ofstream output("results.txt"); // Create output file
    if(!output){
        cout<<"Error: could not open results.txt" << endl;
        return 1;
    }

    int wins = 0;
    int losses = 0;

    // Count control loop for all rounds
    for(int currRound = 1; currRound <= numRounds; currRound++){
        output << "Round " << currRound << ":" << endl;

        // Play one round and track result
        int roundResult = printRoll(currRound, output);
        if(roundResult == 1){
            wins = wins + 1;
        }else{
            losses = losses + 1;
        }

        output << "------------"<<endl;
    }

    // Output final statistics
    printResult(numRounds, wins, losses, output);

    output.close();
    cout << "Results saved to results.txt"<< endl;
    return 0;
}