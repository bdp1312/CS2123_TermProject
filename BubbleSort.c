#include <string.h>

#include "ArrayLib.h"


void bubbleIntSort(int *myArray, int numElements) //sorts myArray using bubble sort algorithm
  //myArray: collection to be sorted, numElements:Number of elements in myArray
{
  int i;
  int sorted; //Set to 1 if sorted, 0 if unsorted
  do{
    for(i=0; i<numElements-1; ++i){
      sorted = 1;
      if(myArray[i]>myArray[i+1]){
        sorted = 0;
        swapIntElement(myArray, i, i+1);
      }
    }
  } while(sorted == 0);
}


void bubbleStringSort(char **myArray, int numElements) //sorts string array using bubble sort algorithm
  //myArray: collection to be sorted, numElements:Number of elements in myArray
{
  int i;
  int sorted; //Set to 1 if sorted, 0 if unsorted
  do{
    for(i=0; i<numElements-1; ++i){
      sorted = 1;
      if(strcmp(myArray[i], myArray[i+1]) < 0){ //check if myArray[i] has a greater char val
        sorted = 0;
        swapStringElement(myArray, i, i+1);
      }
    }
  } while(sorted == 0);
}
