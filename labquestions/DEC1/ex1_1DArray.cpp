/*
Name: Jana Marie Reyes
ID: 200548478
File name: ex1_IDArray.cpp
date: 12/1/25
*/

#include <iostream>
using namespace std;

//func prototypes
void fillArr(int[],int); 
void returnAArr(int[], int);
void returnDArr(int[], int);
int sumArr(int[], int);

int main(){
    int arr[10]; //array size 10
    fillArr(arr, 10); //limits to 10

    cout<<"Index Ascending: "; //calls index ascending func
    returnAArr(arr, 10);
    cout << endl;

    cout<<"Index Descending: ";//calls index descending func
    returnDArr(arr, 10);
    cout << endl;

    cout<<"The Total is: ";
    cout << sumArr(arr, 10); //calls sum func
    cout << endl;



}

//asks for user input
void fillArr(int arr[], int size){
    cout<<"Please give me "<< size << " numbers: "<<endl;
    for(int i = 0; i < size; i++){
        cin>>arr[i]; //stores data in array
    }
}

//returns index ascending order
void returnAArr(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i];
        if ( i < size - 1){
            cout<<", ";
        }
    }
}

//returns index descending order
void returnDArr(int arr[], int size){
    for(int i = size - 1; i >= 0; i--){ 
        cout << arr[i];
        if(i > 0){
            cout << ", ";
        }
    }

}

//returns sum of the array
int sumArr(int arr[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i]; 
    }
    return sum;
}
