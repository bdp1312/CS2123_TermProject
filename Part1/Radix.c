/*
Authors:
Assignment Number: Project 1
File Name:
Course/Section: CS 2123
Due Date:
Instructor: Dr. Ku
*/

#include<stdio.h>
#include <string.h>

void countSortInt(int arr[], int arrLen, int ind)
{
    int output[arrLen]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < arrLen; i++)
    {
        count[(arr[i]/ind)%10]++;
    }

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (i = arrLen - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/ind)%10 ] - 1] = arr[i];
        count[ (arr[i]/ind)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < arrLen; i++)
    {
        arr[i] = output[i];
    }
}


int getMaxInt(int arr[], int arrLen)
{
    int max = arr[0];
    int i;
    for (i = 1; i < arrLen; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void radixSortInt(int arr[], int arrLen)
{
    // Find the maximum number to know number of digits
    int max = getMaxInt(arr, arrLen);
    int ind;
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for(ind = 1; max/ind > 0; ind *= 10)
    {
        countSortInt(arr, arrLen, ind);
    }
}

void countSortStr(char* arr[], int maxLen, int ind)
{
    char* output[maxLen]; // output array
    int i;
    int count[53] = {0};

    // Store count of occurrences in count[]
    for(i = 0; i < maxLen; i++)
    {
    	if(strlen(arr[i]) <= ind)
        {
            count[0]++;
        }
	else
        {
            count[(int)arr[i][ind] - (int) 'A' + 1]++;
        }
    }

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for(i = 1; i < 53; i++)
    {
        count[i] += count[i - 1];
    }


    // Build the output array
    for (i = maxLen - 1; i >= 0; i--)
    {
    	if(strlen(arr[i]) <= ind)
        {
            output[count[0] - 1] = arr[i];
            count[0]--;
	}
	else
        {
            output[count[(int)arr[i][ind] - (int) 'A' + 1] - 1] = arr[i];
            count[(int)arr[i][ind] - (int) 'A' + 1]--;
	}
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for(i = 0; i < maxLen; i++)
    {
        arr[i] = output[i];
    }

}


int getMaxStr(char* arr[], int arrLen)
{
    int max = strlen(arr[0]);
    int i;
    for (i = 1; i < arrLen; i++)
    {
        if(strlen(arr[i]) > max)
        {
            max = strlen(arr[i]);
        }
    }
    return max;
}

void radixSortStr(char* arr[], int arrLen)
{
    // Find the maximum number to know number of digits
    int max = getMaxStr(arr, arrLen);
    int i;
    int ind;
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for(ind = max - 1; ind >= 0; ind--)
    {
        countSortStr(arr, arrLen, ind);
    }
}

/*
int main()
{
    int i;
    int arrInt[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int intArrLen = sizeof(arrInt)/sizeof(arrInt[0]);
    radixSortInt(arrInt, intArrLen);
    printf("Sorted array is: \n");
    for(i = 0; i < intArrLen; i++)
    {
        printf("%d ", arrInt[i]);
    }

    char* arrStr[] = {"AAAAA", "a", "AAA", "aaaa", "AAa", "AAAAa", "AAa", "A", "aa", "Aaa"};
    int strArrLen = sizeof(arrStr)/sizeof(arrStr[0]);
    radixSortStr (arrStr, strArrLen);
    printf("Sorted array is: \n");
    for(i = 0; i < strArrLen; i++)
    {
        printf("%s ", arrStr[i]);
    }
    return 0;
}
*/
