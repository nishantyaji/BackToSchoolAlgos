#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char** wordSubsets(char** words1, int words1Size, char** words2, int words2Size, int* returnSize) {
    int i = 0, j = 0;
    int * unified = (int *) malloc(sizeof(int) * 26);
    for(j = 0; j < 26; j++) {
        unified[j] = 0;
    }
    char aChar = 'a';
    int aInt = (int) aChar;
    for(i = 0; i < words2Size; i++) {
        int * map = (int *) malloc(sizeof(int) * 26);
        for(j = 0; j < 26; j++) {
            map[j] = 0;
        }
        for(j = 0; j < strlen(words2[i]); j++) {
            map[words2[i][j] - aInt]++;
        }
        for(j = 0; j < 26; j++) {
            unified[j] = unified[j] > map[j] ? unified[j] : map[j];
        }
        free(map);
    }
    int skip = 1, count = 0;
    char ** res = (char **) malloc(sizeof(char *) * words1Size);
    for(i = 0; i < words1Size; i++) {
        skip = 1;
        int * map = (int *) malloc(sizeof(int) * 26);
        for(j = 0; j < 26; j++) {
            map[j] = 0;
        }
        for(j = 0; j < strlen(words1[i]); j++) {
            map[words1[i][j] - aInt]++;
        }
        for(j = 0; j < 26; j++) {
            if(map[j] < unified[j]) {
                skip = 0;
                break;
            }
        }
        if(skip > 0) {
            res[count] = words1[i];
            count++;
        } 
    }
    *returnSize = count;
    return res;
}
