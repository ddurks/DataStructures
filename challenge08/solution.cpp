// Challenge 08: Palindrome Permutation

#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

//Determines Palindrome Permutation status in O(n) time
bool is_palindrome(string s){
    unordered_map<char, int> entry;
    int singles = 0;
    int watch = 0;

    //Step through each char in input string
    for(int i = 0; i < s.length(); i++){
        //Ignore punctuation, convert uppercase to lowercase
        if( s[i] < 97 || s[i] > 122 ){
            if( s[i] >= 65 && s[i] <= 90){
                s[i] += 32;
            }
            else{
                continue;
            }
        }

        auto search = entry.find(s[i]);
        // Check if value already exists
        if( search != entry.end() ){
            int val = search->second;
            // if value is one, it will be increased to two, char is no longer a single.
            if(val == 1){
                --singles;
            }
            // watch value for characters appearing more than twice. Must be even
            // to signify proper pairing
            else if(val >= 2){
                ++watch;
            }

            ++val;
            search->second = val;
        }
        // if inserting for the first time, is a single, unpaired char
        else{
            entry.insert({s[i], 1});
            ++singles;
        }
    }

    // Can only be 1 or 0 unpaired chars, if over 2 occurrences of a character, must be
    // even for proper pairing, as mentioned earlier.
    if((singles == 0 || singles == 1) && watch%2 == 0){
        return true;
    }
    else{
        return false;
    }

}


// Main Execution
int main(int argc, char *argv[]) {

    string line;
    while(getline(cin, line)){
        if(is_palindrome(line)){
            cout << "\"" << line << "\"" << " is a palindrome permutation" << endl;
        }
        else{
            cout << "\"" << line << "\"" << " is not a palindrome permutation" << endl;
        }
    }

    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp: