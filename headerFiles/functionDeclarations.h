#ifndef _FUNCTION_DECLARATIONS_H_
#define _FUNCTION_DECLARATIONS_H_

//General functions
int PreviousPrimeNumber(int);
int FollowingPrimeNumber(int);
int RandomNumberGenerator(int, int);
int* GenerateRandomNumbers(int, int);

//Hashing functions
int Hash(int, int);
int CollisionHandlingLP(int, int, int);
int CollisionHandlingQP(int, int, int);
int Hash2(int, int);
int CollisionHandlingDH(int, int, int);

//Open addressing - service layer
int* CreateEmptyTable(int);
OAHT TableInitializationOA(int);
int PrintTableOA(int, int*);
int IsEmpty(int, int*);
int HashingAlgorithm(int, OAHT, int (*CHFunction)(int, int, int));
int AddElementOA(int,  OAHT, int (*CHFunction)(int, int, int));
int FindElementOA(int, int, OAHT, int (*CHFunction)(int, int, int));
int DeleteElementOA(int, int, OAHT, int (*CHFunction)(int, int, int));

//Open addressing - controllers
int Rehashing(int, int, OAHT, int (*CHFunction)(int, int, int));
OAHT AddAllElementsOA(int, int, int*, OAHT, int (*CHFunction)(int, int, int));
int FindAllElementsOA(int, int, int*, OAHT, int (*CHFunction)(int, int, int));
int DeleteAllElementsOA(int, int, int*, OAHT, int (*CHFunction)(int, int, int));

//Separate chaining - service layer
SCHT TableInitializationSC(int);
int PrintTableSC(SCHT);
int AddElementSC(int, SCHT);
Position FindElementSC(int, SCHT);
int FindElementIndexSC(int, int, SCHT);
Position FindPreviousElementSC(int, List);
int DeleteElementSC(int, int, SCHT);

//Separate chaining - controllers
int AddAllElementsSC(int, int, int*, SCHT);
int FindAllElementsSC(int, int, int*, SCHT);
int DeleteAllElementsSC(int, int, int*, SCHT);

//Timing functions
double ExecutionTimeToSeconds(clock_t);
double* TimingFunctionOA(int, int, int, int*, int (*CHFunction)(int, int, int));
double* TimingFunctionSC(int, int, int, int*);
int TimingResults(double*);

//Menu function
int DisplayMenu(void);
int CheckInputIsInteger(int);
int CheckNumberIsInRange(int, int, int);

#endif
