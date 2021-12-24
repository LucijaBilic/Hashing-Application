#ifndef _SC_HASH_TABLE_DATA_H_
#define _SC_HASH_TABLE_DATA_H_

struct _listNode;
typedef struct _listNode ListNode;

typedef struct _listNode* Position;
typedef struct _listNode* List;

//Structure of hash table for separate chaining
struct _SC_hashTable;
typedef struct _SC_hashTable* SCHT;

struct _listNode {
    int Element;
    
    Position Next;
};

struct _SC_hashTable {
    int TableSize;
    
    List* HashLists;
};

#endif
