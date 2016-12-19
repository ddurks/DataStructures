//David Durkin, Christopher Beaufils, Matt Reilly
//English Dictionary Main PROGRAM

#include "Trie.h"
#include <iostream>
#include <unistd.h>
using namespace std;

bool INTERACTIVE = false, STANDARD = false, LOADONLY = true;;

// Define usage
void usage(int status) {
    cout << "usage: dictionary" << endl
              << "    -i    INTERACTIVE mode, user is prompted for words to define" << endl
              << "    -s    STANDARD mode, words are taken from standard in" << endl
              << "    -l    LOAD ONLY mode, dictionary file is loaded, nothing else" << endl;

    exit(status);
}

// parse user command line input
void parse_command_line_options(int argc, char *argv[]){
    int c;

    while((c = getopt(argc, argv, "islh")) != -1){
        switch(c){
            case 'i':
                INTERACTIVE = true;
                STANDARD = false;
                break;
            case 's':
                STANDARD = true;
                INTERACTIVE = false;
                break;
            case 'l':
                LOADONLY = true;
                break;
            case 'h':
                usage(0);
                break;
            default:
                usage(1);
                break;
        }
    }
}

// Driver for dictionary aplpication
int main(int argc, char *argv[]){

    parse_command_line_options(argc, argv);

    // define data structure, placeholders
    Trie dictionary;
    bool play = true;
    string key, result, key1, query;

    dictionary.loadDictionaryFile(); // initialize dictionary by loading words/definitions

    if(LOADONLY && !INTERACTIVE && !STANDARD){
        return 0; // no user interaction required, exit
    }

    if(INTERACTIVE){ // user interaction
        cout << "Welcome to our Dictionary!" << endl;
        cout << "==========================" << endl;
        while(play){
            cout << "Enter a word: ";
            getline(cin, query); // get user input
            //system("clear");
            transform(query.begin(), query.end(), query.begin(), ::tolower); // buid query
            if(query == "q"){ // quit
                break;
            }
            result = dictionary.search(query); // search for word
            if(result != "\0"){     // definition found
                cout << "Definition: " << result << endl;
            }
            else{                   // definition not found
                cout << "This doesn't appear to be a word." << endl;
                cout << "Did you mean... ";
                dictionary.printSuggestions();  // find suggestions
                cout << endl;
            }
            cout << "----------" << endl;
        }
    }
    else{ // words taken from stdio
        while(getline(cin, query)){
            transform(query.begin(), query.end(), query.begin(), ::tolower);
            result = dictionary.search(query);

            if(result != "\0"){
                cout << query << " -- " << result << endl;
            }
            else{
                cout << "This doesn't appear to be a word." << endl;
                cout << "Did you mean... ";
                dictionary.printSuggestions();
                cout << endl;
            }
            cout << endl;
        }
    }

    return 0;
}
