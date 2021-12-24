#include "../headerFiles/mainHeaderFile.h"

int PreviousPrimeNumber(int number) {
    int i = 3;
    
    if(number <= 2) {
        printf("Number %d does not have previous prime number.", number);
    }
    else if(number == 3) {
        return 2;
    }
    
    if(number % 2 == 0) {
        number--;
    }
    else {
        number -= 2;
    }
    
    while((i * i) <= number) {
        if(number % i != 0)
            i += 2;
        else {
            number -= 2;
            i = 3;
        }
    }
    
    return number;
}

int FollowingPrimeNumber(int number) {
    int i = 3;
    
    if(number <= 3)
        return number;
    
    if(number % 2 == 0) {
        number++;
    }
    else {
        number+=2;
    }
    
    while((i * i) <= number) {
        if(number % i != 0)
            i += 2;
        else {
            number += 2;
            i = 3;
        }
    }
    
    return number;
}

int RandomNumberGenerator(int rand_min, int rand_max) {
    return rand() % (rand_max + 1 - rand_min) + rand_min;
}

int* GenerateRandomNumbers(int rand_max, int numberOfElements) {
    int* array = (int*)malloc(sizeof(int) * rand_max);
    
    if(array == NULL) {
        return RETURN_ERROR_MEMORY_ALLOCATION_FAILED;
    }
    
    int* newArray = (int*)malloc(sizeof(int) * numberOfElements);
    
    if(newArray == NULL) {
        return RETURN_ERROR_MEMORY_ALLOCATION_FAILED;
    }
    
    for(int i = 0; i < rand_max; i++) {
        array[i] = i + 1;
    }
        
    for(int i = 0; i < numberOfElements; i++) {
        int temp = array[i];
        int random = RandomNumberGenerator(1, rand_max);
        
        newArray[i] = array[random];
        array[random] = temp;
    }
    
    free(array);
    
    return newArray;
}
