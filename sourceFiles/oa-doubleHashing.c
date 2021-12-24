#include "../headerFiles/mainHeaderFile.h"

int Hash2(int key, int tableSize) {
    int previous = PreviousPrimeNumber(tableSize);
    
    return previous - (key % previous);
}

int CollisionHandlingDH(int key, int hashIndex, int tableSize) {
    return (Hash(key, tableSize) + hashIndex * Hash2(key, tableSize)) % tableSize;
}

