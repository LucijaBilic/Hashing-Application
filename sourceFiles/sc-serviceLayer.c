#include "../headerFiles/mainHeaderFile.h"

SCHT TableInitializationSC(int tableSize) {
    SCHT hashTable = NULL;

    hashTable = (SCHT)malloc(sizeof(struct _SC_hashTable));

    if(hashTable == NULL) {
        printf("\n\nERROR! Failed to allocate SCHT struct!");
        return RETURN_ERROR_MEMORY_ALLOCATION_FAILED;
    }

    hashTable->TableSize = tableSize;

    hashTable->HashLists = (List*)malloc(sizeof(List) * hashTable->TableSize);

    if(hashTable->HashLists == NULL) {
        printf("\n\nERROR! Failed to allocate hash table (SCHT)!");
        return RETURN_ERROR_MEMORY_ALLOCATION_FAILED;
    }

    for(int i = 0; i < hashTable->TableSize; i++)
        hashTable->HashLists[i] = NULL;

    return hashTable;
}

int PrintTableSC(SCHT hashTable) {
    List copyList = NULL;

    printf("\n");
    for(int i = 0; i < hashTable->TableSize; i++) {
        printf("\n\t %d", i);
        
        copyList = hashTable->HashLists[i];
        
        while (copyList != NULL) {
            printf(" --> %d ", copyList->Element);
            copyList = copyList->Next;
        }
    }
    
    return RETURN_OK;
}

int AddElementSC(int element, SCHT hashTable) {
    Position newNode = NULL;
    int index = Hash(element, hashTable->TableSize);

    newNode = (Position)malloc(sizeof(struct _listNode));

    if(newNode == NULL)
        return RETURN_ERROR_NEW_NODE_ALLOCATION_FAILED;

    newNode->Element = element;

    newNode->Next = hashTable->HashLists[index];
    hashTable->HashLists[index] = newNode;

    return index;
}

Position FindElementSC(int element, SCHT hashTable) {
    List list = NULL, copyList = NULL;
    
    list = hashTable->HashLists[Hash(element, hashTable->TableSize)];
    
    copyList = list;
    
    while(copyList != NULL && copyList->Element != element) {
        copyList = copyList->Next;
    }

    return copyList;
}

int FindElementIndexSC(int element, int tableSize, SCHT hashTable) {
    int index = Hash(element, hashTable->TableSize);
    
    return index;
}

Position FindPreviousElement(int element, List list) {
    Position previous = list;
    List copyList = list->Next;
    
    while(copyList != NULL && copyList->Element != element) {
        previous = copyList;
        copyList = copyList->Next;
    }

    return previous;
}

int DeleteElementSC(int choice, int element, SCHT hashTable) {
    Position previous = NULL, temp = NULL;
    List copyList = NULL;
    int index = Hash(element, hashTable->TableSize);
    
    copyList = hashTable->HashLists[index];
        
    if(copyList->Element == element) {
        temp = copyList;
        
        hashTable->HashLists[index] = temp->Next;
    }
    else {
        previous = FindPreviousElement(element, copyList);
        
        temp = previous->Next;
        
        previous->Next = temp->Next;
    }
    
    if(choice == 2) {
        printf("\n\t\tElement deleted: %d, from index: %d.", temp->Element, index);
    }
    
    free(temp);
    
    return RETURN_OK;
}
