// Challenge 10: Minimum Spanning Tree

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int VERTICES;
// Functions

int minKey(vector<int> &key, vector<bool> &used){
    int minimumIndex=0, minimum = INT_MAX;

    for(int i = 0; i < VERTICES; i++){
        if(used[i] == false && key[i] < minimum){
            minimum = key[i];
            minimumIndex = i;
        }
    }

    return minimumIndex;
}

void prim(vector<vector<int>> &matrix){
    vector<int> fromNode(VERTICES, 0);
    vector<int> key(VERTICES, 0);
    vector<bool> used(VERTICES, 0);
    vector<pair<char,char>> mst;
    int weight = 0;
    pair<char, char> temp;

    for(int i = 0; i < VERTICES; i++){
        key[i] = INT_MAX;
        used[i] = false;
    }
    used[0] = true;
    fromNode[0] = -1;

    for(int i = 0; i < VERTICES - 1; i++){
        int minVertex = minKey(key, used);
        used[minVertex] = true;

        for(int index = 0; index < VERTICES; index++){
            if( matrix[minVertex][index] != -1 && used[index] == false && matrix[minVertex][index] < key[index]){
                fromNode[index] = minVertex;
                key[index] = matrix[minVertex][index];
            }
        }
    }

    for(int i = 1; i < VERTICES; i++){
        char one = (char)(fromNode[i]+65);
        char two = (char)(i+65);
        if(two > one){
            temp = make_pair(one, two);
        }
        else{
            temp = make_pair(two, one);
        }

        mst.push_back(temp);
        weight += matrix[i][fromNode[i]];
    }
    sort(mst.begin(), mst.end());
    cout << weight << endl;
    for(int i = 0; i < VERTICES-1; i++){
        cout << mst[i].first << mst[i].second << endl;
    }
    mst.clear();
}

// Main Execution

int main(int argc, char *argv[]) {

    int tempInt, first = 1;
    while(cin >> VERTICES){
        vector<vector<int>> matrix(VERTICES, vector<int>(VERTICES));

        for(int i = 0; i < VERTICES; i++){
            for(int j = 0; j < VERTICES; j++){
                cin >> tempInt;
                matrix[i][j] = tempInt;
            }
        }

        if(!first){
            cout << endl;
        }
        prim(matrix);

        first = 0;
    }


    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
