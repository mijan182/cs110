/*
Name: Jana Marie Reyes
ID: 200548478
File name: ex2_arrayFunc.cpp
date: 12/1/25
*/
#include <iostream>
using namespace std;


//func prototypes

void fillArr(int[], int);
void printArr(int[], int);
int findMax(int[], int);

int main(){
    int arr[10]; //limits array to 10 slots
    fillArr(arr,10); //calls user input func
    cout<<"Array: "; 
    printArr(arr, 10); //calls print func
    cout<<"Max: "<<findMax(arr, 10)<<endl; //calls the "find max integer" func
    return 0;
}

//function: asks user for 10 integers
void fillArr(int arr[], int size){
    cout<<"Enter "<< size << " integers: "<<endl;
    for(int i = 0; i < size; i++){
        cout<<"Element "<< (i + 1)<<": ";
        cin>>arr[i]; //stores data in array
    }
}

//function: prints the array
void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

//function: finds the maximum integer in the array
int findMax(int arr[], int size) {
    int max = arr[0];  
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
