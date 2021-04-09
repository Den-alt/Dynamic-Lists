#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "../Headers/inform.h"

#define P_LENGTH 140                                            //Max length of path to file
#define S_LENGTH 14                                             //Max length of sentence

FILE * f_DataFile = NULL;                                       //Pointer to stream with file for reading

//Get data from file
//Parameters: Pointer to element of the list
//Return: a real number of elements
int ScanFromFile(STACK * start)
{
    char path[P_LENGTH];
    int num = 0;                                                        //Real number of elements
    do {
        printf("\nEnter the path to your file: ");
        gets(path);                                                     //Get path to file
    } while (OpenFile(path) == -1);                         //Open file stream
    for (char *str; !feof(f_DataFile) ; )
    {
        str = (char *)malloc(S_LENGTH* sizeof(char));               //Allocate memory for temporary sentence
        if(str == NULL)
        {
            printf("Not enough memory\n");
            break;
        }
        char temp;
        int check = 0;
        for (int i = 0; i < S_LENGTH-1 && (fscanf(f_DataFile, "%c", &temp) == 1) ; i++ )      //Read sentence from file
        {
            check = 1;
            str[i] = temp;
        }
        if(check == 1)                                                              //If at least one symbol read
        {
            int count = S_LENGTH;
            if(isdigit(str[S_LENGTH-2]) != 0)                                   //To avoid breaking the number
            {
                while (fscanf(f_DataFile, "%c", &temp) == 1)
                {
                    if(isdigit(temp) == 0)                                          //If next symbol isn't a number, pass stop reading
                        break;
                    char * p;
                    count++;                                                        //Update length
                    p = (char *)realloc(str, count * sizeof(char));
                    if(p == NULL)
                        break;
                    str = p;                                                        //Change address
                    str[count-2] = temp;                                            //Update string
                }
            }
            str[count-1] = '\0';
            start = AddElement(start, str);                                 //Add element to list
            num++;                                                          //Update number of file
        }
        free(str);
    }
    CloseFile();                                              //Close file stream
    return num;
}

//Open file
//Parameters: Pointer to file stream and path to user file
//Return: -1 if file can't be open, 0 - success
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

//Close file stream
//Parameters: Pointer to file stream
void CloseFile()
{
    if(fclose(f_DataFile) != 0)
        printf("File can't be closed!\n");
}
