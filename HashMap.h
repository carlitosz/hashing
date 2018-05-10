#include <iostream>
using namespace std;


#include "HashEntry.h"

class HashMap {
private:
      HashEntry **table;
      int tableSize;
      int collisions;
      int numElems;

public:
    // Overloaded constructor
    HashMap(int s) {
        tableSize = s;
        collisions = 0;
        numElems = 0;

        table = new HashEntry * [s];
        for (int i = 0; i < tableSize; i++) table[i] = 0;
    }

    // Default constructor
    HashMap() {
        tableSize = 128;
        collisions = 0;
        numElems = 0;

        table = new HashEntry * [tableSize];
        for (int i = 0; i < tableSize; i++) table[i] = 0;
    }

    // Put key into hash table
    void put(int key, int index) {
        int hash = generateHash(key);

        if (table[hash] == 0) {
            table[hash] = new HashEntry(key);
            numElems++;

            return;
        }

        if (table[hash]->getKey() > 0) {
            if (collisions == 0) {
                cout << "First collision detected on insertion "
                     << index << endl;
            }

            collisions++;
        }
    }

    int getCollisions() {
        return collisions;
    }

    // Returns number of current entries
    int getNumEntries() {
        return numElems;
    }

    // Generates the new hash
    int generateHash(int key) {
        return key % tableSize;
    }

    // Destructor
    ~HashMap() {
        cout << endl;
        cout << "============= Cleaning up . . . =================" << endl;
        for (int i = 0; i < tableSize; i++) {
            if (table[i] != 0)
                delete table[i];
        }

        delete[] table;
    }
};