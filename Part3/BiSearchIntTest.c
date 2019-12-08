#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#include"Searches.h"
//#include "projectHeader.h"
#include "QuickSort.h"

// program will create read first 10 names file to stringList
// funtions will be implemented iterativly
// one word will be processed at a time

//reads from filePointer fp until reaches '\n' or '\0' character, or size of buffer is reached.
//returns size of word stored in buffer
//if a line in a file is longer than bufferSize-1 line will be returned as multiple words
int readFileLine(FILE *fp, char *buffer, int bufferSize)
{
  int i;
  char temp;
  for(i=0;i<bufferSize-1;++i){
    temp = fgetc(fp);
    while(temp == '\r'){temp=fgetc(fp);}
    if(temp=='\0' || temp=='\n'){
      break;
    }
    buffer[i]=temp;
  }
  buffer[i]='\0';
  return ++i;
}

int main(){
  //interator variable
  int i, target, k, temp;

  //alocate space for wordArray
  int * intArray = (int *) malloc (10 * sizeof(int));
  for(k = 0; k < 10; k++)
  {
      temp = rand();
      intArray[k] = temp;
  }

//print contents of string arrays
  for(i=0;i<10;++i){
    printf("%d\n", intArray[i]);
  }

//get desired name from terminal
  printf("Enter number to search.\n");
  scanf("%d", &target);

  printf("Number selected: %d\n", target);

//sort wordArray
  // quickSort_int(wordArray, 0, 9);
  quickIntSort(intArray, 0, 9);


//search for target
int found = biIntArraySearch(intArray, 10, target);
// int found = linStringArraySearch(wordArray, 10, target);

if(found!=-1){
  printf("Found %d, at index %d\n", intArray[found], found);
} else {
  printf("%d not found.\n", target);
}

//print sorted array
for(i=0;i<10;++i){
  printf("%d\n", intArray[i]);
}


  free(intArray); //free wordArray pointer itself
  intArray=NULL;

  return 0;
}
