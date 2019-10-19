#include<string.h>

#include "ArrayLib.h"

//returns index of found element or '-1' if fails
int linIntArraySearch(int* myArray, int sizeOfArray, int soughtElement){
  int i;
  for(i = 0; i<sizeOfArray; ++i){
    if(myArray[i]==soughtElement){
      return i;
    }
  }
  return -1;
}

//returns index of found element or '-1' if fails
int linStringAraySearch(char **myArray, int sizeOfArray, char *soughtElement){
  int i;
  for(i = 0; i<sizeOfArray; ++i){
    if(strcmp(myArray[i], soughtElement)==0){ //strcmp will return 0 iff strings are equal
      return i;
    }
  }
  return -1;
}

//returns index of found element or '-1' if fails
int biIntArraySearch(int* myArray, int sizeOfArray, int soughtElement){
    int mid;                  //midpoint between start and end
    int start=0;              //search range starts at first index of array
    int end = sizeOfArray-1;  //search range begins at the last index of array
    while(start<end){
      mid = (end-start)/2 + start;
      if(myArray[mid]==soughtElement){
        return mid;
      } else if(myArray[mid]<soughtElement){
        end = mid-1;
      } else{
        start = mid+1;
      }
    }
    return -1;
}

//returns index of found element or '-1' if fails
int biStringArraySearch(char **myArray, int sizeOfArray, char *soughtElement){
    int mid;                  //midpoint between start and end
    int start=0;              //search range starts at first index of array
    int end = sizeOfArray-1;  //search range begins at the last index of array
    while(start<end){
      mid = (end-start)/2 + start;
      if(strcmp(myArray[mid], soughtElement) == 0){
        return mid;
      } else if(strcmp(myArray[mid], soughtElement)<0){
        end = mid-1;
      } else{
        start = mid+1;
      }
    }
    return -1;
}
