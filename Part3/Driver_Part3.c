#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <ctype.h>

#include"Searches.h"
#include "QuickSort.h"



//#include "Searches.h"

//helper functions to run sorts and get times
int minArraySize = 1000;
int maxArraySize = 75000;
int *arraySizes;
int numArraySizes;
int dataMode;// set to 0 for int,

//reads from filePointer nfp until reaches '\n' or '\0' character, or size of buffer is reached.
//returns size of word stored in buffer
//if a line in a file is longer than bufferSize-1 line will be returned as multiple words
int readFileLine(FILE *nfp, char *buffer, int bufferSize)
{

  int i, j, wordSize;
  char *charTarget; //
  char temp;
  for(i=0;i<bufferSize-1;++i){
    temp = fgetc(nfp);
    while(temp == '\r'){temp=fgetc(nfp);}
    if(temp=='\0' || temp=='\n'){
      break;
    }
    buffer[i]=temp;
  }
  buffer[i]='\0';
  return ++i;
}

//takes arguments for list of array sizes from terminal,
//formats them as array[int], uses existing pointer arraySizes
void processCommands(int argc, char *argv[])
{
  int i, temp;
  numArraySizes = argc-1;
  arraySizes = malloc(sizeof(int)*numArraySizes);
  for(i=0;i<argc;++i){
      temp=atoi(argv[i]);
      if(temp<minArraySize || temp > maxArraySize){
        printf("ERROR! Valid array size is between %d and %d.\n", minArraySize, maxArraySize);
        free(arraySizes);
        exit(EXIT_SUCCESS);
      }
      arraySizes[i]=temp;
  }
}

// void getTimes(int arraySize, char dataType, char searchType){}



/*MAIN STARTS HERE*/

