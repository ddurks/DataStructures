// open.cpp: Open Addressing Map

#include "map.h"

#include <stdexcept>

// Methods --------------------------------------------------------------------

OpenMap::OpenMap(double loadIn){
    size = DEFAULT_TABLE_SIZE;
    loadFactor = loadIn;
    numElements = 0;
    resize(size);
}

OpenMap::~OpenMap(){
    delete[] entries;
}

void            OpenMap::insert(const std::string &key, const std::string &value) {
    double currLoadFactor = (double)numElements / (double)size;
    if( currLoadFactor > loadFactor ){
        resize( size*2 );
    }

    Entry element = std::make_pair(key, value);
    size_t index = locate(key);

    if( entries[index] == NONE ){
        entries[index] = element;
        numElements++;
    }
    else{
        entries[index].second = element.second;
    }
}

const Entry     OpenMap::search(const std::string &key) {
    int index = locate(key);
    if(entries[index] != NONE && entries[index].first == key ){
        Entry element = std::make_pair(entries[index].first, entries[index].second);
        return element;
    }
    else{
        return NONE;
    }
}

void            OpenMap::dump(std::ostream &os, DumpFlag flag) {
    for(int i = 0; i < size; i++){
        if(entries[i] != NONE && entries[i].second != "16384"){
            switch(flag) {
                case DUMP_KEY:          os << entries[i].first  << std::endl; break;
                case DUMP_VALUE:        os << entries[i].second << std::endl; break;
                case DUMP_KEY_VALUE:    os << entries[i].first  << "\t" << entries[i].second << std::endl; break;
                case DUMP_VALUE_KEY:    os << entries[i].second << "\t" << entries[i].first  << std::endl; break;
            }
        }
    }
}

size_t          OpenMap::locate(const std::string &key) {
    int index = hfunc(key) % size;
    while( entries[index] != NONE ){
        if( entries[index].first == key ){
            return index;
        }
        index = (index+1) % size;
    }
    return index;
}

void            OpenMap::resize(const size_t new_size) {
    if( new_size == DEFAULT_TABLE_SIZE ){
        Entry *newMap = new Entry[new_size];
        size = new_size;
        entries = newMap;
        return;
    }
    Entry *newMap = new Entry[new_size];
    for(int i = 0; i < size; i++){
        size_t index = hfunc(entries[i].first) % new_size;
        while( newMap[index] != NONE ){
            index = (index+1) % new_size;
        }
        newMap[index] = entries[i];
    }
    size = new_size;
    delete[] entries;
    entries = newMap;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
