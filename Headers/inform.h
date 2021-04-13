#ifndef DYNAMIC_LISTS_INFORM_H
#define DYNAMIC_LISTS_INFORM_H
//!Demo file
//! ../FiveNumbers.txt

typedef struct s_ListBody {
    char *sent;
}BODY;

typedef struct s_StackList {
    BODY data;
    struct s_StackList *next;
}STACK;

//!list.c
STACK * AddElement(STACK*, char *);
void PrintList(STACK*);
void Table(STACK*);
long CheckBase(char*);
STACK* ListFiltering (STACK*);
void DeleteElement(STACK*);

//!consoledata.c
STACK * ScanFromConsole(STACK *);

//!filedata.c
STACK * ScanFromFile(STACK *);
int OpenFile(char *);
void CloseFile();

#endif //DYNAMIC_LISTS_INFORM_H
