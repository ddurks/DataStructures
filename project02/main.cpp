// lsort.cpp

#include "lsort.h"

#include <iostream>

#include <strings.h>
#include <unistd.h>

// Utility functions -----------------------------------------------------------

void usage(int status) {
    std::cout << "usage: lsort" << std::endl
              << "    -m MODE   Sorting mode (stl, qsort, merge, quick)" << std::endl
              << "    -n        Perform numerical ordering"              << std::endl;

    exit(status);
}

void parse_command_line_options(int argc, char *argv[], Mode &mode, bool &numeric) {
    int c;

    while ((c = getopt(argc, argv, "hm:n")) != -1) {
        switch (c) {
            case 'm':
                if (strcasecmp(optarg, "stl") == 0) {
                    mode = MODE_STL;
                } else if (strcasecmp(optarg, "qsort") == 0) {
                    mode = MODE_QSORT;
                } else if (strcasecmp(optarg, "merge") == 0) {
                    mode = MODE_MERGE;
                } else if (strcasecmp(optarg, "quick") == 0) {
                    mode = MODE_QUICK;
                } else {
                    usage(1);
                }
                break;
            case 'n':
                numeric = true;
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

// Main execution --------------------------------------------------------------

int main(int argc, char *argv[]) {
    Mode mode = MODE_STL;
    bool numeric = false;
    List data;
    std::string line;

    parse_command_line_options(argc, argv, mode, numeric);

    while (std::getline(std::cin, line)) {
        data.push_front(line);
    }

    switch (mode) {
        case MODE_STL:
            stl_sort(data, numeric);
            break;
        case MODE_QSORT:
            qsort_sort(data, numeric);
            break;
        case MODE_MERGE:
            merge_sort(data, numeric);
            break;
        case MODE_QUICK:
            quick_sort(data, numeric);
            break;
    }

    for (auto curr = data.head; curr != nullptr; curr = curr->next) {
        if (numeric) {
            std::cout << curr->number << std::endl;
        } else {
            std::cout << curr->string << std::endl;
        }
    }

    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
