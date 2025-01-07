#include <stdio.h>
#include <string.h>

int compare(const void *a, const void *b) {
    // Note the typecasting
    const char *first = *(const char **)a;
    const char *second = *(const char **)b;
    return strlen(first) - strlen(second);
}

char** stringMatching(char** words, int wordsSize, int* returnSize) {
    qsort(words, wordsSize, sizeof(char *), compare);
    int i = 0, j = 0, count = 0;
    int * flag = (int *) malloc(sizeof(int) * wordsSize);
    for(i = 0; i < wordsSize; i++) {
        flag[i] = 0;
    }
    for(i = 0; i < wordsSize; i++) {
        for(j = i+1; j < wordsSize; j++) {
            if(strstr(words[j], words[i])) {
                flag[i] = 1;
            }
        }
    }
    for(i = 0; i < wordsSize; i++) {
        if(flag[i] == 1) count++;
    }
    char ** res = (char **) malloc(sizeof(char *) * count);
    int index = 0;
    for(i = 0; i < wordsSize; i++) {
        if(flag[i] == 1) {
            res[index] = words[i];
            index++;
        }
    }
    *returnSize = count;
    return res;
}
