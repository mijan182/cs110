/*
Name: Jana Marie Reyes
ID: 200548478
FILENAME: DNA.cpp
DATE: 11/26/25
*/


#include <iostream>
#include <fstream>
using namespace std;

const int GENE_SIZE = 444;
const int NUM_PPL = 4;
const int GENE_PER_PPL = 2;

//function prototypes
bool isSameGene(char gene1[], char gene2[], int size);
void get1Gene(ifstream& input, char gene[], int size);
string dnaAnalysis(char gene1[], char gene2[]);


int main(){
    ifstream input("dna.txt");
    if (!input){
        cout<<"Error: Could not open dna.txt" << endl;
        return 1;
    }

    ofstream output("dnaAnalysis.txt");
    if(!output){
        cout << "Error: Could not create dnaAnalysis.txt" << endl;
        return 1;
    }

    char genes[NUM_PPL][GENE_PER_PPL][GENE_SIZE];


    for (int pereson = 0; person < NUM_PPL; person++){
        for (int geneNum = 0; geneNum < GENE_PER_PPL; geneNum++){
            get1Gene(input, genes[person][geneNum], GENE_SIZE);
        }
    }

    input.close();

    
}

//function prototypes
bool isSameGene(){

}

void get1Gene(){

}

void dnaAnalysis(){

}
