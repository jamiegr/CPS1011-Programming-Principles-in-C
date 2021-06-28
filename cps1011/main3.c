#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){


    FILE *fP;
    char address[256];
    char textLine[150];
    char normalCase[150];
    char upperCase[150];
    printf("Insert the address of the file you wish to check.\n");
    scanf("%s", address);
    while((fP = fopen(address, "r")) == NULL){//note: spaces in file address cause an error
        printf("Invalid address, please try again.\n");
        fflush(stdin);
        scanf("%s", address);
    }
    fP = fopen(address, "r");
    fgets(textLine, 150, fP);//gets the first line in the file
    strcpy(normalCase, textLine);//stores the first line in the file
    strcpy(upperCase, textLine);//stores the first line in the file
    while(!feof(fP)){
        fgets(textLine, 150, fP);//keeps going till it reaches the last line in the file
    }
    for(int i = 0; i < strlen(upperCase); i++) {//converts one of the copies of the first line in the file to uppercase so that a case insensitive comparison can be made to check for an html file
        upperCase[i] = (char)toupper(upperCase[i]);
    }
    for(int i = 0; i < strlen(textLine); i++){//converts the last line in the file to uppercase so that a case insensitive comparison can be made to check for an html file
        textLine[i] = (char)toupper(textLine[i]);
    }
    if(strstr(normalCase,"#include")!=NULL) {//strstr used for case sensitive string comparison
        printf("Selected file is a C File.");
    }else if(strstr(upperCase,"<HTML>")!=NULL && strstr(textLine, "</HTML>")) {//case insensitive comparison for HTML file, comparing uppercase with uppercase
        printf("Selected file is an HTML file.");
    }else{
        printf("Selected file is neither a C file nor an HTML file");
    }

    return 0;

}