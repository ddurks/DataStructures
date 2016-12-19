// reduce.cpp: inverted index

#include <iostream>
#include <cstdlib>
#include <map>
#include <set>
using namespace std;

int main(int argc, char *argv[]) {
    map<string, set<int>> words;
    string word;
    int lineNum;

    while(cin >> word){
        cin >> lineNum;
        words[word].insert(lineNum);
    }
    for(auto it = words.cbegin(); it != words.cend(); ++it)
    {
        cout << it->first << "\t";
        int first = true;
        for(auto it2 = it->second.cbegin(); it2 != it->second.cend(); ++it2){
            if(!first){
                cout << " ";
            }
            cout << *it2;
            first = false;
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
