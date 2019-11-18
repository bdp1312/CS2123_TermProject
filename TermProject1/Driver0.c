#include <stdio.h>
#include <string.h>
#include "SortFunctions.h"
#include"ArrayLib.h"//testing compilation of ArrayLib
#include"Searches.h"
#include"BubbleSort.h"
#include"QuickSort.h"
#include"MergeSort.h"

/*The menu should prompt user to input data coresponding to
what datatype they want to use, what sorting method they use,
what sorting algorithm they use, and what element to search
for.*/

int main()
{
  char *strArr[] = {"AAAAA", "a", "AAA", "aaaa", "AAa", "AAAAa", "AAa", "A", "aa", "Aaa"};
  int strArrLen = sizeof(strArr)/sizeof(strArr[0]);
  int intArr[] = {654, 18, 81, 4, 92, 68, 145, 8, 99, 36};
  int intArrLen = sizeof(intArr)/sizeof(intArr[0]);



    printf("Choose your sorting algorithm:\n1. Bubble sort\n2. Selection sort\n3. Insertion sort\n"
            "4. Merge sort\n5. Quick sort\n6. Radix sort\n7. Heap sort\n");
    int mode;
		//do{
    	scanf("%d", &mode);
//}while(mode!=1 && mode!=2 && mode!=3 && mode!=4 && mode!=5 && mode!=6 && mode!=7);
    printf("Choose your array type:\ni. Integer\ns. String\n");
    char type;
    do{
    	scanf("%c", &type);
    }while(type!='s' && type!='i');
    printf("Choose your search algorithm:\nl. Linear search\nb. Binary search\n");
    char search;
		do{
    	scanf("%c", &search);
	//		printf("%c", search);
		}while(search!='l' && search != 'b');
	//	printf("Menu Cleared!");
    if(type == 's')
    {
        // char *strArr[] = {"AAAAA", "a", "AAA", "aaaa", "AAa", "AAAAa", "AAa", "A", "aa", "Aaa"};
        // int strArrLen = sizeof(strArr)/sizeof(strArr[0]);
        if(mode == 1) //bubble sort
        {
						bubbleStringSort(strArr, strArrLen);
        }
        else if(mode == 2) //selection sort
        {
            selectionString(strArr, strArrLen);
        }
        else if(mode == 3) //insertion sort
        {
            insertionString(strArr, strArrLen);
        }
        else if(mode == 4) //merge sort
        {
						mergeStrSort(strArr, 0, strArrLen);
        }
        else if(mode == 5) //quick sort
        {
						quickStrSort(strArr, 0, strArrLen);
        }
        else if(mode == 6) //radix sort
        {
            radixSortStr(strArr, strArrLen);
        }
        else if(mode == 7) //heap sort
        {
            heapSortString(strArr, strArrLen);
        }
        else
        {
            printf("Not a valid option for sorting\n");
            main();
        }
    }
    else if(type == 'i')
    {
        int intArr[] = {654, 18, 81, 4, 92, 68, 145, 8, 99, 36};
        int intArrLen = sizeof(intArr)/sizeof(intArr[0]);
        if(mode == 1) //bubble sort
        {
					bubbleIntSort(intArr, intArrLen);
        }
        else if(mode == 2) //selection sort
        {
            selectionInt(intArr, intArrLen);
        }
        else if(mode == 3) //insertion sort
        {
            insertionInt(intArr, intArrLen);
        }
        else if(mode == 4) //merge sort
        {
						mergeIntSort(intArr, 0, intArrLen);
        }
        else if(mode == 5) //quick sort
        {
						quickIntSort(intArr, 0, intArrLen);
        }
        else if(mode == 6) //radix sort
        {
            radixSortInt(intArr, intArrLen);
        }
        else if(mode == 7) //heap sort
        {
            heapSortInt(intArr, intArrLen);
        }
        else
        {
            printf("Not a valid option for sorting\n");
            main();
        }
    }
    else
    {
        printf("Not a valid option for string type\n");
        main();
    }

    if(search == 'l' || search == 'L') //linear search
    {
        int found;
        int target;

        if(type == 'i' || type == 'I')
        {
            int target;
            printf("Enter target integer: ");
            scanf("%d", &target);
            found = linIntArraySearch(intArr, intArrLen, target);
        }
        else
        {
            char *target;
            printf("Enter target string: ");
            scanf(%*c);
            scanf("%s", target);
            found = linStringArraySearch(strArr, strArrLen, target);
        }

        if(found >= 0)
        {
            printf("Found\n");
        }
        else
        {
            printf("Not found\n");
        }
    }
    else if(search == 'b' || search == 'B') //binary search
    {
        int found;
        int target;

        if(type == 'i' || type == 'I')
        {
            int target;
            printf("Enter target integer: ");
            scanf("%d", &target);
            found = biIntArraySearch(intArr, intArrLen, target);
        }
        else
        {
            char target[20];
            printf("Enter target string: ");
            scanf(%*c);
            scanf("%s", target);
            found = biStringArraySearch(strArr, strArrLen, target);
        }

        if(found >= 0)
        {
            printf("Found\n");
        }
        else
        {
            printf("Not found\n");
        }
    }
    else
    {
        printf("Not a valid option for searching\n");
        main();
    }
}
