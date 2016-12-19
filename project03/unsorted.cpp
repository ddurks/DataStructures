// unsorted.cpp: Unsorted Map

#include "map.h"
#include <vector>
#include <string>

// Methods --------------------------------------------------------------------

void UnsortedMap::insert(const std::string &key, const std::string &value) {
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
}

const Entry UnsortedMap::search(const std::string &key) {
	for (unsigned int i = 0; i < entries.size(); i++) {
		if (entries[i].first == key)
			return entries[i];
	}
    return NONE;
}

void UnsortedMap::dump(std::ostream &os, DumpFlag flag) {
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

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
