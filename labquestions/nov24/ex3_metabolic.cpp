/*
Name: Jana Marie Reyes
Student ID: 200548478
Date: 11/24/25
File name: ex2_metabolic.cpp
*/

#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes
void getData(double &mass, double &at, double &cp, double &pre, double &post, double &vaf);
void calcVOC(double pre, double post, double vaf, double &voc);
double calcSTP(double voc, double cp, double at);
double calcMP(double stp, double mass);
void printMetPower(double mass, double at, double cp, double pre, double post, double vaf, double mp);

int main()
{
    // declare variables
    double mass, at, cp, pre, post, vaf;
    double voc, stp, mp;
    
    cout << "This program computes the metabolic power of mammals and reptiles." << endl;
    
    // get input data
    getData(mass, at, cp, pre, post, vaf);
    
    // calculate volume of oxygen consumed
    calcVOC(pre, post, vaf, voc);
    
    // calculate standard temp and pressure
    stp = calcSTP(voc, cp, at);
    
    // calculate metabolic power
    mp = calcMP(stp, mass);
    
    // print results
    printMetPower(mass, at, cp, pre, post, vaf, mp);
    
    return 0;
}

// Function to get input data from user
void getData(double &mass, double &at, double &cp, double &pre, double &post, double &vaf)
{
    cout << "Please input the mass of the animal: ";
    cin >> mass;
    cout << "Please input the ambient temperature: ";
    cin >> at;
    cout << "Please input chamber pressure: ";
    cin >> cp;
    cout << "Please input concentration of oxygen in ambient air (pre-animal): ";
    cin >> pre;
    cout << "Please input concentration of oxygen in ambient air (post-animal): ";
    cin >> post;
    cout << "Please input the rate of oxygen: ";
    cin >> vaf;
    cout << endl;
}

// Function to calculate volume of oxygen consumed
void calcVOC(double pre, double post, double vaf, double &voc)
{
    voc = vaf * (pre - post) / (1 - post);
}

// Function to correct to standard temperature and pressure
double calcSTP(double voc, double cp, double at)
{
    const double C1 = 273.0;
    double stp = voc * (cp / 760.0) * (C1 / (C1 + at));
    return stp;
}

// Function to calculate metabolic power
double calcMP(double stp, double mass)
{
    const double C2 = 0.179;
    double mp = stp / (mass * C2);
    return mp;
}

// function to print all results
void printMetPower(double mass, double at, double cp, double pre, double post, double vaf, double mp)
{
    cout << fixed << setprecision(4);
    cout << "The mass of the animal is " << mass << " grams." << endl;
    cout << "The ambient temperature is " << at << " degrees." << endl;
    cout << "The chamber pressure is " << cp << " mmHG." << endl;
    cout << "The concentration of ambient air (pre-animal) is " << pre << "." << endl;
    cout << "The concentration of ambient air (post-animal) is " << post << "." << endl;
    cout << "The rate of oxygen is: " << vaf << " mL/hr." << endl;
    cout << endl;
    cout << "The metabolic power for this mammal or reptile is " << mp << "." << endl;
}