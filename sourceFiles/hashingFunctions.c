#include "../headerFiles/mainHeaderFile.h"

//Hash function
int Hash(int key, int tableSize) {
    return key % tableSize;
}

//Collision handling function for linear probing
int CollisionHandlingLP(int key, int hashIndex, int tableSize) {
    return (Hash(key, tableSize) + hashIndex) % tableSize;
}

//Collision handling function for quadratic probing
int CollisionHandlingQP(int key, int hashIndex, int tableSize) {
    return (Hash(key, tableSize) + hashIndex * hashIndex) % tableSize;
}

//Second hashing function for double hashing
int Hash2(int key, int tableSize) {
    int previous = PreviousPrimeNumber(tableSize);
    
    return previous - (key % previous);
}

//Collision handling function for double hashing
int CollisionHandlingDH(int key, int hashIndex, int tableSize) {
    return (Hash(key, tableSize) + hashIndex * Hash2(key, tableSize)) % tableSize;
}
