#ifndef __HASH_HPP
#define __HASH_HPP

#define INITIAL_SIZE 10

#include<iostream>
#include<vector>

using namespace std;

struct HashEntry {
    string key;
    int frequence;
};

class HashTable {
public:
    vector<HashEntry> entries;
    int size;
    int count;


    HashTable(int initialSize) : size(initialSize), count(0) {
        entries.resize(initialSize);
    }

    unsigned int stringHashFunction(const string& str);
    void resizeHashTable();
    void insert(const string& key);
    int search(const string& key);
    void printHashTable();
    void clear();

};

#endif