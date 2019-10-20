#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "QuickSort.h"

int partitionInt (int arr[], int low, int high)
{
    int temp, j;
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swapping array elemnents
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}


void quickIntSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partitionInt(arr, low, high);
        // Separately sort elements before
        // partition and after partition
        quickIntSort(arr, low, pi - 1);
        quickIntSort(arr, pi + 1, high);
    }
}


int partitionStr (char* arr[], int low, int high)
{
  int j;
  char  *temp= malloc(sizeof(arr[high]));
  // char *pivot = malloc(sizeof(arr[high]));
  // strcpy(pivot, arr[high]);    // pivot
  char*pivot = arr[high];
  int i = (low - 1);  // Index of smaller element

  for (j = low; j <= high- 1; j++)
  {
      // If current element is smaller than or
      // equal to pivot
      if (strcmp(arr[j], pivot) <= 0 )
      {
          i++;    // increment index of smaller element
          // strcpy(temp, arr[i]);
          temp = arr[i];
          // strcpy(arr[i], arr[j]);
          arr[i] = arr[j];
          // strcpy(arr[j], temp);
          arr[j] = temp;

      }
  }
  // Swapping array elemnents
  // strcpy(temp, arr[i + 1]);
  temp=arr[i+1];
  // strcpy(arr[i + 1], arr[high]);
  arr[i+1]=arr[high];
  // strcpy(arr[high], temp);
  arr[high]=temp;
  return (i + 1);
}

void quickStrSort(char *arr[], int low, int high)
{
  if(low<high){
    int pi = partitionStr(arr, low, high);
    quickStrSort(arr, low, pi - 1);
    quickStrSort(arr, pi + 1, high);
  }
}
/*
int main()
{
    int i;
    int intArr[] = {12, 11, 13, 5, 6, 7};
    int intArrLen = sizeof(intArr)/sizeof(intArr[0]);
    quickIntSort(intArr, 0, intArrLen-1);
    printf("Sorted array is: \n");
    for(i = 0; i < intArrLen; i++)
    {
        printf("%d ", intArr[i]);
    }
    printf("\n");

    char *strArr[] = {"AAAAA", "a", "AAA", "aaaa", "AAa", "AAAAa", "AAa", "A", "aa", "Aaa"};
    int strArrLen = sizeof(strArr)/sizeof(strArr[0]);
    quickStrSort(strArr, 0, strArrLen-1);
    printf("Sorted array is: \n");
    for(i = 0; i < strArrLen; i++)
    {
        printf("%s ", strArr[i]);
    }
}
*/
