//Library For Array Functions common to multiple Sort/Merdge algorithms

#include"ArrayLib.h"

//returns 1 for true, 0 for false
int isValidIndex(int targetIndex, int workingLength){
  //helper funtion, checks if targetIndex is less than relevent array length
  if(workingLength > targetIndex){return 1;}
  return 0;
}
//isValidIndex() curantly unused

int insertIntElement(int * myArray, int targetIndex, int numElements, int newElement){
  // if(isValidIndex(targetIndex, numElements)==0){
  //   return 0;
  // }else{
    myArray[numElements] = newElement;
    int i;
    for(i=numElements;i>targetIndex; --i){
      swapIntElement(myArray, i, i-1);
    }
  // }
  return 1;
}


int removeIntElement(int *myArray, int targetIndex, int numElements){
  int i;
    for(i=numElements-1; i>targetIndex;--i){
      swapIntElement(myArray, i, i-1);
    }
  return 1;
}


int swapIntElement(int *myArray, int firstIndex, int secondIndex){
  // if(isValidIndex(firstIndex, numElements)==0 || isValidIndex(secondIndex, numElements) == 0){
  //   return 0; //returns failure if array length isn't greather than both indexes
  // } else {    //else swap the values
    int tempVal = myArray[firstIndex];
    myArray[firstIndex] = myArray[secondIndex];
    myArray[secondIndex] = tempVal;
//  }
  return 1;
}



int insertStringElement(char **myArray, int targetIndex, int numElements, char *newElement){
  return 1;
}


int removeStringElement(char **myArray, int targetIndex, int numElements){
  return 1;
}


int swapStringElement(char **myArray, int firstIndex, int secondIndex){
  return 1;
}
