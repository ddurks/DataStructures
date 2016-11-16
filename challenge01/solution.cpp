// Challenge 01: Rotating Arrays
// David Durkin

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Main Execution
int main(int argc, char *argv[]) {
    
    //initializing variables
	vector<char> info;
	vector<int> values;
	vector<int> copy;
	char character;
	int integer;
	string line;

	//While loop that executes while more lines remain
    while(getline(cin, line)){
    	//creating a string stream of the read line
    	istringstream iss(line);

    	//reading the read lines into arrays
    	while( iss >> character ){
    		info.push_back(character);
    	}
    	getline(cin, line);
    	istringstream is1(line);
    	while( is1 >> integer ){
    		values.push_back(integer);
    	}

    	//Converting character to integer value
    	int rotations = info[1]-'0';

    	//Iterator for desired amount of rotations
    	for(int i = 0; i < rotations; i++){
    		copy = values;
    		//Perform left rotation
    		if(info[2] == 'L'){
    			for(int j = 0; j < values.size(); j++){
    				if( j == values.size()-1 ){
    					values[j] = copy[0];
    				}
    				else{
    					values[j] = copy[j+1];
    				}
    			}
    		}
    		//Perform right rotation
    		else{
    			for(int j = 0; j < values.size(); j++){
    				if( j == 0 ){
    					values[j] = copy.back();
    				}
    				else{
    					values[j] = copy[j-1];
    				}
    			}
    		}
    	}

    	//Print rotated vector
    	for(int i = 0; i < values.size(); i++){
    		if( i == values.size()-1 ){
                cout << values[i];
            }
            else{    
                cout << values[i] << " ";
            }
    	}
    	cout << endl;

    	//clear arrays to get ready for more
    	copy.clear();
    	info.clear();
    	values.clear();
    }
    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
