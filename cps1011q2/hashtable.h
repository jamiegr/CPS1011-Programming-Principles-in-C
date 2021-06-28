#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef CPS1011Q2_HASHTABLE_H
#define CPS1011Q2_HASHTABLE_H

#endif //CPS1011Q2_HASHTABLE_H

//pair struct since it is the same in all versions of the table
typedef struct pair
{
    char key[9];
    char value[25];
}pair;

//Function prototypes
void * createTable(size_t hashSize);
void initializeTable(size_t hashSize, void * p);
int hashFunction(char key[9], size_t hashSize);
int lookUp(char key[9], size_t hashSize, void * p);
int insert(char key[9], char value[25], size_t hashSize, void * p);
int delete(char key[9], size_t hashSize, void * p);
void printContents(size_t hashSize, void * p);
void saveFile(size_t hashSize, void * p);
void readFromFile(size_t hashSize, void * p);
//Function prototypes