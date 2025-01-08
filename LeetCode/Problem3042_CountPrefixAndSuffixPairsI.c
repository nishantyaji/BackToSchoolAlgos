int countPrefixSuffixPairs(char** words, int wordsSize) {
    int i = 0, j = 0, k = 0, count = 0;
    
    for(i = 0; i < wordsSize; i++) {
        for(j = 1 + i; j < wordsSize; j++) {
            char * subStr = strstr(words[j], words[i]);
            if(subStr == NULL || strlen(subStr) < strlen(words[j])) {
                continue;
            }
            
            int equal = 1, iLen = strlen(words[i]), jLen = strlen(words[j]);
            if(jLen < iLen) {
                continue;
            }
            for(k = 0; k < iLen; k++) {
                if(words[j][jLen-1 - k] != words[i][iLen - 1 - k]) {
                    equal = 0;
                    break;
                }
            }
            if(equal == 1) {
                count++;
            }
        }
    }
    return count;
}
