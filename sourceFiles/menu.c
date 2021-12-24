#include "../headerFiles/mainHeaderFile.h"

int DisplayMenu(void) {
    int choice = 0;
    
    printf("\n\n------------------------------------------------------------\n\n");
    
    printf("\tThis is an application for comparing the efficiency of");
    printf("\n\thashing algorithms when entering, searching and deleting ");
    printf("\n\tintegers in a hash table.");
    
    printf("\n\n------------------------------------------------------------\n\n");

    printf("\tAPPLICATION VERSION MENU:\n");
    printf("\n\t1) SHORT VERSION OF APPLICATION");
    printf("\n\t   --> Short version of application displays only");
    printf("\n\t       efficiency results.");
    printf("\n\n\t2) EXTENDED VERSION OF APPLICATION");
    printf("\n\t   --> Extended version of application displays, ");
    printf("\n\t       along with efficiency results, results of ");
    printf("\n\t       function execution step by step.");
    printf("\n\t   --> This is usually used for debugging and ");
    printf("\n\t       result checking (not recommended for a large number ");
    printf("\n\t       of elements. \n\n\n");

    printf("\n\tENTER YOUR CHOICE: ");

    do {
        choice = CheckInputIsInteger(choice);
        
        if(CheckNumberIsInRange(choice, 1, 2) == RETURN_OK) {
            printf("\n\tYour choice: %d\n", choice);
            break;
        }
        
    }while(1);
    
    return choice;
}

int CheckInputIsInteger(int input) {
    while((scanf(" %d", &input)) != 1) {
        while (getchar() != '\n');
    
        printf("\n\tINCORRECT INPUT! Input must be an integer!");
        printf("\n\tENTER AGAIN: ");
    }
    
    while (getchar() != '\n');
    
    return input;
}

int CheckNumberIsInRange(int input, int min, int max) {
    if(input >= min && input <= max) {
        return RETURN_OK;
    }
    
    printf("\n\tINCORRECT INPUT! Input must be in range [%d, %d]!", min, max);
    printf("\n\tENTER AGAIN: ");

    return RETURN_ERROR_ELEMENT_NOT_IN_RANGE;
}
