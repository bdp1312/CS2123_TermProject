#include<stdlib.h>
#include<string.h>


void mergeInt(int arr[],int low, int mid, int high)
{
  int sizeLeft; //calculate size of left and right subArrays
  int sizeRight;

  //Allocate memory for left subarray
  //Allocate memory for right subarray

  //copy elements form arr to Left
  //copy elements from arr to Right

  //while both Left and Right are < sizeLeft and sizeRight, respectivly

  //copy into arr starting from arr[low]

  //check if Left[i] > Right[i]
  //if true
  //

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
