#include "../headerFiles/mainHeaderFile.h"

int AddAllElementsSC(int choice, int numberOfElements, int* randomNumbers, SCHT hashTable) {
    int index = 0;
    
    for(int i = 0; i < numberOfElements; i++) {
        index = AddElementSC(randomNumbers[i], hashTable);
        
        if(index == RETURN_ERROR_NEW_NODE_ALLOCATION_FAILED) {
            printf("\n\t\tMemory allocation failed!");
            return index;
        }
        
        if(choice == 2)  {
            printf("\n\t\tElement added: %d, at index %d.", randomNumbers[i], index);
        }
    }
    
    if(choice == 2) {
        printf("\n\n************************************************************\n");

        printf("\n\t HASH TABLE:");
        PrintTableSC(hashTable);
        
        printf("\n\n************************************************************");
    }
    
    return RETURN_OK;
}

int FindAllElementsSC(int choice, int numberOfElements, int* randomNumbers, SCHT hashTable) {
    Position target = NULL;
    int index = 0;
    
    for(int i = 0; i < numberOfElements; i++) {
        target = FindElementSC(randomNumbers[i], hashTable);
        
        if(choice == 2) {
            if(target != NULL){
                index = FindElementIndexSC(randomNumbers[i], numberOfElements, hashTable);
                
                printf("\n\t\tElement found: %d, at index: %d.", randomNumbers[i], index);
            }
        }
    }

    return RETURN_OK;
}

int DeleteAllElementsSC(int choice, int numberOfElements, int* randomNumbers, SCHT hashTable) {
    for(int i = 0; i < numberOfElements; i++) {
        DeleteElementSC(choice, randomNumbers[i], hashTable);
    }
    
    return RETURN_OK;
}
