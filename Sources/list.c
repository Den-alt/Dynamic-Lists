#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/inform.h"

//!Create a new element in list
//!Parameters: pointer to previous element and an input information
//!Return: pointer to new element
STACK * AddElement(STACK* prev, char *sent)
{
    STACK * new;
    new = (STACK*)malloc(sizeof(STACK));                   //!Allocate memory for element of list
    if(new == NULL)
        return NULL;
    new->data.sent = strdup(sent);                          //!Set sentence in dynamic memory
    new->next = prev;                                       //!Set address of the previous element
    return new;
}
//!Check each item and delete the ones that are wrong
//!Parameters: pointer to start element of the list and array of decimal values
void ListFiltering (STACK* start, long *decimal)
{
    int kst = 0;
    STACK * current = start, *prev = start, *delete;                   //!Set pointer to first element of list
    decimal = (long*)malloc(sizeof(long));                               //!Get memory for decimal values array
    while (current != NULL)
    {
        long * check, temp;
        temp = CheckBase(current->data.sent);                        //!Check data
        if(temp > 0)
        {
            kst++;
            check = (long*)realloc(decimal, kst * sizeof(long));         //!Allocate memory for next number;
            if(check == NULL)
            {
                printf("Not enough memory to write a new decimal value\n");
                return;
            }
            decimal = check;
            decimal[kst-1] = temp;                                        //!Set number in array
        }else if(*decimal == 0)                                           //!If true - delete element
        {
            delete = current;                                  //!Get address of element to delete
            current = current->next;                           //!Set address to the next element
            prev->next = delete->next;                         //!Connect next element to previous
            delete->next = NULL;                               //!Detach element from list
            DeleteElement(delete);
        }else
        {
            prev = current;                                           //!Save address of the previous element
            current = current->next;                                  //!Set pointer to next element
        }
    }
}
//!Print all list console
//!Parameters: pointer to start of the list
void PrintList(STACK* start)
{
    if(start == NULL)
        return;
    printf("Sentence: %s\n", start->data.sent);
    PrintList(start->next);
}
//!Print table with results in console
//!Parameters: pointer to start of the list and pointer to the array of numbers
void Table(STACK* start, long* array)
{
    STACK *temp = start;
    int count = 0;
    printf("Decimal values\tSentence\n");
    while (temp != NULL)
    {
        printf("%14lu\t%s", array[count], temp->data.sent);
        count++;
        temp = temp->next;
    }
}
//!Check if sentence to be 5 number
//!Parameters: pointer to element of the list
//!Return: a decimal value
long CheckBase(char* str)
{
    long number = 0;
    char **end = NULL;
    number = strtol(str, end, 5);
    return number;
}
//!Delete list and free dynamic memory
//!Parameters: pointer to element of the list
void DeleteElement(STACK * start)
{
    STACK * temp = start;               //!Set pointer to first element of list
    if (temp == NULL)                   //!Base of the recursion
        return;
    start = start->next;                //!Set pointer to next element for saving address of the new element
    free(temp->data.sent);              //!Free dynamic memory of sentence
    free(temp);                         //!Delete element
    DeleteElement(start);               //!Set pointer to the next one
}