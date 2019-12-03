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
    long double *timeTrials;
    long double average;
    int size;
}trialNode;

typedef trialNode *masterNode; //use as array of trialNode


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

  int i, j, k, l; //counter Variables

    processCMDArgs(argc, argv);



	//For debugging purposes.
	//Remove all printJobStatus() calls before creating
	//final output and before submitting.
    printJobStatus();
    //total number of trialNode structures required by args
    int numTrialNodes;

    //calculate number of trials = number of array sizes * number of sort algorithms
    if(sortAlg!=7){
      numTrialNodes=numArraySizes;
    } else {
      numTrialNodes=numArraySizes*6;
    }

    masterNode testResults = (masterNode) malloc(sizeof(trialNode)*numTrialNodes);

    //each trail node should contain array of double the size of the number of trials
    for(i=0;i<numTrialNodes;i++){
        testResults[i].timeTrials = (long double *) malloc(sizeof(long double)*numTrials);
        testResults[i].average = 0;
        testResults[i].size = 0;
    }

    if(sortType == 0)
    {

      if(sortType == 0)
      {

          int highest = 0;
          int lowest = 0;
          int temp;
          clock_t start_t, end_t, total_t;

          for(i = 0; i < numArraySizes; i++)
          {

              //create + populate array
              int * intArray = (int *) malloc (arraySizes[i] * sizeof(int));// renaming to intArray
              for(k = 0; k < arraySizes[i]; k++)
              {
                  temp = randNum();
                  intArray[k] = temp;
              }
              //define greatest and least index
              highest = arraySizes[i]-1;
              lowest = 0;

              switch (sortAlg)
              {
                  case 1://quickSort_int

                    //record array sizes
                    testResults[i].size=arraySizes[i];

                    for(j=0;j<numTrials;j++){
                      //create + populate array
                      int * intArray = (int *) malloc (arraySizes[i] * sizeof(int));// renaming to intArray
                      for(k = 0; k < arraySizes[i]; k++)
                      {
                          temp = randNum();
                          intArray[k] = temp;
                      }
                      //define greatest and least index
                      highest = arraySizes[i]-1;
                      lowest = 0;

                      //sort array and get sort time
                      start_t = clock();
                      quickSort_int(intArray, lowest, highest);
                      end_t = clock();
                      total_t = (long double)(end_t - start_t);

                      //store time in appropriate index
                      testResults[i].timeTrials[j]=total_t;
                      testResults[i].average += total_t;
                      if(numTrials-j==1){ testResults[i].average = testResults[i].average / numTrials;}
                      }
                      break;
                  case 2://mergeSort_int
                  //record array sizes
                  testResults[i].size=arraySizes[i];

                  for(j=0;j<numTrials;j++){
                    //create + populate array
                    int * intArray = (int *) malloc (arraySizes[i] * sizeof(int));// renaming to intArray
                    for(k = 0; k < arraySizes[i]; k++)
                    {
                        temp = randNum();
                        intArray[k] = temp;
                    }
                    //define greatest and least index
                    highest = arraySizes[i]-1;
                    lowest = 0;

                    //sort array and get sort time
                    start_t = clock();
                    mergeSort_int(intArray, lowest, highest);
                    end_t = clock();
                    total_t = (long double)(end_t - start_t);

                    //store time in appropriate index
                    testResults[i].timeTrials[j]=total_t;
                    testResults[i].average += total_t;
                    if(numTrials-j==1){ testResults[i].average = testResults[i].average / numTrials;}
                    }
                    break;
                  case 3://radixSort_int
                  //record array sizes
                  testResults[i].size=arraySizes[i];

                  for(j=0;j<numTrials;j++){
                    //create + populate array
                    int * intArray = (int *) malloc (arraySizes[i] * sizeof(int));// renaming to intArray
                    for(k = 0; k < arraySizes[i]; k++)
                    {
                        temp = randNum();
                        intArray[k] = temp;
                    }
                    //define greatest and least index
                    highest = arraySizes[i]-1;
                    lowest = 0;

                    //sort array and get sort time
                    start_t = clock();
                    radixSort_int(intArray, arraySizes[i]);
                    end_t = clock();
                    total_t = (long double)(end_t - start_t);

                    //store time in appropriate index
                    testResults[i].timeTrials[j]=total_t;
                    testResults[i].average += total_t;
                    if(numTrials-j==1){ testResults[i].average = testResults[i].average / numTrials;}
                    }
                    break;
                  case 4://heapSort_int
                  //record array sizes
                  testResults[i].size=arraySizes[i];

                  for(j=0;j<numTrials;j++){
                    //create + populate array
                    int * intArray = (int *) malloc (arraySizes[i] * sizeof(int));// renaming to intArray
                    for(k = 0; k < arraySizes[i]; k++)
                    {
                        temp = randNum();
                        intArray[k] = temp;
                    }
                    //define greatest and least index
                    highest = arraySizes[i]-1;
                    lowest = 0;

                    //sort array and get sort time
                    start_t = clock();
                    heapSort_int(intArray, arraySizes[i]);
                    end_t = clock();
                    total_t = (long double)(end_t - start_t);

                    //store time in appropriate index
                    testResults[i].timeTrials[j]=total_t;
                    testResults[i].average += total_t;
                    if(numTrials-j==1){ testResults[i].average = testResults[i].average / numTrials;}
                    }
                    break;
                  case 5://insertionSort_int
                  //record array sizes
                  testResults[i].size=arraySizes[i];

                  for(j=0;j<numTrials;j++){
                    //create + populate array
                    int * intArray = (int *) malloc (arraySizes[i] * sizeof(int));// renaming to intArray
                    for(k = 0; k < arraySizes[i]; k++)
                    {
                        temp = randNum();
                        intArray[k] = temp;
                    }
                    //define greatest and least index
                    highest = arraySizes[i]-1;
                    lowest = 0;

                    //sort array and get sort time
                    start_t = clock();
                    insertionSort_int(intArray, arraySizes[i]);
                    end_t = clock();
                    total_t = (long double)(end_t - start_t);

                    //store time in appropriate index
                    testResults[i].timeTrials[j]=total_t;
                    testResults[i].average += total_t;
                    if(numTrials-j==1){ testResults[i].average = testResults[i].average / numTrials;}
                    }
                    break;
                  case 6://selectionSort_int
                  //record array sizes
                  testResults[i].size=arraySizes[i];

                  for(j=0;j<numTrials;j++){
                    //create + populate array
                    int * intArray = (int *) malloc (arraySizes[i] * sizeof(int));// renaming to intArray
                    for(k = 0; k < arraySizes[i]; k++)
                    {
                        temp = randNum();
                        intArray[k] = temp;
                    }
                    //define greatest and least index
                    highest = arraySizes[i]-1;
                    lowest = 0;

                    //sort array and get sort time
                    start_t = clock();
                    selectionSort_int(intArray, arraySizes[i]);
                    end_t = clock();
                    total_t = (long double)(end_t - start_t);

                    //store time in appropriate index
                    testResults[i].timeTrials[j]=total_t;
                    testResults[i].average += total_t;
                    if(numTrials-j==1){ testResults[i].average = testResults[i].average / numTrials;}
                    }
                    break;
                  case 7://perform all sorts at once

                    //record array sizes
                    testResults[i].size=arraySizes[i];

                    for(l=0; l<6; l++){

                    for(j=0;j<numTrials;j++){
                      //create + populate array
                      int * intArray = (int *) malloc (arraySizes[i] * sizeof(int));//renaming to intArray
                      for(k = 0; k < arraySizes[i]; k++)
                      {
                          temp = randNum();
                          intArray[k] = temp;
                      }
                      //define greatest and least index
                      highest = arraySizes[i]-1;
                      lowest = 0;

                      //sort array and get sort time
                      if (l==0){
                          start_t = clock();
                          quickSort_int(intArray, lowest, highest);
                          end_t = clock();
                        }

                        if (l==1){
                          start_t = clock();
                          mergeSort_int(intArray, lowest, highest);
                          end_t = clock();
                        }

                        if (l==2){
                          start_t = clock();
                          radixSort_int(intArray, arraySizes[i]);
                          end_t = clock();
                        }

                        if (l==3){
                          start_t = clock();
                          heapSort_int(intArray, arraySizes[i]);
                          end_t = clock();
                        }

                        if (l==4){
                          start_t = clock();
                          insertionSort_int(intArray, arraySizes[i]);
                          end_t = clock();
                        }

                        if (l==5){
                          start_t = clock();
                          selectionSort_int(intArray, arraySizes[i]);
                          end_t = clock();
                        }
                      }
                      total_t = (long double)(end_t - start_t);

                      //store time in appropriate index
                      testResults[i+numArraySizes*l].timeTrials[j]=total_t;
                      testResults[i+numArraySizes*l].average += total_t;
                      if(numTrials-j==1){ testResults[i+numArraySizes*l].average = testResults[i+numArraySizes*l].average / numTrials;}
                    }

                      break;
              }
              free(intArray);
          }

    }
    else if(sortType==1){
      else if(sortType==1){
          int j = 0;
          int highest = 0;
          int lowest = 0;
          int temp;
          clock_t start_t, end_t, total_t;
          FILE *pFile;
          pFile = fopen("last_name.txt", "r");
          char szInputBuffer[100];

          for(i = 0; i < numArraySizes; i++)
          {

              //create + populate array
              char strArray[arraySizes[numTrials-1]][MAX_LEN];
              while(fgets(szInputBuffer, 100, pFile) != NULL)
              {
                  sscanf(szInputBuffer, "%s", strArray[j]);
                  j++;
              }
              //define greatest and least index
              highest = arraySizes[i]-1;
              lowest = 0;

              switch (sortAlg)
              {
                  case 1://quickSort_int
                  start_t = clock();
                  quickSort_str(tempStrArray, lowest, highest);
                  end_t = clock();
                  total_t = (long double)(end_t - start_t);

                  //store time in appropriate index
                  testResults[i].timeTrials[j]=total_t;
                  testResults[i].average += total_t;
                  if(numTrials-j==1){ testResults[i].average = testResults[i].average / numTrials;}
                  }
                  break;
              case 2://mergeSort_int
              //record array sizes
              testResults[i].size=arraySizes[i];

              for(j=0;j<numTrials;j++){
                //create + populate array
                  /*
                int * intArray = (int *) malloc (arraySizes[i] * sizeof(int));//[Benjamin] renaming to intArray
                for(k = 0; k < arraySizes[i]; k++)
                {
                    temp = randNum();
                    intArray[k] = temp;
                }
                   */
                char tempStrArray[arraySizes[numTrials-1]][MAX_LEN];
                strcpy(tempStrArray[j], strArray[j]);
                //define greatest and least index
                highest = arraySizes[i]-1;
                lowest = 0;

                //sort array and get sort time
                start_t = clock();
                mergeSort_str(tempStrArray, lowest, highest);
                end_t = clock();
                total_t = (long double)(end_t - start_t);

                //store time in appropriate index
                testResults[i].timeTrials[j]=total_t;
                testResults[i].average += total_t;
                if(numTrials-j==1){ testResults[i].average = testResults[i].average / numTrials;}
                }
                break;
              case 3://radixSort_int
              //record array sizes
                  /*
              testResults[i].size=arraySizes[i];

              for(j=0;j<numTrials;j++){
                //create + populate array

               // int * intArray = (int *) malloc (arraySizes[i] * sizeof(int));//[Benjamin] renaming to intArray
               // for(k = 0; k < arraySizes[i]; k++)
               // {
               //     temp = randNum();
               //     intArray[k] = temp;
               // }

                char tempStrArray[arraySizes[numTrials-1]][MAX_LEN];
                strcpy(tempStrArray[j], strArray[j]);
                //define greatest and least index
                highest = arraySizes[i]-1;
                lowest = 0;

                //sort array and get sort time
                start_t = clock();
                radixSort_int(tempStrArray, arraySizes[i]);
                end_t = clock();
                total_t = (long double)(end_t - start_t);

                //store time in appropriate index
                testResults[i].timeTrials[j]=total_t;
                testResults[i].average += total_t;
                if(numTrials-j==1){ testResults[i].average = testResults[i].average / numTrials;}
                }
          */
                break;
              case 4://heapSort_int
              //record array sizes
              testResults[i].size=arraySizes[i];
                  start_t = clock();
                  quickSort_str(tempStrArray, lowest, highest);
                  end_t = clock();
                  total_t = (long double)(end_t - start_t);

                  //store time in appropriate index
                  testResults[i].timeTrials[j]=total_t;
                  testResults[i].average += total_t;
                  if(numTrials-j==1){ testResults[i].average = testResults[i].average / numTrials;}
                  }
                  break;
              case 2://mergeSort_int
              //record array sizes
              testResults[i].size=arraySizes[i];

              for(j=0;j<numTrials;j++){
                //create + populate array
                  /*
                int * intArray = (int *) malloc (arraySizes[i] * sizeof(int));//[Benjamin] renaming to intArray
                for(k = 0; k < arraySizes[i]; k++)
                {
                    temp = randNum();
                    intArray[k] = temp;
                }
                   */
                char tempStrArray[arraySizes[numTrials-1]][MAX_LEN];
                strcpy(tempStrArray[j], strArray[j]);
                //define greatest and least index
                highest = arraySizes[i]-1;
                lowest = 0;

                //sort array and get sort time
                start_t = clock();
                mergeSort_str(tempStrArray, lowest, highest);
                end_t = clock();
                total_t = (long double)(end_t - start_t);

                //store time in appropriate index
                testResults[i].timeTrials[j]=total_t;
                testResults[i].average += total_t;
                if(numTrials-j==1){ testResults[i].average = testResults[i].average / numTrials;}
                }
                break;
              case 3://radixSort_int
              //record array sizes
                  /*
              testResults[i].size=arraySizes[i];

              for(j=0;j<numTrials;j++){
                //create + populate array

               // int * intArray = (int *) malloc (arraySizes[i] * sizeof(int));//[Benjamin] renaming to intArray
               // for(k = 0; k < arraySizes[i]; k++)
               // {
               //     temp = randNum();
               //     intArray[k] = temp;
               // }

                char tempStrArray[arraySizes[numTrials-1]][MAX_LEN];
                strcpy(tempStrArray[j], strArray[j]);
                //define greatest and least index
                highest = arraySizes[i]-1;
                lowest = 0;

                //sort array and get sort time
                start_t = clock();
                radixSort_int(tempStrArray, arraySizes[i]);
                end_t = clock();
                total_t = (long double)(end_t - start_t);

                //store time in appropriate index
                testResults[i].timeTrials[j]=total_t;
                testResults[i].average += total_t;
                if(numTrials-j==1){ testResults[i].average = testResults[i].average / numTrials;}
                }

              for(j=0;j<numTrials;j++){
                //create + populate array
                  /*
                int * intArray = (int *) malloc (arraySizes[i] * sizeof(int));//[Benjamin] renaming to intArray
                for(k = 0; k < arraySizes[i]; k++)
                {
                    temp = randNum();
                    intArray[k] = temp;
                }
                   */
                char tempStrArray[arraySizes[numTrials-1]][MAX_LEN];
                strcpy(tempStrArray[j], strArray[j]);
                //define greatest and least index
                highest = arraySizes[i]-1;
                lowest = 0;

                //sort array and get sort time
                start_t = clock();
                heapSort_str(tempStrArray, arraySizes[i]);
                end_t = clock();
                total_t = (long double)(end_t - start_t);

                //store time in appropriate index
                testResults[i].timeTrials[j]=total_t;
                testResults[i].average += total_t;
                if(numTrials-j==1){ testResults[i].average = testResults[i].average / numTrials;}
                }
                break;
              case 5://insertionSort_int
              //record array sizes
              testResults[i].size=arraySizes[i];

              for(j=0;j<numTrials;j++){
                //create + populate array
                  /*
                int * intArray = (int *) malloc (arraySizes[i] * sizeof(int));//[Benjamin] renaming to intArray
                for(k = 0; k < arraySizes[i]; k++)
                {
                    temp = randNum();
                    intArray[k] = temp;
                }
                   */
                char tempStrArray[arraySizes[numTrials-1]][MAX_LEN];
                strcpy(tempStrArray[j], strArray[j]);
                //define greatest and least index
                highest = arraySizes[i]-1;
                lowest = 0;

                //sort array and get sort time
                start_t = clock();
                insertionSort_str(tempStrArray, arraySizes[i]);
                end_t = clock();
                total_t = (long double)(end_t - start_t);

                //store time in appropriate index
                testResults[i].timeTrials[j]=total_t;
                testResults[i].average += total_t;
                if(numTrials-j==1){ testResults[i].average = testResults[i].average / numTrials;}
                }
                break;
              case 6://selectionSort_int
              //record array sizes
              testResults[i].size=arraySizes[i];

              for(j=0;j<numTrials;j++){
                //create + populate array
                  /*
                int * intArray = (int *) malloc (arraySizes[i] * sizeof(int));//[Benjamin] renaming to intArray
                for(k = 0; k < arraySizes[i]; k++)
                {
                    temp = randNum();
                    intArray[k] = temp;
                }
                   */
                char tempStrArray[arraySizes[numTrials-1]][MAX_LEN];
                strcpy(tempStrArray[j], strArray[j]);
                //define greatest and least index
                highest = arraySizes[i]-1;
                lowest = 0;

                //sort array and get sort time
                start_t = clock();
                selectionSort_str(tempStrArray, arraySizes[i]);
                end_t = clock();
                total_t = (long double)(end_t - start_t);

                //store time in appropriate index
                testResults[i].timeTrials[j]=total_t;
                testResults[i].average += total_t;
                if(numTrials-j==1){ testResults[i].average = testResults[i].average / numTrials;}
                }
                break;
              case 7://perform all sorts at once
              //     start_t = clock();
              // randNum    quickSort_int(intArray, lowest, highest);
              //     end_t = clock();
              //     total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
              //     masterQuick->intTrials->trial1;
              //
              //     start_t = clock();
              //     mergeSort_int(intArray, lowest, highest);
              //     end_t = clock();
              //     total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
              //     masterMerge->intTrials->trial1;
              //
              //     start_t = clock();
              //     radixSort_int(intArray, arraySizes[i]);
              //     end_t = clock();
              //     total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
              //     masterRadix->intTrials->trial1;
              //
              //     start_t = clock();
              //     heapSort_int(intArray, arraySizes[i]);
              //     end_t = clock();
              //     total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
              //     masterHeap->intTrials->trial1;
              //
              //     start_t = clock();
              //     insertionSort_int(intArray, arraySizes[i]);
              //     end_t = clock();
              //     total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
              //     masterInsertion->intTrials->trial1;
              //
              //     start_t = clock();
              //     selectionSort_int(intArray, arraySizes[i]);
              //     end_t = clock();
              //     total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
              //     masterSelection->intTrials->trial1;
                  break;
          }
          free(strArray);


    }

    free(arraySizes);

    /*
<<<<<<< HEAD
  [Benjamin]-EXTRA CREDIT (low priority?)
=======

  -EXTRA CREDIT (low priority?)
>>>>>>> 12f3c2e294efb76e56e3a8bfb131d91cd69e37af
      processCMDArgs will reject array sizes larger than 75000.
      If you want to do the extra credit, modify processCMDArgs
      to accept the larger array sizes.
      For sorting strings:
        Create the array for strings like this:
          char array[arraySizes[numExperiments-1]][MAX_LEN];
        This will create an array that can hold the largest
        number of inputs.  Using this larger array to process
        smaller number of inputs will be ok.
        **Declare the string array ONCE at the top of your
          function then reuse it.  DO NOT declare a string
          array for each array size.**
        You do not need to free this type of variable.
        radixSort on strings will not work with this type of variable.
        radixSort on strings is for extra credit.
      For sorting integers:
        Create the array for ints like this:
          int * array = (int *) malloc (arraySizes[i] * sizeof(int));
        You can create the array, fill it, sort it, then free it
        for each array size.  REMEMBER to free it!
        Use randNum() to get each random number for the integer arrays.
      Google 'c clock' to find out how to time your sorting functions.
      */
      //Use this timeing scheme
      // clock_t startTime = clock();
      // clock_t endTime = clock();
      // clock_t totalTime = startTime - endTime;
      /*
      If quick sort and other faster sorts report a time of 0.0, that is ok.
      Report 0.0 if that is the result.  Longer arrays and other sorts should
      produce a visible time.
      Create a data structure to store the results of all your experiments,
      then print out everything at once.
      To run your program in the background:
        $ nohup ./project # # # # # > output.txt &
      When running in the background and you haven't logged out of the server,
      to see your currently running programs type:
        $ jobs
      If you have logged out, type:
        $ ps aux | grep 'abc123'
      If you want to kill the ./project process:
        $ kill 'process id number'
      Server Info
      DO NOT use the fox servers for this assignment
      in the lab $ ssh abc123@hen01.cs.utsarr.net
      outside    $ ssh abc123@10.100.240.211
      Email Josh if you crash the server.
    */

