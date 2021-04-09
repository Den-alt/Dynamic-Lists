#include <stdlib.h>
#include <string.h>
#include "../Headers/inform.h"

//Create a new element in list
//Parameters: pointer to previous element and an input information
//Return: pointer to new element
STACK * AddElement(STACK* prev, char *sent)
{
    STACK * new;
    new = (STACK*)malloc(sizeof(STACK));               //Allocate memory for element of list
    if(new == NULL)
        return NULL;
    new->data.sent = strdup(sent);                      //Set sentence in dynamic memory
    new->next = prev;                                   //Set address of the previous element
    return new;
}

void DeleteList(STACK * start)
{
    STACK * temp = start;           //Set pointer to first element of list
    while (temp != NULL)
    {
        start = start->next;        //Set pointer to next element for saving address of the new element
        free(temp);                 //Free memory
        temp = start;               //Set pointer to the next one
    }
}