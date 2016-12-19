// map.cpp: inverted index

#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

string stripPunc(string in){
    string result;
    int lastPuncFront = -1, firstPuncBack = -1, newsize;
    vector<int> indexes;
    for(int i = 0; i < int(in.length()); i++){
        if( in[i] < 97 || in[i] > 122 ){
            if(in[i] > 47 && in[i] < 58){
                break;
            }
            lastPuncFront = i;
        }
        else{
            break;
        }
    }
    for(int i = int(in.length()-1); i >= 0; i--){
        if( in[i] < 97 || in[i] > 122 ){
            if(in[i] > 47 && in[i] < 58){
                break;
            }
            firstPuncBack = i;
        }
        else{
            break;
        }
    }
    newsize = in.length();

    if(lastPuncFront == int(in.length()-1)){
        return "";
    }

    if(firstPuncBack != -1){
        in.erase(firstPuncBack, newsize-firstPuncBack);
    }
    if(lastPuncFront != -1){
        in.erase(0, lastPuncFront+1);
    }

    return in;
}

int main(int argc, char *argv[]) {
    string line, temp, result;
    int lineNum = 1;
    vector<pair<string,string>> pairs;

    while(getline(cin, line)){
        istringstream ls(line);
        while(ls >> temp){
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            result = stripPunc(temp);
            if(result == ""){
                continue;
            }
            auto pair = make_pair(result, to_string(lineNum));
            pairs.push_back(pair);
        }
        lineNum++;
    }

    for(unsigned int i = 0; i < pairs.size(); i++){
        cout << pairs[i].first << "\t" << pairs[i].second << endl;
    }

    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
