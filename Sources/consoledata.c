#include <stdio.h>
#include <string.h>
#include "../Headers/inform.h"

#define EMPTY ""
#define MAX 20                      //!Max length for "5 number" sentence

//!Get data from console
//!Parameters: Pointer to start of the list
//!Return: a real number of elements
STACK * ScanFromConsole(STACK * start)
{
    do {
        char temp[MAX];
        printf("Enter the number or an empty sentence to finish:\n");
        gets(temp);                                                         //!Get data in temporary string
        if(strcmp(temp, EMPTY) == 0)
            break;
        start = AddElement(start, temp);                                    //!Create new element of the list
    } while (1);
    printf("Data reading finished\n");
    return start;
}
