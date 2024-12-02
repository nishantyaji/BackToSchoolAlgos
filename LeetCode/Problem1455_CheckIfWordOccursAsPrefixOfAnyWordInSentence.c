#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool compare2(char* token, char* searchWord) {
    if(strlen(token) < strlen(searchWord))
        return false;
    int i = 0;
    for(i = 0; i < strlen(searchWord); i++) {
        if(searchWord[i] != token[i]){
            return false;
        }
    }
    return true;
}

int isPrefixOfWord(char* sentence, char* searchWord) {
    
    int index = 1;
    char * token = strtok (sentence," ");
    bool flag = compare2(token, searchWord);
    if(flag) 
        return index;
    while (token != NULL)
    {
        index++;
        token = strtok (NULL, " ");
        if(token == NULL)
            return -1;
        flag = compare2(token, searchWord);
        if(flag) 
            return index;
    }
    return - 1;
}

