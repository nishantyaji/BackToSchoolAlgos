#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool isSubSequence(char * str1, char * str1inc, int len1, char * str2, int len2) {
    int cIdx = 0;
    int i = 0;
    for(i = 0; i < len1; i++) {
        if(str2[cIdx] == str1[i] || str2[cIdx] == str1inc[i]) {
            cIdx++;
            if(cIdx == len2) 
                return true;
        }
    }
    return cIdx == len2;
}

bool canMakeSubsequence(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* str1inc = (char *)malloc(sizeof(char) * (len1 + 1));
    str1inc[len1] = '\0';
    int i = 0;
    int aCharInt = (int) 'a';
    for(i = 0; i < len1; i++) {
        str1inc[i] = (char) (aCharInt + ((int) str1[i] - aCharInt + 1) % 26);
    }
    return isSubSequence(str1, str1inc, len1, str2, len2);
}