//Print results as 2d array
    switch(sortAlg)
    {
      case 1:
        printf("quickSort\n");
        break;
      case 2:
        printf("mergeSort\n");
        break;
      case 3:
        printf("radixSort\n");
        break;
      case 4:
        printf("heapSort\n");
        break;
      case 5:
        printf("insertionSort\n");
        break;
      case 6:
        printf("selectionSort\n");
        break;
    }
    for(i=0; i<numTrialNodes; i++){
      printf("size: %d,    average: %Le, ", testResults[i].size, testResults[i].average / CLOCKS_PER_SEC);
      for(j=0;j<numTrials;j++){
        printf("%Le, ", testResults[i].timeTrials[j] / CLOCKS_PER_SEC);
      }
      printf("\n");
    }

//free masterNode and trialNodes
    for(i=0;i<numTrialNodes;i++){
      //free dynamic array, set ptr to NULL
      free(testResults[i].timeTrials);
      testResults[i].timeTrials = NULL;
      // //free trialNode set to NULL
      // free(testResults[i]);
      // testResults[i]=NULL;
    }
    free(testResults);
    testResults=NULL;

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

		if (temp == 0 || temp < 1000 || temp > 500000000) {
			printf("CMD Usage: ./project {printType} {sortType} {sortAlg} {numTrials} {arraySizes...arraySizes}\n");
			printf("                                                                  {   1000 < n < 75000    }\n");
			free(arraySizes);
			exit(0);
		}

		arraySizes[i-5] = temp;
	}
}
