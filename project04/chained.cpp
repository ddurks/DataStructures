// chained.cpp: Separate Chaining Map

#include "map.h"

#include <stdexcept>

// Methods --------------------------------------------------------------------
ChainedMap::ChainedMap(double loadIn){
    size = DEFAULT_TABLE_SIZE;
    loadFactor = loadIn;
    resize(size);
    numElements = 0;
}

ChainedMap::~ChainedMap(){
    delete[] entries;
}

void            ChainedMap::insert(const std::string &key, const std::string &value) {
    Entry element = std::make_pair(key, value);
    Entry found = search(key);

    double currLoadFactor = (double)numElements / (double)size;
    if( currLoadFactor > loadFactor ){
        resize( size*2 );
    }
    
    if( found != NONE ){
        int index = hfunc(key) % size;
        auto overwrite = entries[index].find(key);
        overwrite->second = value;
    }
    else{
        int index = hfunc(element.first) % size;
        entries[index].insert(element);
        numElements++;
    }
}

const Entry     ChainedMap::search(const std::string &key) {
    int index = hfunc(key) % size;
    auto search = entries[index].find(key);
    if(search != entries[index].end()){
        Entry element = std::make_pair(search->first, search->second);
        return element;
    }
    else{
        return NONE;
    }
}

void            ChainedMap::dump(std::ostream &os, DumpFlag flag) {
    for(int i = 0; i < size; i++){
        for(auto it = entries[i].begin(); it != entries[i].end(); it++){
            switch(flag) {
                case DUMP_KEY:          os << it->first  << std::endl; break;
                case DUMP_VALUE:        os << it->second << std::endl; break;
                case DUMP_KEY_VALUE:    os << it->first  << "\t" << it->second << std::endl; break;
                case DUMP_VALUE_KEY:    os << it->second << "\t" << it->first  << std::endl; break;
            }
        }
    }
}

void            ChainedMap::resize(const size_t new_size) {
    if( new_size == DEFAULT_TABLE_SIZE ){
        std::map<std::string, std::string> *newMap = new std::map<std::string, std::string>[new_size];
        size = new_size;
        entries = newMap;
        return;
    }
    std::map<std::string, std::string> *newMap = new std::map<std::string, std::string>[new_size];
    for(int i = 0; i < size; i++){
        for(auto it = entries[i].begin(); it != entries[i].end(); it++ ){
            int index = hfunc(it->first) % new_size;
            newMap[index].insert(*it);
        }
    }
    size = new_size;
    delete[] entries;
    entries = newMap;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
