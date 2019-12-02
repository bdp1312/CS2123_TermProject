#include <stdio.h>
#include <string.h>

void heapifyInt(int arr[], int arrLen, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int left = 2*i + 1; // left = 2*i + 1 
    int right = 2*i + 2; // right = 2*i + 2 
    
    int temp;
    // If left child is larger than root 
    if (left < arrLen && arr[left] > arr[largest]) 
        largest = left; 
  
    // If right child is larger than largest so far 
    if (right < arrLen && arr[right] > arr[largest]) 
        largest = right; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        // Recursively heapify the affected sub-tree 
        heapifyInt(arr, arrLen, largest); 
    } 
} 

void heapSortInt(int arr[], int arrLen) 
{ 
    int temp, i;
    // Build heap (rearrange array) 
    for (i = arrLen / 2 - 1; i >= 0; i--) 
        heapifyInt(arr, arrLen, i); 
  
    // One by one extract an element from heap 
    for (i=arrLen-1; i>=0; i--) 
    { 
        // Move current root to end 
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
  
        // call max heapify on the reduced heap 
        heapifyInt(arr, i, 0); 
    } 
} 

void heapifyString(char *arr[], int arrLen, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int left = 2*i + 1; // left = 2*i + 1 
    int right = 2*i + 2; // right = 2*i + 2 
  
    char *temp;
    // If left child is larger than root 
    if (left < arrLen && strcmp(arr[left], arr[largest]) > 0) 
        largest = left; 
  
    // If right child is larger than largest so far 
    if (right < arrLen && strcmp(arr[right], arr[largest]) > 0) 
        largest = right; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        // Recursively heapify the affected sub-tree 
        heapifyString(arr, arrLen, largest); 
    } 
} 

void heapSortString(char *arr[], int arrLen) 
{ 
    char *temp;
    int i;
    // Build heap (rearrange array) 
    for (i = arrLen / 2 - 1; i >= 0; i--) 
    {
        heapifyString(arr, arrLen, i); 
    }
  
    // One by one extract an element from heap 
    for (i=arrLen-1; i>=0; i--) 
    { 
        // Move current root to end 
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
  
        // call max heapify on the reduced heap 
        heapifyString(arr, i, 0); 
    } 
}

int getMaxLen(char *arr[], int arrLen)
{
    int max = sizeof(arr[0])/sizeof(char);
    int i;
    int current;
    
    for(i = 0; i <= arrLen; i++)
    {
        current = sizeof(arr[i])/sizeof(char);
        if(max < current)
        {
            max = current;
        }
    }
    
    return max;
}

/*
int main() 
{ 
    int i;
    int intArr[] = {12, 11, 13, 5, 6, 7}; 
    int intArrLen = sizeof(intArr)/sizeof(intArr[0]); 
    heapSortInt(intArr, intArrLen); 
    printf("Sorted array is: \n"); 
    for(i = 0; i < intArrLen; i++)
    {
        printf("%d ", intArr[i]);
    }
    printf("\n");
    
    char *strArr[] = {"AAAAA", "a", "AAA", "aaaa", "AAa", "AAAAa", "AAa", "A", "aa", "Aaa"}; 
    int strArrLen = sizeof(strArr)/sizeof(strArr[0]); 
    heapSortString(strArr, strArrLen); 
    printf("Sorted array is: \n"); 
    for(i = 0; i < strArrLen; i++)
    {
        printf("%s ", strArr[i]);
    }
} 
*/
 