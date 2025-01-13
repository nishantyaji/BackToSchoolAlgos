#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimumLength(char* s) {
    int i = 0, res = 0, n = strlen(s);
    int mp[26] = {0};
    for(i = 0; i < n; i++) {
        int j = (int)(s[i]) - (int) 'a';
        mp[j]++;
        if(mp[j] > 2) {
            res = res + (mp[j] % 2 == 1? -1: 1);
        } else{
            res++;
        }
    }
    return res;
}
