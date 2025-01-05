#include <stdio.h>
#include <string.h>

char* shiftingLetters(char* s, int** shifts, int shiftsSize, int* shiftsColSize) {
    int sLen = strlen(s), i = 0;
    int * dp = (int *) malloc(sizeof(int) * (sLen+1));
    for(i = 0; i < sLen+1; i++) {
        dp[i] = 0;
    }
    
    for(i = 0; i < shiftsSize; i++) {
        int start = shifts[i][0];
        int end = shifts[i][1];
        int dire = shifts[i][2];
        if(dire > 0) {
            dp[start]++;
            dp[end+1]--;
        } else{
            dp[start]--;
            dp[end+1]++;
        }
    }
    
    int cum = 0;
    char * res = (char *) malloc(sizeof(char) * (sLen + 1));
    memset(res, 0, sizeof(char) * (sLen+1));
    
    char aChar = 'a', zChar = 'z';
    int aInt = (int) aChar;
    int zInt = (int) zChar
    for(i = 0; i < sLen; i++) {
        cum += dp[i];
        cum_mod = ((cum % 26) + 26) % 26;
        temp = (int)s[i] + cum_mod;
        if(temp > zInt) temp = temp - zInt + aInt - 1
        res[i] = (char) temp;
    }
    return res
}
