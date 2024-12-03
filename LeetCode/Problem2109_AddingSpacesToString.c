#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void *a, const void *b) {
    int * first = (int *) a;
    int * second = (int *) b;
    return *first - *second;
}


char* addSpaces(char* s, int* spaces, int spacesSize) {
    qsort(spaces, spacesSize, sizeof(int), compare);
    int sLen = strlen(s);
    char* res = (char *) malloc(sizeof(char) * (sLen + spacesSize + 1));
    res[sLen + spacesSize] = '\0';
    int spaceIndex = 0;
    int i = 0;
    int resIndex = 0;
    for(i = 0; i < sLen; i++) {
        if(spaceIndex < spacesSize && i == spaces[spaceIndex]) {
            spaceIndex++;
            res[resIndex] = ' ';
            resIndex++;
        }
        res[resIndex] = s[i];
        resIndex++;
    }
    return res;

}
