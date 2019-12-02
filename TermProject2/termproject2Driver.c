#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projectHeader.h"
#include <time.h>

//Prototypes
void processCMDArgs(int argc, char * argv[]);
void printJobStatus();

//Structs
typedef struct trialNode{
    long double trial1;
    long double trial2;
    long double trial3;
    long double trial4;
    long double average;
    int size;
}trialNode; 

typedef struct masterNode{
    trialNode *intTrials;
    trialNode *stringTrials;
}masterNode;


//Global Variables
//0 == print sorted array, 1 == print time table
int printType;

//0 == integers, 1 == strings
int sortType;

//Sorting Algorithm
//1 == quickSort, 2 == mergeSort, 3 == radixSort, 
//4 == heapSort, 5 == insertionSort, 6 == selectionSort
//7 == test all algorithms
int sortAlg;

//Number of Trials
int numTrials;

//Number of array sizes
int numArraySizes;

//Array sizes
int * arraySizes;

int main(int argc, char * argv[]) 
{
    processCMDArgs(argc, argv);

	//For debugging purposes.
	//Remove all printJobStatus() calls before creating
	//final output and before submitting.
    printJobStatus();
    
    masterNode *masterQuick = malloc(sizeof(masterNode));
    masterNode *masterMerge = malloc(sizeof(masterNode));
    masterNode *masterRadix = malloc(sizeof(masterNode));
    masterNode *masterHeap = malloc(sizeof(masterNode));
    masterNode *masterInsertion = malloc(sizeof(masterNode));
    masterNode *masterSelection = malloc(sizeof(masterNode));
    
            
    if(sortType == 0)
    {
        int i;
        int j;
        int highest = 0;
        int lowest = 0;
        int temp;
        clock_t start_t, end_t, total_t;
        
        for(i = 0; i < numArraySizes; i++)
        {
            int * array = (int *) malloc (arraySizes[i] * sizeof(int));
            for(j = 0; j < arraySizes[i]; j++)
            {
                temp = randNum();
                if(temp > highest)
                {
                    highest = temp;
                }
                else if(temp < lowest)
                {
                    lowest = temp;
                }
                array[j] = temp;
            }
            switch (sortAlg)
            {
                case 1:
                    start_t = clock();
                    quickSort_int(array, lowest, highest);
                    end_t = clock();
                    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
                    masterQuick->intTrials->trial1;
                    break;
                case 2:
                    start_t = clock();
                    mergeSort_int(array, lowest, highest);
                    end_t = clock();
                    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
                    masterMerge->intTrials->trial1;
                    break;
                case 3:
                    start_t = clock();
                    radixSort_int(array, arraySizes[i]);
                    end_t = clock();
                    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
                    masterRadix->intTrials->trial1;
                    break;
                case 4:
                    start_t = clock();
                    heapSort_int(array, arraySizes[i]);
                    end_t = clock();
                    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
                    masterHeap->intTrials->trial1;
                    break;
                case 5:
                    start_t = clock();
                    insertionSort_int(array, arraySizes[i]);
                    end_t = clock();
                    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
                    masterInsertion->intTrials->trial1;
                    break;
                case 6:
                    start_t = clock();
                    selectionSort_int(array, arraySizes[i]);
                    end_t = clock();
                    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
                    masterSelection->intTrials->trial1;
                    break;
                case 7:
                    start_t = clock();
                    quickSort_int(array, lowest, highest);
                    end_t = clock();
                    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
                    masterQuick->intTrials->trial1;
                    
                    start_t = clock();
                    mergeSort_int(array, lowest, highest);
                    end_t = clock();
                    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
                    masterMerge->intTrials->trial1;
                    
                    start_t = clock();
                    radixSort_int(array, arraySizes[i]);
                    end_t = clock();
                    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
                    masterRadix->intTrials->trial1;
                    
                    start_t = clock();
                    heapSort_int(array, arraySizes[i]);
                    end_t = clock();
                    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
                    masterHeap->intTrials->trial1;
                    
                    start_t = clock();
                    insertionSort_int(array, arraySizes[i]);
                    end_t = clock();
                    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
                    masterInsertion->intTrials->trial1;
                    
                    start_t = clock();
                    selectionSort_int(array, arraySizes[i]);
                    end_t = clock();
                    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
                    masterSelection->intTrials->trial1;
                    break;
            }
            free(array);
        }
    }
        
    free(arraySizes);

    return 0;
}









