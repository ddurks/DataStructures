// map.h

#pragma once

// Includes --------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Type definitions ------------------------------------------------------------

typedef enum {
    DUMP_KEY,
    DUMP_VALUE,
    DUMP_KEY_VALUE,
    DUMP_VALUE_KEY,
} DumpFlag;

typedef std::pair<std::string, std::string> Entry;

// Constants -------------------------------------------------------------------

extern const Entry NONE;

// Structures ------------------------------------------------------------------

struct Node {
    Entry entry;
    int     priority;
    Node    *left;
    Node    *right;
    ~Node(){
        delete left;
        delete right;
    }
};

// Classes ---------------------------------------------------------------------

class Map {
public:
    virtual void            insert(const std::string &key, const std::string &value) {}
    virtual const Entry     search(const std::string &key) { return NONE; }
    virtual void            dump(std::ostream &os, DumpFlag flag) {}
    virtual                ~Map() {}
};

class UnsortedMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
            std::vector<Entry> entries;
};

class SortedMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
            std::vector<Entry> entries;
};

class BSTMap : public Map {
public:
            BSTMap(){
                root = nullptr;
            }
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
            ~BSTMap(){
                delete root;
            }
private:
            Node * root;
};

class RBTreeMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
            std::map<std::string, std::string> entries;
            std::map<std::string, std::string>::iterator it;
};

class TreapMap : public Map {
public:
            TreapMap(){
                root = nullptr;
            }
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
            ~TreapMap(){
                delete root;
            }
private:
            Node * root;
};

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
