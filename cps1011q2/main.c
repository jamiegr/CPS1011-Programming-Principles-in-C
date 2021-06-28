#include "hashtable.h"

typedef struct hashTable//defining the properties we need for our table
{
    size_t maxCollisions;
    size_t usedCollisions;
    pair array[5];//store the collisions for every hash index
}hashTable;

void * createTable(size_t hashSize)
{
    hashSize = 5;//hash space is predefined
    hashTable * p = (hashTable*)malloc(hashSize * sizeof(hashTable));//memory is allocated for 5 rows of 5 collisions since the max collisions and hash space are predefined
    return p;
}

void initializeTable(size_t hashSize, void * p)//initializes all the keys and values as empty strings
{
    hashSize = 5;//hash space is predefined
    hashTable * start = (hashTable*)p;//typecasts the void pointer to a pointer of type hashtable
    for(int x = 0; x < hashSize; x++)
    {
        start[x].maxCollisions = 5;//the maximum collisions for every hash index is 5
        start[x].usedCollisions = 0;//initially there are no collisions since no entries are inputted
        for(int i = 0; i < 5; i++)
        {
            strcpy(start[x].array[i].key, "\0");
            strcpy(start[x].array[i].value, "\0");
        }
    }
}

int hashFunction(char key[9], size_t hashSize){//uses the key of an entry to calculate the index where it should be stored
    hashSize = 5;//hash space is predefined
    int keyLength = strlen(key);
    int sum =0;
    for(int c = 0; c<keyLength; c++)
    {
        sum += key[c];
    }
    sum = sum%hashSize;//the algorithm consists of adding the ASCII value value of every character and calculating its mod by the hash space size
    return sum;
}

int lookUp(char key[9], size_t hashSize, void * p)
{
    hashSize = 5;//hash space is predefined
    hashTable * start = (hashTable*)p;
    int hash = hashFunction(key, hashSize);//find the hash index of the key to search for
    for(int i = 0; i < start[hash].maxCollisions; i++)//searches all the collisions for that hash index
    {
        if(strcmp(start[hash].array[i].key, key) == 0)//key inputted must be an exact match with a key in the table
        {
            printf("Key found at location [%d][%d]\n", hash, i);
            return i;
        }
    }
    printf("Key not found\n");
    return -1;
}

int insert(char key[9], char value[25], size_t hashSize, void * p)//inserts new entry into the table
{
    hashTable * start = (hashTable*)p;
    hashSize = 5;//hash space is predefined
    int hashValue = hashFunction(key, hashSize);//uses key and hash size to calculate index
    if(strlen(key)!= 8)//checks if key is of appropriate size
    {
        printf("Key must be 8 characters long\n");
        return -1;
    }
    if(key == "" || value == "")//checks that neither the key nor the value or empty
    {
        printf("Key or value cannot be blank\n");
        return -1;
    }
    if(lookUp(key, hashSize, p) != -1)//checks if the key is unique
    {
        printf("Key is not unique\n");
        return -1;
    }
    if(start[hashValue].maxCollisions == start[hashValue].usedCollisions)//checks if the maximum collisions for the particular index has been reached
    {
        printf("Maximum collisons for hash value %d reached\n", hashValue);
        return -1;
    }
    for(int i = 0; i < start[hashValue].maxCollisions; i++){
        if(start[hashValue].array[i].key[0]=='\0')
        {
            strcpy(start[hashValue].array[i].key, key);
            strcpy(start[hashValue].array[i].value, value);
            printf("Entry successfully inserted\n");
            start[hashValue].usedCollisions += 1;
            i = start[hashValue].maxCollisions+1;
            return 1;
        }
    }
}

int delete(char key[9], size_t hashSize, void * p)//searches for a given key and deletes the entry associated with it
{
    hashSize = 5;//hash space is predefined
    hashTable * start = (hashTable*)p;
    int hashValue = hashFunction(key, hashSize);//finds the hash index for the given key
    int position = lookUp(key, hashSize, p);//finds the position of the key in the respective array if it already exists
    if(position == -1)
    {
        return -1;//if the key doesn't already exist, exit the function
    }else{//if the key is found, replace it and the respective value with empty strings and deduct the used collisions for that hash value by 1
        strcpy(start[hashValue].array[position].key, "\0");
        strcpy(start[hashValue].array[position].value, "\0");
        start[hashValue].usedCollisions-=1;
        printf("Key successfully deleted\n");
        return 1;
    }
}

void printContents(size_t hashSize, void * p)
{
    hashSize = 5;//hash space is predefined
    hashTable * start = (hashTable*)p;
    printf("Index\t\tKey\t\tValue\n");
    for(int i = 0; i < hashSize; i++)
    {
        for(int collisionCounter = 0; collisionCounter < start[i].maxCollisions; collisionCounter++){
            if(start[i].array[collisionCounter].key[0]!='\0')//prints all elements which are not empty
                printf("%d\t\t%s\t%s\n", i, start[i].array[collisionCounter].key, start[i].array[collisionCounter].value);
        }
    }
}

void saveFile(size_t hashSize, void * p)//same as printContents but prints to file
{
    hashSize = 5;//hash space is predefined
    hashTable * start = (hashTable*)p;
    FILE *fp = fopen("hashPartA.txt", "w");
    if (fp == NULL){
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
    hashSize = 5;//hash space is predefined
    FILE *fp = fopen("hashPartA.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
    }else{
        initializeTable(hashSize, p);//empties any elements which currently contain data to override them with the data in the given file
        char temp[100];
        char key[9];
        char value[25];
        int counter = 0;//used so that data is not read from the first line which is a header
        int valueCounter;
        while(!feof(fp))
        {
            valueCounter = 0;//used to find the length of the value loaded so as to add a \0 to the end of it
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