//David Durkin, Christpher Beaufils, Matthew Reilly
//Trie.h
//Trie Class Declaration

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#define ALPHABET (39)
using namespace std;

//Node Structure
struct TrieNode{
    TrieNode(){
        isWord = false;
        definition = "\0";
        word = "\0";
        for(int i = 0; i < ALPHABET; i++ ){     // children
            children[i] = nullptr;
        }
    }
    ~TrieNode(){    // deconstruct
        for(int i = 0; i < ALPHABET; i++){
            delete children[i];
        }
    }
    TrieNode *children[ALPHABET];
    // isWord is true if node represents end of a complete word
    bool isWord;
    string definition;
    string word;
};

//Trie Class
class Trie{
public:
    Trie();
    ~Trie();
    TrieNode *newNode();
    void insert(string, string);
    string search(string);
    void suggest(string, int, TrieNode*);
    void addSuggestions(TrieNode*, string);
    void printSuggestions();
    void loadDictionaryFile(string name = "dictionary.txt");
    void clearSuggestions();
private:
    TrieNode *root;
    vector<string> suggestions;
};
