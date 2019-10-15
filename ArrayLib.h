#ifndef ARRAYLIB_H
#define ARRAYLIB_H

//functions that are to be used multiple times in diferant algorithms

/*INTEGER FUNTIONS*/

  //returns 1 if successfull, if fails return 0
  int insertIntElement(int **myArray, int targetIndex, int numElements, int newElement);
  //inserts newElement at targetIndex of myArray, increments positions of all element at higher indexes
  //numElements is the number of elements in the array initially

  //returns 1 if successfull, 0 if failure.
  int removeIntElement(int **myArray, int targetIndex, int numElements);
  //removes element at targetIndex of myArray, deincrements positions of all ele at higher indexes
  //funtion will live a duplicate of the last element in the array at &myArray[numElements]
  //numElements is the number of elements in the array initially

  //returns 1 if successfull, 0 if failure
  int swapIntElement(int **myArray, int firstIndex, int secondIndex);
  //switches the elements at firstIndex and secondIndex in myArray

/*STRING FUNCTIONS*/

  //returns 1 if successfull, 0 if failure.
  int insertStringElement(char ***myArray, int targetIndex, int numElements, char *newElement);
  //inserts newElement at targetIndex of myArray, increments positions of all element at higher indexes
  //numElements is the number of elements in the array initially

  //returns 1 if successfull, 0 if failure.
  int removeStringElement(char ***myArray, int targetIndex, int numElements);
  //removes element at targetIndex of myArray if targetIndex < numElements
  //funtion will live a duplicate of the last element in the array at &myArray[numElements]
  //numElements is the number of elements in the array initially

  //returns 1 if successfull, 0 if failure
  int swapStringElement(char ***myArray, int firstIndex, int secondIndex);
  //switches the elements at firstIndex and secondIndex in myArray






#endif
