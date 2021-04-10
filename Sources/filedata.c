#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "../Headers/inform.h"

#define P_LENGTH 140                                            //!Max length of path to file
#define S_LENGTH 14                                             //!Max length of sentence

FILE * f_DataFile = NULL;                                       //!Pointer to stream with file for reading

//!Get data from file
//!Parameters: Pointer to element of the list
//!Return: a real number of elements
int ScanFromFile(STACK * start)
{
    char path[P_LENGTH];
    int num = 0;                                                        //!Real number of elements
    do {
        printf("\nEnter the path to your file: ");
        gets(path);                                                     //!Get path to file
    } while (OpenFile(path) == -1);                                     //!Open file stream
    for (char *str; !feof(f_DataFile) ; )
    {
        char temp;
        int count = 0;
        str = (char *)malloc(S_LENGTH* sizeof(char));               //!Allocate memory for temporary sentence
        if(str == NULL)
        {
            printf("Not enough memory\n");
            break;
        }
        while(fscanf(f_DataFile, "%c", &temp) == 1)                 //!Read sentence from file
        {
            if(count == 0)
                if(isspace(temp))                                          //!Skip the space characters in the line
                    continue;
            if(count >= S_LENGTH-1 || !isdigit(temp))                      //!If it is the end of a sentence or a number finish read
                break;
            str[count] = temp;
            count++;
        }
        if(count > 0)                                                              //!If at least one symbol read
        {
            str[S_LENGTH-1] = '\0';
            start = AddElement(start, str);                                 //!Add element to list
            num++;                                                          //!Update number of file
        }
        free(str);
    }
    CloseFile();                                                            //!Close file stream
    return num;
}

//!Open file
//!Parameters: Pointer to the file stream and path to user file
//!Return: -1 if file can't be open, 0 - success
int OpenFile(char * path)
{
    f_DataFile = fopen(path, "r");
    if(f_DataFile == NULL)
    {
        printf("File not found\n");
        return -1;
    }
    return 0;
}

//!Close file stream
//!Parameters: Pointer to file stream
void CloseFile()
{
    if(fclose(f_DataFile) != 0)
        printf("File can't be closed!\n");
}
