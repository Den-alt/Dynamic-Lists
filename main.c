#include <stdio.h>
#include "Headers/inform.h"
int main(void)
{
    STACK * start = NULL;
    int isFile = 0;
    printf("\nSelect input method information\nFrom console: 0\nFrom File: 1\nEnter: ");
    scanf("%d",&isFile);
    getchar();
    if (isFile == 0)                                                //Get data from console
    {
        printf("You selected input from console\n");
        ScanFromConsole(start);
    }else                                                           //Get data from file
    {
        printf("You selected input from file\n");
        ScanFromFile(start);
    }



    DeleteList(start);
    return 0;
}
