#include<stdlib.h>
#include<string.h>
#include<stdio.h>


void mergeInt(int arr[],int low, int mid, int high)
{
  int sizeLeft=mid-low+1; //calculate size of left and right subArrays
  int sizeRight=high-mid;

  //Allocate memory for left subarray
  int subLeft[sizeLeft];

  //Allocate memory for right subarray
  int subRight[sizeRight];

  //copy elements from arr to Left
  int i;
  for(i=0;i<sizeLeft;++i){
    subLeft[i] = arr[low+i];
  }

  //copy elements from arr to Right
  for(i=0;i<sizeRight;++i){
    subRight[i]=arr[mid+i+1];
  }

  i = 0;
  //copy into arr starting from arr[low]
  int k = low, j = 0;
  //while both Left and Right are < sizeLeft and sizeRight, respectivly
  while(i<sizeLeft&&j<sizeRight){
    if(subLeft[i]<subRight[j]){  //check if Left[i] < Right[j]
      //copy left to arr if true
      //increment k, i
      arr[k++]=subLeft[i++];
    }
    else{
      //copy right to arr
      //increment k, j
      arr[k++]=subRight[j++];
    }
  }
  //while i less than sizeLeft
  while(i<sizeLeft){
    //copy left to arr
    //increment k, i
    arr[k++]=subLeft[i++];
  }
  //while j less than sizeRight
    //copy left to arr
    //increment k, i
  while(j<sizeRight){
      arr[k++]=subRight[j++];
  }
  // free(subLeft);
  // free(subRight);
}
void mergeIntSort(int arr[],int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeIntSort(arr,low,mid);
        mergeIntSort(arr,mid+1,high);
        mergeInt(arr,low,mid,high);
    }
}




void mergeStr(char* arr[],int low,int mid,int high) //Merging the Array Function
{
    int nL= mid-low+1;
    int nR= high-mid;

    char** L=malloc(sizeof(char *)*nL);
    char** R=malloc(sizeof(char *)*nR);
    int i;
    for(i=0;i<nL;i++)
    {
      // L[i]=malloc(sizeof(arr[low+i]));
      // strcpy(L[i],arr[low+i]);
      L[i] = arr[low+i];
    }
    for(i=0;i<nR;i++)
    {
      //  R[i]=malloc(sizeof(arr[mid+i+1]));
        //strcpy(R[i],arr[mid+i+1]);
        R[i] = arr[mid+i+1];
    }
    int j=0,k;
    i=0;
    k=low;
    while(i<nL&&j<nR)
    {
        if(strcmp(L[i],R[j])<0){
  //        strcpy(arr[k++],L[i++]);
          arr[k++] = L[i++];
        }
        else {
          //strcpy(arr[k++],R[j++]);
          arr[k++]=R[j++];
        }
    }
    while(i<nL){
      //strcpy(arr[k++],L[i++]);
      arr[k++]=L[i++];
    }
    while(j<nR){
      //strcpy(arr[k++],R[j++]);
      arr[k++] = R[j++];
    }
}


void mergeStrSort(char* arr[],int low,int high) //Main MergeSort function
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeStrSort(arr,low,mid);
        mergeStrSort(arr,mid+1,high);
        mergeStr(arr,low,mid,high);
    }
}

/*
int main()
{
    int i;
    int intArr[] = {12, 11, 13, 5, 6, 7};
    int intArrLen = sizeof(intArr)/sizeof(intArr[0]);
    mergeIntSort(intArr, 0, intArrLen-1);
    printf("Sorted array is: \n");
    for(i = 0; i < intArrLen; i++)
    {
        printf("%d ", intArr[i]);
    }
    printf("\n");

    char *strArr[] = {"AAAAA", "a", "AAA", "aaaa", "AAa", "AAAAa", "AAa", "A", "aa", "Aaa"};
    int strArrLen = sizeof(strArr)/sizeof(strArr[0]);
    mergeStrSort(strArr, 0, strArrLen-1);
    printf("Sorted array is: \n");
    for(i = 0; i < strArrLen; i++)
    {
        printf("%s ", strArr[i]);
    }
}
*/
