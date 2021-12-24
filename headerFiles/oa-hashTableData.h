#ifndef _OA_HASH_TABLE_DATA_H_
#define _OA_HASH_TABLE_DATA_H_

//Structure of hash table for open addressing
struct _OA_hashTable;
typedef struct _OA_hashTable* OAHT;

struct _OA_hashTable {
    int TableSize;
    int RowsFilled;
    
    int* Table;
};

#endif 
