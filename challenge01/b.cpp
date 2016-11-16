// Challenge 01: Rotating Arrays
 
// Main Execution
 
#include <vector>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <utility>
using namespace std;
 
void Rotation(int size, int rotations, char direction, vector<int> inputVector) {
    int SpotsMoved;
    vector<int> copyVector(size);
 
    SpotsMoved = (rotations % size);
    int it = 0;
    if (direction == 'L') {
        while (it < size) {
            if ((it-SpotsMoved) < -1) {
                copyVector[it-SpotsMoved] = inputVector[it];
                it++;
            } else {
                copyVector[size-SpotsMoved+it] = inputVector[it];
                it++;
            }
        }
    } else if (direction == 'R') {
        while (it < size) {
            if ((it+SpotsMoved) < size) {
                copyVector[it+SpotsMoved] = inputVector[it];
                it++;
            } else {
                copyVector[size-SpotsMoved-it] = inputVector[it];
                it++;
            }    
        }
    }
 
    // cout << direction;
    for (int i=0; i < size; i++) {
       cout << copyVector[i] << " ";
    }
    cout << endl;
    return;
}
 
int main(int argc, char *argv[]) {
 
    vector<char> data;
    vector<int> inputVector;
    int letter;
    int integer;
    string input_line;
    char numValues;
    char numRotations;
    char direction;
 
    while (getline(cin, input_line)) {
        istringstream stream(input_line);
 
        while (stream >> letter) {
            data.push_back(letter);
        }
        getline(cin, input_line);
        istringstream stream2(input_line);
        while (stream2 >> integer) {
            inputVector.push_back(integer);
        }
 
        numValues = data[0];
        numRotations = data[1];
        direction = data[2];
 
        for (int j=0; j<numValues; j++) {
             cout << inputVector[j] << " ";
        }
 
        cout << numRotations << " " << direction << "y";
 
        Rotation(numValues, numRotations, direction, inputVector);
 
        data.clear();
        inputVector.clear();
    }
 
    return 0;
};