#include "../headerFiles/mainHeaderFile.h"

int Rehashing(int choice, int newTableSize, OAHT hashTable, int (*CHFunction)(int, int, int)) {
    int oldTableSize = 0, index = 0;
    int* temp = NULL;
    
    oldTableSize = hashTable->TableSize;
    
    hashTable->TableSize = newTableSize;
    
    temp = hashTable->Table;
    
    hashTable->Table = CreateEmptyTable(newTableSize);
    
    if(hashTable->Table == NULL) {
        printf("\n\nERROR! Failed to allocate hash table (OAHT)!");
        return RETURN_ERROR_MEMORY_ALLOCATION_CODE;
    }
    
    hashTable->RowsFilled = 0;
    
    if(choice == 2) {
        printf("\n\n\n\t\tREHASHING...(new table size = %d)\n", newTableSize);
    }
    
    for(int i = 0; i < oldTableSize; i++) {
        if(temp[i] != 0) {
            index = AddElementOA(temp[i], hashTable, (*CHFunction));
            
            if(choice == 2) {
                printf("\n\t\t--> Element moved: %d, to index %d.", temp[i], index);
            }
        }
        
    }

    if(choice == 2) {
        printf("\n");
    }
    
    free(temp);
    
    return RETURN_OK;
}

OAHT AddAllElementsOA(int choice, int numberOfElements, int* randomNumbers, OAHT hashTable, int (*CHFunction)(int, int, int)) {
    int newTableSize = 0, index = 0, returnValue = 0;
    
    for(int i = 0; i < numberOfElements; i++) {
        if(hashTable->RowsFilled > (int)(hashTable->TableSize / 2 + 0.5)) {
            newTableSize = FollowingPrimeNumber(hashTable->TableSize * 2);

            returnValue = Rehashing(choice, newTableSize ,hashTable, (*CHFunction));
            
            if(returnValue != RETURN_OK) {
                return RETURN_ERROR_MEMORY_ALLOCATION_FAILED;
            }
        }
        
        index = AddElementOA(randomNumbers[i], hashTable, (*CHFunction));
        
        if(choice == 2) {
            printf("\n\n\t\tElement added: %d, at index %d.", randomNumbers[i], index);
            printf("\n\t\t--> Table size: %d, rows filled: %d.", hashTable->TableSize, hashTable->RowsFilled);
        }
        
    }
    
    if(choice == 2) {
        printf("\n\n************************************************************\n");

        printf("\n\t HASH TABLE:\n");
        PrintTableOA(hashTable->TableSize, hashTable->Table);
        
        printf("\n\n************************************************************");
    }

    return hashTable;
}

int FindAllElementsOA(int choice, int numberOfElements, int* randomNumbers, OAHT hashTable, int (*CHFunction)(int, int, int)) {
    int index = 0;
    
    for(int i = 0; i < numberOfElements; i++) {
        index = FindElementOA(choice, randomNumbers[i], hashTable, (*CHFunction));
        
        if(index != RETURN_ERROR_ELEMENT_NOT_FOUND && choice == 2) {
            printf("\n\t\tElement found: %d, at index: %d.", randomNumbers[i], index);
        }
    }
    
    return RETURN_OK;
}

int DeleteAllElementsOA(int choice, int numberOfElements, int* randomNumbers, OAHT hashTable, int (*CHFunction)(int, int, int)) {

    for(int i = 0; i < numberOfElements; i++) {
        DeleteElementOA(choice, randomNumbers[i], hashTable, (*CHFunction));
    }

    return RETURN_OK;
}
