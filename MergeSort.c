#include<stdlib.h>
#include<string.h>


void mergeInt(int arr[],int low, int mid, int high)
{
  int sizeLeft=mid-low+1; //calculate size of left and right subArrays
  int sizeRight=high-mid;

  //Allocate memory for left subarray
  int *subLeft = malloc(sizeof(int)*sizeLeft);

  //Allocate memory for right subarray
  int *subRight = malloc(sizeof(int)*sizeRight);

  //copy elements from arr to Left
  int i;
  for(i=0;i<sizeLeft;++i){
    subLeft[i] = arr[low+i];
  }

  //copy elements from arr to Right
  for(i=0;i<sizeRight;++i){
    subRight[i]=arr[low+i];
  }

  i = 0;
  int k = low, j = 0;
  //while both Left and Right are < sizeLeft and sizeRight, respectivly
  while(){

  }
  //copy into arr starting from arr[low]

  //check if Left[i] < Right[j]
    //copy left to arr if true
    //increment k, i
  //else
    //copy right to arr
    //increment k, j
  //while i less than sizeLeft
    //copy left to arr
    //increment k, i
  //while i less than sizeLeft
    //copy left to arr
    //increment k, i
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




void mergeChar(char* arr[],int low,int mid,int high) //Merging the Array Function
{
    int nL= mid-low+1;
    int nR= high-mid;

    char** L=malloc(sizeof(char *)*nL);
    char** R=malloc(sizeof(char *)*nR);
    int i;
    for(i=0;i<nL;i++)
    {
        L[i]=malloc(sizeof(arr[low+i]));
        strcpy(L[i],arr[low+i]);
    }
    for(i=0;i<nR;i++)
    {
        R[i]=malloc(sizeof(arr[mid+i+1]));
        strcpy(R[i],arr[mid+i+1]);
    }
    int j=0,k;
    i=0;
    k=low;
    while(i<nL&&j<nR)
    {
        if(strcmp(L[i],R[j])<0)strcpy(arr[k++],L[i++]);
        else strcpy(arr[k++],R[j++]);
    }
    while(i<nL)strcpy(arr[k++],L[i++]);
    while(j<nR)strcpy(arr[k++],R[j++]);

}


void mergeCharSort(char* arr[],int low,int high) //Main MergeSort function
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeCharSort(arr,low,mid);
        mergeCharSort(arr,mid+1,high);
        mergeChar(arr,low,mid,high);
    }
}