int main(int argc, char *argv[])
{
  clock_t start_t, end_t;
  long double run_t, total_t;
  int i, j, wordSize, targetLocation, intTarget, temp;
  int exit = 1; //exit variable set to 1(=false)
  char dataType, searchType;
  char charTarget[30];
  int arraySize;
  //allocate wordArray pointer, set to NULL
  char **wordArray=NULL;
  //allocate intArray pointer, set to NULL
  int *intArray = NULL;
  //create a buffer to read words from file to
  char charBuffer[100];
  //create name file pointer nfp
  FILE * nfp;
  FILE * ofp; //create output file pointer

  //open Output file
  ofp = fopen("output.txt", "w");

  //processCommands(argc, argv);
  // Create menu for diferant searching algorithms
  while(exit == 1)//main menue loop
  {
      printf("Enter array size between %d and %d\n", minArraySize, maxArraySize);
      scanf("%d", &arraySize);
      if(minArraySize > arraySize || arraySize > maxArraySize)
      {
          printf("Invalid array size\n");
          break;
      }

      printf("Enter desired data type: 'I' for int or 'C' char\n");
      scanf("%*c");
      scanf("%c", &dataType);

      if(toupper(dataType) == 'I')
      {
          if(intArray == NULL)
          {
              intArray = (int *) malloc (arraySize * sizeof(int));
              for(j = 0; j < arraySize; j++)
              {
                  temp = rand();
                  intArray[j] = temp;
              }
          }

          printf("Enter number to search for: \n");
          scanf("%*c");
          scanf("%d", &intTarget);

          fprintf(ofp, "Number entered: %d\n", intTarget);
          
          printf("Enter search type: 'L' for linear or 'B' for binary\n");
          scanf("%*c");
          scanf("%c", &searchType);

          if(toupper(searchType) == 'L')
          {
            fprintf(ofp,"Linear Int Search, Array size: %d\n", arraySize);

            total_t=0;
            for(i=0; i<5; ++i){
              start_t = clock();
              targetLocation = linIntArraySearch(intArray, arraySize, intTarget);
              end_t = clock();
              run_t = (long double)(end_t - start_t);
              total_t+=run_t;
              fprintf(ofp, "Time %d: %Le s, ", i+1, run_t / CLOCKS_PER_SEC);
           }
           fprintf(ofp,"\nAverage: %Le s\n", total_t / 5 / CLOCKS_PER_SEC);
           if(targetLocation!=-1){
             fprintf(ofp, "Found %d, at index %d\n\n", intArray[targetLocation], targetLocation);
           } else {
             fprintf(ofp, "%d not found.\n\n", intTarget);
           }
          }
          else if(toupper(searchType) == 'B')
          {
            fprintf(ofp,"Bianary Int Search, Array size: %d\n", arraySize);

            total_t=0;
            for(i=0; i<5; ++i){
              start_t = clock();
              targetLocation = biIntArraySearch(intArray, arraySize, intTarget);
              end_t = clock();
              run_t = (long double)(end_t - start_t);
              total_t+=run_t;
              fprintf(ofp, "Time %d: %Le s, ", i+1, run_t / CLOCKS_PER_SEC);
           }
           fprintf(ofp,"\nAverage: %Le s\n", total_t / 5 / CLOCKS_PER_SEC);
           if(targetLocation!=-1){
             fprintf(ofp, "Found %d, at index %d\n\n", intArray[targetLocation], targetLocation);
           } else {
             fprintf(ofp, "%d not found.\n\n", intTarget);
           }
          }
          else
          {
              printf("Invalid search type\n");
              break;
          }
      }
      else if(toupper(dataType) == 'C')
      {
        /*create array of char* of length maxArraySize,
        populate with first maxArraySize names from file.*/
        //do this only if wordArray hasn't been created.
        if(wordArray == NULL){

          //alocate space for wordArray
          wordArray=(char **)malloc(sizeof(char*)*maxArraySize);
          //create, open file pointer
          nfp = fopen("last_name.txt", "r");


          //for each slot in wordArray
          for(i=0;i<maxArraySize;++i){
            //read word from file to bufferClear
            //get word size
            wordSize = readFileLine(nfp, charBuffer, 100);

            //point temp to block of memory equal to size of words
            wordArray[i] = (char *)malloc(sizeof(char)*maxArraySize);

            //copy values from charBuffer to wordArray;
            for(j=0;j<wordSize;++j){
              wordArray[i][j] = charBuffer[j];
            }
          }
          //close file
          fclose(nfp);
          //sort wordArray
          quickStrSort(wordArray, 0, maxArraySize-1);

        }



        //prompt user for search charTarget
        //get desired name from terminal
          printf("Enter name to search.\n");
          scanf("%*c");
          scanf("%s", charTarget);

          fprintf(ofp, "Name selected: %s\n", charTarget);


          printf("Enter search type: 'L' for linear or 'B' for binary\n");
          scanf("%*c");
          scanf("%c", &searchType);
          if(toupper(searchType) == 'L')
          {
            fprintf(ofp,"Linear String Search, Array size: %d\n", arraySize);
            //Run linear sort get times
            //search for charTarget
            //targetLocation = biStringArraySearch(wordArray, 10, charTarget);
            total_t=0;
            for(i=0; i<5; ++i){
              start_t = clock();
              targetLocation = linStringArraySearch(wordArray, arraySize, charTarget);
              end_t = clock();
              run_t = (long double)(end_t - start_t);
              total_t+=run_t;
              fprintf(ofp, "Time %d: %Le s, ", i+1, run_t / CLOCKS_PER_SEC);
           }
           fprintf(ofp,"\nAverage: %Le s\n", total_t / 5 / CLOCKS_PER_SEC);

            if(targetLocation!=-1){
              fprintf(ofp, "Found %s, at index %d\n\n", wordArray[targetLocation], targetLocation);
            } else {
              fprintf(ofp, "%s not found.\n\n", charTarget);
            }

          }
          else if(toupper(searchType) == 'B')
          {
            fprintf(ofp,"Bianary String Search, Array size: %d\n", arraySize);
            //Run Bianary sort, get times
            total_t=0;
            for(i=0; i<5; ++i){
              start_t = clock();

              //search for charTarget
              targetLocation = biStringArraySearch(wordArray, arraySize, charTarget);
              // int targetLocation = linStringArraySearch(wordArray, 10, charTarget);

              end_t = clock();
              run_t = (long double)(end_t - start_t);
              total_t+=run_t;
              fprintf(ofp, "Time %d: %Le s, ", i+1, run_t / CLOCKS_PER_SEC);
            }
            fprintf(ofp,"\nAverage: %Le s\n", total_t / 5 / CLOCKS_PER_SEC);

            if(targetLocation!=-1){
              fprintf(ofp, "Found %s, at index %d\n\n", wordArray[targetLocation], targetLocation);
            } else {
              fprintf(ofp, "%s not found.\n\n", charTarget);
            }


          }
          else
          {
              printf("Invalid search type\n");
              break;
          }

      }
      else
      {
          printf("Invalid data type\n");
          break;
      }

      printf("Would you like to exit(0) or continue(1)\n");
      scanf("%d", &exit);
      if(exit != 1 && exit != 0)
      {
          printf("Invalid input... exiting anyway\n");
          break;
      }
  }


  //
  // INTS
  //
  // Make dynamic array[int], randomly picked


  //
  // perform selected searching algorthm three times on three random arrays
  // 	write to same array three times, compute avg.
  // 	free array after all searches are performed
  //
  // analize times and the algoritms by big O notation
  // recomend a searching algorithm
  //
  // STRINGS
  //
  // use file from pt 2
  //
  // add option for string in menu
  //
  // search for provided name
  //
  // repeat at five times compute avg
  // 	five searches on the same sorted array for same word
  //
  // analize times and the algorithm's big o notation
  //
  // recomend which searching algorithm

//close output file

//free wordArray Memeory if it has been opened
  if(wordArray!=NULL){
    for(i=0;i<arraySize;++i){
      free(wordArray[i]); //Free each word in wordArray
      wordArray[i]=NULL;
    }
    free(wordArray); //free wordArray pointer itself
    wordArray=NULL;
  }


//free wordArray Memeory if it has been opened
  if(wordArray!=NULL){
    for(i=0;i<arraySize;++i){
      free(wordArray[i]); //Free each word in wordArray
      wordArray[i]=NULL;
    }
    free(wordArray); //free wordArray pointer itself
    wordArray=NULL;
  }


  return 0;
}
