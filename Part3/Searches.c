#include<string.h>
#include<stdio.h>
//#include "ArrayLib.h"

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
int linStringArraySearch(char **myArray, int sizeOfArray, char *soughtElement){
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
    while(start<=end){
      mid = (end+start)/2;
      if(myArray[mid]==soughtElement){
        return mid;
      } else if(myArray[mid]>soughtElement){
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
    while(start<=end){
      mid = (end+start)/2;
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

// int main()
// {
//     int i;
//     int intArr[] = {1, 2, 3 , 4 , 5, 6, 7, 8, 9};
//     int intArrLen = sizeof(intArr)/sizeof(intArr[0]);
//     int target;
//     printf("Enter target integer: ");
//     scanf("%d", &target);
//
//     int found = biIntArraySearch(intArr, intArrLen, target);
//
//     if(found>=0){printf("Found %d at %d\n", target, found);}
//     for(i = 0; i < intArrLen; i++)
//     {
//         printf("%d ", intArr[i]);
//     }
//     printf("\n");
//
//     char *strArr[] = {"A","B","CC","DDD","EEEE"};
//     int strArrLen = sizeof(strArr)/sizeof(strArr[0]);
//
//    //  char strTarget[20];
//    //  // char *strTarget;
//    //  printf("Enter target string: ");
//    //
//    //  int len=0;
//    // char bufferClear;
//    // scanf("%c", &bufferClear);
//    //  fgets(strTarget, 20, stdin); //get name from stdin
//    //  for(i=0; i<20; ++i){  //removes trailing '\n' from name
//    //    if(strTarget[i]=='\n'){
//    //      strTarget[i]='\0';
//    //      break;
//    //    } else{
//    //      len++;
//    //    }
//    //  }
//    //  char strVal[len];
//    //  for(i=0;i<len; ++i){
//    //    strVal[i]=strTarget[i];
//    //  }
//    //
//     // scanf("%*c");
//     // scanf("%s", strTarget);
//     char *strVal="DDD";
//     found = biStringArraySearch(strArr, strArrLen, strVal);
//
//     if(found>=0){printf("Found %s at %d\n", strVal, found);}
//
//     for(i = 0; i < strArrLen; i++)
//     {
//         printf("%s ", strArr[i]);
//     }
// }
