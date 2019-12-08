#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include "Searches.h"

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
  for(i=0;i<argc;++i){
      temp=atoi(argv[i]);
      if(temp<minArraySize || temp > maxArraySize){
        printf("ERROR! Vallid array size is between %d and %d.\n", minArraySize, maxArraySize);
        free(arraySizes);
        exit(EXIT_SUCCESS);
      }
      arraySizes[i]=temp;
  }
}

int main(int argc, char *argv[])
{
  int exit = 1; //exit variable set to 1(=false)
  processCommands(argc, argv);

  // Create menu for diferant searching algorithms
  while(exit = 1;)//main menue loop
  {

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
