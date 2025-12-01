/*
Name: Jana Marie Reyes
ID: 200548478
FILENAME: Assignment4.cpp
DATE: 11/26/25
*/

#include <iostream>
#include <fstream>
using namespace std;

const int GENE_SIZE = 444;
const int NUM_PPL = 4;
const int GENE_PER_PPL = 2;

// Function prototypes
bool isSameGene(char gene1[], char gene2[], int size);
void get1Gene(ifstream& input, char gene[], int size);
string dnaAnalysis(char gene1[], char gene2[]);

int main() {
    ifstream input("dna.txt");
    if (!input) {
        cout << "Error: Could not open dna.txt" << endl;
        return 1;
    }

    ofstream output("dnaAnalysis.txt");
    if (!output) {
        cout << "Error: Could not create dnaAnalysis.txt" << endl;
        return 1;
    }

    // 3D array: [person][gene number][base position]
    char genes[NUM_PPL][GENE_PER_PPL][GENE_SIZE];

    // Read all genes from file
    for (int person = 0; person < NUM_PPL; person++) {
        for (int geneNum = 0; geneNum < GENE_PER_PPL; geneNum++) {
            get1Gene(input, genes[person][geneNum], GENE_SIZE);
        }
    }

    input.close();

    // Analyze each person's anemia status
    char personLabels[] = {'A', 'B', 'C', 'D'};
    
    for (int person = 0; person < NUM_PPL; person++) {
        string result = dnaAnalysis(genes[person][0], genes[person][1]);
        output << "Person " << personLabels[person] << " is " << result << "." << endl;
    }

    output << endl;

    // Check for related individuals (share at least one gene)
    for (int p1 = 0; p1 < NUM_PPL; p1++) {
        for (int p2 = p1 + 1; p2 < NUM_PPL; p2++) {
            bool related = false;
            
            // Compare all gene combinations between two people
            for (int g1 = 0; g1 < GENE_PER_PPL && !related; g1++) {
                for (int g2 = 0; g2 < GENE_PER_PPL && !related; g2++) {
                    if (isSameGene(genes[p1][g1], genes[p2][g2], GENE_SIZE)) {
                        related = true;
                    }
                }
            }
            
            if (related) {
                output << "Person " << personLabels[p1] << " is related to person " 
                       << personLabels[p2] << "." << endl;
            }
        }
    }

    output.close();
    return 0;
}

// Function to check if two genes are identical
bool isSameGene(char gene1[], char gene2[], int size) {
    for (int i = 0; i < size; i++) {
        if (gene1[i] != gene2[i]) {
            return false;
        }
    }
    return true;
}

// Function to read one gene from input file
void get1Gene(ifstream& input, char gene[], int size) {
    for (int i = 0; i < size; i++) {
        input >> gene[i];
    }
}

// Function to analyze DNA and determine anemia status
string dnaAnalysis(char gene1[], char gene2[]) {
    bool sickle1 = (gene1[19] == 'T');  // 20th position is index 19 (0-based)
    bool sickle2 = (gene2[19] == 'T');
    
    if (sickle1 && sickle2) {
        return "anemic";
    } else if (sickle1 || sickle2) {
        return "a carrier";
    } else {
        return "normal";
    }
}