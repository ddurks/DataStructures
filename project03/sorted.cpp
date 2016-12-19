// sorted.cpp: Sorted Map

#include "map.h"

#include <algorithm>

// Type Definitions ------------------------------------------------------------

typedef std::vector<Entry>::iterator IT;

// Prototypes ------------------------------------------------------------------

const Entry binary_search(const IT &start, const IT &end, const std::string &key);
bool cmp(std::pair<string, string> p1, std::pair<string, string>p2);

// Methods ---------------------------------------------------------------------

void SortedMap::insert(const std::string &key, const std::string &value) {
    if(entries.size()==0){
		Entry element = std::make_pair(key, value);
		entries.push_back(element);
		return;
	}
	for(unsigned int i = 0; i < entries.size(); i++){
        if(entries[i].first == key){
			entries[i].second = value;
			return;
		}
	}
	Entry element = std::make_pair(key, value);
	entries.push_back(element);
    sort(entries.begin(), entries.end(), cmp);
}

const Entry SortedMap::search(const std::string &key) {
    for (unsigned int i = 0; i < entries.size(); i++) {
		if (entries[i].first == key)
			return entries[i];
	}
    return NONE;
}

void SortedMap::dump(std::ostream &os, DumpFlag flag) {
    switch (flag){
		case DUMP_KEY:
			for (unsigned int i = 0; i < entries.size(); i++)
				os << entries[i].first << endl;
			break;
		case DUMP_VALUE:
			for (unsigned int i = 0; i < entries.size(); i++)
				os << entries[i].second << endl;
			break;
		case DUMP_KEY_VALUE:
			for (unsigned int i = 0; i < entries.size(); i++)
				os << entries[i].first << "\t" << entries[i].second << endl;
			break;
		case DUMP_VALUE_KEY:
			for (unsigned int i = 0; i < entries.size(); i++)
				os << entries[i].second << "\t" << entries[i].first << endl;
			break;
	}
}

// Internal Functions ----------------------------------------------------------

const Entry binary_search(const IT &start, const IT &end, const std::string &target) {

    return NONE;
}

bool cmp(std::pair<string, string> p1, std::pair<string, string>p2) {
    int result = p1.first.compare(p2.first);

    if (result >= 0)
        return true;

    return false;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
