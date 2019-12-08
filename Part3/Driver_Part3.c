
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <ctype.h>


#include "Searches.h"
#include "QuickSort.h"

//helper functions to run sorts and get times
int minArraySize = 1000;
int maxArraySize = 500000;
int *arraySizes;
int numArraySizes;
int dataMode;// set to 0 for int,

void processCommands(int argc, char *argv[])
{
  int i, temp;
  numArraySizes = argc-1;
  arraySizes = malloc(sizeof(int)*numArraySizes);
  for(i=1;i<argc;++i){
      temp=atoi(argv[i]);
      if(temp<minArraySize || temp > maxArraySize){
        printf("ERROR! Vallid array size is between %d and %d.\n Run as '/.Project.exe size1, size2, ... sizeN'.\n", minArraySize, maxArraySize);
        free(arraySizes);
        exit(EXIT_SUCCESS);
      }
      arraySizes[i-1]=temp;
  }
}

int main(int argc, char *argv[])
{
  int exit = 1; //exit variable set to 1(=false)
  char dataType;
  char searchType;
  int arraySize;
  //processCommands(argc, argv);
  // Create menu for diferant searching algorithms
  while(exit == 1)//main menue loop
  {

      printf("Enter array size between %d and %d\n", minArraySize, maxArraySize);
      scanf("%d\n", &arraySize);
      if(!(minArraySize <= arraySize || arraySize <= maxArraySize))
      {
          printf("Invalid array size\n");
          break;
      }

      printf("Enter desired data type: 'I' for int or 'C' char\n");
      scanf("%*c");
      scanf("%c", &dataType);

      if(toupper(dataType) == 'I')
      {
          printf("Enter search type: 'L' for linear or 'B' for binary\n");
          scanf("%*c");
          scanf("%c", &searchType);
          if(toupper(searchType) == 'L')
          {
            printf("Running Linear Int Search\n");
          }
          else if(toupper(searchType) == 'B')
          {
            printf("Running Bianary Int Search\n");
          }
          else
          {
              printf("Invalid search type\n");
              break;
          }
      }
      else if(toupper(dataType) == 'C')
      {
          printf("Enter search type: 'L' for linear or 'B' for binary");
          scanf("%*c");
          scanf("%c", &searchType);
          if(toupper(searchType) == 'L')
          {
            printf("Running Linear String Search\n");
          }
          else if(toupper(searchType) == 'B')
          {
            printf("Running Bianary string Search\n");
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


  return 0;
}
