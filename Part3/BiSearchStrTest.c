#include<stdlib.h>
#include<stdio.h>

#include"Searches.h"
#include "projectHeader.h"


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
  int i, j, wordSize;

  char *target;

  //alocate space for wordArray
  char **wordArray=(char **)malloc(sizeof(char*)*10);
  //create, open file pointer
  FILE *fp = fopen("last_name.txt", "r");
  //create a buffer to read words from file to
  char charBuffer[100];

  //for each slot in wordArray
  for(i=0;i<10;++i){
    //read word from file to bufferClear
    //get word size
    wordSize = readFileLine(fp, charBuffer, 100);

    //point temp to block of memory equal to size of words
    wordArray[i] = (char *)malloc(sizeof(char)*wordSize);

    //copy values from charBuffer to wordArray;
    for(j=0;j<wordSize;++j){
      wordArray[i][j] = charBuffer[j];
    }
  }

//print contents of string arrays
  for(i=0;i<10;++i){
    printf("%s\n", wordArray[i]);
  }

//get desired name from terminal
  printf("Enter name to search.\n");
  scanf("%s", target);

  printf("Name selected: %s\n", target);

//sort wordArray
  // quickSort_str(wordArray, 0, 9);


//search for target
//int found = biStringArraySearch(wordArray, 10, target);
int found = linStringArraySearch(wordArray, 10, target);

if(found!=-1){
  printf("Found %s, at index %d\n", wordArray[found], found);
} else {
  printf("%s not found.\n", target);
}


//free wordArray Memeory
  for(i=0;i<10;++i){
    free(wordArray[i]); //Free each word in wordArray
    wordArray[i]=NULL;
  }
  free(wordArray); //free wordArray pointer itself
  wordArray=NULL;

  return 0;
}
