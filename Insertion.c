#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  insertionInt(int targetArray[], int sizeOfArray);
void  insertionString(char *ptargetArray[], int sizeOfArray);

/*
int main(int argc, char** argv)
{
    int unsorted[10] = {654, 18, 81, 4, 92, 68, 145, 8, 99, 36};
    char *unstrings[] = {"AAAAA", "a", "AAA", "aaaa", "AAa", "AAAAa", "AAa", "A", "aa", "Aaa"};
    int i;
    int j;

    insertionInt(unsorted, 10);
    insertionString(10, unstrings, 10);

    for(i = 0; i <= 9; i++)
    {
        printf("%d\n", unsorted[i]);
    }

    for(i = 0; i <= 9; i++)
    {
        for(j = 0; j <= strlen(unstrings[i]) - 1; j++)
        {
            printf("%c", unstrings[i][j]);
        }
        printf("\n");
    }

    return (EXIT_SUCCESS);
}
*/

void  insertionString(char *ptargetArray[], int sizeOfArray)
{
    int i;
    int j;
    char *curr;

    for(i = 0; i <= sizeOfArray - 1; i++)
    {
        curr = ptargetArray[i];
        j = i - 1;

        while(j >= 0 && strcmp(ptargetArray[j], curr) > 0)
        {
            ptargetArray[j + 1] = ptargetArray[j];
            j--;
        }
        ptargetArray[j + 1] = curr;
    }
}

void  insertionInt(int targetArray[], int sizeOfArray)
{
    int i;
    int j;
    int curr;

    for(i = 0; i <= sizeOfArray - 1; i++)
    {
        curr = targetArray[i];
        j = i - 1;

        while(j >= 0 && targetArray[j] > curr)
        {
            targetArray[j + 1] = targetArray[j];
            j--;
        }
        targetArray[j + 1] = curr;
    }
}
