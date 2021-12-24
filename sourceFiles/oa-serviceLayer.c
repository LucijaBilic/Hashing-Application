#include "../headerFiles/mainHeaderFile.h"

int* CreateEmptyTable(int tableSize) {
    int* table = (int*)malloc(sizeof(int) * tableSize);
    
    if(table == NULL) {
        return RETURN_ERROR_MEMORY_ALLOCATION_FAILED;
    }
    
    for(int i = 0; i < tableSize; i++)
        table[i] = 0;
    
    return table;
}

OAHT TableInitializationOA(int tableSize) {
    OAHT hashTable = NULL;

    hashTable = (OAHT)malloc(sizeof(struct _OA_hashTable));
    
    if(hashTable == NULL) {
        printf("\n\nERROR! Failed to allocate OAHT struct!");
        return RETURN_ERROR_MEMORY_ALLOCATION_FAILED;
    }

    hashTable->TableSize = tableSize;
    hashTable->Table = CreateEmptyTable(tableSize);
    
    if(hashTable->Table == NULL) {
        printf("\n\nERROR! Failed to allocate hash table (OAHT)!");
        return RETURN_ERROR_MEMORY_ALLOCATION_FAILED;
    }
    
    hashTable->RowsFilled = 0;
    
    return hashTable;
}

int PrintTableOA(int tableSize, int* table) {
    printf("\n\t[");
    
    for(int i = 0; i < tableSize; i++) {
        if(i != tableSize - 1) {
            printf(" %d ,", table[i]);
        }
        else {
            printf(" %d ", table[i]);
        }
    }
    
    printf("]");
    
    return RETURN_OK;
}

int IsEmpty(int index, int* table) {
    if(table[index] != 0)
        return FALSE;
    else
        return TRUE;
}

int HashingAlgorithm(int key, OAHT hashTable, int (*CHFunction)(int, int, int)) {
    int index = 0, hashIndex = 0;
    
    index = Hash(key, hashTable->TableSize);
    
    if(IsEmpty(index, hashTable->Table) == TRUE) {
        return index;
    }
    else {
        hashIndex = 1;
        
        while(IsEmpty(index, hashTable->Table) == FALSE) {
            index = (*CHFunction)(key, hashIndex, hashTable->TableSize);
            
            hashIndex++;
        }
    }
    
    return index;
}

int AddElementOA(int element,  OAHT hashTable, int (*CHFunction)(int, int, int)) {
    int index = HashingAlgorithm(element, hashTable, (*CHFunction));
    
    hashTable->Table[index] = element;

    hashTable->RowsFilled++;
    
    return index;
}

int FindElementOA(int choice, int element, OAHT hashTable, int (*CHFunction)(int, int, int)) {
    int index = 0, hashIndex = 1;
    
    index = Hash(element, hashTable->TableSize);
    
    if(hashTable->Table[index] == element)
        return index;
    
    while(hashIndex < hashTable->TableSize) {
        index = (*CHFunction)(element, hashIndex, hashTable->TableSize);
        
        if(hashTable->Table[index] == element)
            return index;
        
        hashIndex++;
    }
    
    return RETURN_ERROR_ELEMENT_NOT_FOUND;
}

int DeleteElementOA(int choice, int element, OAHT hashTable, int (*CHFunction)(int, int, int)) {
    int index = FindElementOA(choice, element, hashTable, (*CHFunction));
    
    hashTable->Table[index] = 0;
    hashTable->RowsFilled--;
    
    if(choice == 2) {
        printf("\n\t\tElement deleted: %d, form index %d.", element, index);
    }
    
    return RETURN_OK;
}