void printJobStatus() {
	int i;

	if (printType == 0) printf("\nprintType:   sorted array\n");
	else printf("printType:   time table\n");

	if (sortType == 0) printf("sortType:    integers\n");
	else printf("sortType:    strings\n");

	switch (sortAlg)
	{
	    case 1:
	    	printf("sortAlg:     quickSort\n");
	        break;
	    case 2:
	    	printf("sortAlg:     mergeSort\n");
	        break;
	    case 3:
	    	printf("sortAlg:     radixSort\n");
	        break;
	    case 4:
	    	printf("sortAlg:     heapSort\n");
	        break;
	    case 5:
	    	printf("sortAlg:     insertionSort\n");
	        break;
	    case 6:
	    	printf("sortAlg:     selectionSort\n");
	        break;
	    case 7:
	    	printf("sortAlg:     test all sorting algorithms\n");
	        break;
	}

	printf("numTrials:   %d\n", numTrials);
	printf("numArraySizes: %d\n", numArraySizes);
	printf("array sizes: ");

	for (i=0; i<numArraySizes; i++) {
		printf("%d  ", arraySizes[i]);
	}

	printf("\n\n");
}


void processCMDArgs(int argc, char * argv[]) {
	int i;
	int temp;

	if (argc < 6) {
		printf("CMD Usage: ./project {printType} {sortType} {sortAlg} {numTrials} {arraySizes...arraySizes}\n");
		exit(0);
	}

	for (i=0; i<argc; i++) {
		//get printType
		if (i == 1) {
			if (argv[i][0] == '0') printType = 0;
			else if (argv[i][0] == '1') printType = 1;
			else {
				printf("CMD Usage: ./project {printType} {sortType} {sortAlg} {numTrials} {arraySizes...arraySizes}\n");
				printf("                     {  0 - 1  }\n");
				exit(0);
			}
		}
		if (i == 2) {
			if (argv[i][0] == '0') sortType = 0;
			else if (argv[i][0] == '1') sortType = 1;
			else {
				printf("CMD Usage: ./project {printType} {sortType} {sortAlg} {numTrials} {arraySizes...arraySizes}\n");
				printf("                                 { 0 - 1  }\n");
				exit(0);
			}
		}
		else if (i == 3) {
			temp = atoi(argv[i]);

			if (temp == 0 || temp < 1 || temp > 7) {
				printf("CMD Usage: ./project {printType} {sortType} {sortAlg} {numTrials} {arraySizes...arraySizes}\n");
				printf("                                            { 1 - 7 }\n");
				exit(0);
			}

			sortAlg = temp;
		}
		else if (i == 4) {
			temp = atoi(argv[i]);

			if (temp == 0 || temp < 1 || temp > 3) {
				printf("CMD Usage: ./project {printType} {sortType} {sortAlg} {numTrials} {arraySizes...arraySizes}\n");
				printf("                                                      {  1 - 3  }\n");
				exit(0);
			}

			numTrials = temp;
		}
	}

	numArraySizes = argc - 5;

	if (numArraySizes <= 0) {
		printf("CMD Usage: at least one array size must be given\n");
		printf("CMD Usage: ./project {printType} {sortType} {sortAlg} {numTrials} {arraySizes...arraySizes}\n");
		printf("                                                                  {   1000 < n < 75000    }\n");
		exit(0);
	}

	arraySizes = (int *) malloc(sizeof(int) * numArraySizes);

	if(arraySizes == NULL) {
		printf("Malloc error\n");
		exit(0);
	}

	for (i=5; i<argc; i++) {
		temp = atoi(argv[i]);

		if (temp == 0 || temp < 1000 || temp > 75000) {
			printf("CMD Usage: ./project {printType} {sortType} {sortAlg} {numTrials} {arraySizes...arraySizes}\n");
			printf("                                                                  {   1000 < n < 75000    }\n");
			free(arraySizes);
			exit(0);
		}

		arraySizes[i-5] = temp;
	}
}





