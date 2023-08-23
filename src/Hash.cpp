#include"Hash.hpp"

unsigned int HashTable::stringHashFunction(const string& str)
{
    unsigned int hash = 0;
    for (char c : str) {
        hash += c;
    }
    return hash % this->size;
}

void HashTable::resizeHashTable() 
{
    int newSize = this->size * 2;
    std::vector<HashEntry> newEntries(newSize);

    for (int i = 0; i < newSize; i++) {
        newEntries[i].key = "";
    }

    for (const auto& entry : entries) {
        if (!entry.key.empty()) {
            unsigned int newIndex = stringHashFunction(entry.key) % newSize;
            while (!newEntries[newIndex].key.empty()) {
                newIndex = (newIndex + 1) % newSize; // Linear probing
            }
            newEntries[newIndex] = entry;
        }
    }

    entries = newEntries;
    size = newSize;
}

void HashTable::insert(const string& key) 
{
    if (this->count >= this->size * 0.7) {
        resizeHashTable();
    }

    unsigned int index = stringHashFunction(key) % size;
    while (!entries[index].key.empty()) {
        if (entries[index].key == key) {
            entries[index].frequence++; // Increment frequency if key already exists
            return;
        }
        index = (index + 1) % size; // Linear probing
    }

    entries[index].key = key;
    entries[index].frequence = 1; // Initialize frequency if key is new
    count++;
}

int HashTable::search(const string& key) 
{
    unsigned int index = stringHashFunction(key) % this->size;
    while (!entries[index].key.empty()) 
    {
        if (entries[index].key == key) 
        {
            return entries[index].frequence;
        }
        index = (index + 1) % this->size; // Linear probing
    }
    return 0; // Key not found
}

void HashTable::printHashTable() 
{
    cout << "Hash Table Contents:" << std::endl;
    for (const auto& entry : entries)
    {
        if (!entry.key.empty()) 
        {
            std::cout << "Key: " << entry.key << ", Frequence: " << entry.frequence << std::endl;
        }
    }
}

void HashTable::clear() {
    for (auto& entry : entries) {
        entry.key = "";
        entry.frequence = 0;
    }
    count = 0;
}