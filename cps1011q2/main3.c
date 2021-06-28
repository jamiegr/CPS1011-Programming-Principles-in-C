#include "hashtable.h"

typedef struct node
{
    pair data;
    struct node * nextNode;
}node;

typedef struct hashTable
{
    size_t nodes;//indicates the amount of nodes currently active for every hash value
    node * headOfHash;//points to the head node for every hash value
}hashTable;

void * createTable(size_t hashSize)
{
    hashTable * p = (hashTable*)malloc(hashSize * sizeof(hashTable));
    return p;
}

void initializeTable(size_t hashSize, void * p)
{
    hashTable * start = (hashTable*)p;
    for(int i = 0; i < hashSize; i++)
    {
        start[i].nodes = 0;
        start[i].headOfHash = (node*)malloc(sizeof(node));//allocating memory for the first node
        strcpy(start[i].headOfHash->data.key, "\0");//initializing the first node
        strcpy(start[i].headOfHash->data.value, "\0");
        start[i].headOfHash->nextNode = NULL;
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
    node * tempNode = start[hash].headOfHash;//temporary node used  to search through the list for that particular hash
    int counter = 0;
    while(tempNode->data.key[0]!='\0'){
        if (strcmp(tempNode->data.key, key) == 0) {
            printf("Key found\n");
            return counter;
        }
        tempNode = tempNode->nextNode;
        counter++;
    }
    printf("Key not found\n");
    return -1;
}

int insert(char key[9], char value[25], size_t hashSize, void * p)
{
    hashTable * start = (hashTable*)p;
    int hashValue = hashFunction(key, hashSize);
    node * tempNode = start[hashValue].headOfHash;
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
    while(tempNode->data.key[0]!='\0')
    {
        tempNode = tempNode->nextNode;
    }
    if(tempNode->data.key[0]=='\0')
    {
        strcpy(tempNode->data.key, key);
        strcpy(tempNode->data.value, value);
        start[hashValue].nodes += 1;//increment counter of active nodes for that hash
        tempNode->nextNode = (node*)malloc(sizeof(node));
        tempNode->nextNode->data.key[0] = '\0';
        tempNode->nextNode->data.value[0] = '\0';
        tempNode->nextNode->nextNode = NULL;
        printf("Entry successfully inserted\n");
        return 1;
    }
}

int delete(char key[9], size_t hashSize, void * p)
{
    hashTable * start = (hashTable*)p;
    int hashValue = hashFunction(key, hashSize);
    node * tempNode = start[hashValue].headOfHash;
    if(lookUp(key, hashSize, p) == -1)//key does not exist, exit function
    {
        return -1;
    }else{//if key exists, search for its position
        while(tempNode != NULL){
            if(strcmp(tempNode->data.key,key) == 0)
                break;//stop looping if key is found
            tempNode = tempNode->nextNode;
        }
    }

    if(tempNode == start[hashValue].headOfHash){//first node is target node
        start[hashValue].headOfHash = start[hashValue].headOfHash->nextNode;//set head pointer to second node
        start[hashValue].nodes -= 1;//decrement counter of active nodes for that hash
        printf("Key successfully deleted\n");
        tempNode->nextNode = NULL;
        free(tempNode);
        return 1;
    }else if(tempNode->nextNode == NULL){//last node is target node
        node * previous = NULL;
        tempNode = start[hashValue].headOfHash;
        while(tempNode->nextNode != NULL){
            previous = tempNode;
            tempNode = tempNode->nextNode;
        }
        previous->nextNode = NULL;
        start[hashValue].nodes -= 1;
        printf("Key successfully deleted\n");
        free(tempNode);
        free(previous);
        return 1;
    }else{
        node * searchNode = start[hashValue].headOfHash;
        while(searchNode!= NULL){//sets the newly created node to the node before the one we want to delete
            if(searchNode->nextNode == tempNode)
                break;
            searchNode = searchNode->nextNode;
        }
        searchNode->nextNode = tempNode->nextNode;//sets the node before the deleted node to point to the node after the deleted node
        free(tempNode);
        start[hashValue].nodes -= 1;
        printf("Key successfully deleted\n");
    }
}

void printContents(size_t hashSize, void * p)
{
    hashTable * start = (hashTable*)p;
    node * tempNode;
    printf("Index\t\tKey\t\tValue\n");
    for(int i = 0; i < hashSize; i++)
    {
        tempNode = start[i].headOfHash;
        while(tempNode->nextNode!=NULL){//prints all nodes which are not empty
            printf("%d\t\t%s\t%s\n", i, tempNode->data.key, tempNode->data.value);
            tempNode = tempNode->nextNode;
        }
    }
}

void saveFile(size_t hashSize, void * p)
{
    hashTable * start = (hashTable*)p;
    node * tempNode;
    FILE *fp = fopen("hashPartC.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
    }else{
        fprintf(fp, "Index\t\tKey\t\tValue\n");
        for(int i = 0; i < hashSize; i++)
        {
            tempNode = start[i].headOfHash;
            while(tempNode->nextNode!=NULL){//prints all nodes which are not empty
                fprintf(fp, "%d\t\t%s\t%s\n", i, tempNode->data.key, tempNode->data.value);
                tempNode = tempNode->nextNode;
            }
        }
        printf("File successfully saved\n");
    }
    fclose(fp);
}

void readFromFile(size_t hashSize, void * p)
{
    initializeTable(hashSize, p);
    FILE *fp = fopen("hashPartC.txt", "r");
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