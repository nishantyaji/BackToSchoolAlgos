int prefixCount(char** words, int wordsSize, char* pref) {
    int count = 0, i = 0;

    for(i = 0; i < wordsSize; i++) {
        char * temp = strstr(words[i], pref);
        if(temp != NULL && strlen(temp) == strlen(words[i])) {
            count++;
        }
    }
    return count;
}
