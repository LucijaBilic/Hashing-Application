#include "../headerFiles/mainHeaderFile.h"

double ExecutionTimeToSeconds(clock_t time) {
    return (((double)time) / CLOCKS_PER_SEC);
}

double* TimingFunctionOA(int choice, int tableSize, int numberOfElements, int* randomNumbers, int (*CHFunction)(int, int, int)) {
    
    double* timeTable = (double*)malloc(sizeof(double) * 3);
    
    if(timeTable == NULL) {
        printf("\n\nERROR! Failed allocating time table!");
        return RETURN_ERROR_MEMORY_ALLOCATION_FAILED;
    }
    
    double inputTime = 0, searchTime = 0, deletionTime = 0;
    
    clock_t time;
    OAHT hashTable = TableInitializationOA(tableSize);
    
    if(hashTable == NULL) {
        return RETURN_ERROR_MEMORY_ALLOCATION_FAILED;
    }
    
    if(choice == 2) {
        printf("\n\n\n\t 1) FORMING HASH TABLE:\n");
    }
    
    time = clock();
    
    hashTable = AddAllElementsOA(choice, numberOfElements, randomNumbers, hashTable, (*CHFunction));
    
    if(hashTable == NULL) {
        return RETURN_ERROR_MEMORY_ALLOCATION_FAILED;
    }
    
    time = clock() - time;
    
    inputTime = ExecutionTimeToSeconds(time);

    if(choice == 2) {
        printf("\n\n\t 2) FINDING ALL ELEMENTS IN HASH TABLE:\n");
    }

    time = clock();
    FindAllElementsOA(choice, numberOfElements, randomNumbers, hashTable, (*CHFunction));
    time = clock() - time;
    
    searchTime = ExecutionTimeToSeconds(time);
    
    if(choice == 2) {
        printf("\n\n\n\t 3) DELETING ALL ELEMENTS FROM HASH TABLE:\n");
    }

    time = clock();
    DeleteAllElementsOA(choice, numberOfElements, randomNumbers, hashTable, (*CHFunction));
    time = clock() - time;

    deletionTime = ExecutionTimeToSeconds(time);
    
    timeTable[0] = inputTime;
    timeTable[1] = searchTime;
    timeTable[2] = deletionTime;
    
    free(hashTable);
    
    return timeTable;
}

double* TimingFunctionSC(int choice, int tableSize, int numberOfElements, int* randomNumbers) {
    
    double* timeTable = (double*)malloc(sizeof(double) * 3);
    
    if(timeTable == NULL) {
        printf("\n\nERROR! Failed allocating time table!");
        return RETURN_ERROR_MEMORY_ALLOCATION_FAILED;
    }
    
    double inputTime = 0, searchTime = 0, deletionTime = 0;
    int returnValue = 0;
    
    clock_t time;
    SCHT hashTable = NULL;
    
    hashTable = TableInitializationSC(tableSize);
    
    if(hashTable == NULL) {
        return RETURN_ERROR_MEMORY_ALLOCATION_FAILED;
    }

    if(choice == 2) {
        printf("\n\n\n\t 1) FORMING HASH TABLE:\n");
    }

    time = clock();
    
    returnValue = AddAllElementsSC(choice, numberOfElements, randomNumbers, hashTable);
    
    if(returnValue == RETURN_ERROR_NEW_NODE_ALLOCATION_FAILED) {
        return RETURN_ERROR_MEMORY_ALLOCATION_FAILED;
    }
    
    time = clock() - time;

    inputTime = ExecutionTimeToSeconds(time);
    
    if(choice == 2) {
        printf("\n\n\n\t 2) FINDING ALL ELEMENTS IN HASH TABLE:\n");
    }

    time = clock();
    FindAllElementsSC(choice, numberOfElements, randomNumbers, hashTable);
    time = clock() - time;
    
    searchTime = ExecutionTimeToSeconds(time);
    
    if(choice == 2) {
        printf("\n\n\n\t 3) DELETING ALL ELEMENTS FROM HASH TABLE:\n");
    }

    time = clock();
    DeleteAllElementsSC(choice, numberOfElements, randomNumbers, hashTable);
    time = clock() - time;
    
    deletionTime = ExecutionTimeToSeconds(time);
    
    timeTable[0] = inputTime;
    timeTable[1] = searchTime;
    timeTable[2] = deletionTime;
    
    return timeTable;
}

int TimingResults(double* timeTable) {
    printf("\n\n\n\tRESULTS:\n");
    printf("\n\t--> FORMING HASH TABLE: %f seconds\n", timeTable[0]);
    printf("\t--> FINDING ALL ELEMENTS: %f seconds\n", timeTable[1]);
    printf("\t--> DELETING ALL ELEMENTS: %f seconds\n", timeTable[2]);
    
    return RETURN_OK;
}
