#include<string.h>

#include "ArrayLib.h"

//returns index of found element or '-1' if fails
int linIntArraySearch(**int myArray, int sizeOfArray, int soughtElement){
  int i;
  for(i = 0; i<sizeOfArray; ++i){
    if(*myArray[i]==soughtElement){
      return i;
    }
  }
  return -1;
}

//returns index of found element or '-1' if fails
int linStringAraySearch(***char myArray, int sizeOfArray, char *soughtElement);

//returns index of found element or '-1' if fails
int biIntArraySearch(**int myArray, int sizeOfArray, int soughtElement){
  
}

//returns index of found element or '-1' if fails
int biStringArraySearch(***char myArray, int sizeOfArray, char *soughtElement);
