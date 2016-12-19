// rbtree.cpp: RBTree Map

#include "map.h"

#include <algorithm>

// Methods --------------------------------------------------------------------

void RBTreeMap::insert(const std::string &key, const std::string &value) {
    it = entries.find(key);
    if( it != entries.end() ){
        it->second = value;
        return;
    }
    entries.insert(std::make_pair(key, value));
}

const Entry RBTreeMap::search(const std::string &key) {
    it = entries.find(key);

    if (it != entries.end()){
        Entry element = std::make_pair(it->first, it->second);
        return element;
    }

    return NONE;
}

void RBTreeMap::dump(std::ostream &os, DumpFlag flag) {
    map<std::string, std::string>::const_iterator itr;
    if ((DUMP_KEY & flag) == DUMP_KEY) {
        for (itr = entries.begin(); itr != entries.end(); ++itr)
            os << itr->first << endl;
    } else if ((DUMP_VALUE & flag) == DUMP_VALUE) {
        for (itr = entries.begin(); itr != entries.end(); ++itr)
            os << itr->second << endl;
    } else if ((DUMP_KEY_VALUE & flag) == DUMP_KEY_VALUE) {
        for (itr = entries.begin(); itr != entries.end(); ++itr)
            os << itr->first << "\t" << itr->second << endl;
    } else if ((DUMP_VALUE_KEY & flag) == DUMP_VALUE_KEY) {
        for (itr = entries.begin(); itr != entries.end(); ++itr)
            os << itr->second << "\t" << itr->first << endl;
    }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
