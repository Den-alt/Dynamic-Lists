#include <stdio.h>
#include <string.h>
#include "../Headers/inform.h"

#define EMPTY ""
#define MAX 20                      //!Max length for "5 number" sentence

//!Get data from console
//!Parameters: Pointer to start of the list
//!Return: a real number of elements
int ScanFromConsole(STACK * start)
{
    int kst = 0;
    do {
        char temp[MAX];
        printf("Enter the №%d number or enter an empty sentence to finish:\n", kst + 1);
        gets(temp);                                                         //!Get data in temporary string
        if(strcmp(temp, EMPTY) == 0)
            break;
        start = AddElement(start, temp);                                    //!Create new element of the list
        kst++;                                                              //!Update a number of elements
    } while (1);
    printf("Data reading finished\nYou entered %d sentence\n", kst);
    return kst;
}
