//David Durkin, Christopher Beaufils, Matthew Reilly
//Trie.cpp
//Trie data structure implementation

#include "Trie.h"

using namespace std;

//Utility Function

//for converting chars to children[] indexes
int indexof(char in){
    if(in >= '0' && in <= '9'){
        return ((int)in - 19);
    }
    if(in == '-'){
        return 26;
    }
    if(in == '.'){
        return 27;
    }
    if(in == ' '){
        return 28;
    }
    if(in >= 'a' && in <= 'z'){
        return ((int)in - (int)'a');
    }
    return -1;
}

//calculating the minimum of two values
int minimum(int one, int two, int three){
    if(one <= two && one <= three){
        return one;
    }
    else if(two <= one && two <= three){
        return two;
    }
    else{
        return three;
    }
}

//for determining similarity of strings
int LevenshteinDistance(string s, int s_len, string t, int t_len){
    int cost;

    /* base case: empty strings */
    if (s_len == 0) return t_len;
    if (t_len == 0) return s_len;

    /* test if last characters of the strings match */
    if (s[s_len-1] == t[t_len-1])
        cost = 0;
    else
        cost = 1;

    /* return minimum of delete char from s, delete char from t, and delete char from both */
    return minimum(LevenshteinDistance(s, s_len - 1, t, t_len    ) + 1,
                 LevenshteinDistance(s, s_len    , t, t_len - 1) + 1,
                 LevenshteinDistance(s, s_len - 1, t, t_len - 1) + cost);
}

//Trie Implementation
Trie::Trie(){
    root = new TrieNode();
}

Trie::~Trie(){
    delete root;
}

TrieNode *Trie::newNode(void){
    TrieNode *newNode = new TrieNode();
    return newNode;
}

void Trie::insert(string s, string def){        // Trie insert function

    transform(s.begin(), s.end(), s.begin(), ::tolower);    // format string
    int level;
    int length = s.length();
    int index;

    TrieNode *current = root; // start at root

    for(level = 0; level < length; level++){        // traverse and insert as appropriate
        index = indexof(s[level]);
        if(index == -1){
            return;
        }

        if(current->children[index] == nullptr){
            current->children[index] = newNode();
        }

        current = current->children[index];
    }

    current->isWord = true;
    current->definition = def;
    current->word = s;
}

string Trie::search(string key){        // Trie search function
    int level;
    int length = key.length();
    int index;

    TrieNode *current = root;

    for(level = 0; level < length; level++){        // traverse and search Trie
        index = indexof(key[level]);
        if(index == -1){
            return "\0";
        }

        if(!current->children[index]){
            suggest(key, 0, root);
            return "\0";
        }

        current = current->children[index];
    }

    if(current != nullptr && current->isWord){
        return current->definition;
    }
    else if(current->children[indexof('1')] && current->children[indexof('1')]->isWord){
        string definition = current->children[indexof('1')]->definition;

        for(char i = '2'; i < '9'; i++){

            if(current->children[indexof(i)] && current->children[indexof(i)]->isWord){
                definition += "\n" + current->children[indexof(i)]->definition;
            }

        }
        return definition;
    }
    else{
        return "\0";
    }
}

void Trie::suggest(string key, int pos, TrieNode *head){    // recursively find suggestions
        if((key != head->word) && (head->children[indexof(key[pos])] != nullptr)){
            suggest(key, pos+1, head->children[indexof(key[pos])]);
        }
        else{
            addSuggestions(head, key);
        }
}

void Trie::addSuggestions(TrieNode *head, string key){          // store suggestions for later output
    for(int i = 0; i < ALPHABET; i++){
        if(head->children[i] != nullptr){
            addSuggestions(head->children[i], key);
        }
    }
    if(head->word != "" && LevenshteinDistance(key, key.length(), head->word, head->word.length()) <= 3){
        suggestions.push_back(head->word);
    }
}

void Trie::clearSuggestions(){      // empty suggestions
    suggestions.clear();
}

void Trie::printSuggestions(){      // print suggestions
    bool first = true;
    for(size_t i = 0; i < suggestions.size(); i++){
        if(!first)
            cout << ", ";
        cout << suggestions[i];
        first = false;
    }
    clearSuggestions();
}

void Trie::loadDictionaryFile(string name){     // access dictionary file, words and definitions
    string line;
    string word, definition, temp, second;
    ifstream dictionaryFile;
    dictionaryFile.open("dictionary.txt");

    if(dictionaryFile.is_open()){
        while(getline(dictionaryFile, line)){
            if(line != "\0"){
                istringstream in(line);
                in >> word >> second;
                if(second[second.length()-1] != '.'){
                    word += " " + second;
                }
                else{
                    definition += second;
                }
                while(in >> temp){
                    definition += " " + temp;
                }
            }
            //cout << word << endl << definition << endl << endl;
            insert(word, definition);
            word.clear();
            temp.clear();
            definition.clear();
        }
    }
}
