#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void appendStringArr(char *string, char c, int arrayLength);
void selectionInt(int pptargetArray[], int sizeOfArray);
void selectionString(char *ptargetArray[], int sizeOfArray);
/*
int main(int argc, char** argv)
{
    int unsorted[10] = {654, 18, 81, 4, 92, 68, 145, 8, 99, 36};
    char *unstrings[10] = {"AAAAA", "a", "AAA", "aaaa", "AAa", "AAAAa", "AAa", "A", "aa", "Aaa"};
    int i;
    
    selectionInt(unsorted, 10);
    selectionString(10, unstrings, 10);
    
    for(i = 0; i <= 9; i++)
    {
        printf("%d\n", unsorted[i]);
    }
    
    return (EXIT_SUCCESS);
}
*/
void selectionInt(int targetArray[], int sizeOfArray)
{
    int i;
    int j;
    int temp;
    int lowestInd = 0;
    
    for(i = 0; i <= sizeOfArray-2; i++)
    {
        lowestInd = i;
        for(j = i; j <= sizeOfArray; j++)
        {
            if(targetArray[j] < targetArray[lowestInd])
            {
                lowestInd = j;
            }
        }
        temp = targetArray[i];
        targetArray[i] = targetArray[lowestInd];
        targetArray[lowestInd] = temp;
    }
}
 
void selectionString(char *ptargetArray[], int sizeOfArray)
{
    int i;
    int j;
    char *temp;
    int lowestInd = 0;
    
    for(i = 0; i <= sizeOfArray - 1; i++)
    {
        lowestInd = i;
        for(j = 0; j <= sizeOfArray - 1; j++)
        {
            if(strcmp(ptargetArray[j], ptargetArray[lowestInd]) > 0)
            {
                lowestInd = j;
            }
            temp = ptargetArray[i];
            ptargetArray[i] = ptargetArray[lowestInd];
            ptargetArray[lowestInd] = temp;
        }
    }
}