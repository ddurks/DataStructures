// Challenge 9 Extra Credit: Graph Partitioning
// David Durkin

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
using namespace std;
// Main Execution

int main(int argc, char *argv[]) {

    int numEdges, val, counter;
    char name;
    //map to hold names of nodes mapped to indexes
    map<int, char> names;
    //vector for adjacency list
    vector<vector<int>> adj;
    vector<int> temp;
    //vector to keep track of nodes visited
    vector<int> visited;
    //set to keep track of unvisited nodes
    set<int> unvisited;
    //vector of lists to keep track of new subgraph nodes
    vector<set<int>> newlist;
    set<int> tempSet;
    bool firstpass = true;

    while(cin >> numEdges){
        if(!firstpass){ cout << endl; }
        firstpass = false;
        counter = 0;

        //Parse input and fill adjacency matrix
        for(int i = 0; i < numEdges; i++){
            cin >> name;
            names[counter] = name;
            counter++;
        }
        for(int i = 0; i < numEdges; i++){
            for(int j = 0; j < numEdges; j++){
                cin >> val;
                temp.push_back(val);
            }
            adj.push_back(temp);
            temp.clear();
        }

        //Initialize visited and unvisited structures
        for(int i = 0; i < numEdges; i++){
            visited.push_back(0);
            unvisited.insert(i);
        }

        //Initialize a frontier queue for BFS traversal
        queue<int> frontier;
        bool first;

        //While there are still unvisited nodes in the set
        while(!unvisited.empty()){
            first = true;

            int start = *unvisited.begin();
            visited[start] = 1;
            unvisited.erase(start);
            frontier.push(start);

            //Traverse through each connected graph (BFS) and store nodes in newlist[] subgraph set
            while(!frontier.empty()){
                int element = frontier.front();
                int i;
                frontier.pop();
                tempSet.insert(element);
                for(i=0;i<numEdges;i++){
    				if(adj[element][i] && !visited[i]){
    					frontier.push(i);
    					visited[i]=1;
                        unvisited.erase(i);
    				}
    			}
            }
            newlist.push_back(tempSet);
            tempSet.clear();
        }

        bool firstpass1 = true;

        //Step through each subgraph and print associated node names and matrix
        for(unsigned int count = 0; count < newlist.size(); count++){
            if(!firstpass1){
                cout << endl;
            }
            firstpass1 = false;
            first = true;
            for(auto it = newlist[count].begin(); it != newlist[count].end(); it++){
                if(!first){ cout << " "; }
                cout << names[*it];
                first = false;
            }
            cout << endl;
            for(auto it0 = newlist[count].begin(); it0 != newlist[count].end(); it0++){
                first = true;
                for(auto it = newlist[count].begin(); it != newlist[count].end(); it++){
                    if(!first){ cout << " "; }
                    cout << adj[*it0][*it];
                    first = false;
                }
                cout << endl;
            }
        }

        //clear variables
        adj.clear();
        names.clear();
        visited.clear();
        newlist.clear();
    }

    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
