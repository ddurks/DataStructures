// map_bench.cpp

#include "map.h"

#include <cassert>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <string>

#include <strings.h>
#include <unistd.h>

// Type Definitions ------------------------------------------------------------

std::string BACKEND;
typedef std::chrono::high_resolution_clock  Clock;

// Utility functions -----------------------------------------------------------

void usage(int status) {
    std::cout << "usage: map_bench" << std::endl
              << "    -b BACKEND    Which Map backend (unsorted, sorted, bst, rbtree, treap)" << std::endl
              << "    -n NITEMS     Number of items to benchmark" << std::endl
              << "    -p PADLENGTH  Amount to pad the keys with leading 0's" << std::endl;

    exit(status);
}

void parse_command_line_options(int argc, char *argv[], Map *&map, int &nitems, int &padlength) {
    int c;

    while ((c = getopt(argc, argv, "hb:n:p:")) != -1) {
        switch (c) {
            case 'b':
                if (strcasecmp(optarg, "unsorted") == 0) {
                    BACKEND = optarg;
                    map = new UnsortedMap();
                } else if (strcasecmp(optarg, "sorted") == 0) {
                    BACKEND = optarg;
                    map = new SortedMap();
                } else if (strcasecmp(optarg, "bst") == 0) {
                    BACKEND = optarg;
                    map = new BSTMap();
                } else if (strcasecmp(optarg, "rbtree") == 0) {
                    BACKEND = optarg;
                    map = new RBTreeMap();
                } else if (strcasecmp(optarg, "treap") == 0) {
                    BACKEND = optarg;
                    map = new TreapMap();
                } else if (strcasecmp(optarg, "unordered") == 0) {
                    BACKEND = optarg;
                    map = new UnorderedMap();
                } else if (strcasecmp(optarg, "chained") == 0) {
                    BACKEND = optarg;
                    map = new ChainedMap();
                } else if (strcasecmp(optarg, "open") == 0) {
                    BACKEND = optarg;
                    map = new OpenMap();
                } else if (optarg != nullptr) {
                    std::string str(optarg);
                    if(str.substr(0,7) == "chained" && str.length() > 7){
                        BACKEND = optarg;
                        map = new ChainedMap( stod(str.substr(8,str.length()-8)) );
                    }
                    if(str.substr(0,4) == "open" && str.length() > 4){
                        BACKEND = optarg;
                        map = new ChainedMap( stod(str.substr(5,str.length()-5)) );
                    }
                } else {
                    usage(1);
                }
                break;
            case 'n':
                nitems = atoi(optarg);
                break;
            case 'p':
                padlength = atoi(optarg);
                break;
            case 'h':
                usage(0);
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

std::string int_to_key(int i, size_t padlength) {
    std::string k = std::to_string(i);
    if (padlength > k.size())
        k.insert(k.begin(), padlength - k.size(), '0');
    return k;
}

// Main execution --------------------------------------------------------------

int main(int argc, char *argv[]) {
    Map *map       = nullptr;
    int  nitems    = 1;
    int  padlength = 1;

    parse_command_line_options(argc, argv, map, nitems, padlength);

    // Insert
    auto insert_start = Clock::now();
    for (int i = 0; i < nitems; i++) {
        std::string k = int_to_key(i, padlength);
        std::string v = k;
        map->insert(k, v);
    }
    auto insert_stop  = Clock::now();
    auto insert_diff  = insert_stop - insert_start;

    //std::cout << "Insert: " << std::setprecision(5) << std::chrono::duration<double>(insert_diff).count() << " s" << std::endl;

    // Search
    auto search_start = Clock::now();
    for (int i = 0; i < nitems; i++) {
        std::string k = int_to_key(i, padlength);
        map->search(k);
    }
    auto search_stop  = Clock::now();
    auto search_diff  = search_stop - search_start;

    //std::cout << "Search: " << std::setprecision(5) << std::chrono::duration<double>(search_diff).count() << " s" << std::endl;

    std::cout << "|" << BACKEND << "|" << nitems << "|" << std::setprecision(5) << std::chrono::duration<double>(insert_diff).count() << "|" << std::setprecision(5) << std::chrono::duration<double>(search_diff).count() << "|" << std::endl;

    delete map;
    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
