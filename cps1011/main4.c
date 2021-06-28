#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* replace(char *sentence, char *toBeReplaced, char *replacementWord){

    char* newSentence;
    int counter = 0;
    size_t toBeReplacedLen, replacementLen;
    toBeReplacedLen = strlen(toBeReplaced);
    replacementLen = strlen(replacementWord);
    int i;//counter to represent length of old sentence

    for(i = 0; sentence[i] != '\0'; i++){//checking how many times the string to be replaced appears in the line
        if(strstr(&sentence[i], toBeReplaced) == &sentence[i]){
            counter++;
            i += toBeReplacedLen - 1;//skip the instance of the string to be replaced which was already counted
        }
    }

    newSentence = (char*)malloc(i + counter * (replacementLen - toBeReplacedLen) + 1);//allocating memory according to the length of the new sentence (+1 for end of string character)

    i = 0;

    while(*sentence){//goes through the old sentence and replaces all instances of the desired string, placing the result in newSentence
        if(strstr(sentence, toBeReplaced) == sentence){//checks if the char pointer has reached one of the instances to be replaced
            strcpy(&newSentence[i], replacementWord);//
            i += replacementLen;
            sentence += toBeReplacedLen;
        }else{
            newSentence[i++] = *sentence++;
        }
    }
    newSentence[i] = '\0';
    return newSentence;
}

char * replaceLongWord(char *sentence){

    size_t letterCounter = 1;
    char* longWord;
    char replacementString[50];
    char replaceConfirmation[50];
    for(int i = 0; sentence[i] != '\0'; i++){//checking how many times the string to be replaced appears in the line
        if(sentence[i] != ' ' && sentence[i] != '-' && sentence[i+1] != ' ' && sentence[i+1] != '-' && sentence[i+1] != '\0') {
            letterCounter++;
        }else if(letterCounter > 12){//if a space is found but the letter counter is greater than 12, enter replacement case
            longWord = (char*)malloc(letterCounter * sizeof(char) + 1);//allocating memory for word to be replaced
            for(int x = 0; x <= letterCounter; x++){
                longWord[x] = sentence[i - (letterCounter-x)];//retrieving word to be replaced from sentence
            }
            longWord[letterCounter + 1] = '\0';//appending end of string character to the word to be replaced
            printf("Unusually long word detected: %s. Type 'replace' if you would like to replace it, otherwise type 'no'\n", longWord);
            fflush(stdin);
            scanf("%s", replaceConfirmation);//prompting user for input
            while(strcmp(replaceConfirmation, "replace") != 0 && strcmp(replaceConfirmation, "no") != 0){//user input validation
                printf("Invalid input, please type 'replace' or 'no'\n");
                fflush(stdin);
                scanf("%s", replaceConfirmation);
            }
            if(strcmp(replaceConfirmation, "replace") == 0){
                printf("What would you like to replace it with?\n");
                fflush(stdin);
                scanf("%s", replacementString);
                sentence = replace(sentence, longWord, replacementString);
                i += strlen(replacementString) - strlen(longWord);//adjusting i according to changes made in length of sentence so as to not interrupt the loop for instances of other long words
                letterCounter = 0;
            }else if(strcmp(replaceConfirmation, "no") == 0){
                letterCounter = 0;
            }
        }else{
            letterCounter = 0;
        }
    }
    return sentence;//if no word
}

int main(){

    FILE *fP;
    FILE *correctedFP;
    char *textLine;
    char address[256];
    printf("Insert the address of the file you wish to check.\n");
    fflush(stdin);
    scanf("%s", address);
    while((fP = fopen(address, "r")) == NULL){//note: spaces in file address sometimes cause an error
        printf("Invalid address, please try again.\n");
        fflush(stdin);
        scanf("%s", address);
    }
    fP = fopen(address, "r");
    correctedFP = fopen("corrected.txt", "w");
    while(!feof(fP)){
        textLine = (char*)malloc(256 * sizeof(char));
        fgets(textLine, 256, fP);
        textLine = replace(textLine, " .", ".");
        textLine = replace(textLine, " ,", ",");
        textLine = replace(textLine, "  ", " ");//clear extra spaces
        textLine = replaceLongWord(textLine);//check for and possibly replace unusually long words
        fputs(textLine, correctedFP);
    }

    return 0;

}