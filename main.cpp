#include <iostream>
using namespace std;

#include "HashMap.h"

const int MIN = 1024;
const int MAX = 33554432;

int main(void){
    srand(static_cast<unsigned int>(time(0)));
    int size = rand() % (MAX - MIN + 1) + MIN;

    // Create new hash table
    HashMap table(size);
    cout << "New hash table of size " << size << " has been created." << endl << endl;

    cout << "Populating table . . . (this may take a while)";
    cout << endl << endl;
    int i = 0;
    int key;
    while (table.getNumEntries() < size) {
        key = (rand() % MAX);
        table.put(key, i);
        i++;
    }

    cout << endl << endl;
    cout << "============= Execution has finished ============= " << endl;
    cout << "There were: " << table.getCollisions() << " collisions." << endl;
    cout << "There were: " << key << " attempted insertions." << endl;

    return 0;
}
