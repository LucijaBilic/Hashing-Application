#include "../headerFiles/mainHeaderFile.h"

int main(int argc, const char * argv[]) {
    int hashTableSize = 0, numberOfElements = 0, rand_max = 0, choice = 0;
    
    int* randomNumbers = NULL;
    double* returnValues = NULL;
    
    srand((unsigned)time(NULL));
    
//  --------------------------------------------------------

    printf("\n\n\t\t\t\t~  HASHING  ~\n");
    
    choice = DisplayMenu();
    
    printf("\n------------------------------------------------------------\n\n");
    
    printf("\tUser enters the number of elements (positive integers)  ");
    printf("\n\twhich will be entered into the hash table and the ");
    printf("\n\tsize of the hash table. For the table size, the closest ");
    printf("\n\tfollowing prime number will be chosen: ");
    
    printf("\n\n\n\tENTER THE NUMBER OF ELEMENTS: ");

    do {
        numberOfElements = CheckInputIsInteger(numberOfElements);
        
        if(CheckNumberIsInRange(numberOfElements, 1, INT_MAX) == RETURN_OK) {
            printf("\n\tChosen number of elements: %d", numberOfElements);
            
            break;
        }
        
    }while(1);
    
    printf("\n\n\tENTER THE SIZE OF THE HASH TABLE: ");

    do {
        hashTableSize = CheckInputIsInteger(hashTableSize);
        
        if(CheckNumberIsInRange(hashTableSize, 1, INT_MAX) == RETURN_OK) {
            printf("\n\tChosen size of the hash table: %d\n", hashTableSize);
            break;
        }
        
    }while(1);
    
    printf("\n------------------------------------------------------------\n\n");
    
    rand_max = numberOfElements * 10;
            
    randomNumbers = GenerateRandomNumbers(rand_max, numberOfElements);
    
    if(randomNumbers == RETURN_ERROR_MEMORY_ALLOCATION_FAILED) {
        printf("ERROR! Failed to generate rabndom numbers!\n\n");
        return RETURN_ERROR_MEMORY_ALLOCATION_CODE;
    }
        
    printf("\tAccording to the number of elements, a table containing ");
    printf("\n\trandom integers from range [1, number of elements * 10] ");
    printf("\n\tis created, and these integers are further entered in");
    printf("\n\thash table.");
    
    if(numberOfElements < 100) {
        printf("\n\n\n\tTABLE:\n");
    
        PrintTableOA(numberOfElements, randomNumbers);
    }
    
    hashTableSize = FollowingPrimeNumber(hashTableSize);
    
    printf("\n\n------------------------------------------------------------\n\n");

    printf("\tTwo approaches are being used for forming the hash table:");
    printf("\n\n\t1) OPEN ADDRESSING - by using:");
    printf("\n       --> LINEAR PROBING ALGORITHM");
    printf("\n       --> QUADRATIC PROBING ALGORITHM");
    printf("\n       --> DOUBLE HASHING ALGORITHM");
    printf("\n\n\t2) SEPARATE CHAINING - by using");
    printf("\n       --> LINKED LISTS");
    
    printf("\n\n------------------------------------------------------------\n\n");

    printf("\t ~  LINEAR PROBING ALGORITHM  ~");
    
    returnValues = TimingFunctionOA(choice, hashTableSize, numberOfElements, randomNumbers, CollisionHandlingLP);
    
    if(returnValues == NULL) {
        return RETURN_ERROR_MEMORY_ALLOCATION_CODE;
    }

    TimingResults(returnValues);

    printf("\n\n------------------------------------------------------------\n\n");

    printf("\t ~  QUADRATIC PROBING ALGORITHM  ~");

    returnValues = TimingFunctionOA(choice, hashTableSize, numberOfElements, randomNumbers, CollisionHandlingQP);
    
    if(returnValues == NULL) {
        return RETURN_ERROR_MEMORY_ALLOCATION_CODE;
    }

    TimingResults(returnValues);
    
    printf("\n\n------------------------------------------------------------\n\n");

    printf("\t ~  DOUBLE HASHING ALGORITHM  ~");

    returnValues = TimingFunctionOA(choice, hashTableSize, numberOfElements, randomNumbers, CollisionHandlingDH);
    
    if(returnValues == NULL) {
        return RETURN_ERROR_MEMORY_ALLOCATION_CODE;
    }

    TimingResults(returnValues);
    
    printf("\n\n------------------------------------------------------------\n\n");

    printf("\t ~  LINKED LISTS  ~");

    returnValues = TimingFunctionSC(choice, hashTableSize, numberOfElements, randomNumbers);
    
    if(returnValues == NULL) {
        return RETURN_ERROR_MEMORY_ALLOCATION_CODE;
    }

    TimingResults(returnValues);
    
    printf("\n\n");

    free(randomNumbers);
    free(returnValues);

    return RETURN_OK;
}
