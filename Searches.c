#include "ArrayLib.h"


int linIntArraySearch(**int myArray, int sizeOfArray, int soughtElement){
  int i;
  for(i = 0; i<sizeOfArray; ++i){
    if(*myArray[i]==soughtElement){
      return i;
    }
  }
  return -1;
}


int linStringAraySearch(***char myArray, int sizeOfArray, char *soughtElement);


int biIntArraySearch(**int myArray, int sizeOfArray, int soughtElement);


int biStringArraySearch(***char myArray, int sizeOfArray, char *soughtElement);
