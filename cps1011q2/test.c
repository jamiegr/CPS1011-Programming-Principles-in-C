#include "hashtable.h"

void main()
{
    void * testTable = createTable(5);
    initializeTable(5, testTable);
    printContents(5, testTable);
    insert("1234599M", "Jamie Grech", 5, testTable);
    insert("2790323M", "George Camilleri", 5, testTable);
    insert("3257089M", "Daniel Cini", 5, testTable);
    insert("7849079M", "Andrew Borg", 5, testTable);
    insert("2802093M", "Thomas Vella", 5, testTable);
    insert("3534634M", "Sean Gauci", 5, testTable);
    insert("2308293M", "Craig Galea", 5, testTable);
    insert("2349074M", "test", 5, testTable);
    insert("2349024M", "testiii", 5, testTable);
    insert("2344024M", "testiv", 5, testTable);
    printContents(5, testTable);
    saveFile(5, testTable);
    delete("7849079M", 5, testTable);
    delete("3257089M", 5, testTable);
    delete("2349024M", 5, testTable);
    printContents(5, testTable);
    readFromFile(5, testTable);
    insert("1234599M", "testnonunique", 5, testTable);
    printContents(5, testTable);
}