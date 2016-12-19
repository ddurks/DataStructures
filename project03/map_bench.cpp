// map_bench.cpp

#include "map.h"

#include <cassert>
#include <iostream>
#include <string>
#include <strings.h>
#include <unistd.h>
#include <sstream>
#include <iomanip>
#include <chrono>
using namespace std;

// Constants

int NITEMS;
int PADLENGTH;
string BACKEND;

void usage(int status) {
    std::cout << "usage: map_bench" << std::endl
              << "    -b BACKEND    Which Map backend (unsorted, sorted, bst, rbtree, treap)" << std::endl
              << "    -n NITEMS     Number of items to benchmark" << std::endl
              << "    -p PADLENGTH  Amount to pad the keys with leading 0's" << std:: endl;
    exit(status);
}

void parse_command_line_options(int argc, char *argv[], Map *&map) {
    int c;

    while ((c = getopt(argc, argv, "hb:n:p:")) != -1) {
        switch (c) {
            case 'b':
                BACKEND = optarg;
                if (strcasecmp(optarg, "unsorted") == 0) {
                    map = new UnsortedMap();
                } else if (strcasecmp(optarg, "sorted") == 0) {
                    map = new SortedMap();
                } else if (strcasecmp(optarg, "bst") == 0) {
                    map = new BSTMap();
                } else if (strcasecmp(optarg, "rbtree") == 0) {
                    map = new RBTreeMap();
                } else if (strcasecmp(optarg, "treap") == 0) {
                    map = new TreapMap();
                } else {
                    usage(1);
                }
                break;
            case 'h':
                usage(0);
                break;
            case 'n':
                NITEMS = atoi(optarg);
                break;
            case 'p':
                PADLENGTH = atoi(optarg);
                break;
            default:
                usage(1);
                break;
        }
    }

    if (map == nullptr) {
    	map = new UnsortedMap();
    }
}

// Main execution --------------------------------------------------------------

int main(int argc, char *argv[]) {
    Map *map = nullptr;

    parse_command_line_options(argc, argv, map);

    auto insert_start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < NITEMS; i++){
        stringstream sv, sk;
        sk << setw(PADLENGTH) << setfill('0') << i;
        string k = sk.str();
        sv << setw(PADLENGTH) << setfill('0') << i*2;
        string v = sv.str();
        map->insert(k, v);
    }
    auto insert_end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> insert = insert_end - insert_start;
    cout << "Insertions: " << insert.count() << " seconds" << endl;

    auto search_start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < NITEMS; i++){
        stringstream sv, sk;
        sk << setw(PADLENGTH) << setfill('0') << i;
        string k = sk.str();
        sv << setw(PADLENGTH) << setfill('0') << i*2;
        string v = sv.str();
        auto result = map->search(k);
        /*if( result != NONE && result.second == v){
            cout << "Success" << endl;
        }
        else{
            cout << "Failure" << endl;
        }*/
    }
    auto search_end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> search = search_end - search_start;
    cout << "Searches: " << search.count() << " seconds" << endl;

    cout << "|" << BACKEND << "|" << NITEMS << "|" << PADLENGTH << "|" << insert.count() << "|" << search.count() << "|" << endl;

    delete map;
    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
