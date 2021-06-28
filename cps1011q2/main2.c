#include "hashtable.h"

typedef struct hashTable
{
    size_t maxCollisions;
    size_t usedCollisions;
    pair * array;//using a pointer since max collisions are not fixed
}hashTable;

void * createTable(size_t hashSize)
{
    hashTable * p = (hashTable*)malloc(hashSize * sizeof(hashTable));//allocating memory for the rows
    for(int i = 0; i < hashSize; i++)
    {
        p[i].array = (pair*)malloc(5 * sizeof(pair));//allocating memory for the columns/collisions, initially 5 columns
        p[i].maxCollisions = 5;
        p[i].usedCollisions = 0;
    }
    return p;
}

void initializeTable(size_t hashSize, void * p)
{
    hashTable * start = (hashTable*)p;
    for(int x = 0; x < hashSize; x++)
    {
        for(int i = 0; i < start[x].maxCollisions; i++)
        {
            strcpy(start[x].array[i].key, "\0");
            strcpy(start[x].array[i].value, "\0");
        }
    }
}

int hashFunction(char key[9], size_t hashSize)
{
    int keyLength = strlen(key);
    int sum =0;
    for(int c = 0; c<keyLength; c++)
    {
        sum += key[c];
    }
    sum = sum%hashSize;
    return sum;
}

int lookUp(char key[9], size_t hashSize, void * p)
{
    hashTable * start = (hashTable*)p;
    int hash = hashFunction(key, hashSize);
    for(int i = 0; i < start[hash].maxCollisions; i++)
    {
        if(strcmp(start[hash].array[i].key, key) == 0)
        {
            printf("Key found at location [%d][%d]\n", hash, i);
            return i;
        }
    }
    printf("Key not found\n");
    return -1;
}

int insert(char key[9], char value[25], size_t hashSize, void * p)
{
    hashTable * start = (hashTable*)p;
    int hashValue = hashFunction(key, hashSize);
    if(strlen(key)!= 8)
    {
        printf("Key must be 8 characters long\n");
        return -1;
    }
    if(key == "" || value == "")
    {
        printf("Key or value cannot be blank\n");
        return -1;
    }
    if(lookUp(key, hashSize, p) != -1)
    {
        printf("Key is not unique\n");
        return -1;
    }
    if(start[hashValue].maxCollisions == start[hashValue].usedCollisions)//if an entry is to be inserted to a full index, memory is allocated for one more collision at that index
    {
        start[hashValue].maxCollisions += 1;
        start[hashValue].array = (pair*)realloc((start[hashValue].array), (start[hashValue].maxCollisions)*sizeof(pair));
        strcpy(start[hashValue].array[start[hashValue].maxCollisions-1].key, "\0");//initializing newly allocated memory
        strcpy(start[hashValue].array[start[hashValue].maxCollisions-1].key, "\0");
        return insert(key, value, hashSize, p);//attempt to insert the entry again after allocating more memory for that index
    }
    for(int i = 0; i <  start[hashValue].maxCollisions; i++)
    {
        if(start[hashValue].array[i].key[0]=='\0')
        {
            strcpy(start[hashValue].array[i].key, key);
            strcpy(start[hashValue].array[i].value, value);
            printf("Entry successfully inserted\n");
            start[hashValue].usedCollisions += 1;
            return 1;
        }
    }
}

int delete(char key[9], size_t hashSize, void * p)
{
    hashTable * start = (hashTable*)p;
    int hashValue = hashFunction(key, hashSize);
    int position = lookUp(key, hashSize, p);
    if(position == -1)
    {
        return -1;
    }else{
        strcpy(start[hashValue].array[position].key, "\0");
        strcpy(start[hashValue].array[position].value, "\0");
        start[hashValue].usedCollisions-=1;
        printf("Key successfully deleted\n");
        return 1;
    }
}

void printContents(size_t hashSize, void * p)
{
    hashTable * start = (hashTable*)p;
    printf("Index\t\tKey\t\tValue\n");
    for(int i = 0; i < hashSize; i++)
    {
        for(int collisionCounter = 0; collisionCounter < start[i].maxCollisions; collisionCounter++){
            if(start[i].array[collisionCounter].key[0]!='\0')
                printf("%d\t\t%s\t%s\n", i, start[i].array[collisionCounter].key, start[i].array[collisionCounter].value);
        }
    }
}

void saveFile(size_t hashSize, void * p)
{
    hashTable * start = (hashTable*)p;
    FILE *fp = fopen("hashPartB.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
    }else{
        fprintf(fp, "Index\t\tKey\t\tValue\n");
        for(int i = 0; i < hashSize; i++)
        {
            for(int collisionCounter = 0; collisionCounter < start[i].maxCollisions; collisionCounter++){
                if(start[i].array[collisionCounter].key[0]!='\0')
                    fprintf(fp, "%d\t\t%s\t%s\n", i, start[i].array[collisionCounter].key, start[i].array[collisionCounter].value);
            }
        }
        printf("File successfully saved\n");
    }
    fclose(fp);
}

void readFromFile(size_t hashSize, void * p)
{
    initializeTable(hashSize, p);
    FILE *fp = fopen("hashPartB.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
    }else{
        char temp[100];
        char key[9];
        char value[25];
        int counter = 0;
        int valueCounter;
        while(!feof(fp))
        {
            valueCounter = 0;
            fgets(temp, 100, fp);
            counter++;
            if(!feof(fp) && counter > 1) {
                for (int i = 0; i < strlen(temp); i++) {
                    if (i >= 3 && i < 12 && temp[i] != ' ' && temp[i] != '\t')
                        key[i-3] = temp[i];
                    if (i > 11 && temp[i] != '\n')
                    {
                        value[i-12] = temp[i];
                        valueCounter++;
                    }
                }
                key[8] = '\0';
                value[valueCounter] = '\0';
                insert(key, value, hashSize, p);
            }
        }
    }
    fclose(fp);
}
