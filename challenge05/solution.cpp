// Challenge 05: BST

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Main Execution
int main(int argc, char *argv[]) {

    int temp, count=1;
    string line;
    vector<int> tree;
    bool bst = true;
    while(getline(cin, line)){
        //Read in and fill tree vector
        istringstream in(line);
        while( in >> temp ){
            tree.push_back(temp);
        }
        bst = true;
        //Extract number of Binary Tree nodes and remove from vector
        int size = tree[0];
        tree.erase(tree.begin(), tree.begin()+1);

        //Check if Tree is Binary Search Tree
        for(int i = 0; i < size; i++){
            //Check if left child is greater than parent
            if( (2*i)+1 < size ){
                if( tree[(2*i)+1] != -1 && tree[(2*i)+1] > tree[i] ){
                    bst = false;
                    break;
                }
            }
            //Check if right child is less than or equal to parent
            if( (2*i)+2 < size ){
                if( tree[(2*i)+2] != -1 && tree[(2*i)+2] <= tree[i] ){
                    bst = false;
                    break;
                }
            }
        }

        //Print result
        if(bst){
            cout << "Tree " << count << " is a BST" << endl;
        }
        else{
            cout << "Tree " << count << " is not a BST" << endl;
        }
        
        //Clear tree to start over
        tree.clear();
        count++;
    }
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
