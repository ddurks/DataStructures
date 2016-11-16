// Challenge 03: Closest Numbers
// Given a list of unsorted integers, find the pair(s) that have the smallest absolute difference

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Main Execution

int main(int argc, char *argv[]) {
    int input, elements, minDiff;
    string line;
    vector<int> array, numElements, mins;

    while(getline(cin, line)){
        minDiff = INT_MAX;
        istringstream iss(line);
        while( iss >> elements ){
            numElements.push_back(elements);
        }
        getline(cin, line);
        istringstream is1(line);
        while( is1 >> input ){
            array.push_back(input);
        }

        sort(array.begin(), array.end());

        for(int i = 0; i < array.size()-1; i++){
            int difference = abs(array[i]-array[i+1]);
            if( difference < minDiff ){
                minDiff = difference;
                mins.clear();
                mins.push_back(array[i]);
                mins.push_back(array[i+1]);
            }
            else if( difference == minDiff ){
                mins.push_back(array[i]);
                mins.push_back(array[i+1]);
            }
        }

        for(int i = 0; i < mins.size(); i++){
            if( i == mins.size()-1 )
                cout << mins[i];
            else
                cout << mins[i] << " ";
        }
        cout << endl;

        mins.clear();
        array.clear();
        numElements.clear();
    }

    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
